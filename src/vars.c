#include <eez/vars.h>

/*Warning: If the variables aren't initialized,
           the program will run in a bootloop without showing any errors!*/

static const char *var_main_clock_time = "23:16";
static const char *var_main_clock_seconds = "29";
static const char *var_main_date = "Thursday, Sept 3";
static const char *var_main_day_today = "Mon";
static const char *var_main_day_tomorrow = "Tue";
static const char *var_main_day_scndnextday = "Wed";
static const char *var_main_day_thrdnextday = "Thu";
static const char *var_main_temp_today = "25°C";
static const char *var_main_temp_tomorrow = "26°C";
static const char *var_main_temp_scndnextday = "27°C";
static const char *var_main_temp_thrdnextday = "28°C";
static bool var_main_is_wifi_connected = false;
static const char *var_main_alarm_time = "04:04";
static const char *var_main_alarm_reason = "Wake up";
static const char *var_alarm_time = "00:00";
static const char *var_alarm_reasons = "Wake up\nAppointment\nOther (via wifi)";
static int32_t var_alarm_selected_reason = 0;
static const char *var_timer_time = "00:00";
static int32_t var_timer_arc_value = 0;
static const char *var_stopwatch_time = "";
static const char *var_settings_title = "Settings";
static bool var_settings_hide_selection = false;
static bool var_settings_hide_setting_time = true;
static bool var_settings_hide_setting_alarm = true;
static bool var_settings_hide_setting_audio = true;
static bool var_settings_hide_setting_wifi = true;
static bool var_settings_hide_setting_other = true;
static bool var_settings_setting_time_checked_autoset = true;
static const char *var_settings_setting_time_new_time = "";
static int32_t var_settings_setting_time_selected_month = 0;
static int32_t var_settings_setting_time_selected_day = 0;
static int32_t var_settings_setting_time_selected_year = 0;
static int32_t var_settings_setting_alarm_selected_repeats = 0;
static int32_t var_settings_setting_alarm_selected_repeat_after = 0;
static bool var_settings_setting_audio_checked_alarm_over_aux = true;
static const char *var_settings_setting_audio_selected_music = "";
static int32_t var_settings_setting_audio_alarm_volume_value = 50;
static int32_t var_settings_setting_audio_auxin_volume_value = 50;

const char *get_var_main_clock_time() {
    return var_main_clock_time;
}

void set_var_main_clock_time(const char *value) {
        var_main_clock_time = value;
}

const char *get_var_main_clock_seconds() {
    return var_main_clock_seconds;
}

void set_var_main_clock_seconds(const char *value) {
    var_main_clock_seconds = value;
}

const char *get_var_main_date() {
    return var_main_date;
}

void set_var_main_date(const char *value) {
    var_main_date = value;
}

bool get_var_main_is_wifi_connected() {
    return var_main_is_wifi_connected;
}

void set_var_main_is_wifi_connected(bool value) {
    var_main_is_wifi_connected = !value; // Negate to hide/show the label
                                         // (hide = true, show = false)
}

const char *get_var_main_alarm_time() {
    return var_main_alarm_time;
}

void set_var_main_alarm_time(const char *value) {
    var_main_alarm_time = value;
}

const char *get_var_main_alarm_reason() {
    return var_main_alarm_reason;
}

void set_var_main_alarm_reason(const char *value) {
    var_main_alarm_reason = value;
}

const char *get_var_alarm_time() {
    return var_alarm_time;
}

void set_var_alarm_time(const char *value) {
    var_alarm_time = value;
}

const char *get_var_alarm_reasons() {
    return var_alarm_reasons;
}

void set_var_alarm_reasons(const char *value) {
    var_alarm_reasons = value;
}

const char *get_var_main_day_today() {
    return var_main_day_today;
}

void set_var_main_day_today(const char *value) {
    var_main_day_today = value;
}

const char *get_var_main_day_tomorrow() {
    return var_main_day_tomorrow;
}
void set_var_main_day_tomorrow(const char *value) {
    var_main_day_tomorrow = value;
}

const char *get_var_main_day_scndnextday() {
    return var_main_day_scndnextday;
}

void set_var_main_day_scndnextday(const char *value) {
    var_main_day_scndnextday = value;
}

const char *get_var_main_day_thrdnextday() {
    return var_main_day_thrdnextday;
}

void set_var_main_day_thrdnextday(const char *value) {
    var_main_day_thrdnextday = value;
}

const char *get_var_main_temp_today() {
    return var_main_temp_today;
}

void set_var_main_temp_today(const char *value) {
    var_main_temp_today = value;
}

const char *get_var_main_temp_tomorrow() {
    return var_main_temp_tomorrow;
}

void set_var_main_temp_tomorrow(const char *value) {
    var_main_temp_tomorrow = value;
}

const char *get_var_main_temp_scndnextday() {
    return var_main_temp_scndnextday;
}

void set_var_main_temp_scndnextday(const char *value) {
    var_main_temp_scndnextday = value;
}

