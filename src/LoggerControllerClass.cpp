#include "LoggerControllerClass.h"

LoggerControllerClass::LoggerControllerClass() {
  // Constructor
}

void LoggerControllerClass::initialize() {
  Serial.begin(BAUD_RATE);
  this->logEvent("LoggerController initialized.");
}

void LoggerControllerClass::logError(const String& message) {
  Serial.print("ERROR: ");
  Serial.println(message);
}

void LoggerControllerClass::logEvent(const String& message) {
  Serial.print("EVENT: ");
  Serial.println(message);
}

LoggerControllerClass LoggerController;