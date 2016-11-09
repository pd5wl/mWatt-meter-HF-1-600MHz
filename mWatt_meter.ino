/*-----( Import needed libraries )-----*/
#include <Wire.h>  // Comes with Arduino IDE
#include <LiquidCrystal_I2C.h>
#include <math.h> 

/*-----( Declare Constants )-----*/
#define BACKLIGHT_PIN 13

/*-----( Declare objects )-----*/
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

// the setup routine runs once when you press reset:
void setup() {
// LCD
  lcd.begin(16,2);   // initialize the lcd for 16 chars 2 lines, turn on backlight
  lcd.clear();
  pinMode ( BACKLIGHT_PIN, OUTPUT );
  digitalWrite ( BACKLIGHT_PIN, HIGH );
  lcd.setCursor(0,0); //Start at character 4 on line 0
  lcd.print("dBm/mW meter");
  lcd.setCursor(0,1);
  lcd.print("PD5WL Ver. 0.1b");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Meting");
  lcd.setCursor(5,1);
  lcd.print("dBm");
  lcd.setCursor(14,1);
  lcd.print("W");
}

// the loop routine runs over and over again forever:
void loop() {
  float sensorValue = analogRead(A0);// read the input on analog pin 0:
  float spanning = sensorValue * (5 / 1023.0);  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  double dBm=(40*spanning-40); // calculate dBm
  double Watt= pow( 10.0, (dBm - 30.0) / 10.0);

//Display results   
  lcd.setCursor(0,1);
  lcd.print(dBm,1);
  lcd.setCursor(9,1);
  lcd.print(Watt,2);
  delay(1000);
}
