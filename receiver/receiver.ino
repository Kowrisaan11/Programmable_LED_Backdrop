#include <WiFi.h>
#include <WebServer.h>

const char* ssid     = "Kowri_S9"; // Change this to your WiFi SSID
const char* password = "12345687"; // Change this to your WiFi password
WebServer server(80);



IPAddress local_IP(192, 168, 43, 178);
// Set your Gateway IP address
IPAddress gateway(192, 168, 43,1);

IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(8, 8, 8, 8);   //optional
IPAddress secondaryDNS(8, 8, 4, 4); //optional

void handleBitStream() {
  // This function will handle the incoming HTTP request and process the bit stream
  // In this example, we just print the received data to the serial monitor
  String receivedData = server.arg("data");
  Serial.print("Received bit stream: ");
  Serial.println(receivedData);
  server.send(200, "text/plain", "Data received successfully!");
  
}

void setup() {
  Serial.begin(115200);

  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("STA Failed to configure");
  }
  WiFi.begin(ssid, password);
    //Configures static IP address

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Set up the HTTP server routes
  server.on("/bitstream", handleBitStream);

  // Start the server
  server.begin();

   
}

void loop() {
  // Handle incoming client requests
  server.handleClient();
}

