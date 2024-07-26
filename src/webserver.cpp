#include <WiFi.h>
#include <ESPAsyncWebserver.h>
#include <SPIFFS.h>
#include <DNSServer.h>

AsyncWebServer server(80);
DNSServer dnsServer;

IPAddress local_ip(192,168,4,1);
IPAddress gateway(192,168,4,1);
IPAddress subnet(255,255,255,0);

String _ssid, _password;
const char* AP_SSID = "ESP32 Alarm Clock";
const char* AP_PASSWORD = "NJhYj3KYJh5GvkLN";

void saveCredentials();
void writeFile(const char* path, const char* message);
String readAFile(const char* path);

void startAPMode() {
    WiFi.mode(WIFI_AP_STA);
    WiFi.softAP(AP_SSID, AP_PASSWORD, 1, 1);
    WiFi.softAPConfig(local_ip, gateway, subnet);
    dnsServer.start(53, "*", WiFi.softAPIP());
    
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(SPIFFS, "/index.html", "text/html");
    });

    server.on("/", HTTP_POST, [](AsyncWebServerRequest *request){
    int params = request->params();
    for (int i = 0; i < params; i++) {
      AsyncWebParameter* p = request->getParam(i);
      if (p->name() == "ssid") {
        _ssid = p->value();
      }
      if (p->name() == "pw") {
        _password = p->value();
      }
    }
    saveCredentials();
    request->send(200, "text/plain", "Credentials saved. Restarting...");
    delay(3000);
    ESP.restart();
  });

    server.begin();

    delay(20);
}

void startWebServer() {
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(SPIFFS, "/index.html", "text/html");
    });
    server.begin();
    Serial.println("Web Server Started in Station Mode");
    Serial.print("ESP32 IP Address: ");
    Serial.println(WiFi.localIP());
}

void saveCredentials() {
    writeFile("/ssid.txt", _ssid.c_str());
    writeFile("/pass.txt", _password.c_str());
}

void writeFile(const char* path, const char* message) {
    File file = SPIFFS.open(path, FILE_WRITE);
    if (!file) return;
    file.print(message);
    file.close();
}

String readAFile(const char* path) {
    File file = SPIFFS.open(path);
    if (!file || file.isDirectory()) return "";
    String content = file.readString();
    file.close();
    return content.c_str();
}