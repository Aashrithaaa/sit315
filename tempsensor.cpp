// C++ code
//
#include <Adafruit_LiquidCrystal.h>

int temp = 0;

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  lcd_1.begin(16, 2);
}

void loop()
{
  temp = map(((analogRead(A0) + 20) * 3.043), 0, 1023, -20, 120);
  Serial.println(temp);
  if (temp < 30) {
    digitalWrite(10, HIGH);
  } else {
    digitalWrite(10, LOW);
  }
  if (temp < 50) {
    digitalWrite(11, HIGH);
  } else {
    digitalWrite(11, LOW);
    if (temp < 70) {
      digitalWrite(12, HIGH);
    } else {
      digitalWrite(12, LOW);
    }
  }
  lcd_1.setCursor(0, 0);
  lcd_1.print("temp montr. sys");
  lcd_1.setCursor(0, 1);
  lcd_1.print("Temp value");
  lcd_1.setCursor(13, 1);
  lcd_1.print(temp);
  delay(10); // Delay a little bit to improve simulation performance
}