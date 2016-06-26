#define DUST_LED_PIN 2
#define DUST_DATA_PIN A0

void dustInit(){
	pinMode(DUST_LED_PIN, OUTPUT);
	pinMode(DUST_DATA_PIN, INPUT);
	digitalWrite(DUST_LED_PIN, HIGH);
}

void dustRead(float* voltage, float* dustDensity){
	// https://www.sparkfun.com/datasheets/Sensors/gp2y1010au_e.pdf
	// http://www.howmuchsnow.com/arduino/airquality/
	digitalWrite(DUST_LED_PIN, LOW);
	delayMicroseconds(280);
	*voltage=analogRead(DUST_DATA_PIN)*0.0049;
	delayMicroseconds(40);
	digitalWrite(DUST_LED_PIN, HIGH);
	delayMicroseconds(9680);
	*dustDensity=*voltage*0.171-0.1;
	if (*dustDensity<0)
		*dustDensity=0;
}