#define USE_ARDUINO_INTERRUPTS true
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <PulseSensorPlayground.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Initialize LCD with I2C address 0x27
const int PulseWire = 1;           // Pulse sensor connected to analog pin 1
const int pinLED = 13;             // LED pin
const int pinBuzzer = 4;           // Buzzer pin
int Threshold = 512;               // Set a reasonable threshold for pulse detection
int bpm = 0;                       // Beats per minute

PulseSensorPlayground pulseSensor; // Create PulseSensorPlayground object

void setup() {
  Serial.begin(9600);              // Start serial communication at 9600 baud
  lcd.begin();                     // Initialize LCD
  lcd.backlight();                // Turn on the backlight
  pulseSensor.analogInput(PulseWire);  // Set the analog input for the pulse sensor
  pulseSensor.blinkOnPulse(pinLED);    // Blink the LED on each pulse
  pulseSensor.setThreshold(Threshold); // Set the threshold for pulse detection
  pinMode(pinBuzzer, OUTPUT);       // Set the buzzer pin as output

  if (pulseSensor.begin()) {
    Serial.println("Cek Detak Jantungmu!"); // Notify user
    delay(1000);
    lcd.setCursor(0, 0);
    lcd.println("Cek Jantungmu");          // Display message on LCD
    delay(1000);
    lcd.clear();
  } else {
    Serial.println("Pulse Sensor tidak terdeteksi!");
    lcd.setCursor(0, 0);
    lcd.println("Sensor tidak");
    lcd.setCursor(0, 1);
    lcd.println("terdeteksi!");
    while (1); // Halt if sensor fails
  }
}

void loop() {
  bpm = pulseSensor.getBeatsPerMinute(); // Get BPM value from sensor

  if (pulseSensor.sawStartOfBeat()) {    // Check if a beat was detected
    delay(20);
    for (int i = 0; i < 12; i++) {      // Display counting message
      lcd.setCursor(0, 0);
      lcd.print("Menghitung . . .");
      Serial.println("Menghitung . . . .");
      delay(500);
      lcd.clear();
    }
    buzz();  // Activate the buzzer
    lcd_tampil(); // Update the LCD with BPM value
  }
}

void buzz() {
  if (bpm > 0) {
    digitalWrite(pinBuzzer, HIGH);
    delay(250);
    digitalWrite(pinBuzzer, LOW);
    delay(250);
  }
}

void lcd_tampil() {
  Serial.print("BPM : ");
  Serial.println(bpm);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Nilai BPM Anda");
  lcd.setCursor(0, 1);
  lcd.print("> BPM = ");
  lcd.print(bpm);
  delay(3000); // Display BPM value for 3 seconds
  lcd.clear();
}
