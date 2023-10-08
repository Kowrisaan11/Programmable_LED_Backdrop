#include <WiFi.h>                                                // esp32 library

#include <IOXhop_FirebaseESP32.h>                                             // firebase library

#define FIREBASE_HOST "led-blink-3591d-default-rtdb.firebaseio.com"                         // the project name address from firebase id

#define FIREBASE_AUTH "QNKl6J4EdshxOWWM6RRwaMmjyLPK6xPhjYHtl8Ei"                    // the secret key generated from firebase

#define WIFI_SSID "Ragavan"                                          // input your home or public wifi name

#define WIFI_PASSWORD "Ragavan12"                                    //password of wifi ssid

String fireStatus0 = "";                                                     // led status received from firebase
String fireStatus1 = ""; 

int led0 = 23;  
int led1 = 22;                                                              

void setup() {

  Serial.begin(9600);

  delay(1000);

  pinMode(led0, OUTPUT);                
  pinMode(led1, OUTPUT);  

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

}

void loop() {

  fireStatus0 = Firebase.getString("LED_STATUS0");                     // get led status input from firebase

  if (fireStatus0 == "ON") {                         // compare the input of led status received from firebase

    // Serial.println("Led Turned ON");                 

    digitalWrite(led0, HIGH);                                                         // make output led ON

  }

  else if (fireStatus0 == "OFF") {              // compare the input of led status received from firebase

    // Serial.println("Led Turned OFF");

    digitalWrite(led0, LOW);                                                         // make output led OFF

  }

  else {

    Serial.println("Wrong Credential! Please send ON/OFF");

  }

  // fireStatus1 = Firebase.getString("LED_STATUS1");                     // get led status input from firebase

  // if (fireStatus1 == "ON") {                         // compare the input of led status received from firebase

  //   Serial.println("Led Turned ON");                 

  //   digitalWrite(led1, HIGH);                                                         // make output led ON

  // }

  // else if (fireStatus1 == "OFF") {              // compare the input of led status received from firebase

  //   Serial.println("Led Turned OFF");

  //   digitalWrite(led1, LOW);                                                         // make output led OFF

  // }

  // else {

  //   Serial.println("Wrong Credential! Please send ON/OFF");

  // }

}