#include <Servo.h>
#include <math.h>
#include <Wifi.h>

const char* ssid = "ESP32-Network";
const char* password = "ESP32-Password";

WifiServer server(80); 

Servo coxa1;
Servo femur1;
Servo tibia1;

Servo coxa2;
Servo femur2;
Servo tibia2;

Servo coxa3;
Servo femur3;
Servo tibia3;

Servo coxa4;
Servo femur4;
Servo tibia4;

Servo coxa5;
Servo femur5;
Servo tibia5;

Servo coxa6;
Servo femur6;
Servo tibia6;

const double femur_length = 52.5; // mm
const double tibia_length = 100; // mm

const double Y_Rest = ???;
const double Z_Rest = ???;
const double tibia_extra_angle = ???;

void setup() {
  // put your setup code here, to run once:  

  WiFi.softAP(ssid,password);
}

void loop() {
  // put your main code here, to run repeatedly:
}

void MoveTo(double X, double Y, double Z) {
  Y += Y_Rest;
  Z += Z_Rest;

  double H = sqrt(X*X + Y*Y);
  double length = sqrt(H*H + Z*Z);
  double tibia_angle = acos((femur_length*femur_length + tibia_length*tibia_length - length*length)/(2*femur_length*tibia_length))*(180/PI);
  double B = acos((length*length + femur*femur - tibia*tibia)/(2*length*femur_length))*(180/PI);
  double A = atan(Z/H)*(180/PI);
  double femur_angle = (B + A);
  double coxa_angle = atan(X/Y)*(180/PI);
}
