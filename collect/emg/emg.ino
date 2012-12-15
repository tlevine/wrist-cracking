int flexor_emg() {
  // Reading on the flexor emg pin
  return analogRead(1);
}
int extensor_emg() {
  // Reading on the flexor emg pin
  return analogRead(2);
}

int sync_button_pressed(){
  // Check whether the sync button is pressed.
  // (The button press is recorded on video to ease syncing.)
  return 0;
}

void setup()
{
  Serial.begin(9600);
  Serial.println("millis(),extensor_emg, flexor_emg, sync_button_pressed");
}

void loop()
{
  Serial.print(millis());
  Serial.print(',');
  Serial.print(flexor_emg());
  Serial.print(',');
  Serial.print(extensor_emg());
  Serial.print(',');
  Serial.print(sync_button_pressed());
  Serial.println(); 
  delay(1000);
}
