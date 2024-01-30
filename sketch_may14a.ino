#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <LiquidCrystal_I2C.h>

const int trigPin = 12;
const int echoPin = 11;
// defines variables
long duration;
int distance;

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *Motor = AFMS.getMotor(1);
Adafruit_DCMotor *Motor2 = AFMS.getMotor(2);
Adafruit_DCMotor *Motor3 = AFMS.getMotor(3);
Adafruit_DCMotor *Motor4 = AFMS.getMotor(4);

LiquidCrystal_I2C lcd(0x27,20,4);  

void setup() {

//LED
pinMode(0, OUTPUT);
pinMode(1, OUTPUT);

//Distance
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600); 

//Motors
AFMS.begin(); 
Motor->setSpeed(150);
Motor->run(FORWARD);
Motor->run(RELEASE);

Motor2->setSpeed(150);
Motor2->run(FORWARD);
Motor2->run(RELEASE);

Motor3->setSpeed(150);
Motor3->run(FORWARD);
Motor3->run(RELEASE);

Motor4->setSpeed(150);
Motor4->run(FORWARD);
Motor4->run(RELEASE);
}
//FUNCTIONS

void Stop(){
Motor->setSpeed(100);
Motor->run(RELEASE);
Motor2->setSpeed(100);
Motor2->run(RELEASE);
Motor3->setSpeed(100);
Motor3->run(RELEASE);
Motor4->setSpeed(100);
Motor4->run(RELEASE);
}

void forwards(){
Motor->setSpeed(100);
Motor->run(BACKWARD);
Motor2->setSpeed(100);
Motor2->run(FORWARD);
Motor3->setSpeed(100);
Motor3->run(BACKWARD);
Motor4->setSpeed(100);
Motor4->run(FORWARD);
}

void backwards(){
Motor->setSpeed(100);
Motor->run(FORWARD);
Motor2->setSpeed(100);
Motor2->run(BACKWARD);
Motor3->setSpeed(100);
Motor3->run(FORWARD);
Motor4->setSpeed(100);
Motor4->run(BACKWARD);
}
void pivotleft(){
Motor->setSpeed(100);
Motor->run(RELEASE);
Motor2->setSpeed(100);
Motor2->run(RELEASE);
Motor3->setSpeed(100);
Motor3->run(BACKWARD);
Motor4->setSpeed(100);
Motor4->run(FORWARD);
}

void pivotright(){
Motor->setSpeed(100);
Motor->run(BACKWARD);
Motor2->setSpeed(100);
Motor2->run(FORWARD);
Motor3->setSpeed(100);
Motor3->run(RELEASE);
Motor4->setSpeed(100);
Motor4->run(RELEASE);
}
void left(){    //delay about 625 ms for right angle turn
Motor->setSpeed(100);
Motor->run(FORWARD);
Motor2->setSpeed(100);
Motor2->run(BACKWARD);
Motor3->setSpeed(100);
Motor3->run(BACKWARD);
Motor4->setSpeed(100);
Motor4->run(FORWARD);
}

void right(){   //delay about 625 ms for right angle turn
Motor->setSpeed(100);
Motor->run(BACKWARD);
Motor2->setSpeed(100);
Motor2->run(FORWARD);
Motor3->setSpeed(100);
Motor3->run(FORWARD);
Motor4->setSpeed(100);
Motor4->run(BACKWARD);
}

void dontcrash(){
if (distance <=25)
backwards();
else
forwards();
}

//Other Functions

void dist(){ //Distance Sensor
digitalWrite(trigPin, LOW);
delayMicroseconds(1);
digitalWrite(trigPin, HIGH);
delayMicroseconds(1);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
Serial.print("Distance: ");
Serial.println(distance);
lcd.print("Distance: ");  
lcd.print(distance);
lcd.print(" cm");  

}

void screen(){
lcd.init();       
lcd.backlight();
lcd.setCursor(1,0);
}

void led(){
digitalWrite(0, LOW);
if (distance <=15)
digitalWrite(1, LOW);
else 
digitalWrite(1, LOW);
}

void loop(){
dist();
screen();
led();
dontcrash();
}
