#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

uint16_t calData[5];

extern void create_wi_fi_table();
extern void delete_wi_fi_table();
extern bool connectToWiFi(const char *ssid, const char *password);
extern void printlong(unsigned long value);
extern void print(const char *value);
void printuint16t(uint16_t value);
extern const char* fs_dir_list_as_string(const char * dir_path);
extern void restart_esp();
extern void calibrate_touch();
extern const char* readFile(const char *filename);
void writeFile(const char *filename, const char *data);

#ifdef __cplusplus
}
#endif