#include <Servo.h>
#define TRIG_PIN_SS1 12
#define ECHO_PIN_SS1 13
#define TRIG_PIN_SS2 4
#define ECHO_PIN_SS2 2
#define TIME_OUT 5000

Servo servo1;
Servo servo2;

void setup() {
  Serial.begin(9600);
  servo1.attach(9);
  servo2.attach(10);
  pinMode(TRIG_PIN_SS1, OUTPUT);
  pinMode(ECHO_PIN_SS1 , INPUT);
  pinMode(TRIG_PIN_SS2, OUTPUT);
  pinMode(ECHO_PIN_SS2, INPUT);
  servo1.write(0);
  servo2.write(180);
}

void loop() {
  long durationSS1; float distanceSS1;

  digitalWrite(TRIG_PIN_SS1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN_SS1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_SS1, LOW);


  durationSS1 = pulseIn(ECHO_PIN_SS1, HIGH, TIME_OUT);


  long durationSS2; float distanceSS2;

  digitalWrite(TRIG_PIN_SS2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN_SS2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_SS2, LOW);


  durationSS2 = pulseIn(ECHO_PIN_SS2, HIGH, TIME_OUT);


  // convert to distance
  distanceSS2 = durationSS2 / 29.1 / 2;
  if(distanceSS2>40) distanceSS2=40;

  // convert to distance
  distanceSS1 = durationSS1 / 29.1 / 2;
  if(distanceSS1>40) distanceSS1=40;
  Serial.print("Distance 2: ");
  Serial.println(distanceSS2);
    if (distanceSS2 >= 1 && distanceSS2 <= 4)
    {
      servo1.write(90);
      servo2.write(90);
      delay(5000);
    }
    else
    {
      servo1.write(0);
      servo2.write(180);
    }
 
}
