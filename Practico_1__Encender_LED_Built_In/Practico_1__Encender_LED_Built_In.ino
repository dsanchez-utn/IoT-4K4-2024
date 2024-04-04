//int contador = 0;
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hola alumnos del 4K4!");
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("Encenderemos el Led integrado");
  delay(2000);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("Led integrado Encendido ");
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("Led integrado Apagado ");
  delay(1000);
}