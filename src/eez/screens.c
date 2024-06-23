#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

objects_t objects;
lv_obj_t *tick_value_change_obj;

static void event_handler_cb_main_obj3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
}

static void event_handler_cb_main_next_screen(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_go_to_set_alarm_screen(e);
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

static void event_handler_cb_set_alarm_next_screen_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_go_to_timer_screen(e);
    }
}

static void event_handler_cb_set_alarm_next_screen_2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_go_back(e);
    }
}

static void event_handler_cb_set_alarm_plus_time(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_alarm_plus_pressed(e);
    }
    if (event == LV_EVENT_LONG_PRESSED) {
        action_alarm_plus_long_pressed(e);
    }
}

static void event_handler_cb_set_alarm_minus_time(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_alarm_minus_pressed(e);
    }
    if (event == LV_EVENT_LONG_PRESSED) {
        action_alarm_minus_long_pressed(e);
    }
}

static void event_handler_cb_set_timer_next_screen_3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_go_to_stopwatch_screen(e);
    }
}

static void event_handler_cb_set_timer_next_screen_4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_go_back(e);
    }
}

static void event_handler_cb_set_timer_obj8(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_arc_get_value(ta);
            set_var_timer_value(value);
        }
    }
}

static void event_handler_cb_set_stopwatch_time_input_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            set_var_stopwatch_time(value);
        }
    }
}

static void event_handler_cb_set_stopwatch_next_screen_5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_go_to_settings_screen(e);
    }
}

static void event_handler_cb_set_stopwatch_next_screen_6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_go_back(e);
    }
}

static void event_handler_cb_set_settings_next_screen_7(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_go_to_main_screen(e);
    }
}

static void event_handler_cb_set_settings_next_screen_8(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_go_back(e);
    }
}

static void event_handler_cb_set_settings_setting__time(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_settings_time_selected(e);
    }
}

static void event_handler_cb_set_settings_setting__wi_fi(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_settings_wi_fi_selected(e);
    }
}

static void event_handler_cb_set_settings_setting__bluetooth(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_settings_bluetooth_selected(e);
    }
}

static void event_handler_cb_set_settings_setting__other(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_settings_other_selected(e);
    }
}

static void event_handler_cb_set_settings_auto_set(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            set_var_settings_time_auto_set_checked(value);
        }
    }
}

static void event_handler_cb_set_settings_setting_time_input(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            set_var_settings_time_changed_time(value);
        }
    }
}

static void event_handler_cb_set_settings_plus_time_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_alarm_plus_pressed(e);
    }
    if (event == LV_EVENT_LONG_PRESSED) {
        action_alarm_plus_long_pressed(e);
    }
}

static void event_handler_cb_set_settings_minus_time_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_PRESSED) {
        action_alarm_minus_pressed(e);
    }
    if (event == LV_EVENT_LONG_PRESSED) {
        action_alarm_minus_long_pressed(e);
    }
}

static void event_handler_cb_set_settings_date_input__month(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_dropdown_get_selected(ta);
            set_var_settings_time_month_selected(value);
        }
    }
}

static void event_handler_cb_set_settings_date_input__day(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_dropdown_get_selected(ta);
            set_var_settings_time_day_selected(value);
        }
    }
}

static void event_handler_cb_set_settings_date_input__year(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_dropdown_get_selected(ta);
            set_var_settings_time_year_selected(value);
        }
    }
}

static void event_handler_cb_set_settings_setting__pair(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_settings_bt_pair_pressed(e);
    }
}

static void event_handler_cb_set_settings_setting__connect(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_settings_bt_connect_pressed(e);
    }
}

static void event_handler_cb_set_settings_setting__recalibrate_touch(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_settings_other_recalibrate_pressed(e);
    }
}

