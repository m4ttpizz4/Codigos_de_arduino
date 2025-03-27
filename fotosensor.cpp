void setup(){
  pinMode(8, OUTPUT); //led
  pinMode(A0, INPUT); //Fotosensor
}

void loop(){
  int valor = analogRead(A0); //valor entre 0 e 1023
  if(valor < 200){ //luminosidade baixa
    digitalWrite(8, HIGH); 
  } else{
    digitalWrite(8, LOW);
  }
 }
