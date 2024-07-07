#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"
#include <main.hpp>
#include "actions.h"
#include <Arduino.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

static void event_handler_cb_main_main_forward(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_screen_go_forward(e);
    }
}

static void event_handler_cb_set_alarm_alarm_time_input(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            set_var_alarm_time(value);
        }
    }
}

static void event_handler_cb_set_alarm_alarm_forward(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_screen_go_forward(e);
    }
}

static void event_handler_cb_set_alarm_alarm_backward(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_screen_go_backward(e);
    }
}

static void event_handler_cb_set_alarm_alarm_plus_time(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_alarm_plus_pressed(e);
    }
    if (event == LV_EVENT_LONG_PRESSED_REPEAT) {
        action_alarm_plus_long_pressed_repeat(e);
    }
}

static void event_handler_cb_set_alarm_alarm_minus_time(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_alarm_minus_pressed(e);
    }
    if (event == LV_EVENT_LONG_PRESSED_REPEAT) {
        action_alarm_minus_long_pressed_repeat(e);
    }
}

static void event_handler_cb_set_alarm_alarm_set_button(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_alarm_set_pressed(e);
    }
}

static void event_handler_cb_set_alarm_alarm_reset_button(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_alarm_reset_pressed(e);
    }
}

static void event_handler_cb_set_timer_timer_forward(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_screen_go_forward(e);
    }
}

static void event_handler_cb_set_timer_timer_backward(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_screen_go_backward(e);
    }
}

static void event_handler_cb_set_timer_timer_set_button(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_timer_set_pressed(e);
    }
}

static void event_handler_cb_set_timer_timer_reset_button(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_timer_reset_pressed(e);
    }
}

char buffer[6];
static void event_handler_cb_set_timer_timer_arc(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_arc_get_value(ta);
            set_var_timer_arc_value(value);
            // Map the value of timer_arc to the range of 0 to 180min (0 to 3 hours)
            int32_t value_mapped = lv_map(value, 0, 100, 0, 180);

            // Calculate the hours and minutes from the mapped value
            int hours = value_mapped / 60;
            int minutes = value_mapped % 60;

            lv_snprintf(buffer, sizeof(buffer), "%02d:%02d", hours, minutes);
            set_var_timer_time((const char*)buffer);
        }
    }
}

static void event_handler_cb_set_stopwatch_stopwatch_time_count(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            set_var_stopwatch_time(value);
        }
    }
}

static void event_handler_cb_set_stopwatch_stopwatch_forward(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_screen_go_forward(e);
    }
}

static void event_handler_cb_set_stopwatch_stopwatch_backward(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_screen_go_backward(e);
    }
}

static void event_handler_cb_set_stopwatch_stopwatch_start_button(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_stopwatch_start_pressed(e);
    }
}

static void event_handler_cb_set_stopwatch_stopwatch_reset_button(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_stopwatch_reset_pressed(e);
    }
}

static void event_handler_cb_set_settings_settings_forward(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_screen_go_forward(e);
    }
}

static void event_handler_cb_set_settings_settings_backward(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_screen_go_backward(e);
    }
}

static void event_handler_cb_set_settings_setting__time(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_settings_time_selected(e);
    }
}

static void event_handler_cb_set_settings_setting__alarm(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_settings_alarm_selected(e);
    }
}

static void event_handler_cb_set_settings_setting__audio(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_settings_audio_selected(e);
    }
}

static void event_handler_cb_set_settings_setting__wi_fi(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_settings_wifi_selected(e);
    }
}

static void event_handler_cb_set_settings_setting__other(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_settings_other_selected(e);
    }
}

static void event_handler_cb_set_settings_time_auto_set_checkbox(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            set_var_settings_setting_time_checked_autoset(value);
        }
    }
}

static void event_handler_cb_set_settings_setting_time_input(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            set_var_settings_setting_time_new_time(value);
        }
    }
}

static void event_handler_cb_set_settings_plus_time_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        //action_alarm_plus_pressed(e); FIX!!! ADD ACTION
    }
    if (event == LV_EVENT_LONG_PRESSED_REPEAT) {
        //action_alarm_plus_long_pressed_repeat(e);
    }
}

static void event_handler_cb_set_settings_minus_time_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        //action_alarm_minus_pressed(e);
    }
    if (event == LV_EVENT_LONG_PRESSED_REPEAT) {
        //action_alarm_minus_long_pressed_repeat(e);
    }
}

static void event_handler_cb_set_settings_date_input__month(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_dropdown_get_selected(ta);
            set_var_settings_setting_time_selected_month(value);
        }
    }
}

static void event_handler_cb_set_settings_date_input__day(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_dropdown_get_selected(ta);
            set_var_settings_setting_time_selected_day(value);
        }
    }
}

static void event_handler_cb_set_settings_date_input__year(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_dropdown_get_selected(ta);
            set_var_settings_setting_time_selected_year(value);
        }
    }
}

static void event_handler_cb_set_settings_obj12(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_dropdown_get_selected(ta);
            set_var_settings_setting_alarm_selected_repeats(value);
        }
    }
}

static void event_handler_cb_set_settings_alarm_select_repeats_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_dropdown_get_selected(ta);
            set_var_settings_setting_alarm_selected_repeat_after(value);
        }
    }
}

static void event_handler_cb_set_settings_audio_play_alarm_over_aux(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            set_var_settings_setting_audio_checked_alarm_over_aux(value);
        }
    }
}

static void event_handler_cb_set_settings_audio_select_music(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_dropdown_get_selected(ta);
            set_var_settings_setting_audio_selected_music(value);
        }
    }
    if(event == LV_EVENT_CLICKED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            action_settings_audio_music_selection_pressed(e);
        }
    
    }
}

static void event_handler_cb_set_settings_audio_alarm_volume_slider(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_value(ta);
            set_var_settings_setting_audio_alarm_volume_value(value);
        }
    }
}

static void event_handler_cb_set_settings_audio_aux_in_volume_slider(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_value(ta);
            set_var_settings_setting_audio_auxin_volume_value(value);
        }
    }
}

static void event_handler_cb_set_settings_other_calibrate_touch(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_settings_other_calibrate_pressed(e);
    }
}

