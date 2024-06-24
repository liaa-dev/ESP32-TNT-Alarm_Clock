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
    FLOW_GLOBAL_VARIABLE_DIGITAL_TIME = 0,
    FLOW_GLOBAL_VARIABLE_DIGITAL_DATE = 1,
    FLOW_GLOBAL_VARIABLE_DIGITAL_TEMPERATURE = 2,
    FLOW_GLOBAL_VARIABLE_RUNNING_ACTION = 3,
    FLOW_GLOBAL_VARIABLE_RUNNING_ACTION_TIME = 4,
    FLOW_GLOBAL_VARIABLE_STATUS_BAR_TEXT = 5,
    FLOW_GLOBAL_VARIABLE_STATUS_BAR_VALUE = 6,
    FLOW_GLOBAL_VARIABLE_ALARM_TIME = 7,
    FLOW_GLOBAL_VARIABLE_ALARM_REASON = 8,
    FLOW_GLOBAL_VARIABLE_ALARM_SELECTED_REASON = 9,
    FLOW_GLOBAL_VARIABLE_TIMER_TIME = 10,
    FLOW_GLOBAL_VARIABLE_TIMER_VALUE = 11,
    FLOW_GLOBAL_VARIABLE_STOPWATCH_TIME = 12,
    FLOW_GLOBAL_VARIABLE_STOPWATCH_HIDE_PAUSE_BTN = 13,
    FLOW_GLOBAL_VARIABLE_STOPWATCH_HIDE_START_BTN = 14,
    FLOW_GLOBAL_VARIABLE_SETTINGS_TITLE = 15,
    FLOW_GLOBAL_VARIABLE_SETTINGS_HIDE_TIME = 16,
    FLOW_GLOBAL_VARIABLE_SETTINGS_HIDE_MUSIC = 17,
    FLOW_GLOBAL_VARIABLE_SETTINGS_HIDE_WI_FI = 18,
    FLOW_GLOBAL_VARIABLE_SETTINGS_HIDE_OTHER = 19,
    FLOW_GLOBAL_VARIABLE_SETTINGS_HIDE_SELECTION = 20,
    FLOW_GLOBAL_VARIABLE_SETTINGS_TIME_AUTO_SET_CHECKED = 21,
    FLOW_GLOBAL_VARIABLE_SETTINGS_TIME_CHANGED_TIME = 22,
    FLOW_GLOBAL_VARIABLE_SETTINGS_TIME_MONTH_SELECTED = 23,
    FLOW_GLOBAL_VARIABLE_SETTINGS_TIME_DAY_SELECTED = 24,
    FLOW_GLOBAL_VARIABLE_SETTINGS_TIME_YEAR_SELECTED = 25,
    FLOW_GLOBAL_VARIABLE_SETTINGS_MUSIC_ALARM_OVER_AUX_CHECKED = 26,
    FLOW_GLOBAL_VARIABLE_SETTINGS_MUSIC_SELECTED = 27,
    FLOW_GLOBAL_VARIABLE_SETTINGS_MUSIC_SELECTION = 28,
    FLOW_GLOBAL_VARIABLE_SETTINGS_MUSIC_ALARM_VOLUME = 29,
    FLOW_GLOBAL_VARIABLE_SETTINGS_MUSIC_AUXIN_VOLUME = 30,
    FLOW_GLOBAL_VARIABLE_ALARM_SELECTED_REPEATS = 31,
    FLOW_GLOBAL_VARIABLE_SETTINGS_WI_FI_HIDE_CONNECT_TO_WI_FI_POPUP = 32,
    FLOW_GLOBAL_VARIABLE_SETTINGS_WI_FI_POPUP_PASSWORD = 33,
    FLOW_GLOBAL_VARIABLE_SETTINGS_WI_FI_CONNECTION_ANSWER = 34,
    FLOW_GLOBAL_VARIABLE_SETTINGS_WI_FI_HIDE_ANSWER_POPUP = 35,
    FLOW_GLOBAL_VARIABLE_SETTINGS_WI_FI_HIDE_ANSWER_SUCCESS = 36,
    FLOW_GLOBAL_VARIABLE_SETTINGS_WI_FI_HIDE_ANSWER_FAILED = 37,
    FLOW_GLOBAL_VARIABLE_SETTINGS_WI_FI_HIDE_ANSWER_LOADING = 38
};

// Native global variables

