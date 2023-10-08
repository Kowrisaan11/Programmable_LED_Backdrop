#include <WebServer.h>
#include <WiFi.h>
#include <WiFiUdp.h>

//set up to connect to an existing network 
const char *ssid = "Kowri_S9";
const char *password = "12345687";

WiFiUDP Udp;
unsigned int localUdpPort = 4210;  //  port to listen on
char incomingPacket[255];  // buffer for incoming packets

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

  // Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);

  // // we recv one packet from the remote so we can know its IP and port
  // bool readPacket = false;
  // while (!readPacket) {
  //   int packetSize = Udp.parsePacket();
  //   if (packetSize)
  //    {
  //     // receive incoming UDP packets
  //     Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
  //     int len = Udp.read(incomingPacket, 255);
  //     if (len > 0)
  //     {
  //       incomingPacket[len] = 0;
  //     }
  //     Serial.printf("UDP packet contents: %s\n", incomingPacket);
  //     readPacket = true;
  //   } 
  // }
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

      const char* message1 = myString;
      size_t messageLength1 = strlen(message1);
      uint8_t udpMessage1[messageLength1];
      memcpy(udpMessage1, message1, messageLength1);

      Udp.write(udpMessage1, messageLength1);
      Serial.println(message1);
      Udp.endPacket();
      
      analogWrite(23, ledVal);
      analogWrite(22, ledVal);
      
      delay(5);
     }

}
