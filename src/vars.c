#include <eez/vars.h>

const char *var_digital_time = "14:09";
const char *var_digital_date = "Wednesday, May 12";
const char *var_digital_temperature = "30°C";
const char *var_status_bar_text = "This is a placeholder!";
const char *var_alarm_time = "99:99";
const char *var_alarm_reason = "This is a placeholder!";
int32_t var_alarm_selected_reason = 0;
const char *var_timer_time = "00:00";
const char *var_stopwatch_time = "00:00:00:00";
bool var_stopwatch_hide_pause_btn = true;
bool var_stopwatch_hide_start_btn = false;

extern const char *get_var_digital_time() {
    return var_digital_time;
}
extern void set_var_digital_time(const char *value) {
    var_digital_time = value;
}
extern const char *get_var_digital_date() {
    return var_digital_date;
}
extern void set_var_digital_date(const char *value) {
    var_digital_date = value;
}
extern const char *get_var_digital_temperature() {
    return var_digital_temperature;
}
extern void set_var_digital_temperature(const char *value) {
    var_digital_temperature = value;
}
extern const char *get_var_status_bar_text() {
    return var_status_bar_text;
}
extern void set_var_status_bar_text(const char *value) {
    var_status_bar_text = value;
}
extern const char *get_var_alarm_time() {
    return var_alarm_time;
}
extern void set_var_alarm_time(const char *value) {
    var_alarm_time = value;
}
extern const char *get_var_alarm_reason() {
    return var_alarm_reason;
}
extern void set_var_alarm_reason(const char *value) {
    var_alarm_reason = value;
}
extern int32_t get_var_alarm_selected_reason() {
    return var_alarm_selected_reason;
}
extern void set_var_alarm_selected_reason(int32_t value) {
    var_alarm_selected_reason = value;
}
extern const char *get_var_timer_time() {
    return var_timer_time;
}
extern void set_var_timer_time(const char *value) {
    var_timer_time = value;
}
extern const char *get_var_stopwatch_time() {
    return var_stopwatch_time;
}
extern void set_var_stopwatch_time(const char *value) {
    var_stopwatch_time = value;
}
extern bool get_var_stopwatch_hide_pause_btn() {
    return var_stopwatch_hide_pause_btn;
}
extern void set_var_stopwatch_hide_pause_btn(bool value) {
    var_stopwatch_hide_pause_btn = value;
}
extern bool get_var_stopwatch_hide_start_btn() {
    return var_stopwatch_hide_start_btn;
}
extern void set_var_stopwatch_hide_start_btn(bool value) {
    var_stopwatch_hide_start_btn = value;
}