#include "DNSServerControllerClass.h"

DNSServerControllerClass::DNSServerControllerClass() {
    this->dnsServer = new DNSServer();
}

void DNSServerControllerClass::initialize(IPAddress apIP) {
    this->dnsServer->start(DNS_SERVER_PORT, "*", apIP);
    LoggerController.logEvent("DNS server initialized.");
}

void DNSServerControllerClass::loop() {
    this->dnsServer->processNextRequest();
}

DNSServerControllerClass DNSServerController;