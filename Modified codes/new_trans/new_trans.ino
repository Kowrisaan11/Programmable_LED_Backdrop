#include <WebServer.h>
#include <WiFi.h>
#include <WiFiUdp.h>

//set up to connect to an existing network 
const char *ssid = "Kowri_S9";
const char *password = "12345687";

WiFiUDP Udp;
unsigned int localUdpPort = 4210;  //  port to listen on

void setup()
{
  int status = WL_IDLE_STATUS;
  Serial.begin(115200);
  WiFi.begin(ssid, password); 
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to wifi");

  Udp.begin(localUdpPort);
  pinMode(23, OUTPUT);  
  pinMode(22, OUTPUT);  

}

void loop()
{
    // Fade in
    for(int ledVal = 0; ledVal <= 255; ledVal +=1) {

      Udp.beginPacket("192.168.43.176", 4210);
            
      char myString[10]; // Allocate a char array to hold the converted string (adjust the size as needed)
      sprintf(myString, "%d", ledVal); // Convert the integer to a string using sprintf

      const char* message = myString;
      size_t messageLength = strlen(message);
      uint8_t udpMessage[messageLength];
      memcpy(udpMessage, message, messageLength);

      Udp.write(udpMessage, messageLength);
      Serial.println(message);
      Udp.endPacket();

      analogWrite(23, ledVal);
      analogWrite(22, ledVal);
      delay(5);
     }  
 
    // Fade out
    for(int ledVal = 255; ledVal >= 0; ledVal -=1) {

      Udp.beginPacket("192.168.43.176", 4210);
            
      char myString[10]; // Allocate a char array to hold the converted string (adjust the size as needed)
      sprintf(myString, "%d", ledVal); // Convert the integer to a string using sprintf

      const char* message = myString;
      size_t messageLength = strlen(message);
      uint8_t udpMessage[messageLength];
      memcpy(udpMessage, message, messageLength);

      Udp.write(udpMessage, messageLength);
      Serial.println(message);
      Udp.endPacket();
      
      analogWrite(23, ledVal);
      analogWrite(22, ledVal);
      
      delay(5);
     }

}

