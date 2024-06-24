#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *set_alarm;
    lv_obj_t *set_timer;
    lv_obj_t *set_stopwatch;
    lv_obj_t *set_settings;
    lv_obj_t *action;
    lv_obj_t *alarm;
    lv_obj_t *alarm_time_input;
    lv_obj_t *alarm_time_input_1;
    lv_obj_t *answer;
    lv_obj_t *auto_set;
    lv_obj_t *change_date;
    lv_obj_t *change_time;
    lv_obj_t *clock;
    lv_obj_t *connect_to_wi_fi_popup;
    lv_obj_t *date;
    lv_obj_t *date_input__day;
    lv_obj_t *date_input__month;
    lv_obj_t *date_input__year;
    lv_obj_t *description;
    lv_obj_t *description_1;
    lv_obj_t *description_2;
    lv_obj_t *failed;
    lv_obj_t *info;
    lv_obj_t *minus_time;
    lv_obj_t *minus_time_1;
    lv_obj_t *music_selection;
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
    lv_obj_t *obj13;
    lv_obj_t *obj14;
    lv_obj_t *obj2;
    lv_obj_t *obj3;
    lv_obj_t *obj4;
    lv_obj_t *obj5;
    lv_obj_t *obj6;
    lv_obj_t *obj7;
    lv_obj_t *obj8;
    lv_obj_t *obj9;
    lv_obj_t *play_alarm_over_aux;
    lv_obj_t *plus_time;
    lv_obj_t *plus_time_1;
    lv_obj_t *select_setting;
    lv_obj_t *selected_setting__music;
    lv_obj_t *selected_setting__other;
    lv_obj_t *selected_setting__time;
    lv_obj_t *setting__music;
    lv_obj_t *setting__other;
    lv_obj_t *setting__recalibrate_touch;
    lv_obj_t *setting__reset;
    lv_obj_t *setting__time;
    lv_obj_t *setting__wi_fi;
    lv_obj_t *setting_time_input;
    lv_obj_t *spacer;
    lv_obj_t *status_bar;
    lv_obj_t *success;
    lv_obj_t *time_input_1;
    lv_obj_t *title;
    lv_obj_t *title_1;
    lv_obj_t *title_2;
    lv_obj_t *title_3;
    lv_obj_t *volume_slider__alarm;
    lv_obj_t *volume_slider__aux_in;
    lv_obj_t *wi_fi_connection_answer_popup;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_SET_ALARM = 2,
    SCREEN_ID_SET_TIMER = 3,
    SCREEN_ID_SET_STOPWATCH = 4,
    SCREEN_ID_SET_SETTINGS = 5,
};

void create_screen_main();
void tick_screen_main();

void create_screen_set_alarm();
void tick_screen_set_alarm();

void create_screen_set_timer();
void tick_screen_set_timer();

void create_screen_set_stopwatch();
void tick_screen_set_stopwatch();

void create_screen_set_settings();
void tick_screen_set_settings();

void create_screens();
void tick_screen(int screen_index);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/