#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const int wifiStatusLed = LED_BUILTIN;
ESP8266WebServer server(80);

//const char* ssid = "***";
//const char* password = "***"; 


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define LED_STRIP_PIN  D4
#define NUM_LEDS      30
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_STRIP_PIN, NEO_GRB + NEO_KHZ800);

