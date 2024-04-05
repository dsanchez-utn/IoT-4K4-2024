
const int ledPin = 23;

void setup(){
  pinMode(ledPin, OUTPUT);
}
void loop(){
  // aumenta el brillo
  for(int ciclo = 0; ciclo <= 255; ciclo++){
    analogWrite(ledPin, ciclo);
    delay(5);
  }
  // disminuye el brillo
 for(int ciclo = 255; ciclo >= 0; ciclo--){
    analogWrite(ledPin, ciclo);
    delay(5);
  }
  delay(500);
}
