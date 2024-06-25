#include <eez/actions.h>
#include <eez/ui.h>
#include <eez/vars.h>
#include <lvgl.h>
#include <main.hpp>
#include <Arduino.h>

extern void action_screen_go_forward(lv_event_t * e) {
    loadScreen(getCurrentScreenId()+1);
}
extern void action_screen_go_backward(lv_event_t * e) {
    loadScreen(getCurrentScreenId()-1);
}

/*ALARM*/
extern void action_alarm_plus_long_pressed(lv_event_t * e) {

}
extern void action_alarm_plus_pressed(lv_event_t * e) {

}
extern void action_alarm_minus_long_pressed(lv_event_t * e) {

}
extern void action_alarm_minus_pressed(lv_event_t * e) {

}
extern void action_alarm_set_pressed(lv_event_t * e) {

}
extern void action_alarm_reset_pressed(lv_event_t * e) {

}

/*TIMER*/
extern void action_timer_set_pressed(lv_event_t * e) {

}
extern void action_timer_reset_pressed(lv_event_t * e) {

}
extern void action_stopwatch_start_pressed(lv_event_t * e) {

}
extern void action_stopwatch_reset_pressed(lv_event_t * e) {

}

/*SETTINGS*/
extern void action_settings_time_selected(lv_event_t * e) {

}
extern void action_settings_alarm_selected(lv_event_t * e) {

}
extern void action_settings_audio_selected(lv_event_t * e) {

}
extern void action_settings_wifi_selected(lv_event_t * e) {

}
extern void action_settings_other_selected(lv_event_t * e) {

}
extern void action_settings_other_calibrate_pressed(lv_event_t * e) {

}
extern void action_settings_other_reset_pressed(lv_event_t * e) {

}