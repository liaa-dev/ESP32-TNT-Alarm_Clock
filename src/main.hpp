#ifdef __cplusplus
extern "C" {
#endif

extern void create_wi_fi_table();
extern void delete_wi_fi_table();
extern bool connectToWiFi(const char *ssid, const char *password);
extern void printlong(unsigned long value);
extern void print(const char *value);
extern void restart_esp();
extern bool calibrate_touch();

#ifdef __cplusplus
}
#endif