static void event_handler_cb_set_settings_other_reset(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_settings_other_reset_pressed(e);
    }
}

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff171717), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Main Clock
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.main_clock = obj;
            lv_obj_set_pos(obj, 74, 40);
            lv_obj_set_size(obj, 332, 89);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_y(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_ofs_x(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff212121), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff404040), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj0 = obj;
                    lv_obj_set_pos(obj, -10, -8);
                    lv_obj_set_size(obj, 290, 74);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_font(obj, &ui_font_smallpixel7_num_148, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj1 = obj;
                    lv_obj_set_pos(obj, 275, 46);
                    lv_obj_set_size(obj, 28, 20);
                    lv_label_set_text(obj, "");
                    apply_style_smallpixel7_32(obj);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffb2b2b2), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Main Date
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.main_date = obj;
            lv_obj_set_pos(obj, 40, 146);
            lv_obj_set_size(obj, 400, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
            lv_obj_set_style_text_font(obj, &ui_font_bmarmy_32, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff171717), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Main Forward
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.main_forward = obj;
            lv_obj_set_pos(obj, 425, 112);
            lv_obj_set_size(obj, 55, 96);
            lv_obj_add_event_cb(obj, event_handler_cb_main_main_forward, LV_EVENT_ALL, 0);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN);
            lv_obj_set_style_bg_img_src(obj, &img_arrow_right_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Main Info
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.main_info = obj;
            lv_obj_set_pos(obj, 80, 190);
            lv_obj_set_size(obj, 328, 51);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            apply_style_container(obj);
            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Alarm
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.alarm = obj;
                    lv_obj_set_pos(obj, 0, -197);
                    lv_obj_set_size(obj, 152, 49);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    apply_style_container(obj);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_img_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_img_set_src(obj, &img_alarm_32);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff171717), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 14, 0);
                            lv_obj_set_size(obj, 120, 50);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            apply_style_container(obj);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 26, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj2 = obj;
                                    lv_obj_set_pos(obj, 42, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "");
                                    apply_style_smallpixel7_32(obj);
                                    lv_obj_set_style_text_font(obj, &ui_font_bmarmy_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj3 = obj;
                                    lv_obj_set_pos(obj, 42, 0);
                                    lv_obj_set_size(obj, 114, LV_SIZE_CONTENT);
                                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                                    lv_label_set_text(obj, "");
                                    apply_style_smallpixel7_32(obj);
                                    lv_obj_set_style_text_font(obj, &ui_font_bmarmy_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                    }
                }
            }
        }
        {
            // Main Weather Info
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.main_weather_info = obj;
            lv_obj_set_pos(obj, 115, 248);
            lv_obj_set_size(obj, 250, 72);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            apply_style_container(obj);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Main Weather Today
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.main_weather_today = obj;
                    lv_obj_set_pos(obj, 13, -252);
                    lv_obj_set_size(obj, 50, 72);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    apply_style_container(obj);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj4 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "");
                            apply_style_smallpixel7_32(obj);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_img_create(parent_obj);
                            lv_obj_set_pos(obj, 47, 4);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_img_set_src(obj, &img_partly_cloudy_day);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj5 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "");
                            apply_style_smallpixel7_32(obj);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // Main Weather Next Day
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.main_weather_next_day = obj;
                    lv_obj_set_pos(obj, 0, -256);
                    lv_obj_set_size(obj, 50, 72);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    apply_style_container(obj);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj6 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "");
                            apply_style_smallpixel7_32(obj);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_img_create(parent_obj);
                            lv_obj_set_pos(obj, 47, 4);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_img_set_src(obj, &img_partly_cloudy_day);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj7 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "");
                            apply_style_smallpixel7_32(obj);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // Main Weather Day After Next Day
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.main_weather_day_after_next_day = obj;
                    lv_obj_set_pos(obj, 0, -256);
                    lv_obj_set_size(obj, 50, 72);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    apply_style_container(obj);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj8 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "");
                            apply_style_smallpixel7_32(obj);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_img_create(parent_obj);
                            lv_obj_set_pos(obj, 47, 4);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_img_set_src(obj, &img_partly_cloudy_day);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj9 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "");
                            apply_style_smallpixel7_32(obj);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // Main Weather Day After Next Next Day
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.main_weather_day_after_next_next_day = obj;
                    lv_obj_set_pos(obj, 0, -256);
                    lv_obj_set_size(obj, 50, 72);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    apply_style_container(obj);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj10 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "");
                            apply_style_smallpixel7_32(obj);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_img_create(parent_obj);
                            lv_obj_set_pos(obj, 47, 4);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_img_set_src(obj, &img_partly_cloudy_day);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj11 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "");
                            apply_style_smallpixel7_32(obj);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 5);
            lv_obj_set_size(obj, 480, 20);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            apply_style_container(obj);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Main Icon Wifi Connected
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.main_icon_wifi_connected = obj;
                    lv_obj_set_pos(obj, 167, 12);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_wifi_16);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 184, 12);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "WiFi connected");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Main Creeper Image
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.main_creeper_image = obj;
            lv_obj_set_pos(obj, 416, 227);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_crepper_64x95);
            lv_img_set_angle(obj, 20);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
    }
}

void tick_screen_main() {
    {
        const char *new_val = get_var_main_clock_time();
        const char *cur_val = lv_label_get_text(objects.obj0);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj0;
            lv_label_set_text(objects.obj0, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_main_clock_seconds();
        const char *cur_val = lv_label_get_text(objects.obj1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj1;
            lv_label_set_text(objects.obj1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_main_date();
        const char *cur_val = lv_label_get_text(objects.main_date);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.main_date;
            lv_label_set_text(objects.main_date, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_main_alarm_time();
        const char *cur_val = lv_label_get_text(objects.obj2);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj2;
            lv_label_set_text(objects.obj2, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_main_alarm_reason();
        const char *cur_val = lv_label_get_text(objects.obj3);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj3;
            lv_label_set_text(objects.obj3, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_main_day_today();
        const char *cur_val = lv_label_get_text(objects.obj4);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj4;
            lv_label_set_text(objects.obj4, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_main_temp_today();
        const char *cur_val = lv_label_get_text(objects.obj5);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj5;
            lv_label_set_text(objects.obj5, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_main_day_tomorrow();
        const char *cur_val = lv_label_get_text(objects.obj6);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj6;
            lv_label_set_text(objects.obj6, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_main_temp_tomorrow();
        const char *cur_val = lv_label_get_text(objects.obj7);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj7;
            lv_label_set_text(objects.obj7, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_main_day_scndnextday();
        const char *cur_val = lv_label_get_text(objects.obj8);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj8;
            lv_label_set_text(objects.obj8, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_main_temp_scndnextday();
        const char *cur_val = lv_label_get_text(objects.obj9);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj9;
            lv_label_set_text(objects.obj9, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_main_day_thrdnextday();
        const char *cur_val = lv_label_get_text(objects.obj10);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj10;
            lv_label_set_text(objects.obj10, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_main_temp_thrdnextday();
        const char *cur_val = lv_label_get_text(objects.obj11);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj11;
            lv_label_set_text(objects.obj11, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_set_alarm() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.set_alarm = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff171717), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Alarm Title
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.alarm_title = obj;
            lv_obj_set_pos(obj, 122, 10);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Alarm");
            lv_obj_set_style_text_font(obj, &ui_font_smallpixel7_128, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Alarm Description
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.alarm_description = obj;
            lv_obj_set_pos(obj, 107, 92);
            lv_obj_set_size(obj, 267, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Set an alarm,\nfor a specific time");
            apply_style_smallpixel7_32(obj);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_bmarmy_20, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Alarm Time Input
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.alarm_time_input = obj;
            lv_obj_set_pos(obj, 97, 164);
            lv_obj_set_size(obj, 94, 44);
            lv_textarea_set_accepted_chars(obj, "01234568789:");
            lv_textarea_set_max_length(obj, 5);
            lv_textarea_set_placeholder_text(obj, "99:99");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_set_alarm_alarm_time_input, LV_EVENT_ALL, 0);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_text_font(obj, &ui_font_smallpixel7_32, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Alarm Forward
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.alarm_forward = obj;
            lv_obj_set_pos(obj, 425, 112);
            lv_obj_set_size(obj, 55, 96);
            lv_obj_add_event_cb(obj, event_handler_cb_set_alarm_alarm_forward, LV_EVENT_ALL, 0);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN);
            lv_obj_set_style_bg_img_src(obj, &img_arrow_right_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Alarm Backward
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.alarm_backward = obj;
            lv_obj_set_pos(obj, 0, 112);
            lv_obj_set_size(obj, 55, 96);
            lv_obj_add_event_cb(obj, event_handler_cb_set_alarm_alarm_backward, LV_EVENT_ALL, 0);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN);
            lv_obj_set_style_bg_img_src(obj, &img_arrow_left_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Alarm Plus Time
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.alarm_plus_time = obj;
            lv_obj_set_pos(obj, 199, 164);
            lv_obj_set_size(obj, 20, 20);
            lv_obj_add_event_cb(obj, event_handler_cb_set_alarm_alarm_plus_time, LV_EVENT_ALL, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff171717), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff9e9e9e), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -15, -12);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "+");
                    apply_style_smallpixel7_32(obj);
                }
            }
        }
        {
            // Alarm Minus Time
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.alarm_minus_time = obj;
            lv_obj_set_pos(obj, 199, 188);
            lv_obj_set_size(obj, 20, 20);
            lv_obj_add_event_cb(obj, event_handler_cb_set_alarm_alarm_minus_time, LV_EVENT_ALL, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff171717), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff9e9e9e), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -15, -12);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "-");
                    apply_style_smallpixel7_32(obj);
                }
            }
        }
        {
            // Alarm Select Reason
            lv_obj_t *obj = lv_dropdown_create(parent_obj);
            objects.alarm_select_reason = obj;
            lv_obj_set_pos(obj, 240, 165);
            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
            lv_dropdown_set_options(obj, get_var_alarm_reasons());
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Alarm Set Button
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.alarm_set_button = obj;
            lv_obj_set_pos(obj, 122, 239);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_set_alarm_alarm_set_button, LV_EVENT_ALL, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00ff53), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -16, 5);
                    lv_obj_set_size(obj, 100, 35);
                    lv_label_set_text(obj, "SET");
                    apply_style_smallpixel7_32(obj);
                    lv_obj_set_style_text_font(obj, &ui_font_smallpixel7_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Alarm Reset Button
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.alarm_reset_button = obj;
            lv_obj_set_pos(obj, 259, 239);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_set_alarm_alarm_reset_button, LV_EVENT_ALL, 0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff2626), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -1, 5);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "RESET");
                    apply_style_smallpixel7_32(obj);
                }
            }
        }
    }
}

