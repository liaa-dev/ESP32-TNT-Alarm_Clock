#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include <lvgl.h>
#include <SD.h>
#include <eez/ui.h>
#include <WiFi.h>
#include <eez/vars.h>
#include <eez/fonts.h>
#include <main.hpp>
#include <eez/actions.h>

TFT_eSPI tft = TFT_eSPI(TFT_HOR_RES, TFT_VER_RES);

static lv_color_t buf[TFT_HOR_RES * TFT_VER_RES / 10];
lv_disp_t *disp;
static lv_disp_draw_buf_t disp_buf;
lv_indev_t *indev;

uint16_t calData[5];

void my_disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p);
void my_touchpad_read(lv_indev_drv_t *drv, lv_indev_data_t *data);
void lvgl_debug_print(const char * buf);
void handleLVGL();

//TODO
/*Notice:

AUX mode is enabled and the preference mode is selected.
In the event of an alarm, the alarm will take precedence over the AUX input.
Procedure during an alarm:

When an alarm is played, we will set the mute pin of the audio amplifier to HIGH.
The alarm sound will be played.
After the alarm ends, the mute pin will be reset to its original state.
Important: This behavior will only occur if the "Alarm over AUX" function is enabled to prevent signal mixing.*/

void setup() {
  pinMode(TFT_BL, OUTPUT); // controlable with analogWrite(TFT_BL, 0-255);

  Serial.begin(115200);
  Serial.println("Starting...");
  Serial.print("Using LVGL Version: ");
  Serial.print(LVGL_VERSION_MAJOR);
  Serial.print(".");
  Serial.print(LVGL_VERSION_MINOR);
  Serial.print(".");
  Serial.println(LVGL_VERSION_PATCH);

  Serial.println("Initializing TFT_eSPI...");

  tft.init();
  tft.fillScreen(TFT_BLACK);
  tft.setRotation(3);

  calData[0] = 278;
  calData[1] = 3616;
  calData[2] = 296;
  calData[3] = 3477;
  calData[4] = 1;
  tft.setTouch(calData);

  Serial.println("Initializing LVGL...");
  lv_init();
  lv_disp_draw_buf_init(&disp_buf, buf, NULL, TFT_HOR_RES * TFT_VER_RES / 10);

  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = TFT_HOR_RES;
  disp_drv.ver_res = TFT_VER_RES;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &disp_buf;
  disp = lv_disp_drv_register(&disp_drv);

  if(!disp) {
    Serial.println("Failed to create display!");
  }

  Serial.println("Initializing touchscreen input device XPT2046...");
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  indev = lv_indev_drv_register(&indev_drv);
  if(!indev) {
    Serial.println("Failed to create input device");
  } else {
    Serial.println("Touchscreen input device created!");
  }

  #if LV_USE_LOG
    lv_log_register_print_cb(lvgl_debug_print);
  #endif

  Serial.println("LVGL initialized!");

  /*Serial.println("Initializing SD card...");
  if (!SD.begin(SD_CS)) {
    Serial.println(F("SD Card failed, or not present! Please press RESET to try again!"));
    return;
  }*/

  Serial.println("SD card initialized!");

  Serial.println("Initializing WiFi...");
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  Serial.println("WiFi initialized!");

  //lv_fs_fatfs_init();

  ui_init();

  handleLVGL();
}

void loop() {
  handleLVGL();
}

void print(const char *message) {
  Serial.println(message);
}
void printlong(unsigned long value) {
  Serial.println(value);
}

void handleLVGL() {
  ui_tick();
    
  lv_refr_now(NULL); // Tell LVGL to refresh the screen (Increases FPS to 30, Drops CPU usage to 33%)
  lv_task_handler(); // Call the LVGL task handler
  delay(5);
}

static void event_handler_cb_wi_fi_table_draw_part(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    lv_obj_draw_part_dsc_t * dsc = lv_event_get_draw_part_dsc(e);
    /*If the cells are drawn...*/
    if(dsc->part == LV_PART_ITEMS) {
        uint32_t row = dsc->id /  lv_table_get_col_cnt(obj);
        uint32_t col = dsc->id - row * lv_table_get_col_cnt(obj);

        dsc->label_dsc->align = LV_TEXT_ALIGN_CENTER;

        /*Make the texts in the first cell center aligned*/
        if(row == 0) {
            dsc->rect_dsc->bg_color = lv_color_hex(0x080808);
            dsc->rect_dsc->bg_opa = LV_OPA_COVER;
            dsc->label_dsc->color = lv_color_hex(0xFF0000);
        }
        /*Make every other row dark colored*/
        else {
            dsc->label_dsc->color = lv_color_white();
            dsc->rect_dsc->bg_color = lv_color_hex(0x101010);
        }

        /*Make every 2nd row grayish*/
        if((row != 0 && row % 2) == 0) {
            dsc->rect_dsc->bg_color = lv_color_hex(0x181818);
            dsc->rect_dsc->bg_opa = LV_OPA_COVER;
        }
    }
}

