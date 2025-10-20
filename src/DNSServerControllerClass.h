#ifndef DNSSERVERCONTROLLERCLASS_H
#define DNSSERVERCONTROLLERCLASS_H

#include <DNSServer.h>
#include <WiFi.h>
#include <LoggerControllerClass.h>

class DNSServerControllerClass {
private:
    DNSServer *dnsServer;
    IPAddress apIP;

public:
    DNSServerControllerClass();
    void initialize(IPAddress apIP);
    void loop();
};

extern DNSServerControllerClass DNSServerController;

#endif // DNSSERVERCONTROLLERCLASS_H