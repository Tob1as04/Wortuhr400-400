#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <ArduinoOTA.h>
#include <time.h>
#include <Adafruit_NeoPixel.h>
#define WEBSERVER_H
#include <TLC5928.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <SPI.h>
#include <FS.h>
#include "LittleFS.h"
#include <WiFiManager.h>
#define RGB_PIN 5
#define NUM_RGB 118

const char* ssid = "Galaxysdfghj";
const char* password= "test1234";
//const char* ssid = "TP-LINK_90A9";
//const char* password= "23667709";
const char* ntpServer1 = "pool.ntp.org";
const char* ntpServer2 = "time.nist.gov";

AsyncWebServer server(80);
TLC5928 tlc(12,16,14,13, 15);//CLK,DATA,LATCH,BLANK, NUM_TLC
Adafruit_NeoPixel rgb(NUM_RGB, RGB_PIN, NEO_GRB + NEO_KHZ800);

int red = 0; 
int green = 0;
int blue = 0;
int white = 150;
int backgroundred = 0;
int backgroundgreen = 0;
int backgroundblue = 0;
int farbered = 0;
int farbegreen = 0;
int farbeblue = 0;
int brightness = 0;

int flag_rainbow = 0;
int flag_farbe = 0;
int flag_ldr = 0;
int rainbowcounter = 0;
unsigned long lastMillis = 0;
int ldrtime[3] = {0};
int setting[3] = {0};
int modus = 0;
int zwangsUpdate = 0; 

int lastMinute = -1;
int minute = 0;
int hour = 0;
time_t rawtime;
struct tm * timeinfo;

volatile int interrupt = 0;

void farbe();
void update();
void update(int red, int green, int blue, int white, int backgroundred, int backgroundgreen, int backgroundblue);


void IRAM_ATTR timer1ISR() {
  for(int i = 0; i <= 15; i++){
    tlc.setPixel(i, 0);
  }

  if(interrupt > 5) interrupt = 0;
    switch (interrupt){
      case 0:
      tlc.setPixel(0,1);
      tlc.setPixel(1,1);
      tlc.setPixel(14,1);
      tlc.setPixel(15,1);
      break;
      case 1:
      tlc.setPixel(2,1);
      tlc.setPixel(3,1);
      tlc.setPixel(12,1);
      tlc.setPixel(13,1);
      break;
      case 2:
      tlc.setPixel(4,1);
      tlc.setPixel(5,1);
      tlc.setPixel(10,1);
      tlc.setPixel(11,1);
      break;
      case 3:
      tlc.setPixel(6,1);
      tlc.setPixel(7,1);
      tlc.setPixel(8,1);
      tlc.setPixel(9,1);
      break;
      case 4:
      tlc.setPixel(4,1);
      tlc.setPixel(5,1);
      tlc.setPixel(10,1);
      tlc.setPixel(11,1);
      break;
      case 5:
      tlc.setPixel(2,1);
      tlc.setPixel(3,1);
      tlc.setPixel(12,1);
      tlc.setPixel(13,1);
      break;
      default:
      break;
    }
    tlc.show();
    interrupt++;
}

     

