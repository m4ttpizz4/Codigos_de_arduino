#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10, 11);
const int ledPin = 13;
String mensagem = "";

void setup() {
  pinMode(ledPin, OUTPUT); 
  digitalWrite(ledPin, LOW);

  Serial.begin(9600);
  bluetooth.begin(9600);
  
  Serial.println("Sistema pronto. Aguardando comandos...");
}

void loop() {
  
  while (bluetooth.available()) {
    char caractere = bluetooth.read();
    mensagem += caractere;
    
 
    if (caractere == '\n') {
      mensagem.trim();
      
      Serial.print("Mensagem recebida: ");
      Serial.println(mensagem);
      

      if (mensagem.equalsIgnoreCase("sala")) {
        digitalWrite(ledPin, HIGH);
        bluetooth.println("LED aceso - Sala");
        Serial.println("LED aceso");
      } else {
        digitalWrite(ledPin, LOW);
        bluetooth.println("Comando desconhecido");
        Serial.println("Comando desconhecido");
      }
      
      mensagem = ""; 
    }
  }
}
