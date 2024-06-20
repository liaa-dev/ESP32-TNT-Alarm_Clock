#include <eez/actions.h>
#include <eez/ui.h>
#include <eez/vars.h>
#include <lvgl/lvgl.h>

void hideAllSelectableSettings();

extern void action_go_to_main_screen(lv_event_t * e) {
    loadScreen(SCREEN_ID_MAIN);
}

extern void action_go_to_set_alarm_screen(lv_event_t * e) {
    loadScreen(SCREEN_ID_SET_ALARM);
}

extern void action_go_to_timer_screen(lv_event_t * e) {
    loadScreen(SCREEN_ID_SET_TIMER);
}
extern void action_go_to_stopwatch_screen(lv_event_t * e) {
    loadScreen(SCREEN_ID_SET_STOPWATCH);
}

extern void action_go_to_settings_screen(lv_event_t * e) {
    loadScreen(SCREEN_ID_SET_SETTINGS);

}

extern void action_go_back(lv_event_t * e) {
    loadScreen(get_current_screen() - 1);
}

extern void action_alarm_plus_long_pressed(lv_event_t * e) {

}
extern void action_alarm_plus_pressed(lv_event_t * e) {

}
extern void action_alarm_minus_long_pressed(lv_event_t * e) {

}
extern void action_alarm_minus_pressed(lv_event_t * e) {

}

extern void action_alarm_set_pressed(lv_event_t * e) {
    set_var_alarm_time("12:00");
}
extern void action_alarm_reset_pressed(lv_event_t * e) {

}
extern void action_timer_set_pressed(lv_event_t * e) {

}
extern void action_timer_reset_pressed(lv_event_t * e) {

}
extern void action_stopwatch_start_pressed(lv_event_t * e) {

}
extern void action_stopwatch_reset_pressed(lv_event_t * e) {

}

extern void action_settings_time_selected(lv_event_t * e) {
    hideAllSelectableSettings();
    set_var_settings_hide_time(false);
}
extern void action_settings_wi_fi_selected(lv_event_t * e) {
    hideAllSelectableSettings();
    set_var_settings_hide_wi_fi(false);
}
extern void action_settings_bluetooth_selected(lv_event_t * e) {
    hideAllSelectableSettings();
    set_var_settings_hide_bluetooth(false);
}
extern void action_settings_other_selected(lv_event_t * e) {
    hideAllSelectableSettings();
    set_var_settings_hide_other(false);
}

void hideAllSelectableSettings() {
    set_var_settings_hide_time(true);
    set_var_settings_hide_wi_fi(true);
    set_var_settings_hide_bluetooth(true);
    set_var_settings_hide_other(true);
}