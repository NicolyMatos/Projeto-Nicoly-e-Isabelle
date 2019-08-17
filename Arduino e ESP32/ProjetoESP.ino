#define RXD2 16
#define TXD2 17
#include <WiFi.h>
#include <HTTPClient.h>
#include<String.h>

const String SENSOR = "\"SENSOR\":";

int pinLED1 = 2;
float seno;


const char* ssid = "RJNRS"; // your wireless network name (SSID)
const char* password = "2207140714"; // your Wi-Fi network password

int frequencia;
void sens1();
String payload = "0000000000000";

const String UPLOAD = "upload"; 
const String DOWNLOAD = "download";

String JSON_SENSOR(){ 
 int sensor_value = analogRead(A0);
 
    return "{" +
      SENSOR + String(sensor_value) +
      "}";
}

void uploadSENSOR(){ 

   http.begin(LOCATION+UPLOAD);
   http.addHeader("Content-Type", "application/json");
   http.POST(JSON_SENSOR());
   http.end();
}
String downloadWEB(){
  
      http.begin(LOCATION+DOWNLOAD); 
      http.GET();
      String payload = http.getString();
      http.end();
      return payload;
  
}


void setup() {

  Serial.begin(9600); //Inicia a comunicação serial
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
 

  pinMode(pinLED1, OUTPUT);
  pinMode(25, OUTPUT);

  WiFi.begin(ssid, password);

  Serial.print("Conectando...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("conectado");


}

void loop() {
  int analogSensor = analogRead(sensor);
  if (digitalRead(25))
    Serial.println("{ALARME: 1}");
    Serial.print(JSON_SENSOR());
    uploadSENSOR(); 
    delay(10);
  else 
    Serial.println("{ALARME: 0}");
  if (Serial2.available()) {
    char c = (char(Serial2.read()));
    Serial.print ("Arduino: ");
    Serial.println(c);
    Serial.print(JSON_SENSOR());
    uploadSENSOR(); 
    delay(10);
    if (c == '1' and payload[11] == '1') {
      //Serial.println("ativado");
      ativar_buzzer();
    }
  }


  String site = "http://projetoin.herokuapp.com/download";
  //Serial.println(site);

  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
    //    Serial.print("Endereço IP: ");
    //    Serial.println(WiFi.localIP());
    HTTPClient http;  //Declare an object of class HTTPClient
    http.begin(site);
    int httpCode = http.GET();
    //Serial.println(httpCode);
    //Serial.println(http);
    if (httpCode > 0) { //Check the returning code
      payload = http.getString();   //Get the request response payload
      Serial.print("Internet:  ");
      Serial.println(payload[11]);                     //Print the response payload
      if (payload[11] == '0') {
        desativar_buzzer();
      }
    }
    http.end();   //Close connection
  }


}


void ativar_buzzer() {
  Serial.println("Ativando Buzzer");
  digitalWrite(25, HIGH);
  
}


void desativar_buzzer() {
  Serial.println("Desativando Buzzer");
  digitalWrite(25, LOW);
}
