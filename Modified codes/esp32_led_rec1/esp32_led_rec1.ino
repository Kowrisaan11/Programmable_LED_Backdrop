#include <WiFi.h>
#include <WiFiUdp.h>

WiFiUDP udp;
char packetBuffer[255];
unsigned int localPort = 4210;
const char *ssid = "Kowri_S9";
const char *password = "12345687";

void setup() {
 	Serial.begin(115200);
 	WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 	udp.begin(localPort);
 	Serial.print(F("UDP Client : ")); 
  Serial.println(WiFi.localIP());
  pinMode(23, OUTPUT);  
  pinMode(22, OUTPUT);
  pinMode(1, OUTPUT);  
  pinMode(3, OUTPUT);
  pinMode(21, OUTPUT);  
  pinMode(19, OUTPUT);
}
void loop() {
 	int packetSize = udp.parsePacket();
 	// Serial.print(" Received packet from : "); 
  // Serial.println(udp.remoteIP());
 	// Serial.print(" Size : "); 
  // Serial.println(packetSize);
 	//Serial.print(" Data : ");
 	if (packetSize) {
 			int len = udp.read(packetBuffer, 255);
      //Serial.print(len+" ");     
 			if (len > 0) {
        packetBuffer[len - 1] = 0;
        int myint = atoi(packetBuffer);
        //Serial.println(myint);
        analogWrite(23, myint);
        analogWrite(22, myint);
        analogWrite(1, myint);
        analogWrite(3, myint);
        analogWrite(21, myint);
        analogWrite(19, myint);

        //memset(packetBuffer, 0, sizeof(packetBuffer));      

       }
      
 	}
 	// Serial.println("\n");
 	// delay(25);

}
