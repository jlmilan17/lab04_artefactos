#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

Adafruit_SH1106G display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);

const int TOUCH_PIN_1 = 4;      
const int TOUCH_PIN_2 = 27;     

const int UMBRAL_TOUCH = 350;    

void setup() {

  Serial.begin(115200);

  Wire.begin(21, 22);

  if (!display.begin(OLED_ADDRESS, true)) {
    Serial.println("Error al iniciar la pantalla OLED");
    while (1);
  }

  display.clearDisplay();
  display.setTextColor(SH110X_WHITE);
}

void loop() {

  int valorTouch1 = touchRead(TOUCH_PIN_1);
  int valorTouch2 = touchRead(TOUCH_PIN_2);

  bool boton1 = valorTouch1 < UMBRAL_TOUCH;
  bool boton2 = valorTouch2 < UMBRAL_TOUCH;

  Serial.print("T1: ");
  Serial.print(valorTouch1);
  Serial.print("  |  T2: ");
  Serial.println(valorTouch2);

  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(26, 5);
  display.println("ESP32 TOUCH");

  display.drawCircle(20, 52, 5, SH110X_WHITE);
  display.drawCircle(108, 52, 5, SH110X_WHITE);

  if (boton1 && boton2) {

    display.setCursor(22, 28);
    display.println("AMBOS BOTONES");

    display.fillCircle(20, 52, 5, SH110X_WHITE);
    display.fillCircle(108, 52, 5, SH110X_WHITE);
  }

  else if (boton1) {

    display.setCursor(16, 28);
    display.println("BOTON 1 ACTIVADO");

    display.fillCircle(20, 52, 5, SH110X_WHITE);
  }

  else if (boton2) {

    display.setCursor(16, 28);
    display.println("BOTON 2 ACTIVADO");

    display.fillCircle(108, 52, 5, SH110X_WHITE);
  }

  else {

    display.setCursor(28, 28);
    display.println("ESPERANDO...");
  }

  display.display();

  delay(100);
}
