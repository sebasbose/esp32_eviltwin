#ifndef LOGGERCONTROLLERCLASS_H
#define LOGGERCONTROLLERCLASS_H

#include <Arduino.h>
#include "constants.h"

class LoggerControllerClass {
private: 
public:
  LoggerControllerClass();
  void initialize();
  void logError(const String& message);
  void logEvent(const String& message);
};

extern LoggerControllerClass LoggerController;

#endif // LOGGERCONTROLLERCLASS_H