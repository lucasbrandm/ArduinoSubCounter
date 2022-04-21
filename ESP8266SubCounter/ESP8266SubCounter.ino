

// A Simple program to show Youtube & Instagram subscribers
// Credit to Roberto Delgado who wrote most of the code. I have just changed a few lines of it. 


// Libraries included

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include "Arduino.h"
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include "JsonStreamingParser.h"
#include <ArduinoJson.h>
#include "theSwedishMaker.h"

#include "InstagramStats.h"



const uint16_t WAIT_TIME = 60000; //Time between fecthing data.


// Define the typ of hardware and the pins used. 

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4

#define CLK_PIN   12
#define DATA_PIN  15
#define CS_PIN    13

// Hardware SPI connection
//MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
// Arbitrary output pins
MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

String INSTAGRAM_ACCESS_TOKEN = "EAAFZAqm0nbB0BAMf469ZADX1NbPuyPDiPNFilWHtwPWtdesh6VW1qkZArnuZCEFza495HlcZBrt0B69AKuFdsqnVpuOwca3iLkFpap8KEkxECWdCCwZA7CJjliZAxzzu8ZB0QHaTaN6PIdZBzfOrvujycJiHWAoLJRHv5gpiZAM0nYLIFPuLtbk8hZAS6RnmMyT6VDlIaOpQDQCMwZDZD";
String IG_USER_ID = "17841431535273762";
String FB_USER_ID = "112229417070625";
String FACEBOOK_ACCESS_TOKEN = INSTAGRAM_ACCESS_TOKEN;


WiFiClientSecure client; //For ESP8266 boards
InstagramStats instaStats(client, INSTAGRAM_ACCESS_TOKEN, IG_USER_ID);



// =======================================================================
// Configuration of router settings
// =======================================================================

const char* ssid     = "Guest";      // SSID of local network
const char* password = "MY-PC-ER";                // Password on network


void setup() 
{
  P.begin();
  P.setFont(fontSubs);
  
  // Connecting to wifi
  Serial.begin(115200);
  Serial.print("Connecting WiFi ");
  WiFi.begin(ssid, password);
  //P.print(" WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("."); delay(500);
  }
  Serial.println("");
  Serial.print("Connected: "); Serial.println(WiFi.localIP());
  
  client.setInsecure();
}


void loop(void)
{

  Serial.println("Getting data ... and stats for " + IG_USER_ID);
  //P.print("fetching");
  long insta;
  long fb;
  long gr;
    
    // PRINT
    insta = instaStats.getFollowersCount(IG_USER_ID, INSTAGRAM_ACCESS_TOKEN);
    String instaFollowers = num_format(insta);
    P.setTextAlignment(PA_LEFT);
    P.print("&" + instaFollowers);
    delay(10000);

    
    fb = instaStats.getLikesCount(FB_USER_ID, FACEBOOK_ACCESS_TOKEN);
    String fbLikes = num_format(fb);
    P.print("#" + fbLikes);
    delay(10000);
}
    

String num_format(long num){
     String num_s;
     long num_original = num;
     if (num>99999 && num<=999999){
        num = num / 1000;
        long fraction = num_original%1000;
        String num_fraction = String(fraction);
        String decimal = num_fraction.substring(0,1);
        num_s = String(num) + "." + decimal + "K";          
    }
    else if(num>999999){
        num = num / 1000000;
        long fraction = num_original%1000000;
        String num_fraction = String(fraction);
        String decimal = num_fraction.substring(0,1);
        if (num_original<100000000){
          num_s = " " + String(num) + "." + decimal + "M";      
        }
        else{
        num_s = String(num) + "." + decimal + "M";
        }
    }
    else{
        int num_l = String(num).length();
        char num_f[15];
        int blankDigits = 6 - num_l;
        for(int i = 0; i < blankDigits; i++){
          num_f[i] = ' '; 
        }
        num_f[blankDigits] = '\0';
        num_s = num_f + String(num);
    }
    return num_s;

    delay(60);
}    
