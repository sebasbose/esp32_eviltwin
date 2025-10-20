#include "WebServerControllerClass.h"

WebServerControllerClass::WebServerControllerClass() {;
    this->dnsServer = new DNSServer();
    this->webServer = new AsyncWebServer(WEB_SERVER_PORT);
    this->apIP = IPAddress(192, 168, 4, 1);
    this->netMsk = IPAddress(255, 255, 255, 0);
}

void WebServerControllerClass::initialize() {
    WiFi.mode(WIFI_AP);
    WiFi.softAPConfig(this->apIP, this->apIP, this->netMsk);
    WiFi.softAP(NETWORK_SSID, NETWORK_PASSWORD);

    this->dnsServer->start(DNS_SERVER_PORT, "*", this->apIP);

    this->webServer->on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/html", "<h1>Welcome to the Captive Portal!</h1><form action='/connect' method='POST'><input type='text' name='ssid' placeholder='SSID'><br><input type='password' name='password' placeholder='Password'><br><input type='submit' value='Connect'></form>");
    });

    this->webServer->on("/connect", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/html", "");
    });

    this->webServer->begin();

    LoggerController.logEvent("Web server initialized.");
}

void WebServerControllerClass::handleRequest() {
    // Request handling code
}

void WebServerControllerClass::loop() {
    this->dnsServer->processNextRequest();
}

WebServerControllerClass WebServerController;