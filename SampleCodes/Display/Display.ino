
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire);

#define PIN 19
#define PIN_2 34

void setup() {
  Serial.begin(115200);

  setupDisplay();
  testdrawchar();

  pinMode(PIN, OUTPUT);
  pinMode(PIN_2, INPUT);
}

void loop() {

  //digitalWrite(PIN, LOW);
  //delay(1000);
  //digitalWrite(PIN, HIGH);
  //delay(1000);

  Serial.println(analogRead(PIN_2));

  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println(analogRead(PIN_2));
  display.display();


  delay(500);
}

void setupDisplay() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  // Clear the buffer
  display.clearDisplay();
}


void testdrawchar(void) {
  display.clearDisplay();

  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  // Not all the characters will fit on the display. This is normal.
  // Library will draw what it can and the rest will be clipped.
  for (int16_t i = 0; i < 256; i++) {
    if (i == '\n') display.write(' ');
    else          display.write(i);
  }

  display.display();
  delay(2000);
}
