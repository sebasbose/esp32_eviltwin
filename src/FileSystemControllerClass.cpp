#include "FileSystemControllerClass.h"

FileSystemControllerClass::FileSystemControllerClass() {
    // Constructor
}

bool FileSystemControllerClass::initialize() {
    if (!LittleFS.begin()) {
        LoggerController.logError("Failed to initialize LittleFS.");
        return false;
    }
    LoggerController.logEvent("LittleFS initialized successfully.");
    return true;
}

bool FileSystemControllerClass::readFile(const String& path, String& content) {
    File file = LittleFS.open(path, "r");
    if (!file) {
        LoggerController.logError("Failed to open file for reading.");
        return false;
    }
    content = file.readString();
    file.close();
    LoggerController.logEvent("File read successfully.");
    return true;
}

bool FileSystemControllerClass::writeFile(const String& path, const String& content) {
    File file = LittleFS.open(path, "w");
    if (!file) {
        LoggerController.logError("Failed to open file for writing.");
        return false;
    }
    file.print(content);
    file.close();
    LoggerController.logEvent("File written successfully.");
    return true;
}

bool FileSystemControllerClass::deleteFile(const String& path) {
    if (!LittleFS.remove(path)) {
        LoggerController.logError("Failed to delete file.");
        return false;
    }
    LoggerController.logEvent("File deleted successfully.");
    return true;
}
