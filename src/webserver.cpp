#include <WiFi.h>
#include <ESPAsyncWebserver.h>
#include <SPIFFS.h>

AsyncWebServer server(80);

IPAddress local_ip(192,168,4,1);
IPAddress gateway(192,168,4,1);
IPAddress subnet(255,255,255,0);

void webserver_init() {
    if(!SPIFFS.begin(true)){
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
    }
    WiFi.softAP("ESP32 Alarm Clock", "NJhYj3KYJh5GvkLN", 1, 1);
    WiFi.softAPConfig(local_ip, gateway, subnet);
    
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(SPIFFS, "/index.html", "text/html");
    });

    server.begin();

    delay(20);
}