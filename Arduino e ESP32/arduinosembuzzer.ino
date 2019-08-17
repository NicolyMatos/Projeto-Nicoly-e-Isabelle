#include <SoftwareSerial.h>

int pinoFototransistor1 = A0;
int pinLED1 = 7;
void sens1();

SoftwareSerial esp(8, 9);

void setup() {

  Serial.begin(9600); //Inicia a comunicação serial
  esp.begin(9600);

  pinMode(pinLED1, OUTPUT);

}

void loop() {
  sens1();

}

void sens1() {
  int valor = analogRead(pinoFototransistor1);
  if (valor < 1000) {
    Serial.print("Recebendo sinal infravermelho1:  ");
    Serial.println(valor);
    digitalWrite(pinLED1, LOW);
    esp.print('0');
  } else { //SENÃO, FAZ
    Serial.println("Sinal infravermelho1 interrompido");
    esp.print('1');
    digitalWrite(pinLED1, HIGH);
    
  }
  delay(1000);
}
