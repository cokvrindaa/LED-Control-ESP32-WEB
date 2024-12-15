#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>

// WiFi credentials
const char* ssid = "Samsung Galaxy A55";
const char* password = "123456789";

// Web server
WebServer server(80);

// LED Pins
const int espLed = 2;
const int led1 = 19;
const int led2 = 18;
const int led3 = 5;
const int led4 = 22;

// DHT Sensor
#define DHTPIN 4     // Pin connected to the DHT sensor
#define DHTTYPE DHT11 // DHT11 or DHT22
DHT dht(DHTPIN, DHTTYPE);

// LED States
bool lampupertamastat = false;
bool lampukeduastat = false;
bool lampuketigastat = false;
bool lampukeempatstat = false;

void setup() {
  Serial.begin(115200);

  // Initialize LED pins
  pinMode(led1, OUTPUT);
  pinMode(espLed, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  // Initialize DHT sensor
  dht.begin();

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    Serial.print(".");
    digitalWrite(espLed, LOW);
  }
  Serial.println("\nConnected to WiFi!");
  digitalWrite(espLed, HIGH);
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Define Web Server Endpoints
  server.on("/lampupertama", HTTP_GET, getlampupertama);
  server.on("/lampukedua", HTTP_GET, getlampukedua);
  server.on("/lampuketiga", HTTP_GET, getlampuketiga);
  server.on("/lampukeempat", HTTP_GET, getlampukeempat);

  server.on("/lampupertama", HTTP_POST, setlampupertama);
  server.on("/lampukedua", HTTP_POST, setlampukedua);
  server.on("/lampuketiga", HTTP_POST, setlampuketiga);
  server.on("/lampukeempat", HTTP_POST, setlampukeempat);

  // Endpoint for DHT data
  server.on("/dht", HTTP_GET, getDHTData);

  // Start the server
  server.begin();
  Serial.println("Server started...");
}

void loop() {
  server.handleClient();
}

// POST Methods
void setlampupertama() {
  lampupertamastat = !lampupertamastat;
  digitalWrite(led1, lampupertamastat ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", lampupertamastat ? "ON" : "OFF");
}
void setlampukedua() {
  lampukeduastat = !lampukeduastat;
  digitalWrite(led2, lampukeduastat ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", lampukeduastat ? "ON" : "OFF");
}
void setlampuketiga() {
  lampuketigastat = !lampuketigastat;
  digitalWrite(led3, lampuketigastat ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", lampuketigastat ? "ON" : "OFF");
}
void setlampukeempat() {
  lampukeempatstat = !lampukeempatstat;
  digitalWrite(led4, lampukeempatstat ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", lampukeempatstat ? "ON" : "OFF");
}

// GET Methods
void getlampupertama() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", lampupertamastat ? "ON" : "OFF");
}
void getlampukedua() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", lampukeduastat ? "ON" : "OFF");
}
void getlampuketiga() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", lampuketigastat ? "ON" : "OFF");
}
void getlampukeempat() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", lampukeempatstat ? "ON" : "OFF");
}

// DHT Data Endpoint
void getDHTData() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check if readings are valid
  if (isnan(temperature) || isnan(humidity)) {
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(500, "text/plain", "Failed to read from DHT sensor!");
    return;
  }

  // Send JSON response
  String json = "{";
  json += "\"temperature\": " + String(temperature) + ",";
  json += "\"humidity\": " + String(humidity);
  json += "}";
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json", json);
}