static void event_handler_cb_wi_fi_table_value_changed(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_VALUE_CHANGED) {
      uint16_t row;
      uint16_t col;
      lv_table_get_selected_cell(obj, &row, &col);
      //set_var_settings_wi_fi_hide_connect_to_wi_fi_popup(false);
    }
}

lv_obj_t *wi_fi_table;
void create_wi_fi_table() {
  delete_wi_fi_table();
  wi_fi_table = lv_table_create(lv_scr_act());
  int pixel_size = 30;
  lv_obj_set_pos(wi_fi_table, 90, 109);
  lv_obj_set_size(wi_fi_table, 300, 200);
  lv_obj_set_style_bg_color(wi_fi_table, lv_color_hex(0x101010), 0);
  lv_obj_set_style_text_font(wi_fi_table, &lv_font_montserrat_16, 0);

  lv_table_set_cell_value(wi_fi_table, 0, 0, "Nr.");
  lv_table_set_col_width(wi_fi_table, 0, 60);
  lv_table_set_cell_value(wi_fi_table, 0, 1, "SSID");
  lv_table_set_cell_value(wi_fi_table, 0, 2, "Sig.");
  lv_table_set_col_width(wi_fi_table, 2, 90);
  lv_table_set_cell_value(wi_fi_table, 0, 3, "Auth.");

  int foundNetworks = WiFi.scanNetworks();
  for(int i = 1; i < foundNetworks; i++) {
      lv_table_set_cell_value(wi_fi_table, i, 0, String(i).c_str());
      lv_table_set_cell_value(wi_fi_table, i, 1, WiFi.SSID(i).c_str());
      lv_table_set_cell_value(wi_fi_table, i, 2, String(WiFi.RSSI(i)).c_str());
      lv_table_set_cell_value(wi_fi_table, i, 3, WiFi.encryptionType(i) == WIFI_AUTH_OPEN ? "Open" : "WPA/WPA2");
      delay(10);
  }

  lv_obj_add_event_cb(wi_fi_table, event_handler_cb_wi_fi_table_draw_part, LV_EVENT_DRAW_PART_BEGIN, NULL);
  lv_obj_add_event_cb(wi_fi_table, event_handler_cb_wi_fi_table_value_changed, LV_EVENT_VALUE_CHANGED, NULL);
}

void delete_wi_fi_table() {
  if(wi_fi_table != NULL) {
    lv_obj_del(wi_fi_table);
    wi_fi_table = NULL;
  }
}

bool connectToWiFi(const char *ssid, const char *password) {
  WiFi.begin(ssid, password);
  delay(5000);
  if(WiFi.status() != WL_CONNECTED) {
    Serial.println("Could not connect to the WiFi network!");
    return false;
  }
  Serial.println("Successfully connected to the WiFi network!");
  return true;
}

// Implement and register a function which can copy the rendered image to an area of your display:
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
  uint32_t w = lv_area_get_width(area);
  uint32_t h = lv_area_get_height(area);

  tft.startWrite();
  tft.setAddrWindow(area->x1, area->y1, w, h);      // Set window area to pour pixels into
  tft.pushColors( (uint16_t *) color_p, w*h, true);  // Push Color Informations into area
  tft.endWrite();

  lv_disp_flush_ready(disp);                        // Indicate you are ready with the flushing
}

// Implement and register a function which can read an input device. E.g. for a touchpad:
void my_touchpad_read(lv_indev_drv_t *drv, lv_indev_data_t *data) { // Read the touchscreen
  uint16_t x, y;

  if (tft.getTouch(&x, &y)) {
    data->point.x = x;
    data->point.y = y;
    data->state = LV_INDEV_STATE_PR;
    Serial.printf("Touchpad pressed at x: %d, y: %d\n", x, y);
  } else {
    data->state = LV_INDEV_STATE_REL;
  }
}

#if LV_USE_LOG
// user function, that is called from LVGL
// Serial debugging 
void lvgl_debug_print(const char * buf) {
  Serial.printf(buf);
  Serial.flush();
}
#endif

bool calibrate_touch() {
  tft.calibrateTouch(calData, TFT_MAGENTA, TFT_BLACK, 15);
  tft.setTouch(calData);
  return true;
}

void restart_esp() {
  ESP.restart();
}