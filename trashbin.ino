#include <Arduino.h>
#include <ESP32Servo.h>   // <-- This is the correct library for ESP32

// Pins (these are fine for most ESP32 boards)
#define TRIG_PIN  5
#define ECHO_PIN  18
#define SERVO_PIN 15
#define LED_PIN   2   // Onboard LED on many ESP32 boards

Servo myServo;

long duration;
int distance;

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  // Allow allocation of all timers for ESP32 (recommended)
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  
  myServo.setPeriodHertz(50);    // Standard 50 Hz servo
  myServo.attach(SERVO_PIN, 500, 2400);  // 500μs to 2400μs pulse (typical for most servos)
  
  myServo.write(0);      // Lid closed
  digitalWrite(LED_PIN, LOW);
  
  delay(500);
}

int getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH, 30000); // timeout ~30ms (~5m max range)
  if (duration == 0) return 999; // no echo received
  
  distance = duration * 0.0343 / 2;  // Speed of sound 343 m/s → 0.0343 cm/µs
  return distance;
}

void loop() {
  int dist = getDistance();

  Serial.print("Distance: ");
  Serial.print(dist);
  Serial.println(" cm");

  if (dist > 0 && dist < 20) {        // Hand detected within 20 cm
    myServo.write(90);                // Open lid
    digitalWrite(LED_PIN, HIGH);
    delay(5000);                      // Keep open for 5 seconds
    myServo.write(0);                 // Close again after 5s
    digitalWrite(LED_PIN, LOW);
    delay(1000);                      // Small debounce after closing
  }

  delay(200);  // Main loop delay
}