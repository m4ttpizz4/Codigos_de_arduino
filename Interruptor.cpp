void setup(){
  pinMode(7, OUTPUT); //Led
  pinMode(8, INPUT); //Botão
}

int estado_led = 0;

void loop(){
  if(digitalRead(8)){
    if(estado_led == 0){
      estado_led = 1;
      digitalWrite(7, HIGH);
    } else{
      estado_led = 0;
      digitalWrite(7, LOW);
    }
    delay(100);
  }
}
