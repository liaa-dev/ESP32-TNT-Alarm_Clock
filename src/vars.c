#include <eez/vars.h>

const char *var_digital_time = "14:09";
const char *var_digital_date = "Wednesday, May 12";
const char *var_digital_temperature = "30°C";
const char *var_running_action = "Action";
const char *var_running_action_time = "None";
const char *var_status_bar_text = "Nothing Playing";
int32_t var_status_bar_value = 0;
const char *var_alarm_time = "06:30";
const char *var_alarm_reason = "None";
int32_t var_alarm_selected_reason = 0;
int32_t var_alarm_selected_repeats = 0;
const char *var_timer_time = "00:00";
int32_t var_timer_value = 0;
const char *var_stopwatch_time = "";
bool var_stopwatch_hide_pause_btn = true;
bool var_stopwatch_hide_start_btn = false;
const char *var_settings_title = "Settings";
bool var_settings_hide_time = true;
bool var_settings_hide_wi_fi = true;
bool var_settings_hide_music = true;
bool var_settings_hide_other = true;
bool var_settings_hide_selection = false;
bool var_settings_time_auto_set_checked = true;
const char *var_settings_time_changed_time = "";
int32_t var_settings_time_month_selected = 0;
int32_t var_settings_time_day_selected = 0;
int32_t var_settings_time_year_selected = 0;
bool var_settings_music_alarm_over_aux_checked = true;
int32_t var_settings_music_selected = 0;
const char *var_settings_music_selection = "None\nBeep";
int32_t var_settings_music_alarm_volume = 50;
int32_t var_settings_music_auxin_volume = 50;

/* MAIN SCREEN*/

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

extern const char *get_var_running_action() {
    return var_running_action;
}
extern void set_var_running_action(const char *value) {
    var_running_action = value;
}
extern const char *get_var_running_action_time() {
    return var_running_action_time;
}
extern void set_var_running_action_time(const char *value) {
    var_running_action_time = value;
}

extern const char *get_var_status_bar_text() {
    return var_status_bar_text;
}

extern int32_t get_var_status_bar_value() {
    return var_status_bar_value;
}
extern void set_var_status_bar_value(int32_t value) {
    var_status_bar_value = value;
}

extern void set_var_status_bar_text(const char *value) {
    var_status_bar_text = value;
}

/* ALARM SCREEN*/

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
extern int32_t get_var_alarm_selected_repeats() {
    return var_alarm_selected_repeats;
}
extern void set_var_alarm_selected_repeats(int32_t value) {
    var_alarm_selected_repeats = value;
}

/* TIMER SCREEN */

extern const char *get_var_timer_time() {
    return var_timer_time;
}
extern void set_var_timer_time(const char *value) {
    var_timer_time = value;
}
extern int32_t get_var_timer_value() {
    return var_timer_value;
}
extern void set_var_timer_value(int32_t value) {
    var_timer_value = value;
}

/* STOPWATCH SCREEN */

extern void set_var_stopwatch_time(const char *value) {
    var_stopwatch_time = value;
}
extern const char *get_var_stopwatch_time() {
    return var_stopwatch_time;
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

/* SETTINGS SCREEN */

extern const char *get_var_settings_title() {
    return var_settings_title;
}
extern void set_var_settings_title(const char *value) {
    var_settings_title = value;
}
extern bool get_var_settings_hide_time() {
    return var_settings_hide_time;
}
extern void set_var_settings_hide_time(bool value) {
    var_settings_hide_time = value;
}
extern bool get_var_settings_hide_music() {
    return var_settings_hide_music;
}
extern void set_var_settings_hide_music(bool value) {
    var_settings_hide_music = value;
}
extern bool get_var_settings_hide_wi_fi() {
    return var_settings_hide_wi_fi;
}
extern void set_var_settings_hide_wi_fi(bool value) {
    var_settings_hide_wi_fi = value;
}
extern bool get_var_settings_hide_other() {
    return var_settings_hide_other;
}
extern void set_var_settings_hide_other(bool value) {
    var_settings_hide_other = value;
}
extern bool get_var_settings_hide_selection() {
    return var_settings_hide_selection;
}
extern void set_var_settings_hide_selection(bool value) {
    var_settings_hide_selection = value;
}
extern bool get_var_settings_time_auto_set_checked() {
    return var_settings_time_auto_set_checked;
}
extern void set_var_settings_time_auto_set_checked(bool value) {
    var_settings_time_auto_set_checked = value;
}
extern const char *get_var_settings_time_changed_time() {
    return var_settings_time_changed_time;
}
extern void set_var_settings_time_changed_time(const char *value) {
    var_settings_time_changed_time = value;
}
extern int32_t get_var_settings_time_month_selected() {
    return var_settings_time_month_selected;
}
extern void set_var_settings_time_month_selected(int32_t value) {
    var_settings_time_month_selected = value;
}
extern int32_t get_var_settings_time_day_selected() {
    return var_settings_time_day_selected;
}
extern void set_var_settings_time_day_selected(int32_t value) {
    var_settings_time_day_selected = value;
}
extern int32_t get_var_settings_time_year_selected() {
    return var_settings_time_year_selected;
}
extern void set_var_settings_time_year_selected(int32_t value) {
    var_settings_time_year_selected = value;
}

extern bool get_var_settings_music_alarm_over_aux_checked() {
    return var_settings_music_alarm_over_aux_checked;
}
extern void set_var_settings_music_alarm_over_aux_checked(bool value) {
    var_settings_music_alarm_over_aux_checked = value;
}
extern int32_t get_var_settings_music_selected() {
    return var_settings_music_selected;
}
extern void set_var_settings_music_selected(int32_t value) {
    var_settings_music_selected = value;
}
extern const char *get_var_settings_music_selection() {
    return var_settings_music_selection;
}
extern void set_var_settings_music_selection(const char *value) {
    var_settings_music_selection = value;
}
extern int32_t get_var_settings_music_alarm_volume() {
    return var_settings_music_alarm_volume;
}
extern void set_var_settings_music_alarm_volume(int32_t value) {
    var_settings_music_alarm_volume = value;
}
extern int32_t get_var_settings_music_auxin_volume() {
    return var_settings_music_auxin_volume;
}
extern void set_var_settings_music_auxin_volume(int32_t value) {
    var_settings_music_auxin_volume = value;
}