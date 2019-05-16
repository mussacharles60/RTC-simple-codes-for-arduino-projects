/* This is the simple code for read and run the clock from every RTC module with i2c but protocal...

Created by Mussa Charles (Myssa)

Visit http://www.github.com/mussacharles60 for more info.

code no. 2 (run clock).
*/

#include <Wire.h>

uint8_t second, minute, hour, wday, day, month, year, ctrl;

//this is a list of long variables used in this clock program
long s;
long m;
long h;
long sec;
long minutes;
long hrs;

void setup() {
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect
  }
  Wire.begin();
}

void loop() {
  if (read_ds1307()) {
    hours();
    mins();
    secs();
      
    Serial.print("Date: ");
    Serial.print(day);
    Serial.print('/');
    Serial.print(month);
    Serial.print('/');
    Serial.print(year);
    Serial.print("  Clock: ");
    Serial.print(hour);
    Serial.print(':');
    Serial.print(minute);
    Serial.print(':');
    Serial.print(second);
    Serial.print(" ");
    Serial.print(wday);
    Serial.println();
    delay(1000);
  
  }
  else {
    Serial.println("Error!!... DS1307 not detected");
  }
  
}

bool read_ds1307() {
  Wire.beginTransmission(0x68);
  Wire.write(0x00);
  if (Wire.endTransmission() != 0);
    return false; 
  Wire.requestFrom(0x68, 8);
  second = bcd2bin(Wire.read());
  minute = bcd2bin(Wire.read());
  hour = bcd2bin(Wire.read());
  wday = bcd2bin(Wire.read());
  day = bcd2bin(Wire.read());
  month = bcd2bin(Wire.read());
  year = bcd2bin(Wire.read());

  ctrl = Wire.read();
  return true;                 
}

uint8_t bcd2bin(uint8_t bcd) {
  return (bcd / 16 * 10) + (bcd % 16);
}

long hours()   { hrs =  hour; h =  hour; return hrs;           } //this method is for hours
long mins()    { minutes = minute; m = minute; return minutes; } //this method is for minutes
long seconds() { s = second; return s;                         } //this method is for seconds
long secs()    { sec = second; return sec;                     }

