#define SKETCH "pingTest"
#define VERSION "1.00"           // Four characters

/*
   This program is a test of the ping function
*/

//-------------------------
#include <ESP8266Ping.h>
#include <Kaywinnet.h>          // WiFi credentials

#include "Arduino.h"

// setup_wifi vars
char macBuffer[24];       // Holds the last three digits of the MAC, in hex.
char pingIP[20];          // IP that we're going to ping.

//****************************** SERIAL **************************
void beginSerial() {
  Serial.begin(115200);
  delay(100);
  Serial.println();
  Serial.println();
  Serial.println(SKETCH);
  Serial.println(VERSION);
  Serial.println();
}


//****************************** WiFi **************************
void setup_wifi() {
#ifndef Kaywinnet
#include <Kaywinnet.h>
#endif
  
  Serial.println();
  Serial.println("Connecting to ");
  Serial.println(MY_SSID);

  WiFi.mode(WIFI_STA);
  //WiFi.enableInsecureWEP();
  WiFi.hostname(SKETCH);
  WiFi.begin(MY_SSID, MY_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(WiFi.status());
    Serial.print(" ");
  }

  Serial.println("\nWiFi connected, ");
  Serial.print("MAC Address: ");
  Serial.println(WiFi.macAddress());
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Hostname: ");
  Serial.println(WiFi.hostname().c_str());

}


//****************************** PING **************************
void pingit() {
  Serial.print(pingIP);
  Serial.print(F(": "));
  if (Ping.ping(pingIP)) {                    // Ping
    Serial.println("OK");
  } else {
    Serial.println("Fail");
  }
  yield();                                    // Reset the WDT on the ESP8266
}

//****************************** SETUP **************************
void setup() {
  beginSerial();
  setup_wifi();
}


//****************************** LOOP **************************
void loop() {
  strcpy(pingIP, "192.168.1.1");
  pingit();
  strcpy(pingIP, "192.168.1.57");
  pingit();
  strcpy(pingIP, "192.168.1.124");
  pingit();
  strcpy(pingIP, "192.168.1.198");
  pingit();
  strcpy(pingIP, "127.0.0.1");
  pingit();

  Serial.println(F("---------------"));
  delay(1000);
}
