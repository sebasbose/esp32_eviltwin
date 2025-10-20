#ifndef WEBSERVERCONTROLLERCLASS_H
#define WEBSERVERCONTROLLERCLASS_H

#include <ESPAsyncWebServer.h>
#include <DNSServer.h>
#include <WiFi.h>
#include <LittleFS.h>
#include <LoggerControllerClass.h>
#include <FileSystemControllerClass.h>
#include "constants.h"

class WebServerControllerClass {
private:
    DNSServer *dnsServer;
    AsyncWebServer *webServer;

public:
    WebServerControllerClass();
    void initialize(IPAddress apIP, IPAddress netMsk);
    void loop();
    void storeCredentials(const String& email, const String& password);
    void clearCredentials();
};

extern WebServerControllerClass WebServerController;

#endif // WEBSERVERCONTROLLERCLASS_H