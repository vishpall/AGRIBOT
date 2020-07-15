#include<Servo.h>

#include <MPU6050_tockn.h>

#include <Wire.h>

Servo myservo;

int pos=0;

float ang, initang;

static int i=0;

int lf1=4,lf2=5,lb1=6,lb2=7,rf1=8,rf2=9,rb1=10,rb2=11, ser=3;

MPU6050 mpu6050(Wire); 

void setup()

{

  pinMode(lf1,OUTPUT);

  pinMode(lf2,OUTPUT);

  pinMode(lb1,OUTPUT);

  pinMode(lb2,OUTPUT);

  pinMode(rf1,OUTPUT);

  pinMode(rf2,OUTPUT);

  pinMode(rb1,OUTPUT);

  pinMode(rb2,OUTPUT);

  myservo.attach(ser);

  pinMode(2,OUTPUT);

  pinMode(A4,OUTPUT);

  pinMode(A5,OUTPUT);

  Serial.begin(9600);

 Wire.begin();

  mpu6050.begin();

  mpu6050.calcGyroOffsets(true);

}
void forward()

{

digitalWrite(lf1,HIGH);

digitalWrite(lf2,LOW);

digitalWrite(lb1,HIGH);

digitalWrite(lb2,LOW);

digitalWrite(rf1, HIGH);

digitalWrite(rf2,LOW);

digitalWrite(rb1,HIGH);

digitalWrite(rb2,LOW);

  for(int i=0; i<10; i++)

{

myservo.write(0);

delay(200);

myservo.write(90);

delay(100);

}

}

void right()

{
  mpu6050.update();
initang=mpu6050.getAngleZ();

  digitalWrite(lf1,HIGH);

digitalWrite(lf2,LOW);

digitalWrite(lb1,HIGH);

digitalWrite(lb2,LOW);

digitalWrite(rf1, LOW);

digitalWrite(rf2,LOW);

digitalWrite(rb1,LOW);

digitalWrite(rb2,LOW);



Serial.println(initang);

for(ang=initang; initang-ang<=180  ; ang = mpu6050.getAngleZ(), mpu6050.update())
  {
    Serial.println(ang);
  }
    



     forward();     

}

void left()

{
  mpu6050.update();
  initang=mpu6050.getAngleZ();

  digitalWrite(lf1,LOW);

digitalWrite(lf2,LOW);

digitalWrite(lb1,LOW);

digitalWrite(lb2,LOW);

digitalWrite(rf1, HIGH);

digitalWrite(rf2,LOW);

digitalWrite(rb1,HIGH);

digitalWrite(rb2,LOW);

Serial.println(initang);

for(ang=initang; ang-initang<=180 ; mpu6050.update(),ang = mpu6050.getAngleZ())
{
Serial.println(ang);
     

}

}

void loop()

{

 
  forward();
 right();
  
  left();
  

}
