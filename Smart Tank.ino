
/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-ultrasonic-sensor-piezo-buzzer
 */

#define TRIG_PIN   5 // ESP32 pin GIOP26 connected to Ultrasonic Sensor's TRIG pin
#define ECHO_PIN   18 // ESP32 pin GIOP25 connected to Ultrasonic Sensor's ECHO pin
#define BUZZER_PIN 14 // ESP32 pin GIOP17 connected to Piezo Buzzer's pi
//#define l 2 // ESP32 pin GIOP17 connected to Piezo Buzzer's pin

#define DISTANCE_THRESHOLD 5 // centimeters

// variables will change:
float duration_us, distance_cm;

void setup() {
  Serial.begin (9600);         // initialize serial port
  pinMode(TRIG_PIN, OUTPUT);   // set ESP32 pin to output mode
  pinMode(ECHO_PIN, INPUT);    // set ESP32 pin to input mode
  pinMode(BUZZER_PIN, OUTPUT); // set ESP32 pin to output mode
}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);
  // calculate the distance
  distance_cm = 0.017 * duration_us;

  if (distance_cm < DISTANCE_THRESHOLD){
    digitalWrite(BUZZER_PIN, HIGH);
      Serial.println("Full");
  }
  else if(distance_cm >12 && distance_cm<13  )
  {
          digitalWrite(BUZZER_PIN, LOW);
          Serial.println("Half");
  }  // turn off Piezo Buzzer
  else if(distance_cm>19)
  {
          digitalWrite(BUZZER_PIN, HIGH);
          Serial.println("Empty");
  }
  else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(5000);
}


