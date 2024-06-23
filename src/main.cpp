#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include <lvgl.h>
#include <SD.h>
#include <eez/ui.h>
#include <AudioTools.h>
#include <BluetoothA2DP.h>
#include <WiFi.h>

TFT_eSPI tft = TFT_eSPI(TFT_HOR_RES, TFT_VER_RES);

static lv_color_t buf[TFT_HOR_RES * TFT_VER_RES / 10];
lv_disp_t *disp;
static lv_disp_draw_buf_t disp_buf;
lv_indev_t *indev;

uint16_t lv_lastTick = 0;  // Used to track the tick timer

void my_disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p);
void my_touchpad_read(lv_indev_drv_t *drv, lv_indev_data_t *data);
void lvgl_debug_print(const char * buf);
void handleLVGL();
static uint32_t lvgl_tick(void);

void setup() {
  pinMode(TFT_BL, OUTPUT); // steuerbar über analogWrite(TFT_BL, 0-255);

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

  uint16_t calData[5] = { 278, 3616, 296, 3477, 1 };
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

  lv_lastTick = millis();
  //lv_tick_inc(millis());

  #if LV_USE_LOG
    lv_log_register_print_cb(lvgl_debug_print);
  #endif

  Serial.println("LVGL initialized!");

  Serial.println("Initializing SD card...");
  if (!SD.begin(SD_CS)) {
    Serial.println(F("SD Card failed, or not present! Please press RESET to try again!"));
    return;
  }

  Serial.println("SD card initialized!");

  lv_fs_fatfs_init();

  ui_init();
  handleLVGL();
}

void loop() {
  handleLVGL();
}

void handleLVGL() {
  //lv_tick_inc(millis() - lv_lastTick); // LVGL needs a system tick to know the elapsed time for animations and other tasks.
  lv_lastTick = millis();

  ui_tick();
    
  lv_refr_now(NULL); // Tell LVGL to refresh the screen (Increases FPS to 30, Drops CPU usage to 33%)
  lv_task_handler(); // Call the LVGL task handler
  delay(5);
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