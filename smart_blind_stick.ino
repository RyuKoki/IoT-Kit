/* THIS PROJECT FOR CRAFTING THE SMART BLIND STICK */
// Arduino Uno R3      =  1
// Ultrasonic HC-SR04  =  2
// Buzzer              =  1

/* THE CONNECTION OF METERIALS */
// Ultrasonic 1st      =  Vcc===>5V, TRIG===>Digital pin 2, ECHO===>Digital pin 3, GND===>GND
// Ultrasonic 2nd      =  Vcc===>5V, TRIG===>Digital pin 5, ECHO===>Digital pin 6, GND===>GND
// Buzzer              =  Positive===>Digital pin 8, Negative===>GND

#define ECHO_PIN1 (3)
#define TRIG_PIN1 (2)
#define ECHO_PIN2 (6)
#define TRIG_PIN2 (5)
#define PIEZO_PIN (8)

void ActivateSensor_1() {
  digitalWrite(TRIG_PIN1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN1, LOW);
}

void ActivateSensor_2() {
  digitalWrite(TRIG_PIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN2, LOW);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // set the echo pin of ultrasonic sensor
  pinMode(ECHO_PIN1, INPUT);
  pinMode(ECHO_PIN2, INPUT);
  // set the trigger pin of ultrasonic sensor
  pinMode(TRIG_PIN1, OUTPUT);
  pinMode(TRIG_PIN2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // define the variables for carrying the value of duration in microsenconds and distance in centimetre
  int duration1, distance1, duration2, distance2;

  // start the 1st ultrasonic
  ActivateSensor_1();
  // measure the distance in 1st ultrasonic in centimetre
  duration1 = pulseIn(ECHO_PIN1, HIGH);
  distance1 = duration1 / 29 / 2; // or divide by 58 or multiple by 0.017

  // start the 2nd ultrasonic
  ActivateSensor_2();
  // measure the distance in 2nd ultrasonic in centimetre
  duration2 = pulseIn(ECHO_PIN2, HIGH);
  distance2 = duration2 / 29 / 2; // or divide by 58 or multiple by 0.017

  // showing the value up in the serial monitor
  Serial.print(distance1);
  Serial.print("          ");
  Serial.println(distance2);

  // condition for alerting 
  if (distance1 <= 10 || distance2 <=10) {
    tone(PIEZO_PIN, 1000, 300);
    delay(450);
  } else {
    noTone;
  }
}
