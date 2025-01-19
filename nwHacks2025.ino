#include <Servo.h>
#include <math.h>
//#include <Wifi.h>

// const char* ssid = "ESP32-Network";
// const char* password = "ESP32-Password";

// WifiServer server(80); 

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

const double Y_Rest = 50.0; // estimated
const double Z_Rest = 130.0; // estimated
const double tibia_extra_angle = 65.0; // estimated !!! measure later

// PINS FOR ARDUINO 1
const int coxa1Pin = 3; // Arduino 1
const int femur1Pin = 5;
const int tibia1Pin = 7;

// const int coxa2Pin = 5;
// const int femur2Pin = 6;
// const int tibia2Pin = 7;

// const int coxa3Pin = 10;
// const int femur3Pin = 9;
// const int tibia3Pin = 8;

// PINS FOR ARDUINO 2
// const int coxa4Pin = ;
// const int femur4Pin = ;
// const int tibia4Pin = ;

// const int coxa5Pin = ;
// const int femur5Pin = ;
// const int tibia5Pin = ;

// const int coxa6Pin = ;
// const int femur6Pin = ;
// const int tibia6Pin = ;

void setup() {
  // put your setup code here, to run once:  
  coxa1.attach(coxa1Pin);
  femur1.attach(femur1Pin);
  tibia1.attach(tibia1Pin);

  // coxa2.attach(coxa2Pin);
  // femur2.attach(femur2Pin);
  // tibia2.attach(tibia2Pin);

  // coxa3.attach(coxa3Pin);
  // femur3.attach(femur3Pin);
  // tibia3.attach(tibia3Pin);

  Serial.begin(9600);

  // coxa4.attach(coxa4Pin);
  // femur4.attach(femur4Pin);
  // tibia4.attach(tibia4Pin);

  // coxa5.attach(coxa5Pin);
  // femur5.attach(femur5Pin);
  // tibia5.attach(tibia5Pin);

  // coxa6.attach(coxa6Pin);
  // femur6.attach(femur6Pin);
  // tibia6.attach(tibia6Pin);
  // WiFi.softAP(ssid,password);
}

void loop() {
  // put your main code here, to run repeatedly:
  MoveTo(coxa1, femur1, tibia1, 0, 0, 0);
  MoveTo(coxa2, femur2, tibia2, 0, 0, 0);
  MoveTo(coxa3, femur3, tibia3, 0, 0, 0);
  delay(2000);

  // MoveTo(coxa1, femur1, tibia1, -30, 40, -50);
  // MoveTo(coxa2, femur2, tibia2, -30, 40, -50);
  // MoveTo(coxa3, femur3, tibia3, -30, 40, -50);
  // delay(2000);
}

void MoveTo(Servo& coxa, Servo& femur, Servo& tibia, double X, double Y, double Z) {
  Y += Y_Rest;
  Z += Z_Rest;

  Serial.print("Input Coordinates: X=");
  Serial.print(X);
  Serial.print(", Y=");
  Serial.print(Y);
  Serial.print(", Z=");
  Serial.println(Z);
  
  double H = sqrt((X * X) + (Y * Y));
  double length = sqrt((H * H) + (Z * Z));
  double tibia_angle = acos((femur_length * femur_length + tibia_length * tibia_length - length * length) / 
  (2 * femur_length * tibia_length)) * (180 / PI);
  double B = acos((length * length + femur_length * femur_length - tibia_length * tibia_length) / 
  (2 * length * femur_length)) * (180 / PI);
  double A = atan(Z / H) * (180 / PI);
  double femur_angle = (B + A);
  double coxa_angle = atan(X / Y) * (180 / PI);

  Serial.print("Tibia Angle: ");
  Serial.println(tibia_angle);
  Serial.print("Femur Angle: ");
  Serial.println(femur_angle);
  Serial.print("Coxa Angle: ");
  Serial.println(coxa_angle);

  coxa.write(90 - coxa_angle);
  femur.write(90 - femur_angle);
  tibia.write(tibia_angle + tibia_extra_angle - 90);
}




