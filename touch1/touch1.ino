const int TOUCH_PIN = 4;   
const int UMBRAL = 350;

void setup() {

  Serial.begin(115200);

  delay(1000);

  Serial.println("PRUEBA SENSOR TOUCH");
  Serial.println();
}

void loop() {

  int valorTouch = touchRead(TOUCH_PIN);

  Serial.print("Valor Touch: ");
  Serial.println(valorTouch);

  if(valorTouch < UMBRAL) {
    Serial.println("Jose Luis Milan - 00144723");
  }
  

  delay(200);
}