void setup()
{
  Serial.begin(9600);
  Serial.println("date,                           extensor_emg, flexor_emg, sync_button_pressed");
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

void loop()
{
  Serial.println("2012-11-21 11:20:43.007000000,           123,        123, 0");
  delay(1000);
}
