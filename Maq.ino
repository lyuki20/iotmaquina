#include <Servo.h>
Servo servo;
const int pinoBotao = 4; // Pinos equivalentes na placa WeMOS
const int pinoLed = 15; // Pinos equivalentes na placa WeMOS
const int pinoSensor = 13; // Pinos equivalentes na placa WeMOS

int estadoBotao = 0;
int pos = 0;

void setup(){  
  pinMode(pinoSensor, INPUT); //DEFINE O PINO COMO ENTRADA
  pinMode(pinoLed, OUTPUT); //DEFINE O PINO COMO SAÍDA   
  pinMode(pinoBotao, INPUT);
  servo.attach(13);
  
  digitalWrite(pinoLed, LOW); //LED INICIA DESLIGADO
  Serial.begin(9600);
}  
   
void loop(){
  estadoBotao = digitalRead(pinoBotao);
  if (digitalRead(pinoSensor) == 1){
        if (estadoBotao == HIGH) {
          Serial.println("Debug pinoSensor == 1");
          digitalWrite(pinoLed, HIGH);
          Serial.println(estadoBotao);
          delay(1000);
          //digitalWrite(pinoLed, LOW);
          //delay(1000);
          for(pos = 0; pos <=120; pos+=1) {
          servo.write(pos);
          delay(15);
}
          for(pos = 120; pos >=0; pos-=1) {
           servo.write(pos);
          delay(15);
}
        }
        else { digitalWrite(pinoLed, LOW); }
        
        //Serial.print(digitalRead(pinoSensor));
        Serial.println("Fora do if botão = high");
        //digitalWrite(pinoLed, HIGH); //ACENDE O LED
        //delay(5000);
  } else{
        digitalWrite(pinoLed, LOW); //APAGA O LED
        Serial.println("Debug: Fora do if pinoSensor == 1");
        delay(5000);
  }    
}
