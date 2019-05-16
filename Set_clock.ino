/* This is the simple code for setting the clock for almost every RTC module which uses the i2c bus protocal...

created by Mussa Charles (Myssa)

Visit http://www.github.com/mussacharles60 for more info.

code no. 1 (set clock).
*/

#include <Wire.h>

uint8_t second, minute, hour, wday, day, month, year;

voidid setup() {
   Serial.begin(9600);
   Wire.begin();

// Enter new date & clock below
   second = 00;
   minute = 15;
   hour = 21;
   wday = 3;
   day = 19;
   month = 03;
   year = 19;
}

void loop() {
   write_ds1307();

   Serial.println("Setting date & clock to DS1307 Tiny RTC:");
   print_time();

   for (;;);
}
bool write_ds1307() {
  Wire.beginTransmission(0x68);
  Wire.write(0x00);
  Wire.write(bin2bcd(second & 0x7F));
  Wire.write(bin2bcd(minute));
  Wire.write(bin2bcd(hour));
  Wire.write(bin2bcd(wday));
  Wire.write(bin2bcd(day));
  Wire.write(bin2bcd(month));
  Wire.write(bin2bcd(year));

  if (Wire.endTransmission() != 0)
    return false;

  return true;
}

uint8_t bin2bcd(uint8_t bin) {
  return (bin / 10 * 16) + (bin % 10);
}

void print_time() {
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
}