static void event_handler_cb_set_settings_setting__reset(lv_event_t *e) {
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
            // Clock
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.clock = obj;
            lv_obj_set_pos(obj, 15, 40);
            lv_obj_set_size(obj, 450, 89);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            apply_style_style_container(obj);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, "E:/images/partly-cloudy-day_75.bin");
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj0 = obj;
                    lv_obj_set_pos(obj, 10, 48);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_IGNORE_LAYOUT);
                    apply_style_style_smallpixel7_32(obj);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj1 = obj;
                    lv_obj_set_pos(obj, 19, 25);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_font(obj, &ui_font_smallpixel7_num_148, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Date
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.date = obj;
            lv_obj_set_pos(obj, 40, 146);
            lv_obj_set_size(obj, 400, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
            lv_obj_set_style_text_font(obj, &ui_font_bm_army_32, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff171717), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Status Bar
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.status_bar = obj;
            lv_obj_set_pos(obj, 144, 270);
            lv_obj_set_size(obj, 192, 50);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            apply_style_style_container(obj);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj2 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL_CIRCULAR);
                    lv_label_set_text(obj, "");
                    apply_style_style_smallpixel7_32(obj);
                    lv_obj_set_style_text_font(obj, &ui_font_bm_army_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_bar_create(parent_obj);
                    objects.obj3 = obj;
                    lv_obj_set_pos(obj, -18, 0);
                    lv_obj_set_size(obj, 192, 8);
                    lv_obj_add_event_cb(obj, event_handler_cb_main_obj3, LV_EVENT_ALL, 0);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                    lv_obj_set_style_bg_img_src(obj, "E:/images/minecraft_xp_bar.bin", LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_img_src(obj, "E:/images/minecraft_xp_bar_filled.bin", LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Next Screen
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.next_screen = obj;
            lv_obj_set_pos(obj, 425, 112);
            lv_obj_set_size(obj, 55, 96);
            lv_obj_add_event_cb(obj, event_handler_cb_main_next_screen, LV_EVENT_ALL, 0);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN);
            lv_obj_set_style_bg_img_src(obj, "E:/images/arrow_right_24.bin", LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Info
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.info = obj;
            lv_obj_set_pos(obj, 75, 197);
            lv_obj_set_size(obj, 330, 60);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            apply_style_style_container(obj);
            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_AROUND, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Alarm
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.alarm = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 215, 60);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    apply_style_style_container(obj);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, -10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_img_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_img_set_src(obj, "E:/images/alarm_32.bin");
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
                            apply_style_style_container(obj);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 24, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj4 = obj;
                                    lv_obj_set_pos(obj, 42, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "");
                                    apply_style_style_smallpixel7_32(obj);
                                    lv_obj_set_style_text_font(obj, &ui_font_bm_army_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj5 = obj;
                                    lv_obj_set_pos(obj, 42, 0);
                                    lv_obj_set_size(obj, 114, LV_SIZE_CONTENT);
                                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                                    lv_label_set_text(obj, "");
                                    apply_style_style_smallpixel7_32(obj);
                                    lv_obj_set_style_text_font(obj, &ui_font_bm_army_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                    }
                }
                {
                    // Spacer
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.spacer = obj;
                    lv_obj_set_pos(obj, -1, 0);
                    lv_obj_set_size(obj, 2, 60);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // Action
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.action = obj;
                    lv_obj_set_pos(obj, -68, 0);
                    lv_obj_set_size(obj, 215, 60);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    apply_style_style_container(obj);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_img_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_img_set_src(obj, "E:/images/chronometer_32.bin");
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff171717), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 1, 16);
                            lv_obj_set_size(obj, 119, 50);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj6 = obj;
                                    lv_obj_set_pos(obj, -16, -10);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "");
                                    apply_style_style_smallpixel7_32(obj);
                                    lv_obj_set_style_text_font(obj, &ui_font_bm_army_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj7 = obj;
                                    lv_obj_set_pos(obj, -16, 10);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "");
                                    apply_style_style_smallpixel7_32(obj);
                                    lv_obj_set_style_text_font(obj, &ui_font_bm_army_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void tick_screen_main() {
    {
        const char *new_val = get_var_digital_temperature();
        const char *cur_val = lv_label_get_text(objects.obj0);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj0;
            lv_label_set_text(objects.obj0, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_digital_time();
        const char *cur_val = lv_label_get_text(objects.obj1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj1;
            lv_label_set_text(objects.obj1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_digital_date();
        const char *cur_val = lv_label_get_text(objects.date);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.date;
            lv_label_set_text(objects.date, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_status_bar_text();
        const char *cur_val = lv_label_get_text(objects.obj2);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj2;
            lv_label_set_text(objects.obj2, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = get_var_status_bar_value();
        int32_t cur_val = lv_bar_get_value(objects.obj3);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj3;
            lv_bar_set_value(objects.obj3, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_alarm_time();
        const char *cur_val = lv_label_get_text(objects.obj4);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj4;
            lv_label_set_text(objects.obj4, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_alarm_reason();
        const char *cur_val = lv_label_get_text(objects.obj5);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj5;
            lv_label_set_text(objects.obj5, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_running_action();
        const char *cur_val = lv_label_get_text(objects.obj6);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj6;
            lv_label_set_text(objects.obj6, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_running_action_time();
        const char *cur_val = lv_label_get_text(objects.obj7);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj7;
            lv_label_set_text(objects.obj7, new_val);
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
            // Title
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.title = obj;
            lv_obj_set_pos(obj, 122, 10);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Alarm");
            lv_obj_set_style_text_font(obj, &ui_font_smallpixel7_128, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Description
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.description = obj;
            lv_obj_set_pos(obj, 107, 92);
            lv_obj_set_size(obj, 267, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Set an alarm,\nfor a specific time");
            apply_style_style_smallpixel7_32(obj);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_bm_army_20, LV_PART_MAIN | LV_STATE_DEFAULT);
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
            // Next Screen_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.next_screen_1 = obj;
            lv_obj_set_pos(obj, 425, 112);
            lv_obj_set_size(obj, 55, 96);
            lv_obj_add_event_cb(obj, event_handler_cb_set_alarm_next_screen_1, LV_EVENT_ALL, 0);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN);
            lv_obj_set_style_bg_img_src(obj, "E:/images/arrow_right_24.bin", LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Next Screen_2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.next_screen_2 = obj;
            lv_obj_set_pos(obj, 0, 112);
            lv_obj_set_size(obj, 55, 96);
            lv_obj_add_event_cb(obj, event_handler_cb_set_alarm_next_screen_2, LV_EVENT_ALL, 0);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN);
            lv_obj_set_style_bg_img_src(obj, "E:/images/arrow_left_24.bin", LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Plus Time
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.plus_time = obj;
            lv_obj_set_pos(obj, 199, 164);
            lv_obj_set_size(obj, 20, 20);
            lv_obj_add_event_cb(obj, event_handler_cb_set_alarm_plus_time, LV_EVENT_ALL, 0);
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
                    lv_obj_set_pos(obj, -13, -10);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "+");
                    apply_style_style_smallpixel7_32(obj);
                }
            }
        }
        {
            // Minus Time
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.minus_time = obj;
            lv_obj_set_pos(obj, 199, 188);
            lv_obj_set_size(obj, 20, 20);
            lv_obj_add_event_cb(obj, event_handler_cb_set_alarm_minus_time, LV_EVENT_ALL, 0);
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
                    lv_obj_set_pos(obj, -13, -10);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "-");
                    apply_style_style_smallpixel7_32(obj);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 122, 239);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00ff53), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 13, 5);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "SET");
                    apply_style_style_smallpixel7_32(obj);
                    lv_obj_set_style_text_font(obj, &ui_font_smallpixel7_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 259, 239);
            lv_obj_set_size(obj, 100, 50);
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
                    apply_style_style_smallpixel7_32(obj);
                }
            }
        }
        {
            lv_obj_t *obj = lv_dropdown_create(parent_obj);
            lv_obj_set_pos(obj, 240, 165);
            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
            lv_dropdown_set_options(obj, "No Reason\nWake up!\nAppointment\nCustom (bluetooth)");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
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
            // Title_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.title_1 = obj;
            lv_obj_set_pos(obj, 122, 10);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Timer");
            lv_obj_set_style_text_font(obj, &ui_font_smallpixel7_128, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Description_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.description_1 = obj;
            lv_obj_set_pos(obj, 107, 92);
            lv_obj_set_size(obj, 267, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Set a timer,\nfor up to 3 hours");
            apply_style_style_smallpixel7_32(obj);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_bm_army_20, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Next Screen_3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.next_screen_3 = obj;
            lv_obj_set_pos(obj, 425, 112);
            lv_obj_set_size(obj, 55, 96);
            lv_obj_add_event_cb(obj, event_handler_cb_set_timer_next_screen_3, LV_EVENT_ALL, 0);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN);
            lv_obj_set_style_bg_img_src(obj, "E:/images/arrow_right_24.bin", LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Next Screen_4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.next_screen_4 = obj;
            lv_obj_set_pos(obj, 0, 112);
            lv_obj_set_size(obj, 55, 96);
            lv_obj_add_event_cb(obj, event_handler_cb_set_timer_next_screen_4, LV_EVENT_ALL, 0);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN);
            lv_obj_set_style_bg_img_src(obj, "E:/images/arrow_left_24.bin", LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 55, 183);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00ff53), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 13, 5);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "SET");
                    apply_style_style_smallpixel7_32(obj);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 325, 183);
            lv_obj_set_size(obj, 100, 50);
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
                    apply_style_style_smallpixel7_32(obj);
                }
            }
        }
        {
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.obj8 = obj;
            lv_obj_set_pos(obj, 165, 141);
            lv_obj_set_size(obj, 150, 150);
            lv_arc_set_bg_end_angle(obj, 60);
            lv_arc_set_rotation(obj, -1);
            lv_obj_add_event_cb(obj, event_handler_cb_set_timer_obj8, LV_EVENT_ALL, 0);
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
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj9 = obj;
                    lv_obj_set_pos(obj, 21, 61);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    apply_style_style_smallpixel7_48(obj);
                }
            }
        }
    }
}

