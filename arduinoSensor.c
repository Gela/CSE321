#define ANALOG_PIN_A0 0
#define ANALOG_PIN_A1 1
#define ARRAY 8


#include <stdio.h>

float distanceArray[ARRAY+1] = {2.0 , 4.0 , 6.0 , 8.0 , 10.0 , 12.0 , 14.0 , 32.0 };
float voltageArray[ARRAY+1] = {689.0 , 497.0 , 303.0 , 249.0 , 247.0 , 203.0 , 138.0 , 125.0 , 0};
float analogValue = 0.0 ;
float slope = 0.0 ;
float distance = 0.0 ;
float b = 0.0;   //as in y = ax + b;

void setup() {

	Serial.begin(9600);
}

void loop(){

	analogValue = analogRead(0);
	Serial.println(analogValue);
	for (int i = 0; i < ARRAY; i++) {
		if ((analogValue < voltageArray[i]) && (analogValue > voltageArray[i+1]) ) {
			//do the math function here
			slope = (distanceArray[i+1] - distanceArray[i] ) / (voltageArray[i+1] - voltageArray[i] ); // slope = (y2-y1) / (x2-x1)
			b = distanceArray[i] - (slope * voltageArray[i]);
			distance = slope * analogValue + b;
			break;

		} else if (analogValue == voltageArray[i]) {
			distance = distanceArray[i];
			break;
		} 
  
	}
	
	Serial.println(distance);
        delay(500);
}
