#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void create_popup_with_custom_button(const uint16_t id, lv_obj_t* parent, const lv_img_dsc_t* title_img, const char* message, const char* btn_txt, const lv_color_t btn_color, const bool add_close_btn, const bool do_auto_close, const unsigned long auto_close_after);
extern void create_popup_with_second_message(const uint16_t id, lv_obj_t* parent, const lv_img_dsc_t* title_img, const char* message, const char* second_message, const bool add_close_btn, const bool do_auto_close, const unsigned long auto_close_after);
extern void create_popup_with_custom_button_and_second_message(const uint16_t id, lv_obj_t* parent, const lv_img_dsc_t* title_img, const char* message, const char* second_message, const char* btn_txt, const lv_color_t btn_color, const bool add_close_btn, const bool do_auto_close, const unsigned long auto_close_after);
extern void create_popup_with_message(const uint16_t id, lv_obj_t* parent, const lv_img_dsc_t* title_img, const char* message, const bool add_close_btn, const bool do_auto_close, const unsigned long auto_close_after);
extern void close_popup();
extern bool exists_popup();
extern void tick_popup();
extern const uint16_t get_current_popup_id();

#ifdef __cplusplus
}
#endif