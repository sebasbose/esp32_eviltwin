#include "WebServerControllerClass.h"

WebServerControllerClass::WebServerControllerClass() {
    this->webServer = new AsyncWebServer(WEB_SERVER_PORT);
}

void WebServerControllerClass::initialize(IPAddress apIP, IPAddress netMsk) {
    WiFi.mode(WIFI_AP);
    WiFi.softAPConfig(apIP, apIP, netMsk);
    WiFi.softAP(NETWORK_SSID, NETWORK_PASSWORD);

    this->webServer->on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/html", "<h1>Welcome to the Captive Portal!</h1><form action='/connect' method='POST'><input type='text' name='ssid' placeholder='SSID'><br><input type='password' name='password' placeholder='Password'><br><input type='submit' value='Connect'></form>");
    });

    this->webServer->on("/connect", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/html", "");
    });

    this->webServer->onNotFound([](AsyncWebServerRequest *request){
        request->redirect("/");
    });

    this->webServer->begin();

    LoggerController.logEvent("Web server initialized.");
}

void WebServerControllerClass::handleRequest() {
    // Request handling code
}

void WebServerControllerClass::loop() {
    // webServer->handleClient();
}

WebServerControllerClass WebServerController;