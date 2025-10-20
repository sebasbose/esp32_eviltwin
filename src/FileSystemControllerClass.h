#ifndef FILESYSTEMCONTROLLERCLASS_H
#define FILESYSTEMCONTROLLERCLASS_H

#include <Arduino.h>
#include <LittleFS.h>
#include <LoggerControllerClass.h>
#include "constants.h"

class FileSystemControllerClass {
public:
    FileSystemControllerClass();
    bool initialize();
    bool readFile(const String& path, String& content);
    bool writeFile(const String& path, const String& content);
    bool appendFile(const String& path, const String& content);
    bool deleteFile(const String& path);
};

extern FileSystemControllerClass FileSystemController;

#endif // FILESYSTEMCONTROLLERCLASS_H