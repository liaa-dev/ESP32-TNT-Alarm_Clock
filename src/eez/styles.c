#include "styles.h"
#include "images.h"
#include "fonts.h"

void apply_style_style_smallpixel7_20(lv_obj_t *obj) {
    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(obj, &ui_font_smallpixel7_20, LV_PART_MAIN | LV_STATE_DEFAULT);
};
void apply_style_style_smallpixel7_32(lv_obj_t *obj) {
    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(obj, &ui_font_smallpixel7_32, LV_PART_MAIN | LV_STATE_DEFAULT);
};
void apply_style_style_smallpixel7_48(lv_obj_t *obj) {
    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(obj, &ui_font_smallpixel7_48, LV_PART_MAIN | LV_STATE_DEFAULT);
};
void apply_style_style_smallpixel7_64(lv_obj_t *obj) {
    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(obj, &ui_font_smallpixel7_64, LV_PART_MAIN | LV_STATE_DEFAULT);
};
void apply_style_style_container(lv_obj_t *obj) {
    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
};

