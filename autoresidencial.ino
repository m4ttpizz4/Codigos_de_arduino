#include <SoftwareSerial.h>

// Configuração da comunicação serial software
SoftwareSerial bluetooth(10, 11); // RX, TX

const int ledPin = 13; // Pino do LED
String mensagem = "";  // Variável para armazenar a mensagem recebida

void setup() {
  pinMode(ledPin, OUTPUT); // Define o pino do LED como saída
  digitalWrite(ledPin, LOW); // Inicia com LED apagado
  
  // Inicia a comunicação serial com o computador (para debug)
  Serial.begin(9600);
  
  // Inicia a comunicação serial com o módulo Bluetooth
  bluetooth.begin(9600);
  
  Serial.println("Sistema pronto. Aguardando comandos...");
}

void loop() {
  // Verifica se há dados disponíveis no Bluetooth
  while (bluetooth.available()) {
    char caractere = bluetooth.read(); // Lê um caractere
    mensagem += caractere; // Adiciona à string da mensagem
    
    // Se for fim de linha (ou tempo suficiente passou)
    if (caractere == '\n') {
      mensagem.trim(); // Remove espaços e quebras de linha
      
      Serial.print("Mensagem recebida: ");
      Serial.println(mensagem);
      
      // Verifica se a mensagem é "sala"
      if (mensagem.equalsIgnoreCase("sala")) {
        digitalWrite(ledPin, HIGH); // Acende o LED
        bluetooth.println("LED aceso - Sala");
        Serial.println("LED aceso");
      } else {
        digitalWrite(ledPin, LOW); // Apaga o LED
        bluetooth.println("Comando desconhecido");
        Serial.println("Comando desconhecido");
      }
      
      mensagem = ""; // Limpa a mensagem para a próxima
    }
  }
}