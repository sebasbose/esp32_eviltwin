#include <Arduino.h>
#include <LoggerControllerClass.h>
#include <FileSystemControllerClass.h>

LoggerControllerClass logger;
FileSystemControllerClass fileSystem;

void setup() {
  // put your setup code here, to run once:
  logger = LoggerControllerClass();
  fileSystem = FileSystemControllerClass();

  logger.initialize();
  fileSystem.initialize();
}

void loop() {
  // put your main code here, to run repeatedly:
}