void setup() {
  LittleFS.begin();
  Serial.begin(115200);
  tlc.off();
  analogWriteRange(255);
  analogWriteFreq(22000);//100-40000
  tlc.begin();
  tlc.clear();
  tlc.off();

  WiFiManager wm;
  delay(100);
  rgb.begin();
  delay(100);
  rgb.clear();
  rgb.show();

    tlc.on();
    tlc.setPixel(157);
    tlc.setPixel(146);
    tlc.setPixel(141);
    tlc.setPixel(130);
    tlc.setPixel(202);
    tlc.setPixel(203);
    tlc.setPixel(213);
    tlc.setPixel(212);
    tlc.show();
    timer1_attachInterrupt(timer1ISR); 
    timer1_enable(TIM_DIV16, TIM_EDGE, TIM_LOOP);
    timer1_write(800000); // 2500000 / 5 ticks/µs => 0.5s interval


  bool res;
  wm.setConnectTimeout(20);
  res = wm.autoConnect("Wortuhr");

  


  Serial.println("Zeit holen");
  configTime(0, 0, ntpServer1, ntpServer2);//Konfiguriert die Zeit, hier kein Timeoffset und Daylightoffset, da dies später durch die Zeitzone gesetzt wird.
  setenv("TZ", "CET-1CEST,M3.5.0,M10.5.0/3", 1);//Setzt die Zeitzone, umstellung von Sommer und Winterzeit automatisch (getestet)
  tzset();
  time (&rawtime);
  delay(300);
  time(&rawtime);
  timeinfo = localtime (&rawtime);
  Serial.println(asctime(timeinfo));
  delay(1000);
  
  Serial.println("Zeit fertig");
 ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH) {
      type = "sketch";
    } else {  // U_FS
      type = "filesystem";
    }

    // NOTE: if updating FS this would be the place to unmount FS using FS.end()
    Serial.println("Start updating " + type);
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) {
      Serial.println("Auth Failed");
    } else if (error == OTA_BEGIN_ERROR) {
      Serial.println("Begin Failed");
    } else if (error == OTA_CONNECT_ERROR) {
      Serial.println("Connect Failed");
    } else if (error == OTA_RECEIVE_ERROR) {
      Serial.println("Receive Failed");
    } else if (error == OTA_END_ERROR) {
      Serial.println("End Failed");
    }
  });

  ArduinoOTA.setHostname("Wortuhr");
  ArduinoOTA.setPassword("123");
  ArduinoOTA.begin();
 
  
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        //request->send_P(200, "text/html", website);
        request->send(LittleFS, "/wortuhr.html", "text/html");
    });
  server.on("/favicon.ico", HTTP_GET, [](AsyncWebServerRequest *request){
      //request->send_P(200, "text/html", website);
      request->send(200);
  });
  server.on("/css", HTTP_GET, [](AsyncWebServerRequest *request){
        //request->send_P(200, "text/html", website);
        request->send(LittleFS, "/style.css", "text/css");
    });
 server.on("/js", HTTP_GET, [](AsyncWebServerRequest *request){
      //request->send_P(200, "text/html", website);
      request->send(LittleFS, "/script.js", "text/javascript");
  });
  server.on("/vordergrund", HTTP_GET, [] (AsyncWebServerRequest *request) {
        String message;
        if (request->hasParam("red")) {
            message = request->getParam("red")->value();
            red = message.toInt();
        }
        if (request->hasParam("green")) {
            message = request->getParam("green")->value();
            green = message.toInt();
        }
        if (request->hasParam("blue")) {
            message = request->getParam("blue")->value();
            blue = message.toInt();
        }
        if (request->hasParam("white")) {
            message = request->getParam("white")->value();
            white = message.toInt();
        }
        request->send(200);
        flag_rainbow = 0;
        flag_farbe = 0;
        zwangsUpdate = 1;
        
    });
    server.on("/hintergrund", HTTP_GET, [] (AsyncWebServerRequest *request) {
        String message;
        if (request->hasParam("red")) {
            message = request->getParam("red")->value();
            backgroundred = message.toInt();
        }
        if (request->hasParam("green")) {
            message = request->getParam("green")->value();
            backgroundgreen = message.toInt();
        }
        if (request->hasParam("blue")) {
            message = request->getParam("blue")->value();
            backgroundblue = message.toInt();
        }
        request->send(200);
        flag_rainbow = 0;
        flag_farbe = 0;
        zwangsUpdate = 1;
        
    });
    server.on("/farbe", HTTP_GET, [] (AsyncWebServerRequest *request) {
        String message;
        if (request->hasParam("red")) {
            message = request->getParam("red")->value();
            farbered = message.toInt();
        }
        if (request->hasParam("green")) {
            message = request->getParam("green")->value();
            farbegreen = message.toInt();
        }
        if (request->hasParam("blue")) {
            message = request->getParam("blue")->value();
            farbeblue = message.toInt();
        }
        farbe();
        request->send(200);
        flag_rainbow = 0;
        flag_farbe = 1;
    });
    server.on("/config", HTTP_GET, [] (AsyncWebServerRequest *request) {
        String message;
        if (request->hasParam("timeeins")) {
            message = request->getParam("timeeins")->value();
            ldrtime[0] = message.toInt();
        }
        if (request->hasParam("settingeins")) {
            message = request->getParam("settingeins")->value();
            setting[0] = message.toInt();
        }
        if (request->hasParam("timezwei")) {
            message = request->getParam("timezwei")->value();
            ldrtime[1] = message.toInt();
        }
        if (request->hasParam("settingzwei")) {
            message = request->getParam("settingzwei")->value();
            setting[1] = message.toInt();
        }
        if (request->hasParam("timedrei")) {
            message = request->getParam("timedrei")->value();
            ldrtime[2] = message.toInt();
        }        
        if (request->hasParam("settingdrei")) {
            message = request->getParam("settingdrei")->value();
            setting[2] = message.toInt();
        }
        zwangsUpdate = 1;
        request->send(200);
    });
    server.on("/rainbow", HTTP_GET, [] (AsyncWebServerRequest *request) {
        flag_rainbow = 1;
        flag_farbe = 0;
        request->send(200);
    });
    server.on("/settime", HTTP_GET, [] (AsyncWebServerRequest *request) {
        request->send(200);
        configTime(0, 0, ntpServer1, ntpServer2);//Konfiguriert die Zeit, hier kein Timeoffset und Daylightoffset, da dies später durch die Zeitzone gesetzt wird.
        setenv("TZ", "CET-1CEST,M3.5.0,M10.5.0/3", 1);//Setzt die Zeitzone, umstellung von Sommer und Winterzeit automatisch (getestet)
        tzset();
        time (&rawtime);
        delay(300);
        time(&rawtime);
    });
    server.on("/getcolor", HTTP_GET, [](AsyncWebServerRequest *request){
      int ebene = 0;
      String message;
      String response;
      if (request->hasParam("ebene")) {
            message = request->getParam("ebene")->value();
            ebene = message.toInt();
        }

    switch(ebene){
      case 0:
      response = R"({"red":")";
    response += red;
    response += R"(","green":")";
    response += green;
    response += R"(","blue":")";
    response += blue;
    response += R"(","white":")";
    response += white;
    response += R"("})";
      break;
      case 1:
      response = R"({"red":")";
    response += backgroundred;
    response += R"(","green":")";
    response += backgroundgreen;
    response += R"(","blue":")";
    response += backgroundblue;
    response += R"(","white":")";
    response += "0";
    response += R"("})"; 
      break;
      case 2: 
      response = R"({"red":")";
    response += farbered;
    response += R"(","green":")";
    response += farbegreen;
    response += R"(","blue":")";
    response += farbeblue;
    response += R"(","white":")";
    response += "0";
    response += R"("})";
      break;
      default:
      break;
    }
    request->send_P(200, "text/plain", response.c_str());
    });

    server.begin();
}






void loop() {
  
  time (&rawtime);
  timeinfo = localtime (&rawtime);


  

  if(lastMinute != timeinfo->tm_min && flag_rainbow == 0 && flag_farbe == 0 || zwangsUpdate){//Update jede Minute
    minute = timeinfo->tm_min;
    hour = timeinfo->tm_hour;
    lastMinute = minute;
    for (int i = 0; i < 3; i++){
      if (timeinfo->tm_hour == ldrtime[i]){
        if (setting[i] == 1){
          modus = 1;
        }
        else if (setting[i] == 2){
          modus = 2;
        }
        else modus = 0;
        i = 4;
      }
    }
    zwangsUpdate = 0;
    if(modus == 0) brightness = 100;
    if(modus == 1) brightness = 0;
    if(modus == 2) brightness = map(analogRead(A0),5,800,30,100);
    if (brightness > 100) brightness = 100;
    if (brightness < 30) brightness = 30;
    update(brightness*red/100, brightness*green/100, brightness*blue/100, brightness*white/100, brightness*backgroundred/100, brightness*backgroundgreen/100, brightness*backgroundblue/100);
  }


  if(flag_rainbow) rainbow();

//Serial.println(modus);


  ArduinoOTA.handle();
}
