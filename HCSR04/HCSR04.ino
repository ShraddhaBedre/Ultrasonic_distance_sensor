/*Distance Measuring tool using HC-SR04 ULTRASONIC DISTANCE SENSOR and ARDUINO-NANO Board
Trigger = D5
Echo = D10
Vcc = 5V
GND = GND*/
#define trigPin 5
#define echoPin 10

float timeDelay, distance;
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}

void loop() {
 
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);

 //measure the response from HC-SR04
 timeDelay = pulseIn(echoPin, HIGH);

 distance = (timeDelay / 2)* 0.034606;

 Serial.print("Distance = ");
 if((distance >= 400)||(distance <= 2)){
 Serial.println("Out of range"); 
 }
 else{
 Serial.print(distance);
 Serial.println(" cm");
 }
 delay(100);
}
