#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
#include <avr/sleep.h>
#include <avr/power.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
RTC_DS3231 rtc;

#define TOUCH_PIN 2  // Interrupt pin

volatile bool wakeFlag = false;

void wakeUp() {
  wakeFlag = true;
}

void setup() {
  Serial.begin(9600);
  delay(300);
  Wire.begin();

  lcd.init();
  lcd.backlight();

  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC!");
    lcd.print("RTC Error!");
    while (1);
  }

  pinMode(TOUCH_PIN, INPUT);

  // Show normal message immediately - no blank screen
  lcd.print("Starting...");

  // Only check serial briefly (non-blocking feel), short window
  checkForTimeSet();

  lcd.clear();
  lcd.print("Touch to check");
  delay(1500);
  goToSleep();
}

void checkForTimeSet() {
  unsigned long startWait = millis();
  while (millis() - startWait < 3000) {  // reduced to 3 sec, quick check
    if (Serial.available()) {
      String line = Serial.readStringUntil('\n');
      int yr, mo, dy, hh, mi, ss;
      if (sscanf(line.c_str(), "%d,%d,%d,%d,%d,%d", &yr, &mo, &dy, &hh, &mi, &ss) == 6) {
        rtc.adjust(DateTime(yr, mo, dy, hh, mi, ss));
        Serial.println("RTC time manually set!");
        lcd.clear();
        lcd.print("Time Updated!");
        delay(1000);
      }
      break;
    }
  }
}

void loop() {
  // Should never really reach here continuously, sleep handles flow
}

void goToSleep() {
  lcd.noBacklight();
  lcd.clear();

  attachInterrupt(digitalPinToInterrupt(TOUCH_PIN), wakeUp, RISING);

  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_mode(); // CPU sleeps here

  // ---- Execution resumes here after wake ----
  sleep_disable();
  detachInterrupt(digitalPinToInterrupt(TOUCH_PIN));

  showDataFor5Seconds();
  goToSleep(); // back to sleep after showing data
}

void showDataFor5Seconds() {
  lcd.backlight();

  DateTime now = rtc.now();
  float temp = rtc.getTemperature();

  lcd.setCursor(0, 0);
  lcd.print(now.day() < 10 ? "0" : "");
  lcd.print(now.day());
  lcd.print('/');
  lcd.print(now.month() < 10 ? "0" : "");
  lcd.print(now.month());
  lcd.print('/');
  lcd.print(now.year());

  lcd.setCursor(0, 1);
  lcd.print(now.hour() < 10 ? "0" : "");
  lcd.print(now.hour());
  lcd.print(':');
  lcd.print(now.minute() < 10 ? "0" : "");
  lcd.print(now.minute());
  lcd.print(" ");
  lcd.print(temp, 1);
  lcd.print("C");

  delay(5000); // show for 5 seconds
}