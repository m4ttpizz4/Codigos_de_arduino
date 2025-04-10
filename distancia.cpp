int pinoEcho = 2, pinoTrig = 3; //Pino Echo e Trig, sendo Echo a entrada e Trig a saída

//função setup:
void setup(){
  pinMode(pinoEcho, INPUT);
  pinMode(pinoTrig, OUTPUT);
  Serial.begin(9600);
}

//função loop:
void loop(){
  digitalWrite(pinoTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinoTrig, LOW);

  double tempo = pulseIn(pinoEcho, HIGH);
  double distancia = 0.034 * tempo/2.0;
  double beep = distancia*10;
  Serial.println(distancia);

  if(distancia < 30.0){
    tone(4, 100, beep);
    delay(beep*2);
    noTone(4);
  }
}
