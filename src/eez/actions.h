#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void action_screen_go_forward(lv_event_t * e);
extern void action_screen_go_backward(lv_event_t * e);
extern void action_alarm_plus_long_pressed_repeat(lv_event_t * e);
extern void action_alarm_plus_pressed(lv_event_t * e);
extern void action_alarm_minus_long_pressed_repeat(lv_event_t * e);
extern void action_alarm_minus_pressed(lv_event_t * e);
extern void action_alarm_set_pressed(lv_event_t * e);
extern void action_alarm_reset_pressed(lv_event_t * e);
extern void action_timer_set_pressed(lv_event_t * e);
extern void action_timer_reset_pressed(lv_event_t * e);
extern void action_stopwatch_start_pressed(lv_event_t * e);
extern void action_stopwatch_reset_pressed(lv_event_t * e);
extern void action_settings_time_selected(lv_event_t * e);
extern void action_settings_alarm_selected(lv_event_t * e);
extern void action_settings_audio_selected(lv_event_t * e);
extern void action_settings_wifi_selected(lv_event_t * e);
extern void action_settings_other_selected(lv_event_t * e);
extern void action_settings_other_calibrate_pressed(lv_event_t * e);
extern void action_settings_other_reset_pressed(lv_event_t * e);

extern bool isTimerRunning();
extern bool isTimerPaused();

extern bool isStopwatchRunning();
extern bool isStopwatchPaused();

extern void action_tick();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/