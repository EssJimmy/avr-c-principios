#include <Wire.h>
#include <LiquidCrystal_I2C.h> // libreria LiquidCrystal_I2c de Frank de Brabander
#include <avr.io> 
// se puede copiar al ide de arduino y subirlo desde ahi

// config ultrasonic
const int trigger = 13;
const int echo = 12;

//config tilt
const int tilt = 11;

// config alarm stuff
const int alarm = 10;

//config switch
const int sw = 9;

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  pinMode(alarm, OUTPUT);
  pinMode(tilt, INPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(sw, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.clear();

  Serial.begin(9600);
}

void loop() {
  int val = digitalRead(tilt);
  int swVal = digitalRead(sw);

  if(swVal) {
    alarmConfig(val);
    long distance = irDistance();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor IR");
    lcd.setCursor(0, 1);
    lcd.print(distance); lcd.print("cm");
  }
  else {
    alarmConfig(val);
    long distance = ultrasound();
    if(distance != -1){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Ultrasonico");
      lcd.setCursor(0, 1);
      lcd.print(distance); lcd.print("cm");
    }
  }
  delay(100);
}

long irDistance(){
  long adc = analogRead(A0);
  long distance = 17659.7*pow(adc, -1.2062);
  return distance;
}

long ultrasound(){
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  
  long duration = pulseIn(echo, HIGH);
  long distance = duration * 0.034 / 2;
  
  if(distance > 200) distance = -1;
  return distance;
}

void alarmConfig(int val){
  if(val){
    for (int i=0; i < 180; i++) {
        float sinVal = (sin(i*(3.1412/180)));
        float toneVal = 2000+(int(sinVal*1000));
        tone(alarm, toneVal);
    }
  }
  else noTone(alarm);
}