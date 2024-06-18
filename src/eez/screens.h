#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *set_alarm;
    lv_obj_t *main;
    lv_obj_t *action;
    lv_obj_t *alarm;
    lv_obj_t *clock;
    lv_obj_t *date;
    lv_obj_t *description;
    lv_obj_t *dropdown_fix;
    lv_obj_t *info;
    lv_obj_t *minus_time;
    lv_obj_t *next_screen;
    lv_obj_t *next_screen_1;
    lv_obj_t *next_screen_2;
    lv_obj_t *plus_time;
    lv_obj_t *reason;
    lv_obj_t *spacer;
    lv_obj_t *status_bar;
    lv_obj_t *time_input;
    lv_obj_t *title;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_SET_ALARM = 2,
    SCREEN_ID_MAIN = 1,
};

void create_screen_set_alarm();
void tick_screen_set_alarm();

void create_screen_main();
void tick_screen_main();

void create_screens();
void tick_screen(int screen_index);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/