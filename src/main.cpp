#include <Arduino.h>

const int pinA = 8;
const int pinB = 9;

constexpr float frequency = 10; 

const unsigned long active_percentage = 30; 
constexpr unsigned long period = 1000 / (frequency*2); 
constexpr unsigned long active_duration = period * active_percentage/100;
constexpr unsigned long break_duration = period - active_duration;

// unsigned long start_time;
// const unsigned long max_ringing_time = 4000; 

void setup() {
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  //start_time = millis();
}

void loop() {
  // if(millis() - start_time > max_ringing_time) {
  //   while(true);
  // } 
  // Pin A HIGH, Pin B LOW
  digitalWrite(pinA, HIGH);
  delay(active_duration);
  digitalWrite(pinA, LOW);
  //digitalWrite(pinB, LOW);
  delay(break_duration);

  // Pin A LOW, Pin B HIGH
  digitalWrite(pinB, HIGH);
  delay(active_duration);
  digitalWrite(pinB, LOW);
  //digitalWrite(pinA, LOW);
  delay(break_duration);
}

	
