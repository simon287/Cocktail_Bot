
/* Adafruit Arduino - Lesson 16. Stepper */
#include <Stepper.h>
int in1Pin = 6; 
int in2Pin = 7; 
int in3Pin = 8; 
int in4Pin = 9;
int stop_switch = 10;
int posi_slider=0;

Stepper motor(200, in1Pin, in2Pin, in3Pin, in4Pin);  

void setup() {  
  
  pinMode(in1Pin, OUTPUT);  
  pinMode(in2Pin, OUTPUT);  
  pinMode(in3Pin, OUTPUT);  
  pinMode(in4Pin, OUTPUT);
  pinMode(stop_switch, INPUT);
 
  // this line is for Leonardo's,   it delays the serial interface  
  // until the terminal window is opened 
  while (!Serial);    
  Serial.begin(9600);  
  motor.setSpeed(100); // corresponding to 1.2cm/sec, or 300steps/sec ; speed to 100 seems the faster possible by this config
  
  initialize();
  }

  
void loop() {
  
  if (Serial.available())  
  {    motor.setSpeed(50);
       int steps = Serial.parseInt();
        Serial.println(posi_slider+steps);
       if (posi_slider+steps>0 ){
         motor.step(steps);
         posi_slider=posi_slider+steps;  
         Serial.print(steps);
         Serial.print("steps/  new position:");
        Serial.println(posi_slider);
         delay(5);
        }
   }
}

void initialize(){
    Serial.println("Go to init");
    motor.setSpeed(30);
   while(digitalRead(stop_switch )==LOW){
       motor.step(10);  
       }
    Serial.println("Init position reached");
    posi_slider=0;
    Serial.println(posi_slider);
}
