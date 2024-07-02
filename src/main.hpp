#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

uint16_t calData[5];

extern void *sd_dir_open(lv_fs_drv_t *drv, const char *dirpath);

extern void create_wi_fi_table();
extern void delete_wi_fi_table();
extern bool connectToWiFi(const char *ssid, const char *password);
extern void printlong(unsigned long value);
extern void print(const char *value);
void printuint16t(uint16_t value);
extern void restart_esp();
extern void calibrate_touch();

#ifdef __cplusplus
}
#endif