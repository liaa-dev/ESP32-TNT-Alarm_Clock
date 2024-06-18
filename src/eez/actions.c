#include "actions.h"
#include "ui.h"
#include <lvgl/lvgl.h>

extern void action_change_to_main_screen(lv_event_t * e) {
    loadScreen(SCREEN_ID_SET_ALARM);
}

extern void action_change_to_set_alarm_screen(lv_event_t * e) {
    loadScreen(SCREEN_ID_MAIN);
}