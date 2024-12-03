#include <Servo.h> // Include Servo library

// Pin assignments
const int soundSensorPin = 2;  // Digital pin for sound sensor
const int ledPin = 13;         // Built-in LED pin
const int servoPin = 9;        // PWM pin for servo

// Variables to manage state
Servo myServo;                 // Create Servo object
bool isLightOn = false;        // Tracks LED and servo state
unsigned long lastClapTime = 0; // Debouncing to avoid false triggers
const int debounceDelay = 500; // 500ms delay to avoid double claps

void setup() {
  pinMode(soundSensorPin, INPUT); // Set sound sensor pin as input
  pinMode(ledPin, OUTPUT);        // Set LED pin as output

  myServo.attach(servoPin);       // Attach servo to the pin
  myServo.write(0);               // Start servo in OFF position
  digitalWrite(ledPin, LOW);      // Ensure LED is OFF initially
}

void loop() {
  int soundDetected = digitalRead(soundSensorPin); // Read sound sensor
  unsigned long currentTime = millis();            // Current time for debounce
  
  if (soundDetected == HIGH && currentTime - lastClapTime > debounceDelay) {
    lastClapTime = currentTime; // Update last clap time
    
    if (isLightOn) {
      // Turn OFF the light and reset servo
      digitalWrite(ledPin, LOW); // Turn OFF LED
      myServo.write(0);          // Move servo to OFF position
      isLightOn = false;         // Update state
    } else {
      // Turn ON the light and move servo
      digitalWrite(ledPin, HIGH); // Turn ON LED
      myServo.write(360);          // Move servo to ON position
      isLightOn = true;           // Update state
    }
    delay(100); // Small delay to allow for servo movement
  }
}
