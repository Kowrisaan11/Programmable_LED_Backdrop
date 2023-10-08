#include <WiFi.h>                                                // esp32 library

#include <IOXhop_FirebaseESP32.h>                                             // firebase library

#define FIREBASE_HOST "mode-31704-default-rtdb.firebaseio.com"                         // the project name address from firebase id

#define FIREBASE_AUTH "DqC7UuJjHT5jHbYtMOENYq21m65wDVodlN2jwOl1"                    // the secret key generated from firebase

#define WIFI_SSID "Ragavan-Dailog"                                          // input your home or public wifi name

#define WIFI_PASSWORD "DHTRDL18A9B"                                    //password of wifi ssid





String fireStatus = ""; 
String current_mode = "";    

                                                 // led status received from firebase

int led = 2;
                                                      

void setup() {

  Serial.begin(115200);

  delay(1000);

  pinMode(2, OUTPUT);       
  
  pinMode(0, OUTPUT);   
  digitalWrite(0, LOW);              
  pinMode(5, OUTPUT);   
  digitalWrite(5, LOW);   
  pinMode(15, OUTPUT);   
  digitalWrite(15, LOW);

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

  // Firebase.setString("LED_STATUS", "OFF");                                          //send initial string of led status

}

void loop() {

  fireStatus = Firebase.getString("MODE");
  if (current_mode != fireStatus ){

      //Serial.println("Mode=");
      Serial.println(fireStatus);
      current_mode = fireStatus;
  }                    // get led status input from firebase

}



