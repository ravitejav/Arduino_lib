
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
 
const char* ssid = "Redmi";
const char* password = "9986609802";
 
void setup() {
 
  Serial.begin(115200);
  delay(1000);
 
  WiFi.begin("Redmi", "9986609802"); 
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println(".");
  }
  Serial.println("Connected to the WiFi network");
} 
void loop() {
 
  if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
    HTTPClient http;
    http.begin("http://192.168.43.54"); //Specify the URL and certificate
    delay(10000);
    int httpCode = http.GET();                                                  //Make the request
    Serial.println(httpCode);
    String payload = http.getString();
    Serial.println(httpCode);
    Serial.println(payload);
    http.end(); //Free the resources
    Serial.println(WiFi.localIP());
  }
}
