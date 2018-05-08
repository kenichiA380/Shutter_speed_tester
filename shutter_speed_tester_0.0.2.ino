#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7); //LCD pin
unsigned long duration = 0;          //Shutter speed (ns)
double sec = 0;                      //Shutter speed (ms)(s)
double shutter = 0;                  //Shutter speed (denominator)

void setup()
{
	pinMode(15, INPUT);              //Set sensor pin to PIN(15) INPUT
	Serial.begin(9600);              //Serial monitor 9600bps
	lcd.begin(16, 2);                //LCD initialize
	lcd.setCursor(11, 0);
	lcd.print("READY");
}
void loop()
{
	duration = pulseIn(15, LOW, 180000000);     //time out at 180sec
	if (duration > 1);
	{
		lcd.clear();
		Serial.println("---");
		if (duration >= 100000 && duration < 1000000) //0.1sec >= duration < 1sec
		{
			sec = duration / 1000;
			sec = 1000 / sec;

			//Transfer data to serial monitor
			Serial.print("1/"); Serial.println(sec, 0);
			Serial.print(duration); Serial.println("ns");
			Serial.println("");

			//LCD
			lcd.setCursor(0, 0);
			lcd.print("1/"); lcd.print(sec, 0);
			lcd.setCursor(0, 1);
			lcd.print(duration); lcd.print("ns");
		}
		else if (duration >= 1000000)// >=1sec
		{
			sec = duration / 1000;
			sec = sec / 1000;

			//Transfer data to serial monitor
			Serial.print(sec); Serial.println("s");
			Serial.print(duration); Serial.println("ns");
			Serial.println("");

			//LCD
			lcd.setCursor(0, 0);
			lcd.print(sec); lcd.print("s");
			lcd.setCursor(0, 1);
			lcd.print(duration); lcd.print("ns");
		}
		else if (duration < 100000) // < 0.1
		{
			shutter = 1000000 / duration;

			//Transfer data to serial monitor
			Serial.print("1/"); Serial.println(shutter, 0);
			Serial.print(duration); Serial.println("ns");
			Serial.println("");

			//LCD
			lcd.setCursor(0, 0);
			lcd.print("1/"); lcd.print(shutter, 0);
			lcd.setCursor(0, 1);
			lcd.print(duration); lcd.print("ns");
		}
		else if (duration = 0)
		{
			//LCD
			lcd.setCursor(0, 0);
			lcd.print("ERROR");
			
		}
		delay(1000);
		lcd.setCursor(11, 0);
		lcd.print("READY");
	
	}
}
