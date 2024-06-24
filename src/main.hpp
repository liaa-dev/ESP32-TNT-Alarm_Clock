#ifdef __cplusplus
extern "C" {
#endif

extern void create_wi_fi_table();
extern void delete_wi_fi_table();
extern bool connectToWiFi(const char *ssid, const char *password);

#ifdef __cplusplus
}
#endif