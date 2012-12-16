int speakerPin = 11;
int syncButtonPin = 8;
int ledPin = 13;
int button_state;

int flexor_emg() {
  // Reading on the flexor emg pin
  return analogRead(4);
}
int extensor_emg() {
  // Reading on the flexor emg pin
  return analogRead(5);
}

int sync_button_pressed(){
  // Check whether the sync button is pressed.
  // (The button press is recorded on video to ease syncing.)
  button_state = digitalRead(syncButtonPin);

  // Yell if and only if pressed.
  digitalWrite(ledPin, button_state);
  digitalWrite(speakerPin, button_state);
  
  // Return 0 for false instead of for true.
  return (button_state == HIGH);
}

void setup()
{
  pinMode(syncButtonPin, INPUT);
  pinMode(ledPin, INPUT);
  pinMode(speakerPin, OUTPUT);
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
