//const short PIN_LED = 12;

void setup() {
    // put your setup code here, to run once:
  Serial.begin(9600);
  delay(2000);
  Serial.println("Hola alumnos del 4K4!");
  pinMode(LED_BUILTIN, OUTPUT);
  //pinMode(PIN_LED, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);
  static int contador = 0;
  //digitalWrite(PIN_LED, HIGH);
  delay(1000);
  contador++;
  Serial.print("Encendido ");
  Serial.println(contador);
  digitalWrite(LED_BUILTIN, HIGH);
  //digitalWrite(PIN_LED, LOW);
  delay(1000); 
}

void incrementa(int &i) // Nótese el uso de una referencia
{
  i = i + 1;
}