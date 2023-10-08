#include <WiFi.h>                                                // esp32 library

#include <IOXhop_FirebaseESP32.h>                                             // firebase library

#define FIREBASE_HOST "led-blink-3591d-default-rtdb.firebaseio.com"                         // the project name address from firebase id

#define FIREBASE_AUTH "QNKl6J4EdshxOWWM6RRwaMmjyLPK6xPhjYHtl8Ei"                    // the secret key generated from firebase

#define WIFI_SSID "Ragavan"                                          // input your home or public wifi name

#define WIFI_PASSWORD "Ragavan12"                                    //password of wifi ssid                                                     

void setup() {

  Serial.begin(9600);

  delay(1000);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                      //try to connect with wifi

  Serial.print("Connecting to ");

  Serial.print(WIFI_SSID);

  while (WiFi.status() != WL_CONNECTED) {

    Serial.print(".");

    delay(500);

  }

  Serial.println();

  Serial.print("Connected to ");

  Serial.println(WIFI_SSID);

  Serial.print("IP Address is : ");

  Serial.println(WiFi.localIP());                                                      //print local IP address

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                                       // connect to firebase

  Firebase.setString("LED_STATUS0", "OFF");                                          //send initial string of led status
  // Firebase.setString("LED_STATUS1", "OFF");                                          //send initial string of led status


}

void loop() {

  Firebase.setString("LED_STATUS0", "ON");  
  delay(500);
  Firebase.setString("LED_STATUS0", "OFF");  
  delay(500);
  // Firebase.setString("LED_STATUS1", "ON");  
  // delay(500);
  // Firebase.setString("LED_STATUS1", "OFF");  
  // delay(500);

}