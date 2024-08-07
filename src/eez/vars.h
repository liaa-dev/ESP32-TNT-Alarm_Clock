#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// enum declarations



// Flow global variables

enum FlowGlobalVariables {
    FLOW_GLOBAL_VARIABLE_MAIN_CLOCK_TIME = 0,
    FLOW_GLOBAL_VARIABLE_MAIN_CLOCK_SECONDS = 1,
    FLOW_GLOBAL_VARIABLE_MAIN_DATE = 2,
    FLOW_GLOBAL_VARIABLE_MAIN_DAY_TODAY = 3,
    FLOW_GLOBAL_VARIABLE_MAIN_DAY_TOMORROW = 4,
    FLOW_GLOBAL_VARIABLE_MAIN_DAY_SCNDNEXTDAY = 5,
    FLOW_GLOBAL_VARIABLE_MAIN_DAY_THRDNEXTDAY = 6,
    FLOW_GLOBAL_VARIABLE_MAIN_TEMP_TODAY = 7,
    FLOW_GLOBAL_VARIABLE_MAIN_TEMP_TOMORROW = 8,
    FLOW_GLOBAL_VARIABLE_MAIN_TEMP_SCNDNEXTDAY = 9,
    FLOW_GLOBAL_VARIABLE_MAIN_TEMP_THRDNEXTDAY = 10,
    FLOW_GLOBAL_VARIABLE_MAIN_ACTION = 11,
    FLOW_GLOBAL_VARIABLE_MAIN_ACTION_TIME = 12,
    FLOW_GLOBAL_VARIABLE_MAIN_IS_WIFI_CONNECTED = 13,
    FLOW_GLOBAL_VARIABLE_MAIN_INFO_BAR_TEXT = 14,
    FLOW_GLOBAL_VARIABLE_MAIN_INFO_BAR_VALUE = 15,
    FLOW_GLOBAL_VARIABLE_MAIN_ALARM_TIME = 16,
    FLOW_GLOBAL_VARIABLE_MAIN_ALARM_REASON = 17,
    FLOW_GLOBAL_VARIABLE_ALARM_REASONS = 18,
    FLOW_GLOBAL_VARIABLE_ALARM_SELECTED_REASON = 19,
    FLOW_GLOBAL_VARIABLE_TIMER_TIME = 20,
    FLOW_GLOBAL_VARIABLE_TIMER_ARC_VALUE = 21,
    FLOW_GLOBAL_VARIABLE_STOPWATCH_TIME = 22,
    FLOW_GLOBAL_VARIABLE_SETTINGS_TITLE = 23,
    FLOW_GLOBAL_VARIABLE_SETTINGS_HIDE_SELECTION = 24,
    FLOW_GLOBAL_VARIABLE_SETTINGS_HIDE_SETTING_TIME = 25,
    FLOW_GLOBAL_VARIABLE_SETTINGS_HIDE_SETTING_ALARM = 26,
    FLOW_GLOBAL_VARIABLE_SETTINGS_HIDE_SETTING_AUDIO = 27,
    FLOW_GLOBAL_VARIABLE_SETTINGS_HIDE_SETTING_WIFI = 28,
    FLOW_GLOBAL_VARIABLE_SETTINGS_HIDE_SETTING_OTHER = 29,
    FLOW_GLOBAL_VARIABLE_SETTINGS_SETTING_TIME_CHECKED_AUTOSET = 30,
    FLOW_GLOBAL_VARIABLE_SETTINGS_SETTING_TIME_NEW_TIME = 31,
    FLOW_GLOBAL_VARIABLE_SETTINGS_SETTING_TIME_SELECTED_MONTH = 32,
    FLOW_GLOBAL_VARIABLE_SETTINGS_SETTING_TIME_SELECTED_DAY = 33,
    FLOW_GLOBAL_VARIABLE_SETTINGS_SETTING_TIME_SELECTED_YEAR = 34,
    FLOW_GLOBAL_VARIABLE_SETTINGS_SETTING_ALARM_SELECTED_REPEATS = 35,
    FLOW_GLOBAL_VARIABLE_SETTINGS_SETTING_ALARM_SELECTED_REPEAT_AFTER = 36,
    FLOW_GLOBAL_VARIABLE_SETTINGS_SETTING_AUDIO_CHECKED_ALARM_OVER_AUX = 37,
    FLOW_GLOBAL_VARIABLE_SETTINGS_SETTING_AUDIO_SELECTED_MUSIC = 38,
    FLOW_GLOBAL_VARIABLE_SETTINGS_SETTING_AUDIO_ALARM_VOLUME_VALUE = 39,
    FLOW_GLOBAL_VARIABLE_SETTINGS_SETTING_AUDIO_AUXIN_VOLUME_VALUE = 40
};

// Native global variables

