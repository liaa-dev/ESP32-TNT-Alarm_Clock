#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

objects_t objects;
lv_obj_t *tick_value_change_obj;

static void event_handler_cb_set_alarm_next_screen_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_change_to_set_alarm_screen(e);
    }
}

static void event_handler_cb_set_alarm_next_screen_2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_change_to_main_screen(e);
    }
}

static void event_handler_cb_main_next_screen(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_change_to_set_alarm_screen(e);
    }
}

void create_screen_set_alarm() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.set_alarm = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff6053), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(obj, &ui_font_smallpixel7_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Title
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.title = obj;
            lv_obj_set_pos(obj, 122, 23);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Alarm");
            lv_obj_set_style_text_font(obj, &ui_font_smallpixel7_128, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Description
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.description = obj;
            lv_obj_set_pos(obj, 107, 112);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Set an alarm,\nfor a specific time.");
            apply_style_style_smallpixel7_32(obj);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Time Input
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.time_input = obj;
            lv_obj_set_pos(obj, 97, 164);
            lv_obj_set_size(obj, 92, 44);
            lv_textarea_set_accepted_chars(obj, "1234568789");
            lv_textarea_set_max_length(obj, 5);
            lv_textarea_set_placeholder_text(obj, "99:99");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_text_font(obj, &ui_font_smallpixel7_32, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Next Screen_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.next_screen_1 = obj;
            lv_obj_set_pos(obj, 425, 112);
            lv_obj_set_size(obj, 55, 96);
            lv_obj_add_event_cb(obj, event_handler_cb_set_alarm_next_screen_1, LV_EVENT_ALL, 0);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN);
            lv_obj_set_style_bg_image_src(obj, &img_arrow_right_24, LV_PART_MAIN | LV_STATE_DEFAULT);
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
            lv_obj_set_style_bg_image_src(obj, &img_arrow_left_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Reason
            lv_obj_t *obj = lv_dropdown_create(parent_obj);
            objects.reason = obj;
            lv_obj_set_pos(obj, 240, 169);
            lv_obj_set_size(obj, 150, 35);
            lv_dropdown_set_options(obj, "Wake up!\nAppointment\nCustom (bluetooth)");
            lv_obj_set_style_text_font(obj, &ui_font_smallpixel7_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Plus Time
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.plus_time = obj;
            lv_obj_set_pos(obj, 199, 164);
            lv_obj_set_size(obj, 20, 20);
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
            // Dropdown Fix
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.dropdown_fix = obj;
            lv_obj_set_pos(obj, 366, 179);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_double_arrow_down_16);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_image_recolor(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_image_recolor_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 122, 239);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff19d554), LV_PART_MAIN | LV_STATE_DEFAULT);
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
    }
}

void tick_screen_set_alarm() {
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
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    lv_obj_set_pos(obj, 68, 71);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_partly_cloudy_day);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_margin_top(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 10, 48);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "12°C");
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_IGNORE_LAYOUT);
                    apply_style_style_smallpixel7_32(obj);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 19, 25);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "13:43");
                    lv_obj_set_style_text_font(obj, &ui_font_smallpixel_148, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Date
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.date = obj;
            lv_obj_set_pos(obj, 80, 145);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Monday, May 3rd");
            lv_obj_set_style_text_font(obj, &ui_font_smallpixel7_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_letter_space(obj, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
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
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL_CIRCULAR);
                    lv_label_set_text(obj, "Playing: The Beatles - Hey Jude");
                    apply_style_style_smallpixel7_32(obj);
                }
                {
                    lv_obj_t *obj = lv_bar_create(parent_obj);
                    lv_obj_set_pos(obj, -18, 0);
                    lv_obj_set_size(obj, 192, 8);
                    lv_bar_set_value(obj, 75, LV_ANIM_OFF);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                    lv_obj_set_style_bg_image_src(obj, &img_minecraft_xp_bar, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_image_src(obj, &img_minecraft_xp_bar_filled, LV_PART_INDICATOR | LV_STATE_DEFAULT);
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
            lv_obj_set_style_bg_image_src(obj, &img_arrow_right_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Info
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.info = obj;
            lv_obj_set_pos(obj, 75, 195);
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
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_img_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_img_set_src(obj, &img_alarm_32);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_margin_right(obj, -10, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 120, 50);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            apply_style_style_container(obj);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "06:30");
                                    apply_style_style_smallpixel7_32(obj);
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Wake up!");
                                    apply_style_style_smallpixel7_32(obj);
                                }
                            }
                        }
                    }
                }
                {
                    // Spacer
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.spacer = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 2, 60);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_margin_right(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_margin_left(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // Action
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.action = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 215, 60);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    apply_style_style_container(obj);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_img_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_img_set_src(obj, &img_chronometer_32);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_margin_right(obj, -25, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 120, 50);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            apply_style_style_container(obj);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Action");
                                    apply_style_style_smallpixel7_32(obj);
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "None");
                                    apply_style_style_smallpixel7_32(obj);
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
}


void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_set_alarm();
    create_screen_main();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_set_alarm,
    tick_screen_main,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
