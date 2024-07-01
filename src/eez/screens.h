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
    lv_obj_t *alarm;
    lv_obj_t *alarm_backward;
    lv_obj_t *alarm_description;
    lv_obj_t *alarm_forward;
    lv_obj_t *alarm_minus_time;
    lv_obj_t *alarm_plus_time;
    lv_obj_t *alarm_repeat_for;
    lv_obj_t *alarm_reset_button;
    lv_obj_t *alarm_select_reason;
    lv_obj_t *alarm_select_repeat_after;
    lv_obj_t *alarm_select_repeats;
    lv_obj_t *alarm_select_repeats_1;
    lv_obj_t *alarm_set_button;
    lv_obj_t *alarm_time_input;
    lv_obj_t *alarm_title;
    lv_obj_t *audio_alarm_volume_slider;
    lv_obj_t *audio_aux_in_volume_slider;
    lv_obj_t *audio_change_alarm_volume;
    lv_obj_t *audio_change_aux_in_volume;
    lv_obj_t *audio_play_alarm_over_aux;
    lv_obj_t *audio_select_music;
    lv_obj_t *change_date;
    lv_obj_t *date_input__day;
    lv_obj_t *date_input__month;
    lv_obj_t *date_input__year;
    lv_obj_t *main_clock;
    lv_obj_t *main_creeper_image;
    lv_obj_t *main_date;
    lv_obj_t *main_forward;
    lv_obj_t *main_icon_wifi_connected;
    lv_obj_t *main_info;
    lv_obj_t *main_weather_day_after_next_day;
    lv_obj_t *main_weather_day_after_next_next_day;
    lv_obj_t *main_weather_info;
    lv_obj_t *main_weather_next_day;
    lv_obj_t *main_weather_today;
    lv_obj_t *minus_time_1;
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
    lv_obj_t *other_calibrate_touch;
    lv_obj_t *other_reset;
    lv_obj_t *plus_time_1;
    lv_obj_t *select_setting;
    lv_obj_t *selected_setting__alarm;
    lv_obj_t *selected_setting__audio;
    lv_obj_t *selected_setting__other;
    lv_obj_t *selected_setting__time;
    lv_obj_t *selected_setting__wi_fi;
    lv_obj_t *setting__alarm;
    lv_obj_t *setting__audio;
    lv_obj_t *setting__other;
    lv_obj_t *setting__time;
    lv_obj_t *setting__wi_fi;
    lv_obj_t *setting_time_input;
    lv_obj_t *settings_backward;
    lv_obj_t *settings_forward;
    lv_obj_t *settings_title;
    lv_obj_t *stopwatch_backward;
    lv_obj_t *stopwatch_description;
    lv_obj_t *stopwatch_forward;
    lv_obj_t *stopwatch_reset_button;
    lv_obj_t *stopwatch_start_button;
    lv_obj_t *stopwatch_time_count;
    lv_obj_t *stopwatch_title;
    lv_obj_t *time_auto_set_checkbox;
    lv_obj_t *time_change_time;
    lv_obj_t *timer_arc;
    lv_obj_t *timer_backward;
    lv_obj_t *timer_description;
    lv_obj_t *timer_forward;
    lv_obj_t *timer_reset_button;
    lv_obj_t *timer_set_button;
    lv_obj_t *timer_time_displayed;
    lv_obj_t *timer_title;
    lv_obj_t *popup;
    lv_obj_t *popup_close_bar;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_SET_ALARM = 2,
    SCREEN_ID_SET_TIMER = 3,
    SCREEN_ID_SET_STOPWATCH = 4,
    SCREEN_ID_SET_SETTINGS = 5,
};

bool exists_popup();
void create_popup(lv_obj_t* parent, const lv_img_dsc_t* title_img, const char* message, const char* scnd_message, const char * btns[2], bool btn_close, int btns_size, bool auto_close, unsigned long close_after);
void close_popup();
void tick_popup();

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