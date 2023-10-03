#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);


const int pinSensor = A5;
const int pinRelay = 7;
const int buzzer = 2;     // inisialisasi buzzer pin pada 2

int nilaiSensor = 0;

void setup (){
  lcd.init();
  lcd.backlight();
  lcd.clear();
Serial.begin (9600);

pinMode(pinRelay, OUTPUT);
pinMode(pinSensor, INPUT); // Jadikan sensor sebagai input analog
pinMode(buzzer, OUTPUT);  // Untuk menentukan pin buzzer sebagai output
digitalWrite(pinRelay, LOW);

}

void loop(){

nilaiSensor = analogRead(pinSensor);
Serial.print ("Sensor = ");
Serial.println(nilaiSensor);

if (nilaiSensor > 550) {

digitalWrite(pinRelay, HIGH);
Serial.print ("Sensor = ");
Serial.print (nilaiSensor);
Serial.println ("\t => SUARA TERDETEKSI");
lcd.setCursor(0, 0);
  lcd.print("Sensor =  ");
  lcd.print(nilaiSensor);
  lcd.setCursor(2, 1);
  lcd.print("SUARA TERDETEKSI");
  lcd.clear();

delay (3000);

}

else {

//turn Relay off:
digitalWrite(pinRelay, LOW);
lcd.setCursor(0, 0);
  lcd.print("Sensor =  ");
  lcd.print(nilaiSensor);
  lcd.setCursor(2, 1);
  lcd.print("TIDAK TERDETEKSI");
  lcd.clear();

}

delay(2000);

}
