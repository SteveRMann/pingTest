#define SKETCH "pingTest"
#define VERSION "1.00"           // Four characters
#define hostPrefix "PINGER"      // Six characters max
/*
   This program is a test of the ping function
*/

//-------------------------
#include <ESP8266Ping.h>
#include <Kaywinnet.h>          // WiFi credentials

#include "Arduino.h"

// setup_wifi vars
char macBuffer[24];       // Holds the last three digits of the MAC, in hex.
char hostNamePrefix[] = hostPrefix;
char hostName[24];        // Holds hostNamePrefix + the last three bytes of the MAC address.


//************************************** SETUP *******************************
void setup() {
  beginSerial();
  setup_wifi();
}


//************************************** LOOP *******************************
void loop() {
  char pingIP[20];                            // IP that we're going to ping.
  strcpy(pingIP, "192.168.1.1");
  yield();                                    // Reset the WDT on the ESP8266

  if (Ping.ping(pingIP)) {                    // Ping
    Serial.println("OK");
  } else {
    Serial.println("Fail");
  }
  delay(1000);
}
