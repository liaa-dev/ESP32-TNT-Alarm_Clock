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
    FLOW_GLOBAL_VARIABLE_SETTINGS_HIDE_WI_FI = 17,
    FLOW_GLOBAL_VARIABLE_SETTINGS_HIDE_BLUETOOTH = 18,
    FLOW_GLOBAL_VARIABLE_SETTINGS_HIDE_OTHER = 19,
    FLOW_GLOBAL_VARIABLE_SETTINGS_HIDE_SELECTION = 20,
    FLOW_GLOBAL_VARIABLE_SETTINGS_BT_HIDE_DISCONNECT_BTN = 21,
    FLOW_GLOBAL_VARIABLE_SETTINGS_BT_HIDE_CONNECT_BTN = 22,
    FLOW_GLOBAL_VARIABLE_SETTINGS_BT_CONNECTED_DEVICE_NAME = 23,
    FLOW_GLOBAL_VARIABLE_SETTINGS_TIME_AUTO_SET_CHECKED = 24,
    FLOW_GLOBAL_VARIABLE_SETTINGS_TIME_CHANGED_TIME = 25,
    FLOW_GLOBAL_VARIABLE_SETTINGS_TIME_MONTH_SELECTED = 26,
    FLOW_GLOBAL_VARIABLE_SETTINGS_TIME_DAY_SELECTED = 27,
    FLOW_GLOBAL_VARIABLE_SETTINGS_TIME_YEAR_SELECTED = 28
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
extern bool get_var_settings_hide_wi_fi();
extern void set_var_settings_hide_wi_fi(bool value);
extern bool get_var_settings_hide_bluetooth();
extern void set_var_settings_hide_bluetooth(bool value);
extern bool get_var_settings_hide_other();
extern void set_var_settings_hide_other(bool value);
extern bool get_var_settings_hide_selection();
extern void set_var_settings_hide_selection(bool value);
extern bool get_var_settings_bt_hide_disconnect_btn();
extern void set_var_settings_bt_hide_disconnect_btn(bool value);
extern bool get_var_settings_bt_hide_connect_btn();
extern void set_var_settings_bt_hide_connect_btn(bool value);
extern const char *get_var_settings_bt_connected_device_name();
extern void set_var_settings_bt_connected_device_name(const char *value);
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


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/