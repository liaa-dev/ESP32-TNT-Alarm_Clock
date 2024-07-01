#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_alarm_32;
extern const lv_img_dsc_t img_partly_cloudy_day;
extern const lv_img_dsc_t img_chronometer_32;
extern const lv_img_dsc_t img_arrow_right_24;
extern const lv_img_dsc_t img_arrow_left_24;
extern const lv_img_dsc_t img_wifi_16;
extern const lv_img_dsc_t img_crepper_64x95;
extern const lv_img_dsc_t img_wifi_qrcode_128;
extern const lv_img_dsc_t img_sleepy_fox_128;
extern const lv_img_dsc_t img_success_64;
extern const lv_img_dsc_t img_failed_64;
extern const lv_img_dsc_t img_warning_64;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[8];


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/