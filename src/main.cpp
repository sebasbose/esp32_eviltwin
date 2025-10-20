#include <Arduino.h>
#include <LoggerControllerClass.h>
#include <FileSystemControllerClass.h>
#include <DNSServerControllerClass.h>
#include <WebServerControllerClass.h>

LoggerControllerClass logger;
FileSystemControllerClass fileSystem;
WebServerControllerClass webServerController;
DNSServerControllerClass dnsServerController;

void setup() {
  IPAddress apIP(192, 168, 4, 1);
  IPAddress netMsk(255, 255, 255, 0);

  // put your setup code here, to run once:
  logger = LoggerControllerClass();
  fileSystem = FileSystemControllerClass();
  webServerController = WebServerControllerClass();
  dnsServerController = DNSServerControllerClass();

  logger.initialize();
  fileSystem.initialize();
  webServerController.initialize(apIP, netMsk);
  dnsServerController.initialize(apIP);
}

void loop() {
  // put your main code here, to run repeatedly:
  // webServerController.loop();
  dnsServerController.loop();
}