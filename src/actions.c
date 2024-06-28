#include <eez/actions.h>
#include <eez/ui.h>
#include <eez/vars.h>
#include <lvgl.h>
#include <main.hpp>
#include <stdio.h>
#include <Arduino.h>

void hideSettings();

void action_screen_go_forward(lv_event_t * e) {
    if(getCurrentScreenId() == SCREEN_ID_SET_SETTINGS) loadScreen(SCREEN_ID_MAIN);
    else loadScreen(getCurrentScreenId()+1);
}
void action_screen_go_backward(lv_event_t * e) {
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
void action_alarm_plus_long_pressed(lv_event_t * e) {

}
void action_alarm_plus_pressed(lv_event_t * e) {

}
void action_alarm_minus_long_pressed(lv_event_t * e) {

}
void action_alarm_minus_pressed(lv_event_t * e) {

}
void action_alarm_set_pressed(lv_event_t * e) {

}
void action_alarm_reset_pressed(lv_event_t * e) {

}

/*TIMER*/
unsigned long timer_start_time = 0;
unsigned long timer_pause_duration = 0;
unsigned long timer_total_duration = 0;
bool timer_running = false;
bool timer_paused = false;
void action_timer_set_pressed(lv_event_t * e) {
    if(get_var_timer_arc_value() <= 0) return;
    if(!timer_running && !timer_paused) {
        int hours = 0;
        int minutes = 0;

        // Get the hours and minutes from the time string
        sscanf(get_var_timer_time(), "%02d:%02d", &hours, &minutes);
        timer_start_time = (hours * 3600 + minutes * 60) * 1000;
        timer_total_duration = timer_start_time;
        timer_pause_duration = 0;

        timer_running = true;
        timer_paused = false;
    }else { // If the timer is running and the start button is pressed again, pause/resume the timer
        if(timer_paused) { // If the timer is already paused, dont reset the time, just resume
            timer_pause_duration = millis() - timer_pause_duration;
            timer_running = true;
            timer_paused = false;
        }else {
            timer_pause_duration = millis() - timer_pause_duration;
            timer_running = false;
            timer_paused = true;
        }
    }
}
void action_timer_reset_pressed(lv_event_t * e) {
    timer_running = false;
    timer_paused = false;
    timer_start_time = 0;
    timer_pause_duration = 0;
    timer_total_duration = 0;
    set_var_timer_time("00:00"); // No placeholder text for labels
    set_var_timer_arc_value(0);
}

char timer_buffer[7];
void update_timer() {
    if (timer_running) {
        print("Running!\n");
        unsigned long remaining_time = timer_start_time - (millis() - timer_pause_duration);
        print("Remaining time: "); printlong(remaining_time); print("\n");

        // TODO: Doesnt work correctly, with the arc value
        // Can only us it after directly starting because millis() is growing => Cant use 2 times

        if(remaining_time < 10) {
            print("The end!\n");
            action_timer_reset_pressed(NULL); // Reset the timer
            // TODO: Notify user that timer is done, sound or popup
            return;
        }
        
        unsigned long hours = remaining_time / 3600000;
        unsigned long minutes = (remaining_time % 3600000) / 60000;
        print("Hours:"); printlong(hours); print("\n");
        print("Minutes:"); printlong(minutes); print("\n");

        lv_snprintf(timer_buffer, sizeof(timer_buffer), "%02lu:%02lu", hours, minutes);
        set_var_timer_time((const char*)timer_buffer);
        unsigned long arc_value = lv_map(remaining_time, 0, timer_total_duration, 0, 100);
        set_var_timer_arc_value(arc_value);
    }
}

bool isTimerRunning() {
    return timer_running;
}

bool isTimerPaused() {
    return timer_paused;
}

unsigned long start_time = 0;
bool stopwatch_running = false;
bool stopwatch_paused = false;
void action_stopwatch_start_pressed(lv_event_t * e) {
    if (!stopwatch_running && !stopwatch_paused) {
        start_time = millis();
        stopwatch_running = true;
        stopwatch_paused = false;
    }else { // If the stopwatch is running and the start button is pressed again, pause/resume the stopwatch
        if(stopwatch_paused) { // If the stopwatch is already paused, dont reset the time, just resume
            stopwatch_running = true;
            stopwatch_paused = false;
        }else {
            stopwatch_running = false;
            stopwatch_paused = true;
        }
    }
}
void action_stopwatch_reset_pressed(lv_event_t * e) {
    stopwatch_running = false;
    stopwatch_paused = false;
    set_var_stopwatch_time("");
}

const char *elapsed;
char stopwatch_buffer[13]; // You have to define the buffer here, because if you try to define it in the function, it will be destroyed after the function ends therefore the value of the buffer will be destroyed
                 // So the const char* elapsed would point to a memory location that is not valid anymore
void update_stopwatch() {
    if (stopwatch_running) {
        unsigned long elapsed_time = millis() - start_time;
        
        unsigned long hours = elapsed_time / 3600000;
        unsigned long minutes = (elapsed_time % 3600000) / 60000;
        unsigned long seconds = (elapsed_time % 60000) / 1000;
        unsigned long milliseconds = elapsed_time % 1000;

        print("Hours: "); printlong(hours);
        print("Minutes: "); printlong(minutes);
        print("Seconds: "); printlong(seconds);
        print("Milliseconds: "); printlong(milliseconds);
        
        lv_snprintf(stopwatch_buffer, sizeof(stopwatch_buffer), "%02lu:%02lu:%02lu.%03lu", hours, minutes, seconds, milliseconds);
        //elapsed = stopwatch_buffer; // Elapsed gets initialized with the buffer
        
        set_var_stopwatch_time((const char*)stopwatch_buffer);
    }
}

bool isStopwatchRunning() {
    return stopwatch_running;
}

bool isStopwatchPaused() {
    return stopwatch_paused;
}

/*SETTINGS*/
void action_settings_time_selected(lv_event_t * e) {
    hideSettings();
    set_var_settings_hide_setting_time(false);
}
void action_settings_alarm_selected(lv_event_t * e) {
    hideSettings();
    set_var_settings_hide_setting_alarm(false);
}
void action_settings_audio_selected(lv_event_t * e) {
    hideSettings();
    set_var_settings_hide_setting_audio(false);
}
void action_settings_wifi_selected(lv_event_t * e) {
    hideSettings();
    set_var_settings_hide_setting_wifi(false);
}
void action_settings_other_selected(lv_event_t * e) {
    hideSettings();
    set_var_settings_hide_setting_other(false);
}
void action_settings_other_calibrate_pressed(lv_event_t * e) {

}
void action_settings_other_reset_pressed(lv_event_t * e) {

}

void action_tick() {
    update_stopwatch();
    update_timer();
}

void hideSettings() {
    set_var_settings_hide_selection(true);
    set_var_settings_hide_setting_time(true);
    set_var_settings_hide_setting_alarm(true);
    set_var_settings_hide_setting_audio(true);
    set_var_settings_hide_setting_wifi(true);
    set_var_settings_hide_setting_other(true);
}