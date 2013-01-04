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

char* sync_button_pressed(){
  // Check whether the sync button is pressed.
  // (The button press is recorded on video to ease syncing.)
  if (HIGH == digitalRead(syncButtonPin)){
    digitalWrite(ledPin, HIGH);
    return 'true';
  } else {
    digitalWrite(ledPin, LOW);
    return 'false';
  }
}

void setup()
{
  pinMode(syncButtonPin, INPUT);
  pinMode(ledPin, INPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
}

void loop()
{
  // Start a JSON document
  Serial.print('{')

  // Milliseconds since boot
  Serial.print('"millis":');
  Serial.print(millis());
  Serial.print(',');

  // Extensor EMG reading
  Serial.print('"extensor_emg":');
  Serial.print(extensor_emg());
  Serial.print(',');

  // Flexor EMG reading
  Serial.print('"flexor_emg":');
  Serial.print(flexor_emg());
  Serial.print(',');

  // Whether the sync button is pressed
  Serial.print('"sync_button_pressed":');
  Serial.print(sync_button_pressed());

  // End the JSON document
  Serial.print('}')

  // New line
  Serial.println(); 

  // Ten readings per second
  delay(99);
}
