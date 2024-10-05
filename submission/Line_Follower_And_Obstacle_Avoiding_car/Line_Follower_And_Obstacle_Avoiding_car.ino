// line follow + insert obstacle code sequentially
// Motor Driver Pins
#define enA 10  // Enable1 L298 Pin enA
#define in1 9   // Motor1 L298 Pin in1
#define in2 8   // Motor1 L298 Pin in1
#define in3 7   // Motor2 L298 Pin in1
#define in4 6   // Motor2 L298 Pin in1
#define enB 5   // Enable2 L298 Pin enB
// Ultrasonic Sensor Pins
// #define trigPin 12
// #define echoPin 13

// IR Sensor Pins
#define leftIR A0
#define rightIR A1

#define echo A2    //Echo pin
#define trigger A3 //Trigger pin

#define servo A5
int Set=15;
int distance_L, distance_F, distance_R;

void setup() {
  // Motor setup, run once
  Serial.begin(9600); // start serial communication at 9600bps


  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);

  pinMode(echo, INPUT );// declare ultrasonic sensor Echo pin as input
  pinMode(trigger, OUTPUT); // declare ultrasonic sensor Trigger pin as Output  

  // IR Sensor setup
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);

  // Set initial motor speed
  analogWrite(enA, 50);
  analogWrite(enB, 50);

  pinMode(servo, OUTPUT);
  
 for (int angle = 70; angle <= 140; angle += 5)  {
   servoPulse(servo, angle);  }
 for (int angle = 140; angle >= 0; angle -= 5)  {
   servoPulse(servo, angle);  }

 for (int angle = 0; angle <= 70; angle += 5)  {
   servoPulse(servo, angle);  }

distance_F = Ultrasonic_read();

delay(500);

}

void loop() {

  distance_F = Ultrasonic_read();

  int leftIRValue = digitalRead(leftIR);
  int rightIRValue = digitalRead(rightIR);
  if (leftIRValue == LOW && rightIRValue == LOW) {
      if(distance_F > Set){
    moveForward();
    }
    else{
      stopCar();
      delay(2000);
      compareDistance();
    } 
  }
  // Line Following
  else if (leftIRValue == HIGH && rightIRValue == LOW) {
    // Turn right
    turnRight();
  } else if (leftIRValue == LOW && rightIRValue == HIGH) {
    // Turn left
    turnLeft();
  } else {
    // Move forward
    moveForward();
  }
  delay(10);
}
long Ultrasonic_read(){
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  long time = pulseIn (echo, HIGH);
  return time / 29 / 2;
}
// void moveForward() {
//   digitalWrite(in1, LOW);
//   digitalWrite(in2, HIGH);
//   digitalWrite(in3, LOW);
//   digitalWrite(in4, HIGH);
// }

// void turnLeft() {
//   digitalWrite(in1, HIGH);
//   digitalWrite(in2, LOW);
//   digitalWrite(in3, LOW);
//   digitalWrite(in4, HIGH);
// }

// void turnRight() {
//   digitalWrite(in1, LOW);
//   digitalWrite(in2, HIGH);
//   digitalWrite(in3, HIGH);
//   digitalWrite(in4, LOW);
// }


// int getDistance() {
//   digitalWrite(trigPin, LOW);
//   delayMicroseconds(2);
//   digitalWrite(trigPin, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(trigPin, LOW);

//   long duration = pulseIn(echoPin, HIGH);
//   return (duration / 2) * 0.0343;
// }

void servoPulse (int pin, int angle){
int pwm = (angle*11) + 500;      // Convert angle to microseconds
 digitalWrite(pin, HIGH);
 delayMicroseconds(pwm);
 digitalWrite(pin, LOW);
 delay(50); // Refresh cycle of servo
}

void compareDistance(){
  Check_side();
  turnLeft();
  delay(660);
  stopCar();
  delay(1000);
  moveForward();
  delay(500);

  turnRight();
  delay(560);
  stopCar();
  delay(1000);
  moveForward();
  delay(820);

  turnRight();
  delay(550);
  stopCar();
  delay(1000);
  moveForward();
  
  corner();

  turnLeft();
  delay(630);
  stopCar();
  delay(1000);
  moveForward();
  
  
}
 
void Check_side(){
    stopCar();
    delay(100);
 for (int angle = 70; angle <= 140; angle += 5)  {
   servoPulse(servo, angle);  }
    delay(300);
    distance_R = Ultrasonic_read();
    // Serial.print("D R=");Serial.println(distance_R);
    delay(100);
  for (int angle = 140; angle >= 0; angle -= 5)  {
   servoPulse(servo, angle);  }
    delay(500);
    distance_L = Ultrasonic_read();
    // Serial.print("D L=");Serial.println(distance_L);
    delay(100);
 for (int angle = 0; angle <= 70; angle += 5)  {
   servoPulse(servo, angle);  }
    delay(300);
    // compareDistance();
}

void moveForward(){  //forword
digitalWrite(in1, LOW); //Left Motor backword Pin 
digitalWrite(in2, HIGH); //Left Motor forword Pin 
digitalWrite(in3, HIGH); //Right Motor forword Pin 
digitalWrite(in4, LOW); //Right Motor backword Pin 
}

 

void turnRight(){ //turnRight
digitalWrite(in1, LOW); //Left Motor backword Pin 
digitalWrite(in2, HIGH); //Left Motor forword Pin 
digitalWrite(in3, LOW); //Right Motor forword Pin 
digitalWrite(in4, HIGH); //Right Motor backword Pin 
}

void stopCar(){
  // Stop the motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void turnLeft(){ //turnLeft
digitalWrite(in1, HIGH); //Left Motor backword Pin 
digitalWrite(in2, LOW); //Left Motor forword Pin 
digitalWrite(in3, HIGH); //Right Motor forword Pin 
digitalWrite(in4, LOW); //Right Motor backword Pin 
}