#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *set_settings;
    lv_obj_t *set_stopwatch;
    lv_obj_t *main;
    lv_obj_t *set_timer;
    lv_obj_t *set_alarm;
    lv_obj_t *action;
    lv_obj_t *alarm;
    lv_obj_t *clock;
    lv_obj_t *date;
    lv_obj_t *date_input__day;
    lv_obj_t *date_input__month;
    lv_obj_t *date_input__year;
    lv_obj_t *description;
    lv_obj_t *description_1;
    lv_obj_t *description_2;
    lv_obj_t *info;
    lv_obj_t *minus_time;
    lv_obj_t *minus_time_1;
    lv_obj_t *next_screen;
    lv_obj_t *next_screen_1;
    lv_obj_t *next_screen_2;
    lv_obj_t *next_screen_3;
    lv_obj_t *next_screen_4;
    lv_obj_t *next_screen_5;
    lv_obj_t *next_screen_6;
    lv_obj_t *next_screen_7;
    lv_obj_t *next_screen_8;
    lv_obj_t *obj0;
    lv_obj_t *obj1;
    lv_obj_t *obj10;
    lv_obj_t *obj11;
    lv_obj_t *obj12;
    lv_obj_t *obj2;
    lv_obj_t *obj3;
    lv_obj_t *obj4;
    lv_obj_t *obj5;
    lv_obj_t *obj6;
    lv_obj_t *obj7;
    lv_obj_t *obj8;
    lv_obj_t *obj9;
    lv_obj_t *plus_time;
    lv_obj_t *plus_time_1;
    lv_obj_t *spacer;
    lv_obj_t *status_bar;
    lv_obj_t *time_input;
    lv_obj_t *time_input_1;
    lv_obj_t *time_input_2;
    lv_obj_t *title;
    lv_obj_t *title_1;
    lv_obj_t *title_2;
    lv_obj_t *title_3;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_SET_SETTINGS = 1,
    SCREEN_ID_SET_STOPWATCH = 2,
    SCREEN_ID_MAIN = 3,
    SCREEN_ID_SET_TIMER = 4,
    SCREEN_ID_SET_ALARM = 5,
};

void create_screen_set_settings();
void tick_screen_set_settings();

void create_screen_set_stopwatch();
void tick_screen_set_stopwatch();

void create_screen_main();
void tick_screen_main();

void create_screen_set_timer();
void tick_screen_set_timer();

void create_screen_set_alarm();
void tick_screen_set_alarm();

void create_screens();
void tick_screen(int screen_index);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/