extern const char *get_var_main_clock_time();
extern void set_var_main_clock_time(const char *value);
extern const char *get_var_main_clock_seconds();
extern void set_var_main_clock_seconds(const char *value);
extern const char *get_var_main_date();
extern void set_var_main_date(const char *value);
extern const char *get_var_main_day_today();
extern void set_var_main_day_today(const char *value);
extern const char *get_var_main_day_tomorrow();
extern void set_var_main_day_tomorrow(const char *value);
extern const char *get_var_main_day_scndnextday();
extern void set_var_main_day_scndnextday(const char *value);
extern const char *get_var_main_day_thrdnextday();
extern void set_var_main_day_thrdnextday(const char *value);
extern const char *get_var_main_temp_today();
extern void set_var_main_temp_today(const char *value);
extern const char *get_var_main_temp_tomorrow();
extern void set_var_main_temp_tomorrow(const char *value);
extern const char *get_var_main_temp_scndnextday();
extern void set_var_main_temp_scndnextday(const char *value);
extern const char *get_var_main_temp_thrdnextday();
extern void set_var_main_temp_thrdnextday(const char *value);
extern const char *get_var_main_action();
extern void set_var_main_action(const char *value);
extern const char *get_var_main_action_time();
extern void set_var_main_action_time(const char *value);
extern bool get_var_main_is_wifi_connected();
extern void set_var_main_is_wifi_connected(bool value);
extern const char *get_var_main_info_bar_text();
extern void set_var_main_info_bar_text(const char *value);
extern int32_t get_var_main_info_bar_value();
extern void set_var_main_info_bar_value(int32_t value);
extern const char *get_var_main_alarm_time();
extern void set_var_main_alarm_time(const char *value);
extern const char *get_var_main_alarm_reason();
extern void set_var_main_alarm_reason(const char *value);
extern const char *get_var_alarm_time();
extern void set_var_alarm_time(const char *value);
extern const char *get_var_alarm_reasons();
extern void set_var_alarm_reasons(const char *value);
extern int32_t get_var_alarm_selected_reason();
extern void set_var_alarm_selected_reason(int32_t id);
const char* get_alarm_selected_reason(int32_t id);
extern const char *get_var_timer_time();
extern void set_var_timer_time(const char *value);
extern int32_t get_var_timer_arc_value();
extern void set_var_timer_arc_value(int32_t value);
extern const char *get_var_stopwatch_time();
extern void set_var_stopwatch_time(const char *value);
extern const char *get_var_settings_title();
extern void set_var_settings_title(const char *value);
extern bool get_var_settings_hide_selection();
extern void set_var_settings_hide_selection(bool value);
extern bool get_var_settings_hide_setting_time();
extern void set_var_settings_hide_setting_time(bool value);
extern bool get_var_settings_hide_setting_alarm();
extern void set_var_settings_hide_setting_alarm(bool value);
extern bool get_var_settings_hide_setting_audio();
extern void set_var_settings_hide_setting_audio(bool value);
extern bool get_var_settings_hide_setting_wifi();
extern void set_var_settings_hide_setting_wifi(bool value);
extern bool get_var_settings_hide_setting_other();
extern void set_var_settings_hide_setting_other(bool value);
extern bool get_var_settings_setting_time_checked_autoset();
extern void set_var_settings_setting_time_checked_autoset(bool value);
extern const char *get_var_settings_setting_time_new_time();
extern void set_var_settings_setting_time_new_time(const char *value);
extern int32_t get_var_settings_setting_time_selected_month();
extern void set_var_settings_setting_time_selected_month(int32_t value);
extern int32_t get_var_settings_setting_time_selected_day();
extern void set_var_settings_setting_time_selected_day(int32_t value);
extern int32_t get_var_settings_setting_time_selected_year();
extern void set_var_settings_setting_time_selected_year(int32_t value);
extern int32_t get_var_settings_setting_alarm_selected_repeats();
extern void set_var_settings_setting_alarm_selected_repeats(int32_t value);
extern int32_t get_var_settings_setting_alarm_selected_repeat_after();
extern void set_var_settings_setting_alarm_selected_repeat_after(int32_t value);
extern bool get_var_settings_setting_audio_checked_alarm_over_aux();
extern void set_var_settings_setting_audio_checked_alarm_over_aux(bool value);
extern int32_t get_var_settings_setting_audio_selected_music();
extern void set_var_settings_setting_audio_selected_music(int32_t value);
extern const char *get_var_settings_setting_audio_music_selection();
extern void set_var_settings_setting_audio_music_selection(const char* value);
extern int32_t get_var_settings_setting_audio_alarm_volume_value();
extern void set_var_settings_setting_audio_alarm_volume_value(int32_t value);
extern int32_t get_var_settings_setting_audio_auxin_volume_value();
extern void set_var_settings_setting_audio_auxin_volume_value(int32_t value);

const char* get_var_settings_setting_time_selected_date();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/