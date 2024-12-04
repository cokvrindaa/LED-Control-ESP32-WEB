#include <WiFi.h>
#include <WebServer.h>
const char* ssid = "Samsung Galaxy A55";
const char* password = "123456789";
WebServer server(80);
// 19 18 5 4
// bawaan led esp2
const int espLed = 2;
const int led1 = 19;
const int led2 = 18;
const int led3 = 5;
const int led4 = 4;

bool lampupertamastat = false;
bool lampukeduastat = false;
bool lampuketigastat = false;
bool lampukeempatstat = false;

void setup() {

  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(espLed, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  WiFi.begin(ssid, password);
  Serial.print("lagi koneksii....");
  // ketika tidak konek
  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    Serial.print(".");
    digitalWrite(espLed, LOW);
  }
  // ketika konek
  Serial.println("\nConnected to WiFi!");
  digitalWrite(espLed, HIGH);
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/lampupertama", HTTP_GET, getlampupertama);
  server.on("/lampukedua", HTTP_GET, lampukedua);
  server.on("/lampuketiga", HTTP_GET, lampuketiga);
  server.on("/lampukeempat", HTTP_GET, lampukeempat);


  server.on("/lampupertama", HTTP_POST, setlampupertama);
  server.on("/lampukedua", HTTP_POST, lampukedua);
  server.on("/lampuketiga", HTTP_POST, lampuketiga);
  server.on("/lampukeempat", HTTP_POST, lampukeempat);

  server.begin();
  Serial.println("server started..");
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}
// Metod post
void setlampupertama() {
  lampupertamastat = !lampupertamastat;
  // Kalau true high, false low.
  digitalWrite(led1, lampupertamastat ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", lampupertamastat ? "ON" : "OFF");
}
void lampukedua() {
  lampukeduastat = !lampukeduastat;
  // Kalau true high, false low.
  digitalWrite(led2, lampukeduastat ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", lampukeduastat ? "ON" : "OFF");
}
void lampuketiga() {
  lampuketigastat = !lampuketigastat;
  // Kalau true high, false low.
  digitalWrite(led3, lampuketigastat ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", lampuketigastat ? "ON" : "OFF");
}
void lampukeempat() {
  lampukeempatstat = !lampukeempatstat;
  // Kalau true high, false low.
  digitalWrite(led4, lampukeempatstat ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", lampukeempatstat ? "ON" : "OFF");
}
// metod get
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