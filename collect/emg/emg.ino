int syncButtonPin = 6;
int ledPin = 13;

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
  if (HIGH == digitalRead(syncButtonPin)){
    digitalWrite(ledPin, HIGH);
    return 0;
  } else {
    digitalWrite(ledPin, LOW);
    return 1;
  }
}

void setup()
{
  pinMode(syncButtonPin, INPUT);
  pinMode(ledPin, INPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
  Serial.println("millis(),extensor_emg,flexor_emg,sync_button_pressed");
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
  delay(99);
}
