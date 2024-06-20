#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include <lvgl.h>
#include <eez/screens.h>
#include <eez/ui.h>
#include <WiFi.h>

TFT_eSPI tft = TFT_eSPI();

#define DRAW_BUF_SIZE (TFT_HOR_RES * TFT_VER_RES / 10 * (LV_COLOR_DEPTH / 8))
uint32_t draw_buf[DRAW_BUF_SIZE / 4];

lv_indev_t * indev;    // Touchscreen input device for LVGL
uint32_t lv_lastTick = 0;  // Used to track the tick timer

void my_disp_flush(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map);
void my_touchpad_read(lv_indev_t *indev, lv_indev_data_t *data);
void lvgl_debug_print(lv_log_level_t level, const char * buf);
void handleLVGL();
static uint32_t lvgl_tick();

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

  uint16_t calData[5] = { 259, 3639, 231, 3513, 1 };
  tft.setTouch(calData);

  Serial.println("Initializing LVGL...");
  lv_init();
  lv_display_t * disp;

  // Init own display
  disp = lv_display_create(TFT_HOR_RES, TFT_VER_RES);
  lv_display_set_flush_cb(disp, my_disp_flush);
  lv_display_set_buffers(disp, draw_buf, NULL, sizeof(draw_buf), LV_DISPLAY_RENDER_MODE_PARTIAL);

  Serial.println("Initializing touchscreen input device XPT2046...");
  indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);  
  lv_indev_set_read_cb(indev, my_touchpad_read);
  if(!indev) {
    Serial.println("Failed to create input device");
  } else {
    Serial.println("Touchscreen input device created!");
  }

  lv_lastTick = millis();
  lv_tick_set_cb(lvgl_tick); // Set the tick function for LVGL

  #if LV_USE_LOG != 0
    lv_log_register_print_cb(lvgl_debug_print); // register print function for debugging
  #endif

  Serial.println("Initializing WiFi...");
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  ui_init();

  handleLVGL();
}

void loop() {
  handleLVGL();
}

void handleLVGL() {
  lv_tick_inc(millis() - lv_lastTick); // LVGL needs a system tick to know the elapsed time for animations and other tasks.
  lv_lastTick = millis();

  ui_tick();
    
  lv_refr_now(NULL); // Tell LVGL to refresh the screen (Increases FPS to 30, Drops CPU usage to 33%)
  lv_task_handler(); // Call the LVGL task handler
  delay(5);
}

// Implement and register a function which can copy the rendered image to an area of your display:
void my_disp_flush(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map) {
  uint32_t w = lv_area_get_width(area);
  uint32_t h = lv_area_get_height(area);

  tft.startWrite();
  tft.setAddrWindow(area->x1, area->y1, w, h);      // Set window area to pour pixels into
  tft.pushColors( (uint16_t *) px_map, w*h, true);  // Push Color Informations into area
  tft.endWrite();

  lv_disp_flush_ready(disp);                        // Indicate you are ready with the flushing
}

// Implement and register a function which can read an input device. E.g. for a touchpad:
void my_touchpad_read(lv_indev_t *indev, lv_indev_data_t *data) { // Read the touchscreen
  uint16_t x, y;

  if (tft.getTouch(&x, &y)) {
    data->point.x = x;
    data->point.y = y;
    data->state = LV_INDEV_STATE_PRESSED;
    Serial.printf("Touchpad pressed at x: %d, y: %d\n", x, y);
  } else {
    data->state = LV_INDEV_STATE_RELEASED;
  }
}

static uint32_t lvgl_tick() {
  return millis();
}

#if LV_USE_LOG
// user function, that is called from LVGL
// Serial debugging 
void lvgl_debug_print(lv_log_level_t level, const char * buf) {
  LV_UNUSED(level);
  Serial.printf(buf);
  Serial.flush();
}
#endif