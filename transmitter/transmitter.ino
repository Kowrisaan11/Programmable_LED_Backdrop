#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid     = "Kowri_S9"; // Change this to your WiFi SSID
const char* password = "12345687"; // Change this to your WiFi password
const char* serverAddress = "http://192.168.43.178/bitstream"; // Replace "server_ip" with the IP address of the server ESP32
HTTPClient http;
  
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  http.begin(serverAddress);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
}

void loop() {
  // Simulate your bit stream here (you can replace this with actual data)
  String bitStreamData = "10";

  // Send HTTP POST request to the server


  String postData = "data=" + bitStreamData;
  int httpResponseCode = http.POST(postData);


  if (httpResponseCode > 0) {
    String response = http.getString();
    Serial.print("Server response: ");
    Serial.println(response);
  } else {
    Serial.print("Error sending POST request, HTTP error code: ");
    Serial.println(httpResponseCode);
  }

  // http.end();

  delay(50); // Send the bit stream every 5 seconds
}
