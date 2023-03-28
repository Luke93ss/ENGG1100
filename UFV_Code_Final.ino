#include <Blynk.h>
#include <Servo.h>
#include <SoftwareSerial.h>
#include <BlynkSimpleSerialBLE.h>
SoftwareSerial DebugSerial(2, 3); // RX, TX

#define BLYNK_USE_DIRECT_CONNECT
#define BLYNK_PRINT DebugSerial
#define leftForward 2 
#define leftBackward 3
#define rightForward 4
#define rightBackward 5
#define ServoLeft V0
#define ServoRight V1
#define ServoUp V2
#define ServoDown V3
#define MotorForward V4
#define MotorBack V5

Servo HorizontalServo;
Servo VerticalServo;

char auth[] = "IrL_uTfD232al9EjEnMeniLQMqj9qCbq";

void setup()
{
  // Debug console
  DebugSerial.begin(9600);

  DebugSerial.println("Waiting for connections...");

 
  Serial.begin(9600);
  Blynk.begin(Serial, auth);

  pinMode(rightForward, OUTPUT); // Defines Pin as output
  pinMode(rightBackward, OUTPUT); // Defines Pin as output
  pinMode(leftForward, OUTPUT); // Defines Pin as output
  pinMode(leftBackward, OUTPUT); // Defines Pin as output

  HorizontalServo.attach(11); //Attaches the horizontal servo to pin 11 on Arduino Uno
  VerticalServo.attach(10); //Attaches the vertical servo to pin 10 on Arduino Uno
 
}

void MotorTravelForward(int i){
  
    if (i == 1){ // If joystick value is greater than 0, drive motor forwards.
    
      digitalWrite(rightForward, HIGH);
      digitalWrite(rightBackward, LOW);
      digitalWrite(leftForward, HIGH);
      digitalWrite(leftBackward, LOW);
    }
    
    else if (i == 0){ // If joystick value = 0 then stop motor. 
   
      digitalWrite(rightForward, LOW);
      digitalWrite(rightBackward, LOW);
      digitalWrite(leftForward, LOW);
      digitalWrite(leftBackward, LOW);
    }    
     
}

void MotorTravelBack(int i){

    if (i == 1){
      digitalWrite(rightForward, LOW);
      digitalWrite(rightBackward, HIGH);
      digitalWrite(leftForward, LOW);
      digitalWrite(leftBackward, HIGH);
    }

     else if (i == 0){ // If joystick value = 0 then stop motor. 
   
      digitalWrite(rightForward, LOW);
      digitalWrite(rightBackward, LOW);
      digitalWrite(leftForward, LOW);
      digitalWrite(leftBackward, LOW);
}
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(MotorForward){ // Reads virtual pin in Blynk then executes MotorTravel.

    int i = param.asInt(); // Reads value

  MotorTravelForward(i);
}

BLYNK_WRITE(MotorBack){

    int i = param.asInt();

   MotorTravelBack(i);
}

BLYNK_WRITE(ServoLeft){ // Reads virtual pin in Blynk, then rotates servo anti-clockwise.
                        // Can choose to press button once which rotates the servo in small increments or press and hold for continuous rotation.
    int i = param.asInt();
    if (i == 1){
      HorizontalServo.write(120);
      delay(80);
    }
    else if (i == 0){
      HorizontalServo.write(90);
    }           
}
BLYNK_WRITE(ServoRight){  // Reads virtual pin in Blynk, then rotates servo clockwise.
                          // Can choose to press button once which rotates the servo in small increments or press and hold for continuous rotation.
    int i = param.asInt();
    if (i == 1){
      HorizontalServo.write(60);
      delay(80);
}
    else if (i == 0){
      HorizontalServo.write(90);
}
    
  }

BLYNK_WRITE(ServoUp){ // Reads virtual pin in Blynk, then rotates servo upwards.
                      // Can choose to press button once which rotates the servo in small increments or press and hold for continuous rotation.
    int i = param.asInt();
    if (i == 1){
      VerticalServo.write(120);
      delay(80);
    }
    else if (i == 0){
      VerticalServo.write(90);
    
}
    }

BLYNK_WRITE(ServoDown){ // Reads virtual pin in Blynk, then rotates servo downwards.
                        // Can choose to press button once which rotates the servo in small increments or press and hold for continuous rotation.
    int i = param.asInt();
    if (i == 1){
      VerticalServo.write(60);
      delay(80);
    }
    else if (i == 0){
      VerticalServo.write(90);
}
    }

 