const char *get_var_main_temp_thrdnextday() {
    return var_main_temp_thrdnextday;
}

void set_var_main_temp_thrdnextday(const char *value) {
    var_main_temp_thrdnextday = value;
}

int32_t get_var_alarm_selected_reason() {
    return var_alarm_selected_reason;
}

void set_var_alarm_selected_reason(int32_t value) {
    var_alarm_selected_reason = value;
}

const char *get_var_timer_time() {
    return var_timer_time;
}

void set_var_timer_time(const char *value) {
    var_timer_time = value;
}

int32_t get_var_timer_arc_value() {
    return var_timer_arc_value;
}

void set_var_timer_arc_value(int32_t value) {
    var_timer_arc_value = value;
}

const char *get_var_stopwatch_time() {
    return var_stopwatch_time;
}

void set_var_stopwatch_time(const char *value) {
    var_stopwatch_time = value;
}

const char *get_var_settings_title() {
    return var_settings_title;
}

void set_var_settings_title(const char *value) {
    var_settings_title = value;
}

bool get_var_settings_hide_selection() {
    return var_settings_hide_selection;
}

void set_var_settings_hide_selection(bool value) {
    var_settings_hide_selection = value;
}

bool get_var_settings_hide_setting_time() {
    return var_settings_hide_setting_time;
}

void set_var_settings_hide_setting_time(bool value) {
    var_settings_hide_setting_time = value;
}

bool get_var_settings_hide_setting_alarm() {
    return var_settings_hide_setting_alarm;
}

void set_var_settings_hide_setting_alarm(bool value) {
    var_settings_hide_setting_alarm = value;
}

bool get_var_settings_hide_setting_audio() {
    return var_settings_hide_setting_audio;
}

void set_var_settings_hide_setting_audio(bool value) {
    var_settings_hide_setting_audio = value;
}

bool get_var_settings_hide_setting_wifi() {
    return var_settings_hide_setting_wifi;
}

void set_var_settings_hide_setting_wifi(bool value) {
    var_settings_hide_setting_wifi = value;
}

bool get_var_settings_hide_setting_other() {
    return var_settings_hide_setting_other;
}

void set_var_settings_hide_setting_other(bool value) {
    var_settings_hide_setting_other = value;
}

bool get_var_settings_setting_time_checked_autoset() {
    return var_settings_setting_time_checked_autoset;
}

void set_var_settings_setting_time_checked_autoset(bool value) {
    var_settings_setting_time_checked_autoset = value;
}

const char *get_var_settings_setting_time_new_time() {
    return var_settings_setting_time_new_time;
}

void set_var_settings_setting_time_new_time(const char *value) {
    var_settings_setting_time_new_time = value;
}

int32_t get_var_settings_setting_time_selected_month() {
    return var_settings_setting_time_selected_month;
}

void set_var_settings_setting_time_selected_month(int32_t value) {
    var_settings_setting_time_selected_month = value;
}

int32_t get_var_settings_setting_time_selected_day() {
    return var_settings_setting_time_selected_day;
}

void set_var_settings_setting_time_selected_day(int32_t value) {
    var_settings_setting_time_selected_day = value;
}

int32_t get_var_settings_setting_time_selected_year() {
    return var_settings_setting_time_selected_year;
}

void set_var_settings_setting_time_selected_year(int32_t value) {
    var_settings_setting_time_selected_year = value;
}

int32_t get_var_settings_setting_alarm_selected_repeats() {
    return var_settings_setting_alarm_selected_repeats;
}

void set_var_settings_setting_alarm_selected_repeats(int32_t value) {
    var_settings_setting_alarm_selected_repeats = value;
}

int32_t get_var_settings_setting_alarm_selected_repeat_after() {
    return var_settings_setting_alarm_selected_repeat_after;
}

void set_var_settings_setting_alarm_selected_repeat_after(int32_t value) {
    var_settings_setting_alarm_selected_repeat_after = value;
}

bool get_var_settings_setting_audio_checked_alarm_over_aux() {
    return var_settings_setting_audio_checked_alarm_over_aux;
}

void set_var_settings_setting_audio_checked_alarm_over_aux(bool value) {
    var_settings_setting_audio_checked_alarm_over_aux = value;
}

const char *get_var_settings_setting_audio_selected_music() {
    return var_settings_setting_audio_selected_music;
}

void set_var_settings_setting_audio_selected_music(const char *value) {
    var_settings_setting_audio_selected_music = value;
}

int32_t get_var_settings_setting_audio_alarm_volume_value() {
    return var_settings_setting_audio_alarm_volume_value;
}

void set_var_settings_setting_audio_alarm_volume_value(int32_t value) {
    var_settings_setting_audio_alarm_volume_value = value;
}

int32_t get_var_settings_setting_audio_auxin_volume_value() {
    return var_settings_setting_audio_auxin_volume_value;
}

void set_var_settings_setting_audio_auxin_volume_value(int32_t value) {
    var_settings_setting_audio_auxin_volume_value = value;
}