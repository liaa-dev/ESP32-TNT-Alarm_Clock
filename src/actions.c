#include <eez/actions.h>
#include <eez/ui.h>
#include <eez/vars.h>
#include <lvgl/lvgl.h>

void hideSettings();
void wifi();

extern void action_go_to_main_screen(lv_event_t * e) {
    loadScreen(SCREEN_ID_MAIN);
}

extern void action_go_to_set_alarm_screen(lv_event_t * e) {
    loadScreen(SCREEN_ID_SET_ALARM);
}

extern void action_go_to_timer_screen(lv_event_t * e) {
    loadScreen(SCREEN_ID_SET_TIMER);
}
extern void action_go_to_stopwatch_screen(lv_event_t * e) {
    loadScreen(SCREEN_ID_SET_STOPWATCH);
}

extern void action_go_to_settings_screen(lv_event_t * e) {
    loadScreen(SCREEN_ID_SET_SETTINGS);
    hideSettings();
    set_var_settings_title("Settings");
    set_var_settings_hide_selection(false);
}

extern void action_go_back(lv_event_t * e) {
    if(get_current_screen() == SCREEN_ID_SET_SETTINGS) {
        hideSettings();
        set_var_settings_title("Settings");
        set_var_settings_hide_selection(false);

    }else loadScreen(get_current_screen() - 1);
}

extern void action_alarm_plus_long_pressed(lv_event_t * e) {

}
extern void action_alarm_plus_pressed(lv_event_t * e) {

}
extern void action_alarm_minus_long_pressed(lv_event_t * e) {

}
extern void action_alarm_minus_pressed(lv_event_t * e) {

}

extern void action_alarm_set_pressed(lv_event_t * e) {
    set_var_alarm_time("12:00");
}
extern void action_alarm_reset_pressed(lv_event_t * e) {

}
extern void action_timer_set_pressed(lv_event_t * e) {

}
extern void action_timer_reset_pressed(lv_event_t * e) {

}
extern void action_stopwatch_start_pressed(lv_event_t * e) {

}
extern void action_stopwatch_reset_pressed(lv_event_t * e) {

}

extern void action_settings_time_selected(lv_event_t * e) {
    hideSettings();
    set_var_settings_title("Time");
    set_var_settings_hide_time(false);
}
extern void action_settings_wi_fi_selected(lv_event_t * e) {
    hideSettings();
    set_var_settings_title("WiFi");
    set_var_settings_hide_wi_fi(false);
    wifi();
}
extern void action_settings_bluetooth_selected(lv_event_t * e) {
    hideSettings();
    set_var_settings_title("Bluetooth");
    set_var_settings_hide_bluetooth(false);
}
extern void action_settings_other_selected(lv_event_t * e) {
    hideSettings();
    set_var_settings_title("Other");
    set_var_settings_hide_other(false);
}

extern void action_settings_bt_pair_pressed(lv_event_t * e) {

}
extern void action_settings_bt_connect_pressed(lv_event_t * e) {

}
extern void action_settings_bt_disconnect_pressed(lv_event_t * e) {

}
extern void action_settings_other_recalibrate_pressed(lv_event_t * e) {

}
extern void action_settings_other_reset_pressed(lv_event_t * e) {

}

void hideSettings() {
    set_var_settings_hide_selection(true);
    set_var_settings_hide_time(true);
    set_var_settings_hide_wi_fi(true);
    set_var_settings_hide_bluetooth(true);
    set_var_settings_hide_other(true);
}

/* TODO: ADD THIS LATER ON TO SCREENS.C */
lv_obj_t * wifi_table;
void wifi() {
    if(wifi_table != NULL) lv_obj_del(wifi_table);
    wifi_table = lv_table_create(lv_scr_act());
    int pixel_size = 30;
    //lv_table_set_column_width(wifi_table, 0, 300);
    lv_obj_set_pos(wifi_table, 90, 109);
    lv_obj_set_size(wifi_table, 300, 200);
    lv_obj_set_style_text_font(wifi_table, &lv_font_montserrat_20, 0);

    lv_table_set_cell_value(wifi_table, 0, 0, "Nr.");
    lv_table_set_cell_value(wifi_table, 0, 1, "SSID");
    lv_table_set_cell_value(wifi_table, 0, 2, "Sig.");
    lv_table_set_cell_value(wifi_table, 0, 3, "Auth.");

    lv_table_set_column_width(wifi_table, 0, 80);
    lv_table_set_column_width(wifi_table, 1, 120);
    lv_table_set_column_width(wifi_table, 2, 80);
    lv_table_set_column_width(wifi_table, 3, 100);

//int foundNetworks = WiFi.scanNetworks();
    /*for(int i = 0; i < foundNetworks; i++) {
        lv_table_set_cell_value(wifi_table, i, 0, String(i + 1));
        lv_table_set_cell_value(wifi_table, i, 1, WiFi.SSID(i));
        lv_table_set_cell_value(wifi_table, i, 2, WiFi.RSSI(i));
        lv_table_set_cell_value(wifi_table, i, 3, WiFi.encryptionType(i) == WIFI_AUTH_OPEN ? "Open" : "WPA/WPA2");
        delay(10);
    }*/
}