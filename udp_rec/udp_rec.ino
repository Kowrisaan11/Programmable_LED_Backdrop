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
      Serial.println(len);
 			if (len > 2) {
        packetBuffer[len - 1] = 0;
 			  Serial.println(packetBuffer);
        char c = packetBuffer[6];
        Serial.println(c);
        if (c == '1') {
          digitalWrite(23, HIGH);
        }
        if (c == '0') {
          digitalWrite(23, LOW);
        }
      // memset(packetBuffer, 0, sizeof(packetBuffer));       
       }
      
 	}
 	//Serial.println("\n");
 	// delay(25);

}
