#include <Time.h>
#include <TimeAlarms.h>

char* iso_date() {
  return "2012-11-21 11:20:43.007000000";
}

int sync_button_pressed(){
  // Check whether the sync button is pressed.
  // (The button press is recorded on video to ease syncing.)
  return 0;
}

int flexor_emg() {
  // Reading on the flexor emg pin
  return 123;
}
int extensor_emg() {
  // Reading on the flexor emg pin
  return 123;
}

int flexor_emg_pin = 5;
int extensor_emg_pin = 6;

char* i = "2012-11-21 11:20:43.007000000";
int f;
int e;
int b;
int t;

void printPaddedDigits(int digits)
{
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

void printIso8601() {
  // Print the datetime in ISO 8601 format.
  t = now();
  Serial.print(year(t));
  Serial.print("-");
  Serial.print(month(t));
  Serial.print("-");
  Serial.print(day(t));
  Serial.print("T");
  Serial.print(hour(t));
  Serial.print(":");
  printPaddedDigits(minute());
  Serial.print(":");
  printPaddedDigits(second());
}

void setup()
{
  pinMode(flexor_emg_pin, INPUT);
  pinMode(extensor_emg_pin, INPUT);

  Serial.begin(9600);
  Serial.println("date,                           extensor_emg, flexor_emg, sync_button_pressed");
}

void loop()
{
  //Serial.println("2012-11-21 11:20:43.007000000,           123,        123, 0");
  i = iso_date();
  f = flexor_emg();
  e = extensor_emg();
  b = sync_button_pressed();
  // How do I do printf?
  //Serial.println("%s,%014d,%014d,%d", i,f,e,b);
  printIso8601();
//  Serial.print(i);
//  Serial.print(',');
//  Serial.print(f, DEC);
//  Serial.print(',');
//  Serial.print(e, DEC);
//  Serial.print(',');
//  Serial.print(b, DEC);
  Serial.println(); 
  delay(1000);
}
