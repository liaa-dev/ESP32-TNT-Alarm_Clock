#include <eez/actions.h>
#include <eez/ui.h>
#include <eez/vars.h>
#include <lvgl.h>
#include <main.hpp>
#include <stdio.h>
#include <Arduino.h>

void hideSettings();

extern void action_screen_go_forward(lv_event_t * e) {
    if(getCurrentScreenId() == SCREEN_ID_SET_SETTINGS) loadScreen(SCREEN_ID_MAIN);
    else loadScreen(getCurrentScreenId()+1);
}
extern void action_screen_go_backward(lv_event_t * e) {
    if(getCurrentScreenId() == SCREEN_ID_SET_SETTINGS
    && get_var_settings_hide_selection()
    && (get_var_settings_hide_setting_time()
    || get_var_settings_hide_setting_alarm()
    || get_var_settings_hide_setting_audio()
    || get_var_settings_hide_setting_wifi()
    || get_var_settings_hide_setting_other())) {
        hideSettings();
        set_var_settings_hide_selection(false);
        loadScreen(SCREEN_ID_SET_SETTINGS);
    }
    else loadScreen(getCurrentScreenId()-1);
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

unsigned long start_time = 0;
bool stopwatch_running = false;
bool stopwatch_paused = false;
extern void action_stopwatch_run_pressed(lv_event_t * e) {
    if (!stopwatch_running) {
        start_time = millis();
        stopwatch_running = true;
        stopwatch_paused = false;
        set_var_stopwatch_time("222");
    }else {
        stopwatch_running = false;
        stopwatch_paused = true;
        set_var_stopwatch_time("333");
    }
}
extern void action_stopwatch_reset_pressed(lv_event_t * e) {
    stopwatch_running = false;
    set_var_stopwatch_time("00:00:00.000");
}

void update_stopwatch() {
    if (stopwatch_running) {
        set_var_stopwatch_time("111");
        unsigned long current_time = millis();
        unsigned long elapsed_time = current_time - start_time;

        char buffer[20];
        sprintf(buffer, "%02d:%02d:%02d.%03d", elapsed_time / 3600000, (elapsed_time % 3600000) / 60000,
                                               (elapsed_time % 60000) / 1000, elapsed_time % 1000);
        const char* elapsed = buffer;
        set_var_stopwatch_time(elapsed);
    }
}

extern bool isStopwatchRunning() {
    return stopwatch_running;
}

extern bool isStopwatchPaused() {
    return stopwatch_paused;
}

/*SETTINGS*/
extern void action_settings_time_selected(lv_event_t * e) {
    hideSettings();
    set_var_settings_hide_setting_time(false);
}
extern void action_settings_alarm_selected(lv_event_t * e) {
    hideSettings();
    set_var_settings_hide_setting_alarm(false);
}
extern void action_settings_audio_selected(lv_event_t * e) {
    hideSettings();
    set_var_settings_hide_setting_audio(false);
}
extern void action_settings_wifi_selected(lv_event_t * e) {
    hideSettings();
    set_var_settings_hide_setting_wifi(false);
}
extern void action_settings_other_selected(lv_event_t * e) {
    hideSettings();
    set_var_settings_hide_setting_other(false);
}
extern void action_settings_other_calibrate_pressed(lv_event_t * e) {

}
extern void action_settings_other_reset_pressed(lv_event_t * e) {

}

extern void action_tick() {
    update_stopwatch();
}

void hideSettings() {
    set_var_settings_hide_selection(true);
    set_var_settings_hide_setting_time(true);
    set_var_settings_hide_setting_alarm(true);
    set_var_settings_hide_setting_audio(true);
    set_var_settings_hide_setting_wifi(true);
    set_var_settings_hide_setting_other(true);
}