extern const char *get_var_digital_time();
extern void set_var_digital_time(const char *value);
extern const char *get_var_digital_date();
extern void set_var_digital_date(const char *value);
extern const char *get_var_digital_temperature();
extern void set_var_digital_temperature(const char *value);
extern const char *get_var_running_action();
extern void set_var_running_action(const char *value);
extern const char *get_var_running_action_time();
extern void set_var_running_action_time(const char *value);
extern const char *get_var_status_bar_text();
extern void set_var_status_bar_text(const char *value);
extern int32_t get_var_status_bar_value();
extern void set_var_status_bar_value(int32_t value);
extern const char *get_var_alarm_time();
extern void set_var_alarm_time(const char *value);
extern const char *get_var_alarm_reason();
extern void set_var_alarm_reason(const char *value);
extern int32_t get_var_alarm_selected_reason();
extern void set_var_alarm_selected_reason(int32_t value);
extern const char *get_var_timer_time();
extern void set_var_timer_time(const char *value);
extern int32_t get_var_timer_value();
extern void set_var_timer_value(int32_t value);
extern const char *get_var_stopwatch_time();
extern void set_var_stopwatch_time(const char *value);
extern bool get_var_stopwatch_hide_pause_btn();
extern void set_var_stopwatch_hide_pause_btn(bool value);
extern bool get_var_stopwatch_hide_start_btn();
extern void set_var_stopwatch_hide_start_btn(bool value);
extern const char *get_var_settings_title();
extern void set_var_settings_title(const char *value);
extern bool get_var_settings_hide_time();
extern void set_var_settings_hide_time(bool value);
extern bool get_var_settings_hide_music();
extern void set_var_settings_hide_music(bool value);
extern bool get_var_settings_hide_wi_fi();
extern void set_var_settings_hide_wi_fi(bool value);
extern bool get_var_settings_hide_other();
extern void set_var_settings_hide_other(bool value);
extern bool get_var_settings_hide_selection();
extern void set_var_settings_hide_selection(bool value);
extern bool get_var_settings_time_auto_set_checked();
extern void set_var_settings_time_auto_set_checked(bool value);
extern const char *get_var_settings_time_changed_time();
extern void set_var_settings_time_changed_time(const char *value);
extern int32_t get_var_settings_time_month_selected();
extern void set_var_settings_time_month_selected(int32_t value);
extern int32_t get_var_settings_time_day_selected();
extern void set_var_settings_time_day_selected(int32_t value);
extern int32_t get_var_settings_time_year_selected();
extern void set_var_settings_time_year_selected(int32_t value);
extern bool get_var_settings_music_alarm_over_aux_checked();
extern void set_var_settings_music_alarm_over_aux_checked(bool value);
extern int32_t get_var_settings_music_selected();
extern void set_var_settings_music_selected(int32_t value);
extern const char *get_var_settings_music_selection();
extern void set_var_settings_music_selection(const char *value);
extern int32_t get_var_settings_music_alarm_volume();
extern void set_var_settings_music_alarm_volume(int32_t value);
extern int32_t get_var_settings_music_auxin_volume();
extern void set_var_settings_music_auxin_volume(int32_t value);
extern int32_t get_var_alarm_selected_repeats();
extern void set_var_alarm_selected_repeats(int32_t value);
extern bool get_var_settings_wi_fi_hide_connect_to_wi_fi_popup();
extern void set_var_settings_wi_fi_hide_connect_to_wi_fi_popup(bool value);
extern const char *get_var_settings_wi_fi_popup_password();
extern void set_var_settings_wi_fi_popup_password(const char *value);
extern const char *get_var_settings_wi_fi_popup_ssid();
extern void set_var_settings_wi_fi_popup_ssid(const char *value);
extern const char *get_var_settings_wi_fi_connection_answer();
extern void set_var_settings_wi_fi_connection_answer(const char *value);
extern bool get_var_settings_wi_fi_hide_answer_popup();
extern void set_var_settings_wi_fi_hide_answer_popup(bool value);
extern bool get_var_settings_wi_fi_hide_answer_success();
extern void set_var_settings_wi_fi_hide_answer_success(bool value);
extern bool get_var_settings_wi_fi_hide_answer_failed();
extern void set_var_settings_wi_fi_hide_answer_failed(bool value);
extern bool get_var_settings_wi_fi_hide_answer_loading();
extern void set_var_settings_wi_fi_hide_answer_loading(bool value);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/