#ifndef WEBSERVERCONTROLLERCLASS_H
#define WEBSERVERCONTROLLERCLASS_H

#include <ESPAsyncWebServer.h>
#include <DNSServer.h>
#include <WiFi.h>
#include "constants.h"

class WebServerControllerClass {
private:
    DNSServer *dnsServer;
    AsyncWebServer *webServer;

    IPAddress apIP;
    IPAddress netMsk;

public:
    WebServerControllerClass();
    void initialize();
    void handleRequest();
    void loop();
};

extern WebServerControllerClass WebServerController;

#endif // WEBSERVERCONTROLLERCLASS_H