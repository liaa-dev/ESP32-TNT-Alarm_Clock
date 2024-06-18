#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_alarm_32;
extern const lv_img_dsc_t img_minecraft_xp_bar;
extern const lv_img_dsc_t img_minecraft_xp_bar_filled;
extern const lv_img_dsc_t img_partly_cloudy_day;
extern const lv_img_dsc_t img_chronometer_32;
extern const lv_img_dsc_t img_arrow_right_24;
extern const lv_img_dsc_t img_arrow_left_24;
extern const lv_img_dsc_t img_drop_down;
extern const lv_img_dsc_t img_double_arrow_down_16;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[9];


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/