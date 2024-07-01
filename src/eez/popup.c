#include "popup.h"
#include "actions.h"
#include "styles.h"
#include <Arduino.h>

unsigned long popup_auto_close_after = 5000;
unsigned long popup_start_time = 0;
bool popup_do_auto_close = false;

lv_obj_t *popup;
lv_obj_t *popup_close_bar;

void close_popup();
bool exists_popup();

static void event_handler_cb_set_popup_close(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        close_popup();
    }
}

static void event_handler_cb_set_popup_button(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_RELEASED) {
        action_popup_button_pressed(e);
    }
}

static void create_popup(lv_obj_t* parent, const lv_img_dsc_t* title_img, const char* message, const char* scnd_message, const char* btn_txt, const lv_color_t btn_color, const bool add_btn_close, const bool do_auto_close, const unsigned long auto_close_after) {
    if(exists_popup()) close_popup();

    popup_do_auto_close = do_auto_close;
    popup_auto_close_after = auto_close_after;
    lv_obj_t *obj = lv_obj_create(parent);
    popup = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(obj, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_center(obj);
            lv_obj_set_size(obj, 320, 220);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff171717), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, -16, -16);
                    lv_obj_set_size(obj, 320, 205);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    apply_style_container(obj);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_img_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_img_set_src(obj, title_img);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                        }
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, -17, 80);
                            lv_obj_set_size(obj, 320, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                            lv_label_set_text(obj, message);
                            apply_style_smallpixel7_32(obj);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            if(scnd_message != NULL)
                            {
                                lv_obj_t *obj = lv_label_create(parent_obj);
                                lv_obj_set_pos(obj, -17, 80);
                                lv_obj_set_size(obj, 300, LV_SIZE_CONTENT);
                                lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL_CIRCULAR);
                                lv_label_set_text(obj, scnd_message);
                                apply_style_smallpixel7_32(obj);
                                lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            }
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 320, 50);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            apply_style_container(obj);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    if(btn_txt != NULL) {
                                        /* Custom Button */
                                        lv_obj_t *obj = lv_btn_create(parent_obj);
                                        lv_obj_set_size(obj, 100, 50);
                                        lv_obj_add_event_cb(obj, event_handler_cb_set_popup_button, LV_EVENT_ALL, 0);
                                        lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                        lv_obj_set_style_bg_color(obj, btn_color, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        {
                                            lv_obj_t *parent_obj = obj;
                                            {
                                                lv_obj_t *obj = lv_label_create(parent_obj);
                                                lv_obj_center(obj);
                                                lv_label_set_text(obj, btn_txt);
                                                lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                apply_style_smallpixel7_32(obj);
                                            }
                                        }
                                    }
                                    if(add_btn_close) {
                                        /* Close Button */
                                        lv_obj_t *obj = lv_btn_create(parent_obj);
                                        lv_obj_set_size(obj, 100, 50);
                                        lv_obj_add_event_cb(obj, event_handler_cb_set_popup_close, LV_EVENT_ALL, 0);
                                        lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                        lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2626), LV_PART_MAIN | LV_STATE_DEFAULT);
                                        {
                                            lv_obj_t *parent_obj = obj;
                                            {
                                                lv_obj_t *obj = lv_label_create(parent_obj);
                                                lv_obj_center(obj);
                                                lv_label_set_text(obj, "Close");
                                                lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                apply_style_smallpixel7_32(obj);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_bar_create(parent_obj);
                    popup_close_bar = obj;
                    lv_obj_set_pos(obj, 19, 193);
                    lv_obj_set_size(obj, 250, 5);
                    lv_bar_set_value(obj, 100, LV_ANIM_OFF);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_IGNORE_LAYOUT|LV_OBJ_FLAG_CLICKABLE);
                    lv_obj_set_style_bg_opa(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void create_popup_with_custom_button(lv_obj_t* parent, const lv_img_dsc_t* title_img, const char* message, const char* btn_txt, const lv_color_t btn_color, const bool add_close_btn, const bool do_auto_close, const unsigned long auto_close_after) {
    create_popup(parent, title_img, message, NULL, btn_txt, btn_color, add_close_btn, do_auto_close, auto_close_after);
}

void create_popup_with_second_message(lv_obj_t* parent, const lv_img_dsc_t* title_img, const char* message, const char* second_message, const bool add_close_btn, const bool do_auto_close, const unsigned long auto_close_after) {
    create_popup(parent, title_img, message, second_message, NULL, lv_color_black(), add_close_btn, do_auto_close, auto_close_after);
}

void create_popup_with_custom_button_and_second_message(lv_obj_t* parent, const lv_img_dsc_t* title_img, const char* message, const char* second_message, const char* btn_txt, const lv_color_t btn_color, const bool add_close_btn, const bool do_auto_close, const unsigned long auto_close_after) {
    create_popup(parent, title_img, message, second_message, btn_txt, btn_color, add_close_btn, do_auto_close, auto_close_after);
}

void create_popup_with_message(lv_obj_t* parent, const lv_img_dsc_t* title_img, const char* message, const bool add_close_btn, const bool do_auto_close, const unsigned long auto_close_after) {
    create_popup(parent, title_img, message, NULL, NULL, lv_color_black(), add_close_btn, do_auto_close, auto_close_after);
}

void close_popup() {
    if(popup != NULL) {
        print("called!");
        popup_auto_close_after = 0;
        popup_do_auto_close = false;
        popup_start_time = 0;
        lv_obj_del(popup);
        popup = NULL;
    }
}

bool exists_popup() {
    if(popup != NULL) {
        return true;
    }else return false;
}

void tick_popup() {
    if(exists_popup() && popup_do_auto_close) {
        if(popup_start_time == 0) {
            popup_start_time = millis();
        }
        if(millis() - popup_start_time >= popup_auto_close_after) {
            popup_start_time = 0;
            close_popup();
        }

        lv_bar_set_value(popup_close_bar, lv_map(popup_auto_close_after - (millis() - popup_start_time), 0, popup_auto_close_after, 0, 100), LV_ANIM_ON);
    }
}