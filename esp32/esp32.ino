void setup() {

  Serial.begin(115200);

  delay(1000);

  Serial.println("===============================");
  Serial.println("       PRUEBA DE ESP32");
  Serial.println("===============================");
  Serial.println();
}

void loop() {

  Serial.println("Jose Luis Milan");
  Serial.println("00144723");
  Serial.print("ESP32 funcionando correctamente - Tiempo activo: ");
  Serial.print(millis() / 1000.0);
  Serial.println(" segundos");


  delay(2000);
}