void tick_screen_set_timer() {
    {
        int32_t new_val = get_var_timer_value();
        int32_t cur_val = lv_arc_get_value(objects.obj8);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj8;
            lv_arc_set_value(objects.obj8, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_timer_time();
        const char *cur_val = lv_label_get_text(objects.obj9);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj9;
            lv_label_set_text(objects.obj9, new_val);
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
    lv_obj_set_style_text_font(obj, &ui_font_bm_army_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Title_2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.title_2 = obj;
            lv_obj_set_pos(obj, 10, 10);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Stopwatch");
            lv_obj_set_style_text_font(obj, &ui_font_smallpixel7_128, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Description_2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.description_2 = obj;
            lv_obj_set_pos(obj, 107, 112);
            lv_obj_set_size(obj, 267, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Start a stopwatch");
            apply_style_style_smallpixel7_32(obj);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_bm_army_20, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Time Input_1
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.time_input_1 = obj;
            lv_obj_set_pos(obj, 152, 160);
            lv_obj_set_size(obj, 177, 44);
            lv_textarea_set_accepted_chars(obj, "01234568789:");
            lv_textarea_set_max_length(obj, 12);
            lv_textarea_set_placeholder_text(obj, "00:00:00:00");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_set_stopwatch_time_input_1, LV_EVENT_ALL, 0);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_SNAPPABLE|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN);
            lv_obj_set_style_text_font(obj, &ui_font_smallpixel7_32, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Next Screen_5
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.next_screen_5 = obj;
            lv_obj_set_pos(obj, 425, 112);
            lv_obj_set_size(obj, 55, 96);
            lv_obj_add_event_cb(obj, event_handler_cb_set_stopwatch_next_screen_5, LV_EVENT_ALL, 0);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN);
            lv_obj_set_style_bg_img_src(obj, "E:/images/arrow_right_24.bin", LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Next Screen_6
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.next_screen_6 = obj;
            lv_obj_set_pos(obj, 0, 112);
            lv_obj_set_size(obj, 55, 96);
            lv_obj_add_event_cb(obj, event_handler_cb_set_stopwatch_next_screen_6, LV_EVENT_ALL, 0);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN);
            lv_obj_set_style_bg_img_src(obj, "E:/images/arrow_left_24.bin", LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj10 = obj;
            lv_obj_set_pos(obj, 122, 239);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00ff53), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -1, 5);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "START");
                    apply_style_style_smallpixel7_32(obj);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 259, 239);
            lv_obj_set_size(obj, 100, 50);
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
                    apply_style_style_smallpixel7_32(obj);
                }
            }
        }
    }
}

