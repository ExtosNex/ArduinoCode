#include "ThingSpeak.h"
#include <ESP8266WiFi.h>


char ssid[] = "";             // your network SSID (name) 
char pass[] = "";         // your network password
unsigned long myChannelNumber = ;  // Replace the 0 with your channel number
const char * myWriteAPIKey = "";    // Paste your ThingSpeak Write API Key between the quotes 

/*
const char *ssid =  "Telstra4621C3";     // replace with your wifi ssid and wpa2 key
const char *pass =  "v269cyk66qtp";

unsigned long myChannelNumber = 0;
const char * myWriteAPIKey = "8NMHVJABW7ELF0KA";     //  Enter your Write API key from ThingSpeak

*/


WiFiClient client;

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

 // WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client); 
}


/*
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(115200);

  Serial.println("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);
 
  while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
            Serial.print(".");
     }
   Serial.println("");
   Serial.println("WiFi connected");


  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
   ThingSpeak.begin(client);
  }
}
*/

String command;

void loop() 
{ 

 // Connect or reconnect to WiFi
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass);
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected.");
    delay(1000);
  }



  
  if (Serial.available()) 
  {
 
    char c = Serial.read();
    
    if(c == '\n')
    {
      parseCommand(command);
      command = "";
    }
    else
    {
      command += c;
    }
    
    
    //Serial.write(Serial.read());
  }

}



void parseCommand(String com)
{
  /*
  String part1;
  String part2;
  String part3;
*/
  //Split Data
String  part1 = com.substring(0, com.indexOf("a"));
String  part2 = com.substring(com.indexOf("b")+1 ,com.indexOf("c"));
String  part3 = com.substring(com.indexOf("d")+1);

//Serial.println("V1: " + String(part1) + " V2: " + String(part2) + " V3: " + String(part3) );

//convert to float
/*
v1 = atof(part1);
v2 = atof(part2);
v3 = atof(part3);
//0.00 0.56 0.72
*/

//Send Data to Server
/*
ThingSpeak.writeField(1103446, 1, String(part1), myWriteAPIKey);
ThingSpeak.writeField(1103446, 2, String(part2), myWriteAPIKey);
ThingSpeak.writeField(1103446, 3, String(part3), myWriteAPIKey);
*/

/*
ThingSpeak.writeField(1103446, 1, String(3), myWriteAPIKey);
ThingSpeak.writeField(1103446, 2, String(4), myWriteAPIKey);
ThingSpeak.writeField(1103446, 3, String(5), myWriteAPIKey);
*/

// 0.00, 5.00, 4.74


//set fields
ThingSpeak.setField(1,part1);
ThingSpeak.setField(2,part2);
ThingSpeak.setField(3,part3);
ThingSpeak.setStatus("V1: " + String(part1) + " V2: " + String(part2) + " V3: " + String(part3));
// write to the ThingSpeak channel
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if(x == 200){
    //Serial.println("Channel update successful.");
  }
  else{
 //   Serial.println("Problem updating channel. HTTP error code " + String(x));
  }



//Serial.println("post");

delay(20000); // Wait 20 seconds before sending a new value
  
}
