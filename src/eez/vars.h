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
    FLOW_GLOBAL_VARIABLE_STATUS_BAR_TEXT = 3,
    FLOW_GLOBAL_VARIABLE_ALARM_TIME = 4,
    FLOW_GLOBAL_VARIABLE_ALARM_REASON = 5,
    FLOW_GLOBAL_VARIABLE_ALARM_SELECTED_REASON = 6,
    FLOW_GLOBAL_VARIABLE_TIMER_TIME = 7,
    FLOW_GLOBAL_VARIABLE_STOPWATCH_TIME = 8,
    FLOW_GLOBAL_VARIABLE_STOPWATCH_HIDE_PAUSE_BTN = 9,
    FLOW_GLOBAL_VARIABLE_STOPWATCH_HIDE_START_BTN = 10
};

// Native global variables

extern const char *get_var_digital_time();
extern void set_var_digital_time(const char *value);
extern const char *get_var_digital_date();
extern void set_var_digital_date(const char *value);
extern const char *get_var_digital_temperature();
extern void set_var_digital_temperature(const char *value);
extern const char *get_var_status_bar_text();
extern void set_var_status_bar_text(const char *value);
extern const char *get_var_alarm_time();
extern void set_var_alarm_time(const char *value);
extern const char *get_var_alarm_reason();
extern void set_var_alarm_reason(const char *value);
extern int32_t get_var_alarm_selected_reason();
extern void set_var_alarm_selected_reason(int32_t value);
extern const char *get_var_timer_time();
extern void set_var_timer_time(const char *value);
extern const char *get_var_stopwatch_time();
extern void set_var_stopwatch_time(const char *value);
extern bool get_var_stopwatch_hide_pause_btn();
extern void set_var_stopwatch_hide_pause_btn(bool value);
extern bool get_var_stopwatch_hide_start_btn();
extern void set_var_stopwatch_hide_start_btn(bool value);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/