
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
const char* ssid = "Redmi";
const char* password = "9986609802";

ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);
  setupAccessPoint();
}
void handle_index() {
  server.send(200, "text/html", "50");
}

void handle_feed() {
  server.send(200, "text/html", "This is response to client " );
}

void setupAccessPoint(){
   WiFi.begin("Redmi", "9986609802");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  IPAddress myIP = WiFi.localIP();
  Serial.println(myIP);
  setupServer();
}

void setupServer(){
  server.on("/", handle_index);
  server.on("/feed", handle_feed);
  server.begin();
}

void loop() {
  server.handleClient();
}