void tick_screen_set_stopwatch() {
    {
        const char *new_val = get_var_stopwatch_time();
        const char *cur_val = lv_textarea_get_text(objects.time_input_1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.time_input_1;
            lv_textarea_set_text(objects.time_input_1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = get_var_stopwatch_hide_start_btn();
        bool cur_val = lv_obj_has_flag(objects.obj10, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj10;
            if (new_val) lv_obj_add_flag(objects.obj10, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.obj10, LV_OBJ_FLAG_HIDDEN);
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
            // Title_3
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.title_3 = obj;
            lv_obj_set_pos(obj, 29, 10);
            lv_obj_set_size(obj, 422, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
            lv_obj_set_style_text_font(obj, &ui_font_smallpixel7_128, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Next Screen_7
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.next_screen_7 = obj;
            lv_obj_set_pos(obj, 425, 112);
            lv_obj_set_size(obj, 55, 96);
            lv_obj_add_event_cb(obj, event_handler_cb_set_settings_next_screen_7, LV_EVENT_ALL, 0);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN);
            lv_obj_set_style_bg_img_src(obj, "E:/images/arrow_right_24.bin", LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Next Screen_8
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.next_screen_8 = obj;
            lv_obj_set_pos(obj, 0, 112);
            lv_obj_set_size(obj, 55, 96);
            lv_obj_add_event_cb(obj, event_handler_cb_set_settings_next_screen_8, LV_EVENT_ALL, 0);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN);
            lv_obj_set_style_bg_img_src(obj, "E:/images/arrow_left_24.bin", LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Select Setting
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.select_setting = obj;
            lv_obj_set_pos(obj, 140, 100);
            lv_obj_set_size(obj, 200, 210);
            apply_style_style_container(obj);
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
                            apply_style_style_smallpixel7_32(obj);
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
                            apply_style_style_smallpixel7_32(obj);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // Setting: Bluetooth
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.setting__bluetooth = obj;
                    lv_obj_set_pos(obj, 165, 135);
                    lv_obj_set_size(obj, 150, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_set_settings_setting__bluetooth, LV_EVENT_ALL, 0);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0082fc), LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, -4, 5);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Bluetooth");
                            apply_style_style_smallpixel7_32(obj);
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
                            apply_style_style_smallpixel7_32(obj);
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
            apply_style_style_container(obj);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Auto-Set
                    lv_obj_t *obj = lv_checkbox_create(parent_obj);
                    objects.auto_set = obj;
                    lv_obj_set_pos(obj, 69, 109);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_checkbox_set_text(obj, "Auto-Set");
                    lv_obj_add_event_cb(obj, event_handler_cb_set_settings_auto_set, LV_EVENT_ALL, 0);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // Change Time
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.change_time = obj;
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
                                    apply_style_style_smallpixel7_32(obj);
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
                                    apply_style_style_smallpixel7_32(obj);
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
            // Selected Setting: Bluetooth
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.selected_setting__bluetooth = obj;
            lv_obj_set_pos(obj, 140, 100);
            lv_obj_set_size(obj, 200, 210);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            apply_style_style_container(obj);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Setting: Pair
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.setting__pair = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 150, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_set_settings_setting__pair, LV_EVENT_ALL, 0);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 31, 5);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Pair");
                            apply_style_style_smallpixel7_32(obj);
                        }
                    }
                }
                {
                    // Setting: Connect
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.setting__connect = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 150, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_set_settings_setting__connect, LV_EVENT_ALL, 0);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff4caf50), LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 10, 5);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Connect");
                            apply_style_style_smallpixel7_32(obj);
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, -50);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Connected to:");
                    apply_style_style_smallpixel7_32(obj);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj11 = obj;
                    lv_obj_set_pos(obj, 0, -5);
                    lv_obj_set_size(obj, 184, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    apply_style_style_smallpixel7_32(obj);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
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
            apply_style_style_container(obj);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Setting: Recalibrate Touch
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.setting__recalibrate_touch = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 190, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_set_settings_setting__recalibrate_touch, LV_EVENT_ALL, 0);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 2, -5);
                            lv_obj_set_size(obj, 154, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Recalibrate\nTouch");
                            apply_style_style_smallpixel7_32(obj);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // Setting: Reset
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.setting__reset = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 190, 50);
                    lv_obj_add_event_cb(obj, event_handler_cb_set_settings_setting__reset, LV_EVENT_ALL, 0);
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
                            apply_style_style_smallpixel7_32(obj);
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
        const char *cur_val = lv_label_get_text(objects.title_3);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.title_3;
            lv_label_set_text(objects.title_3, new_val);
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
        bool new_val = get_var_settings_hide_time();
        bool cur_val = lv_obj_has_flag(objects.selected_setting__time, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.selected_setting__time;
            if (new_val) lv_obj_add_flag(objects.selected_setting__time, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.selected_setting__time, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = get_var_settings_time_auto_set_checked();
        bool cur_val = lv_obj_has_state(objects.auto_set, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.auto_set;
            if (new_val) lv_obj_add_state(objects.auto_set, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.auto_set, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_settings_time_changed_time();
        const char *cur_val = lv_textarea_get_text(objects.setting_time_input);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.setting_time_input;
            lv_textarea_set_text(objects.setting_time_input, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = get_var_settings_time_month_selected();
        int32_t cur_val = lv_dropdown_get_selected(objects.date_input__month);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.date_input__month;
            lv_dropdown_set_selected(objects.date_input__month, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = get_var_settings_time_day_selected();
        int32_t cur_val = lv_dropdown_get_selected(objects.date_input__day);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.date_input__day;
            lv_dropdown_set_selected(objects.date_input__day, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = get_var_settings_time_year_selected();
        int32_t cur_val = lv_dropdown_get_selected(objects.date_input__year);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.date_input__year;
            lv_dropdown_set_selected(objects.date_input__year, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = get_var_settings_hide_bluetooth();
        bool cur_val = lv_obj_has_flag(objects.selected_setting__bluetooth, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.selected_setting__bluetooth;
            if (new_val) lv_obj_add_flag(objects.selected_setting__bluetooth, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.selected_setting__bluetooth, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = get_var_settings_bt_hide_connect_btn();
        bool cur_val = lv_obj_has_flag(objects.setting__connect, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.setting__connect;
            if (new_val) lv_obj_add_flag(objects.setting__connect, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.setting__connect, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_settings_bt_connected_device_name();
        const char *cur_val = lv_label_get_text(objects.obj11);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj11;
            lv_label_set_text(objects.obj11, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = get_var_settings_hide_other();
        bool cur_val = lv_obj_has_flag(objects.selected_setting__other, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.selected_setting__other;
            if (new_val) lv_obj_add_flag(objects.selected_setting__other, LV_OBJ_FLAG_HIDDEN);
            else lv_obj_clear_flag(objects.selected_setting__other, LV_OBJ_FLAG_HIDDEN);
            tick_value_change_obj = NULL;
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
}
