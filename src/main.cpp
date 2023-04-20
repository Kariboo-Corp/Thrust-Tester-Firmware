#include <Arduino.h>
#include <HX711.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#include <main.h>

HX711 loadcell;
LiquidCrystal_I2C lcd(0x27, 20, 2);
Servo esc;

void setup() {
  Serial.begin(115200);
  Serial.println("thrust, weight");
  lcd.init();
  esc.attach(PWM_OUT, 1000, 2000);

  loadcell.begin(DATA_1, CLK_1);
  loadcell.set_scale(91821.00 / 900);
  //91821.00000
  
  loadcell.tare();

  pinMode(PWM_OUT, OUTPUT);
  pinMode(SWITCH, INPUT_PULLUP);

  lcd.setCursor(0, 0);
  lcd.print("init done.");
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Thrust : ");
  lcd.setCursor(0, 1);
  lcd.print("Weight : ");
}

unsigned int pot_value = 0;
double weight = 0;

void loop() {

  pot_value = analogRead(POT);
  if (digitalRead(SWITCH)) {
    esc.write(map(pot_value, 0, 1023, 0, 180));
  } else {
    esc.write(0);
  }

  lcd.setCursor(9, 0);
  lcd.print(map(pot_value, 0, 1023, 0, 100));
  lcd.print(" %     ");

  weight = loadcell.get_units(2);

  lcd.setCursor(9, 1);
  lcd.print(weight);
  lcd.print(" g     ");

  Serial.print(map(pot_value, 0, 1023, 0, 100));
  Serial.print(", ");
  Serial.println(weight, 2);

  delay(5);

}