void tick_screen_set_alarm() {
    {
        const char *new_val = get_var_alarm_time();
        const char *cur_val = lv_textarea_get_text(objects.alarm_time_input);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.alarm_time_input;
            lv_textarea_set_text(objects.alarm_time_input, new_val);
            tick_value_change_obj = NULL;
        }
    }
}
    
    void create_screen_set_timer() {
        lv_obj_t *obj = lv_obj_create(0);
        objects.set_timer = obj;
        lv_obj_set_pos(obj, 0, 0);
        lv_obj_set_size(obj, 480, 320);
        lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_set_style_bg_color(obj, lv_color_hex(0xff171717), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
        {
            lv_obj_t *parent_obj = obj;
            {
                // Timer Title
                lv_obj_t *obj = lv_label_create(parent_obj);
                objects.timer_title = obj;
                lv_obj_set_pos(obj, 122, 10);
                lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                lv_label_set_text(obj, "Timer");
                lv_obj_set_style_text_font(obj, &ui_font_smallpixel7_128, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                // Timer Description
                lv_obj_t *obj = lv_label_create(parent_obj);
                objects.timer_description = obj;
                lv_obj_set_pos(obj, 107, 92);
                lv_obj_set_size(obj, 267, LV_SIZE_CONTENT);
                lv_label_set_text(obj, "Set a timer,\nfor up to 3 hours");
                apply_style_smallpixel7_32(obj);
                lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_font(obj, &ui_font_bmarmy_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                // Timer Forward
                lv_obj_t *obj = lv_btn_create(parent_obj);
                objects.timer_forward = obj;
                lv_obj_set_pos(obj, 425, 112);
                lv_obj_set_size(obj, 55, 96);
                lv_obj_add_event_cb(obj, event_handler_cb_set_timer_timer_forward, LV_EVENT_ALL, 0);
                lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN);
                apply_style_forward_backward_btn(obj);
                lv_obj_set_style_bg_img_src(obj, &img_arrow_right_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                // Timer Backward
                lv_obj_t *obj = lv_btn_create(parent_obj);
                objects.timer_backward = obj;
                lv_obj_set_pos(obj, 0, 112);
                lv_obj_set_size(obj, 55, 96);
                lv_obj_add_event_cb(obj, event_handler_cb_set_timer_timer_backward, LV_EVENT_ALL, 0);
                lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN);
                apply_style_forward_backward_btn(obj);
                lv_obj_set_style_bg_img_src(obj, &img_arrow_left_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                // Timer Start Button
                lv_obj_t *obj = lv_btn_create(parent_obj);
                objects.timer_set_button = obj;
                lv_obj_set_pos(obj, 55, 183);
                lv_obj_set_size(obj, 100, 50);
                lv_obj_add_event_cb(obj, event_handler_cb_set_timer_timer_set_button, LV_EVENT_ALL, 0);
                lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00ff53), LV_PART_MAIN | LV_STATE_DEFAULT);
                {
                    lv_obj_t *parent_obj = obj;
                    {
                        lv_obj_t *obj = lv_label_create(parent_obj);
                        lv_obj_set_pos(obj, -16, 5);
                        lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                        lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                        lv_label_set_text(obj, "START");
                        apply_style_smallpixel7_32(obj);
                    }
                }
            }
            {
                // Timer Reset Button
                lv_obj_t *obj = lv_btn_create(parent_obj);
                objects.timer_reset_button = obj;
                lv_obj_set_pos(obj, 325, 183);
                lv_obj_set_size(obj, 100, 50);
                lv_obj_add_event_cb(obj, event_handler_cb_set_timer_timer_reset_button, LV_EVENT_ALL, 0);
                lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff2626), LV_PART_MAIN | LV_STATE_DEFAULT);
                {
                    lv_obj_t *parent_obj = obj;
                    {
                        lv_obj_t *obj = lv_label_create(parent_obj);
                        lv_obj_set_pos(obj, -1, 5);
                        lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        lv_label_set_text(obj, "RESET");
                        apply_style_smallpixel7_32(obj);
                    }
                }
            }
            {
                // Timer Arc
                lv_obj_t *obj = lv_arc_create(parent_obj);
                objects.timer_arc = obj;
                lv_obj_set_pos(obj, 165, 141);
                lv_obj_set_size(obj, 150, 150);
                lv_arc_set_bg_end_angle(obj, 60);
                lv_arc_set_rotation(obj, -1);
                lv_obj_add_event_cb(obj, event_handler_cb_set_timer_timer_arc, LV_EVENT_ALL, 0);
                lv_obj_set_style_arc_width(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_rounded(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(obj, lv_color_hex(0xff640606), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_radius(obj, 32767, LV_PART_KNOB | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_KNOB | LV_STATE_DEFAULT);
                lv_obj_set_style_outline_width(obj, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
                lv_obj_set_style_outline_color(obj, lv_color_hex(0xff171717), LV_PART_KNOB | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_opa(obj, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(obj, lv_color_hex(0xffff0000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                {
                    lv_obj_t *parent_obj = obj;
                    {
                        // Timer Time Displayed
                        lv_obj_t *obj = lv_label_create(parent_obj);
                        objects.timer_time_displayed = obj;
                        lv_obj_set_pos(obj, 28, 63);
                        lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        lv_label_set_text(obj, "00:00");
                        apply_style_smallpixel7_48(obj);
                    }
                }
            }
        }
    }
    
    void tick_screen_set_timer() {
        {
            int32_t new_val = get_var_timer_arc_value();
            int32_t cur_val = lv_arc_get_value(objects.timer_arc);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.timer_arc;
                lv_arc_set_value(objects.timer_arc, new_val);
                tick_value_change_obj = NULL;
            }
        }
        {
            const char *new_val = get_var_timer_time();
            const char *cur_val = lv_label_get_text(objects.timer_time_displayed);
            if (strcmp(new_val, cur_val) != 0) {
                tick_value_change_obj = objects.timer_time_displayed;
                lv_label_set_text(objects.timer_time_displayed, new_val);
                tick_value_change_obj = NULL;
            }
        }
        {
            lv_obj_t *timer_start_button_label = lv_obj_get_child(objects.timer_set_button, 0);
            if(isTimerRunning()) {
                tick_value_change_obj = objects.timer_set_button;
                lv_obj_set_style_bg_color(objects.timer_set_button, lv_color_hex(0xFFEA00), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_label_set_text(timer_start_button_label, "PAUSE");
                lv_obj_clear_flag(objects.timer_arc, LV_OBJ_FLAG_CLICKABLE); // Disable the arc from being changed while the timer is running
                tick_value_change_obj = NULL;
            }else if(isTimerPaused()) {
                tick_value_change_obj = objects.timer_set_button;
                lv_obj_set_style_bg_color(objects.timer_set_button, lv_color_hex(0xff00ff53), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_label_set_text(timer_start_button_label, "RESUME");
                lv_obj_clear_flag(objects.timer_arc, LV_OBJ_FLAG_CLICKABLE); // Disable the arc from being changed while the timer is running
                tick_value_change_obj = NULL;
            }else {
                tick_value_change_obj = objects.timer_set_button;
                lv_obj_set_style_bg_color(objects.timer_set_button, lv_color_hex(0xff00ff53), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_label_set_text(timer_start_button_label, "START");
                lv_obj_add_flag(objects.timer_arc, LV_OBJ_FLAG_CLICKABLE); // Enable the arc to be changed
                tick_value_change_obj = NULL;
            }
        }
    }
    
    void create_screen_set_stopwatch() {
        lv_obj_t *obj = lv_obj_create(0);
        objects.set_stopwatch = obj;
        lv_obj_set_pos(obj, 0, 0);
        lv_obj_set_size(obj, 480, 320);
        lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_set_style_bg_color(obj, lv_color_hex(0xff171717), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(obj, &ui_font_bmarmy_20, LV_PART_MAIN | LV_STATE_DEFAULT);
        {
            lv_obj_t *parent_obj = obj;
            {
                // Stopwatch Title
                lv_obj_t *obj = lv_label_create(parent_obj);
                objects.stopwatch_title = obj;
                lv_obj_set_pos(obj, 10, 10);
                lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                lv_label_set_text(obj, "Stopwatch");
                lv_obj_set_style_text_font(obj, &ui_font_smallpixel7_128, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                // Stopwatch Description
                lv_obj_t *obj = lv_label_create(parent_obj);
                objects.stopwatch_description = obj;
                lv_obj_set_pos(obj, 107, 112);
                lv_obj_set_size(obj, 267, LV_SIZE_CONTENT);
                lv_label_set_text(obj, "Start a stopwatch");
                apply_style_smallpixel7_32(obj);
                lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_font(obj, &ui_font_bmarmy_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                // Stopwatch Time Count
                lv_obj_t *obj = lv_textarea_create(parent_obj);
                objects.stopwatch_time_count = obj;
                lv_obj_set_pos(obj, 144, 160);
                lv_obj_set_size(obj, 192, 44);
                lv_textarea_set_accepted_chars(obj, "01234568789:.");
                lv_textarea_set_max_length(obj, 12);
                lv_textarea_set_placeholder_text(obj, "00:00:00.000");
                lv_textarea_set_one_line(obj, true);
                lv_textarea_set_password_mode(obj, false);
                lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_SNAPPABLE|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN);
                lv_obj_set_style_text_font(obj, &ui_font_smallpixel7_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_add_event_cb(obj, event_handler_cb_set_stopwatch_stopwatch_time_count, LV_EVENT_ALL, 0);
            }
            {
                // Stopwatch Forward
                lv_obj_t *obj = lv_btn_create(parent_obj);
                objects.stopwatch_forward = obj;
                lv_obj_set_pos(obj, 425, 112);
                lv_obj_set_size(obj, 55, 96);
                lv_obj_add_event_cb(obj, event_handler_cb_set_stopwatch_stopwatch_forward, LV_EVENT_ALL, 0);
                lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN);
                lv_obj_set_style_bg_img_src(obj, &img_arrow_right_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                // Stopwatch Backward
                lv_obj_t *obj = lv_btn_create(parent_obj);
                objects.stopwatch_backward = obj;
                lv_obj_set_pos(obj, 0, 112);
                lv_obj_set_size(obj, 55, 96);
                lv_obj_add_event_cb(obj, event_handler_cb_set_stopwatch_stopwatch_backward, LV_EVENT_ALL, 0);
                lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN);
                lv_obj_set_style_bg_img_src(obj, &img_arrow_left_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                // Stopwatch Start Button
                lv_obj_t *obj = lv_btn_create(parent_obj);
                objects.stopwatch_start_button = obj;
                lv_obj_set_pos(obj, 122, 239);
                lv_obj_set_size(obj, 100, 50);
                lv_obj_add_event_cb(obj, event_handler_cb_set_stopwatch_stopwatch_start_button, LV_EVENT_ALL, 0);
                lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE);
                lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00ff53), LV_PART_MAIN | LV_STATE_DEFAULT);
                {
                    lv_obj_t *parent_obj = obj;
                    {
                        lv_obj_t *obj = lv_label_create(parent_obj);
                        lv_obj_set_pos(obj, -16, 5);
                        lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                        lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                        lv_label_set_text(obj, "START");
                        apply_style_smallpixel7_32(obj);
                    }
                }
            }
            {
                // Stopwatch Reset Button
                lv_obj_t *obj = lv_btn_create(parent_obj);
                objects.stopwatch_reset_button = obj;
                lv_obj_set_pos(obj, 259, 239);
                lv_obj_set_size(obj, 100, 50);
                lv_obj_add_event_cb(obj, event_handler_cb_set_stopwatch_stopwatch_reset_button, LV_EVENT_ALL, 0);
                lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE);
                lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff2626), LV_PART_MAIN | LV_STATE_DEFAULT);
                {
                    lv_obj_t *parent_obj = obj;
                    {
                        lv_obj_t *obj = lv_label_create(parent_obj);
                        lv_obj_set_pos(obj, -1, 5);
                        lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        lv_label_set_text(obj, "RESET");
                        apply_style_smallpixel7_32(obj);
                    }
                }
            }
        }
    }
    
    void tick_screen_set_stopwatch() {
        {
            const char *new_val = get_var_stopwatch_time();
            const char *cur_val = lv_textarea_get_text(objects.stopwatch_time_count);
            if (strcmp(new_val, cur_val) != 0) {
                tick_value_change_obj = objects.stopwatch_time_count;
                lv_textarea_set_text(objects.stopwatch_time_count, new_val);
                tick_value_change_obj = NULL;
            }
        }
        {
            lv_obj_t *stopwatch_start_button_label = lv_obj_get_child(objects.stopwatch_start_button, 0);
            if(isStopwatchRunning()) {
                tick_value_change_obj = objects.stopwatch_start_button;
                lv_obj_set_style_bg_color(objects.stopwatch_start_button, lv_color_hex(0xFFEA00), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_label_set_text(stopwatch_start_button_label, "PAUSE");
                tick_value_change_obj = NULL;
            }else if(isStopwatchPaused()) {
                tick_value_change_obj = objects.stopwatch_start_button;
                lv_obj_set_style_bg_color(objects.stopwatch_start_button, lv_color_hex(0xff00ff53), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_label_set_text(stopwatch_start_button_label, "RESUME");
                tick_value_change_obj = NULL;
            }else {
                tick_value_change_obj = objects.stopwatch_start_button;
                lv_obj_set_style_bg_color(objects.stopwatch_start_button, lv_color_hex(0xff00ff53), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_label_set_text(stopwatch_start_button_label, "START");
                tick_value_change_obj = NULL;
            }
        }
    }
    
    void create_screen_set_settings() {
        lv_obj_t *obj = lv_obj_create(0);
        objects.set_settings = obj;
        lv_obj_set_pos(obj, 0, 0);
        lv_obj_set_size(obj, 480, 320);
        lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_set_style_bg_color(obj, lv_color_hex(0xff171717), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
        {
            lv_obj_t *parent_obj = obj;
            {
                // Settings Title
                lv_obj_t *obj = lv_label_create(parent_obj);
                objects.settings_title = obj;
                lv_obj_set_pos(obj, 29, 10);
                lv_obj_set_size(obj, 422, LV_SIZE_CONTENT);
                lv_label_set_text(obj, "");
                lv_obj_set_style_text_font(obj, &ui_font_smallpixel7_128, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                // Settings Forward
                lv_obj_t *obj = lv_btn_create(parent_obj);
                objects.settings_forward = obj;
                lv_obj_set_pos(obj, 425, 112);
                lv_obj_set_size(obj, 55, 96);
                lv_obj_add_event_cb(obj, event_handler_cb_set_settings_settings_forward, LV_EVENT_ALL, 0);
                lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN);
                lv_obj_set_style_bg_img_src(obj, &img_arrow_right_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                // Settings Backward
                lv_obj_t *obj = lv_btn_create(parent_obj);
                objects.settings_backward = obj;
                lv_obj_set_pos(obj, 0, 112);
                lv_obj_set_size(obj, 55, 96);
                lv_obj_add_event_cb(obj, event_handler_cb_set_settings_settings_backward, LV_EVENT_ALL, 0);
                lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN);
                lv_obj_set_style_bg_img_src(obj, &img_arrow_left_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                // Select Setting
                lv_obj_t *obj = lv_obj_create(parent_obj);
                objects.select_setting = obj;
                lv_obj_set_pos(obj, 140, 100);
                lv_obj_set_size(obj, 200, 210);
                apply_style_container(obj);
                lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                {
                    lv_obj_t *parent_obj = obj;
                    {
                        // Setting: Time
                        lv_obj_t *obj = lv_btn_create(parent_obj);
                        objects.setting__time = obj;
                        lv_obj_set_pos(obj, 165, 135);
                        lv_obj_set_size(obj, 150, 50);
                        lv_obj_add_event_cb(obj, event_handler_cb_set_settings_setting__time, LV_EVENT_ALL, 0);
                        lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                        lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                        lv_obj_set_style_bg_color(obj, lv_color_hex(0xff4caf50), LV_PART_MAIN | LV_STATE_DEFAULT);
                        {
                            lv_obj_t *parent_obj = obj;
                            {
                                lv_obj_t *obj = lv_label_create(parent_obj);
                                lv_obj_set_pos(obj, 31, 5);
                                lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                lv_label_set_text(obj, "Time");
                                apply_style_smallpixel7_32(obj);
                            }
                        }
                    }
                    {
                        // Setting: Alarm
                        lv_obj_t *obj = lv_btn_create(parent_obj);
                        objects.setting__alarm = obj;
                        lv_obj_set_pos(obj, 165, 135);
                        lv_obj_set_size(obj, 150, 50);
                        lv_obj_add_event_cb(obj, event_handler_cb_set_settings_setting__alarm, LV_EVENT_ALL, 0);
                        lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                        lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                        lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
                        {
                            lv_obj_t *parent_obj = obj;
                            {
                                lv_obj_t *obj = lv_label_create(parent_obj);
                                lv_obj_set_pos(obj, 24, 5);
                                lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                lv_label_set_text(obj, "Alarm");
                                apply_style_smallpixel7_32(obj);
                                lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            }
                        }
                    }
                    {
                        // Setting: Audio
                        lv_obj_t *obj = lv_btn_create(parent_obj);
                        objects.setting__audio = obj;
                        lv_obj_set_pos(obj, 165, 135);
                        lv_obj_set_size(obj, 150, 50);
                        lv_obj_add_event_cb(obj, event_handler_cb_set_settings_setting__audio, LV_EVENT_ALL, 0);
                        lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                        lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                        lv_obj_set_style_bg_color(obj, lv_color_hex(0xff9200fc), LV_PART_MAIN | LV_STATE_DEFAULT);
                        {
                            lv_obj_t *parent_obj = obj;
                            {
                                lv_obj_t *obj = lv_label_create(parent_obj);
                                lv_obj_set_pos(obj, 24, 5);
                                lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                lv_label_set_text(obj, "Audio");
                                apply_style_smallpixel7_32(obj);
                                lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            }
                        }
                    }
                    {
                        // Setting: WiFi
                        lv_obj_t *obj = lv_btn_create(parent_obj);
                        objects.setting__wi_fi = obj;
                        lv_obj_set_pos(obj, 165, 135);
                        lv_obj_set_size(obj, 150, 50);
                        lv_obj_add_event_cb(obj, event_handler_cb_set_settings_setting__wi_fi, LV_EVENT_ALL, 0);
                        lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                        lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                        lv_obj_set_style_bg_color(obj, lv_color_hex(0xff08a1ec), LV_PART_MAIN | LV_STATE_DEFAULT);
                        {
                            lv_obj_t *parent_obj = obj;
                            {
                                lv_obj_t *obj = lv_label_create(parent_obj);
                                lv_obj_set_pos(obj, 31, 5);
                                lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                lv_label_set_text(obj, "WiFi");
                                apply_style_smallpixel7_32(obj);
                                lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            }
                        }
                    }
                    {
                        // Setting: Other
                        lv_obj_t *obj = lv_btn_create(parent_obj);
                        objects.setting__other = obj;
                        lv_obj_set_pos(obj, 165, 135);
                        lv_obj_set_size(obj, 150, 50);
                        lv_obj_add_event_cb(obj, event_handler_cb_set_settings_setting__other, LV_EVENT_ALL, 0);
                        lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                        lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                        lv_obj_set_style_bg_color(obj, lv_color_hex(0xff808080), LV_PART_MAIN | LV_STATE_DEFAULT);
                        {
                            lv_obj_t *parent_obj = obj;
                            {
                                lv_obj_t *obj = lv_label_create(parent_obj);
                                lv_obj_set_pos(obj, -4, 5);
                                lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                lv_label_set_text(obj, "Other");
                                apply_style_smallpixel7_32(obj);
                                lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            }
                        }
                    }
                }
            }
            {
                // Selected Setting: Time
                lv_obj_t *obj = lv_obj_create(parent_obj);
                objects.selected_setting__time = obj;
                lv_obj_set_pos(obj, 140, 100);
                lv_obj_set_size(obj, 200, 210);
                lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                apply_style_container(obj);
                lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                {
                    lv_obj_t *parent_obj = obj;
                    {
                        // Time Auto-Set Checkbox
                        lv_obj_t *obj = lv_checkbox_create(parent_obj);
                        objects.time_auto_set_checkbox = obj;
                        lv_obj_set_pos(obj, 69, 109);
                        lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        lv_checkbox_set_text(obj, "Auto-Set");
                        lv_obj_add_event_cb(obj, event_handler_cb_set_settings_time_auto_set_checkbox, LV_EVENT_ALL, 0);
                        lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    }
                    {
                        // Time Change Time
                        lv_obj_t *obj = lv_obj_create(parent_obj);
                        objects.time_change_time = obj;
                        lv_obj_set_pos(obj, 293, -9);
                        lv_obj_set_size(obj, 130, 45);
                        lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                        lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                        lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                        {
                            lv_obj_t *parent_obj = obj;
                            {
                                // Setting Time Input
                                lv_obj_t *obj = lv_textarea_create(parent_obj);
                                objects.setting_time_input = obj;
                                lv_obj_set_pos(obj, -16, -15);
                                lv_obj_set_size(obj, 94, 44);
                                lv_textarea_set_accepted_chars(obj, "01234568789:");
                                lv_textarea_set_max_length(obj, 5);
                                lv_textarea_set_placeholder_text(obj, "99:99");
                                lv_textarea_set_one_line(obj, true);
                                lv_textarea_set_password_mode(obj, false);
                                lv_obj_add_event_cb(obj, event_handler_cb_set_settings_setting_time_input, LV_EVENT_ALL, 0);
                                lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                lv_obj_set_style_text_font(obj, &ui_font_smallpixel7_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                                lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            }
                            {
                                // Plus Time_1
                                lv_obj_t *obj = lv_btn_create(parent_obj);
                                objects.plus_time_1 = obj;
                                lv_obj_set_pos(obj, 91, -15);
                                lv_obj_set_size(obj, 20, 20);
                                lv_obj_add_event_cb(obj, event_handler_cb_set_settings_plus_time_1, LV_EVENT_ALL, 0);
                                lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                                lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                lv_obj_set_style_bg_color(obj, lv_color_hex(0xff171717), LV_PART_MAIN | LV_STATE_DEFAULT);
                                lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
                                lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                lv_obj_set_style_border_color(obj, lv_color_hex(0xff9e9e9e), LV_PART_MAIN | LV_STATE_DEFAULT);
                                {
                                    lv_obj_t *parent_obj = obj;
                                    {
                                        lv_obj_t *obj = lv_label_create(parent_obj);
                                        lv_obj_set_pos(obj, -15, -12);
                                        lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                        lv_label_set_text(obj, "+");
                                        apply_style_smallpixel7_32(obj);
                                    }
                                }
                            }
                            {
                                // Minus Time_1
                                lv_obj_t *obj = lv_btn_create(parent_obj);
                                objects.minus_time_1 = obj;
                                lv_obj_set_pos(obj, 91, 9);
                                lv_obj_set_size(obj, 20, 20);
                                lv_obj_add_event_cb(obj, event_handler_cb_set_settings_minus_time_1, LV_EVENT_ALL, 0);
                                lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                                lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                lv_obj_set_style_bg_color(obj, lv_color_hex(0xff171717), LV_PART_MAIN | LV_STATE_DEFAULT);
                                lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                lv_obj_set_style_border_color(obj, lv_color_hex(0xff9e9e9e), LV_PART_MAIN | LV_STATE_DEFAULT);
                                lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);
                                {
                                    lv_obj_t *parent_obj = obj;
                                    {
                                        lv_obj_t *obj = lv_label_create(parent_obj);
                                        lv_obj_set_pos(obj, -15, -12);
                                        lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                        lv_label_set_text(obj, "-");
                                        apply_style_smallpixel7_32(obj);
                                    }
                                }
                            }
                        }
                    }
                    {
                        // Change Date
                        lv_obj_t *obj = lv_obj_create(parent_obj);
                        objects.change_date = obj;
                        lv_obj_set_pos(obj, -1454, 4);
                        lv_obj_set_size(obj, 200, 107);
                        lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                        lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                        lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                        {
                            lv_obj_t *parent_obj = obj;
                            {
                                // Date Input: Month
                                lv_obj_t *obj = lv_dropdown_create(parent_obj);
                                objects.date_input__month = obj;
                                lv_obj_set_pos(obj, 4, -14);
                                lv_obj_set_size(obj, 90, LV_SIZE_CONTENT);
                                lv_dropdown_set_options(obj, "Jan\nFeb\nMar\nApr\nMay\nJun\nJul\nAug\nSep\nOct\nNov\nDec");
                                lv_obj_add_event_cb(obj, event_handler_cb_set_settings_date_input__month, LV_EVENT_ALL, 0);
                                lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            }
                            {
                                // Date Input: Day
                                lv_obj_t *obj = lv_dropdown_create(parent_obj);
                                objects.date_input__day = obj;
                                lv_obj_set_pos(obj, 104, -14);
                                lv_obj_set_size(obj, 60, LV_SIZE_CONTENT);
                                lv_dropdown_set_options(obj, "31\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31");
                                lv_obj_add_event_cb(obj, event_handler_cb_set_settings_date_input__day, LV_EVENT_ALL, 0);
                                lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            }
                            {
                                // Date Input: Year
                                lv_obj_t *obj = lv_dropdown_create(parent_obj);
                                objects.date_input__year = obj;
                                lv_obj_set_pos(obj, 39, 38);
                                lv_obj_set_size(obj, 91, LV_SIZE_CONTENT);
                                lv_dropdown_set_options(obj, "2024\n2025\n2026\n2027\n2028\n2029\n2030\n2031\n2032\n2033\n2034\n2035\n2036\n2037\n2038\n2039\n2040\n2041\n2042\n2043\n2044\n2045\n2046\n2047\n2048\n2049\n2050\n2051\n2052\n2053\n2054\n2055\n2056\n2057\n2058\n2059\n2060\n2061\n2062\n2063\n2064\n2065\n2066\n2067\n2068\n2069\n2070\n2071\n2072\n2073\n2074\n2075\n2076\n2077\n2078\n2079\n2080\n2081\n2082\n2083\n2084\n2085\n2086\n2087\n2088\n2089\n2090\n2091\n2092\n2093\n2094\n2095\n2096\n2097\n2098\n2099");
                                lv_obj_add_event_cb(obj, event_handler_cb_set_settings_date_input__year, LV_EVENT_ALL, 0);
                                lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            }
                        }
                    }
                }
            }
            {
                // Selected Setting: Alarm
                lv_obj_t *obj = lv_obj_create(parent_obj);
                objects.selected_setting__alarm = obj;
                lv_obj_set_pos(obj, 140, 100);
                lv_obj_set_size(obj, 200, 210);
                lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                apply_style_container(obj);
                lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                {
                    lv_obj_t *parent_obj = obj;
                    {
                        // Alarm Repeat for
                        lv_obj_t *obj = lv_label_create(parent_obj);
                        objects.alarm_repeat_for = obj;
                        lv_obj_set_pos(obj, 1, 0);
                        lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        lv_label_set_text(obj, "Repeat for");
                        apply_style_smallpixel7_32(obj);
                        lv_obj_set_style_text_font(obj, &ui_font_smallpixel7_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                    }
                    {
                        // Alarm Select Repeats
                        lv_obj_t *obj = lv_obj_create(parent_obj);
                        objects.alarm_select_repeats = obj;
                        lv_obj_set_pos(obj, -2404, 0);
                        lv_obj_set_size(obj, 200, 50);
                        lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                        apply_style_container(obj);
                        lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                        lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                        {
                            lv_obj_t *parent_obj = obj;
                            {
                                lv_obj_t *obj = lv_dropdown_create(parent_obj);
                                objects.obj12 = obj;
                                lv_obj_set_pos(obj, 4, -14);
                                lv_obj_set_size(obj, 80, LV_SIZE_CONTENT);
                                lv_dropdown_set_options(obj, "0\n1\n3\n5\n8");
                                lv_obj_add_event_cb(obj, event_handler_cb_set_settings_obj12, LV_EVENT_ALL, 0);
                                lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            }
                            {
                                lv_obj_t *obj = lv_label_create(parent_obj);
                                lv_obj_set_pos(obj, 65, -30);
                                lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                lv_label_set_text(obj, "times.");
                                apply_style_smallpixel7_32(obj);
                                lv_obj_set_style_text_font(obj, &ui_font_bmarmy_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                            }
                        }
                    }
                    {
                        lv_obj_t *obj = lv_label_create(parent_obj);
                        lv_obj_set_pos(obj, -2, 22);
                        lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        lv_label_set_text(obj, "Every");
                        apply_style_smallpixel7_32(obj);
                        lv_obj_set_style_text_font(obj, &ui_font_bmarmy_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    }
                    {
                        // Alarm Select Repeat after
                        lv_obj_t *obj = lv_obj_create(parent_obj);
                        objects.alarm_select_repeat_after = obj;
                        lv_obj_set_pos(obj, -2263, 0);
                        lv_obj_set_size(obj, 200, 50);
                        lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                        apply_style_container(obj);
                        lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                        lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                        {
                            lv_obj_t *parent_obj = obj;
                            {
                                // Alarm Select Repeats_1
                                lv_obj_t *obj = lv_dropdown_create(parent_obj);
                                objects.alarm_select_repeats_1 = obj;
                                lv_obj_set_pos(obj, 4, -14);
                                lv_obj_set_size(obj, 80, LV_SIZE_CONTENT);
                                lv_dropdown_set_options(obj, "5\n10\n15\n30\n45\n60");
                                lv_obj_add_event_cb(obj, event_handler_cb_set_settings_alarm_select_repeats_1, LV_EVENT_ALL, 0);
                                lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            }
                            {
                                lv_obj_t *obj = lv_label_create(parent_obj);
                                lv_obj_set_pos(obj, 0, 0);
                                lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                lv_label_set_text(obj, "minutes.");
                                apply_style_smallpixel7_32(obj);
                                lv_obj_set_style_text_font(obj, &ui_font_bmarmy_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                            }
                        }
                    }
                }
            }
            {
                // Selected Setting: Audio
                lv_obj_t *obj = lv_obj_create(parent_obj);
                objects.selected_setting__audio = obj;
                lv_obj_set_pos(obj, 140, 100);
                lv_obj_set_size(obj, 200, 210);
                lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                apply_style_container(obj);
                lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                {
                    lv_obj_t *parent_obj = obj;
                    {
                        // Audio Play alarm over AUX
                        lv_obj_t *obj = lv_checkbox_create(parent_obj);
                        objects.audio_play_alarm_over_aux = obj;
                        lv_obj_set_pos(obj, 69, 109);
                        lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        lv_checkbox_set_text(obj, "Alarm over AUX");
                        lv_obj_add_event_cb(obj, event_handler_cb_set_settings_audio_play_alarm_over_aux, LV_EVENT_ALL, 0);
                        lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    }
                    {
                        // Audio Select Music
                        lv_obj_t *obj = lv_dropdown_create(parent_obj);
                        objects.audio_select_music = obj;
                        lv_obj_set_pos(obj, 4, -14);
                        lv_obj_set_size(obj, 160, LV_SIZE_CONTENT);
                        lv_dropdown_set_options(obj, get_var_settings_setting_audio_music_selection());
                        lv_obj_add_event_cb(obj, event_handler_cb_set_settings_audio_select_music, LV_EVENT_ALL, 0);
                        lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    }
                    {
                        // Audio Change Alarm volume
                        lv_obj_t *obj = lv_label_create(parent_obj);
                        objects.audio_change_alarm_volume = obj;
                        lv_obj_set_pos(obj, 0, 0);
                        lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        lv_label_set_text(obj, "Alarm volume");
                        apply_style_smallpixel7_32(obj);
                        lv_obj_set_style_text_font(obj, &ui_font_bmarmy_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    }
                    {
                        // Audio Alarm Volume Slider
                        lv_obj_t *obj = lv_slider_create(parent_obj);
                        objects.audio_alarm_volume_slider = obj;
                        lv_obj_set_pos(obj, 0, 27);
                        lv_obj_set_size(obj, 150, 10);
                        lv_obj_add_event_cb(obj, event_handler_cb_set_settings_audio_alarm_volume_slider, LV_EVENT_ALL, 0);
                        lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff2323), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                        lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_KNOB | LV_STATE_DEFAULT);
                        lv_obj_set_style_outline_width(obj, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
                        lv_obj_set_style_outline_color(obj, lv_color_hex(0xff171717), LV_PART_KNOB | LV_STATE_DEFAULT);
                        lv_obj_set_style_bg_color(obj, lv_color_hex(0xff640606), LV_PART_MAIN | LV_STATE_DEFAULT);
                    }
                    {
                        // Audio Change AUX-IN volume
                        lv_obj_t *obj = lv_label_create(parent_obj);
                        objects.audio_change_aux_in_volume = obj;
                        lv_obj_set_pos(obj, 0, 0);
                        lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        lv_label_set_text(obj, "AUX-IN volume");
                        apply_style_smallpixel7_32(obj);
                        lv_obj_set_style_text_font(obj, &ui_font_bmarmy_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                        lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    }
                    {
                        // Audio AUX-IN Volume Slider
                        lv_obj_t *obj = lv_slider_create(parent_obj);
                        objects.audio_aux_in_volume_slider = obj;
                        lv_obj_set_pos(obj, 0, 27);
                        lv_obj_set_size(obj, 150, 10);
                        lv_obj_add_event_cb(obj, event_handler_cb_set_settings_audio_aux_in_volume_slider, LV_EVENT_ALL, 0);
                        lv_obj_set_style_bg_color(obj, lv_color_hex(0xff4caf50), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                        lv_obj_set_style_bg_color(obj, lv_color_hex(0xff4caf50), LV_PART_KNOB | LV_STATE_DEFAULT);
                        lv_obj_set_style_outline_width(obj, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
                        lv_obj_set_style_outline_color(obj, lv_color_hex(0xff171717), LV_PART_KNOB | LV_STATE_DEFAULT);
                        lv_obj_set_style_bg_color(obj, lv_color_hex(0xff1e461f), LV_PART_MAIN | LV_STATE_DEFAULT);
                    }
                }
            }
            {
                // Selected Setting: WiFi
                lv_obj_t *obj = lv_obj_create(parent_obj);
                objects.selected_setting__wi_fi = obj;
                lv_obj_set_pos(obj, 90, 120);
                lv_obj_set_size(obj, 300, 190);
                lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                apply_style_container(obj);
                lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                {
                    lv_obj_t *parent_obj = obj;
                    {
                        lv_obj_t *obj = lv_img_create(parent_obj);
                        lv_obj_set_pos(obj, 342, 121);
                        lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        lv_img_set_src(obj, &img_wifi_qrcode_128);
                        lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
                        lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    }
                    {
                        lv_obj_t *obj = lv_label_create(parent_obj);
                        lv_obj_set_pos(obj, 0, 0);
                        lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        lv_label_set_text(obj, "Please open the app\nand scan this qr code.");
                        lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    }
                }
            }
            {
                // Selected Setting: Other
                lv_obj_t *obj = lv_obj_create(parent_obj);
                objects.selected_setting__other = obj;
                lv_obj_set_pos(obj, 140, 100);
                lv_obj_set_size(obj, 200, 210);
                lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                apply_style_container(obj);
                lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                {
                    lv_obj_t *parent_obj = obj;
                    {
                        // Other Calibrate Touch
                        lv_obj_t *obj = lv_btn_create(parent_obj);
                        objects.other_calibrate_touch = obj;
                        lv_obj_set_pos(obj, 0, 0);
                        lv_obj_set_size(obj, 190, 50);
                        lv_obj_add_event_cb(obj, event_handler_cb_set_settings_other_calibrate_touch, LV_EVENT_ALL, 0);
                        lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                        lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                        lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                        {
                            lv_obj_t *parent_obj = obj;
                            {
                                lv_obj_t *obj = lv_label_create(parent_obj);
                                lv_obj_set_pos(obj, 2, -5);
                                lv_obj_set_size(obj, 154, LV_SIZE_CONTENT);
                                lv_label_set_text(obj, "Calibrate\nTouch");
                                apply_style_smallpixel7_32(obj);
                                lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            }
                        }
                    }
                    {
                        // Other Reset
                        lv_obj_t *obj = lv_btn_create(parent_obj);
                        objects.other_reset = obj;
                        lv_obj_set_pos(obj, 0, 0);
                        lv_obj_set_size(obj, 190, 50);
                        lv_obj_add_event_cb(obj, event_handler_cb_set_settings_other_reset, LV_EVENT_ALL, 0);
                        lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                        lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                        lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
                        {
                            lv_obj_t *parent_obj = obj;
                            {
                                lv_obj_t *obj = lv_label_create(parent_obj);
                                lv_obj_set_pos(obj, 2, 5);
                                lv_obj_set_size(obj, 154, LV_SIZE_CONTENT);
                                lv_label_set_text(obj, "Reset");
                                apply_style_smallpixel7_32(obj);
                                lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            }
                        }
                    }
                }
            }
        }
    }
    
    void tick_screen_set_settings() {
        {
            const char *new_val = get_var_settings_title();
            const char *cur_val = lv_label_get_text(objects.settings_title);
            if (strcmp(new_val, cur_val) != 0) {
                tick_value_change_obj = objects.settings_title;
                lv_label_set_text(objects.settings_title, new_val);
                tick_value_change_obj = NULL;
            }
        }
        {
            bool new_val = get_var_settings_hide_selection();
            bool cur_val = lv_obj_has_flag(objects.select_setting, LV_OBJ_FLAG_HIDDEN);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.select_setting;
                if (new_val) lv_obj_add_flag(objects.select_setting, LV_OBJ_FLAG_HIDDEN);
                else lv_obj_clear_flag(objects.select_setting, LV_OBJ_FLAG_HIDDEN);
                tick_value_change_obj = NULL;
            }
        }
        {
            bool new_val = get_var_settings_hide_setting_time();
            bool cur_val = lv_obj_has_flag(objects.selected_setting__time, LV_OBJ_FLAG_HIDDEN);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.selected_setting__time;
                if (new_val) lv_obj_add_flag(objects.selected_setting__time, LV_OBJ_FLAG_HIDDEN);
                else lv_obj_clear_flag(objects.selected_setting__time, LV_OBJ_FLAG_HIDDEN);
                tick_value_change_obj = NULL;
            }
        }
        {
            bool new_val = get_var_settings_setting_time_checked_autoset();
            bool cur_val = lv_obj_has_state(objects.time_auto_set_checkbox, LV_STATE_CHECKED);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.time_auto_set_checkbox;
                if (new_val) lv_obj_add_state(objects.time_auto_set_checkbox, LV_STATE_CHECKED);
                else lv_obj_clear_state(objects.time_auto_set_checkbox, LV_STATE_CHECKED);
                tick_value_change_obj = NULL;
            }
        }
        {
            const char *new_val = get_var_settings_setting_time_new_time();
            const char *cur_val = lv_textarea_get_text(objects.setting_time_input);
            if (strcmp(new_val, cur_val) != 0) {
                tick_value_change_obj = objects.setting_time_input;
                lv_textarea_set_text(objects.setting_time_input, new_val);
                tick_value_change_obj = NULL;
            }
        }
        {
            int32_t new_val = get_var_settings_setting_time_selected_month();
            int32_t cur_val = lv_dropdown_get_selected(objects.date_input__month);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.date_input__month;
                lv_dropdown_set_selected(objects.date_input__month, new_val);
                tick_value_change_obj = NULL;
            }
        }
        {
            int32_t new_val = get_var_settings_setting_time_selected_day();
            int32_t cur_val = lv_dropdown_get_selected(objects.date_input__day);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.date_input__day;
                lv_dropdown_set_selected(objects.date_input__day, new_val);
                tick_value_change_obj = NULL;
            }
        }
        {
            int32_t new_val = get_var_settings_setting_time_selected_year();
            int32_t cur_val = lv_dropdown_get_selected(objects.date_input__year);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.date_input__year;
                lv_dropdown_set_selected(objects.date_input__year, new_val);
                tick_value_change_obj = NULL;
            }
        }
        {
            bool new_val = get_var_settings_hide_setting_alarm();
            bool cur_val = lv_obj_has_flag(objects.selected_setting__alarm, LV_OBJ_FLAG_HIDDEN);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.selected_setting__alarm;
                if (new_val) lv_obj_add_flag(objects.selected_setting__alarm, LV_OBJ_FLAG_HIDDEN);
                else lv_obj_clear_flag(objects.selected_setting__alarm, LV_OBJ_FLAG_HIDDEN);
                tick_value_change_obj = NULL;
            }
        }
        {
            int32_t new_val = get_var_settings_setting_alarm_selected_repeats();
            int32_t cur_val = lv_dropdown_get_selected(objects.obj12);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.obj12;
                lv_dropdown_set_selected(objects.obj12, new_val);
                tick_value_change_obj = NULL;
            }
        }
        {
            int32_t new_val = get_var_settings_setting_alarm_selected_repeat_after();
            int32_t cur_val = lv_dropdown_get_selected(objects.alarm_select_repeats_1);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.alarm_select_repeats_1;
                lv_dropdown_set_selected(objects.alarm_select_repeats_1, new_val);
                tick_value_change_obj = NULL;
            }
        }
        {
            bool new_val = get_var_settings_hide_setting_audio();
            bool cur_val = lv_obj_has_flag(objects.selected_setting__audio, LV_OBJ_FLAG_HIDDEN);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.selected_setting__audio;
                if (new_val) lv_obj_add_flag(objects.selected_setting__audio, LV_OBJ_FLAG_HIDDEN);
                else lv_obj_clear_flag(objects.selected_setting__audio, LV_OBJ_FLAG_HIDDEN);
                tick_value_change_obj = NULL;
            }
        }
        {
            bool new_val = get_var_settings_setting_audio_checked_alarm_over_aux();
            bool cur_val = lv_obj_has_state(objects.audio_play_alarm_over_aux, LV_STATE_CHECKED);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.audio_play_alarm_over_aux;
                if (new_val) lv_obj_add_state(objects.audio_play_alarm_over_aux, LV_STATE_CHECKED);
                else lv_obj_clear_state(objects.audio_play_alarm_over_aux, LV_STATE_CHECKED);
                tick_value_change_obj = NULL;
            }
        }
        {
            const char *new_val = get_var_settings_setting_audio_music_selection();
            const char *cur_val = lv_dropdown_get_options(objects.audio_select_music);
            if (strcmp(new_val, cur_val) != 0) {
                tick_value_change_obj = objects.audio_select_music;
                lv_dropdown_close(objects.audio_select_music); // let the data load into the dropdown menu
                lv_dropdown_set_options(objects.audio_select_music, new_val);
                lv_dropdown_open(objects.audio_select_music);
                tick_value_change_obj = NULL;
            }
        }
        {
            {
                int32_t new_val = get_var_settings_setting_audio_alarm_volume_value();
                int32_t cur_val = lv_slider_get_value(objects.audio_alarm_volume_slider);
                if (new_val != cur_val) {
                    tick_value_change_obj = objects.audio_alarm_volume_slider;
                    lv_slider_set_value(objects.audio_alarm_volume_slider, new_val, LV_ANIM_OFF);
                    tick_value_change_obj = NULL;
                }
            }
            {
                int32_t new_val = get_var_settings_setting_audio_auxin_volume_value();
                int32_t cur_val = lv_slider_get_value(objects.audio_aux_in_volume_slider);
                if (new_val != cur_val) {
                    tick_value_change_obj = objects.audio_aux_in_volume_slider;
                    lv_slider_set_value(objects.audio_aux_in_volume_slider, new_val, LV_ANIM_OFF);
                    tick_value_change_obj = NULL;
                }
            }
            {
                bool new_val = get_var_settings_hide_setting_wifi();
                bool cur_val = lv_obj_has_flag(objects.selected_setting__wi_fi, LV_OBJ_FLAG_HIDDEN);
                if (new_val != cur_val) {
                    tick_value_change_obj = objects.selected_setting__wi_fi;
                    if (new_val) lv_obj_add_flag(objects.selected_setting__wi_fi, LV_OBJ_FLAG_HIDDEN);
                    else lv_obj_clear_flag(objects.selected_setting__wi_fi, LV_OBJ_FLAG_HIDDEN);
                    tick_value_change_obj = NULL;
                }
            }
            {
                bool new_val = get_var_settings_hide_setting_other();
                bool cur_val = lv_obj_has_flag(objects.selected_setting__other, LV_OBJ_FLAG_HIDDEN);
                if (new_val != cur_val) {
                    tick_value_change_obj = objects.selected_setting__other;
                    if (new_val) lv_obj_add_flag(objects.selected_setting__other, LV_OBJ_FLAG_HIDDEN);
                    else lv_obj_clear_flag(objects.selected_setting__other, LV_OBJ_FLAG_HIDDEN);
                    tick_value_change_obj = NULL;
                }
            }
        }
    }
        

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_set_alarm();
    create_screen_set_timer();
    create_screen_set_stopwatch();
    create_screen_set_settings();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_set_alarm,
    tick_screen_set_timer,
    tick_screen_set_stopwatch,
    tick_screen_set_settings,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
    tick_popup();
}
