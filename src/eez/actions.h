#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void action_go_to_main_screen(lv_event_t * e);
extern void action_go_to_set_alarm_screen(lv_event_t * e);
extern void action_go_to_timer_screen(lv_event_t * e);
extern void action_go_to_stopwatch_screen(lv_event_t * e);
extern void action_go_to_settings_screen(lv_event_t * e);
extern void action_go_back(lv_event_t * e);
extern void action_alarm_plus_long_pressed(lv_event_t * e);
extern void action_alarm_plus_pressed(lv_event_t * e);
extern void action_alarm_minus_long_pressed(lv_event_t * e);
extern void action_alarm_minus_pressed(lv_event_t * e);
extern void action_alarm_set_pressed(lv_event_t * e);
extern void action_alarm_reset_pressed(lv_event_t * e);
extern void action_timer_set_pressed(lv_event_t * e);
extern void action_timer_reset_pressed(lv_event_t * e);
extern void action_stopwatch_start_pressed(lv_event_t * e);
extern void action_stopwatch_reset_pressed(lv_event_t * e);
extern void action_settings_time_selected(lv_event_t * e);
extern void action_settings_music_selected(lv_event_t * e);
extern void action_settings_wi_fi_selected(lv_event_t * e);
extern void action_settings_other_selected(lv_event_t * e);
extern void action_settings_other_recalibrate_pressed(lv_event_t * e);
extern void action_settings_other_reset_pressed(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/