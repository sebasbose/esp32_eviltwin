#include <Arduino.h>
#include <LoggerControllerClass.h>
#include <FileSystemControllerClass.h>
#include <WebServerControllerClass.h>

LoggerControllerClass logger;
FileSystemControllerClass fileSystem;
WebServerControllerClass webServerController;

void setup() {
  // put your setup code here, to run once:
  logger = LoggerControllerClass();
  fileSystem = FileSystemControllerClass();
  webServerController = WebServerControllerClass();

  logger.initialize();
  fileSystem.initialize();
  webServerController.initialize();
}

void loop() {
  // put your main code here, to run repeatedly:
  webServerController.loop();
}