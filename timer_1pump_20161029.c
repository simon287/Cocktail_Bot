#include <Time.h>
#include <SPI.h>
#include <SD.h>
// water flow speed unit: ml/sec
int flow_speed=6;
int inputpin = 4;

#define timerpin A1
int pump1 = 12;
  
void setup() {
    // put your setup code here, to run once:
    pinMode(inputpin, INPUT);
    pinMode(timerpin, INPUT);
    pinMode(pump1, OUTPUT);
    Serial.begin(9600);  
    digitalWrite(pump1,LOW);
}

void loop() {
    // put your main code here, to run repeatedly:
    float volume = 0.1*analogRead(timerpin); // from 1 to 1023 on the sensor will give 1 to 100ml 
    int timerinms = 1000*volume/flow_speed; 
    Serial.print("volume =");
    Serial.println(volume );
    Serial.print("timerinms =");
    Serial.println(timerinms );
    Serial.print("inputpin =");
    Serial.println(digitalRead(inputpin));

    if (digitalRead(inputpin) ==HIGH ){
	digitalWrite(pump1,HIGH);
	Serial.print("pump1 =");
	Serial.println(digitalRead(pump1));
	delay(timerinms);
	digitalWrite(pump1,LOW);
    }
}
