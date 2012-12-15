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

int f;
int e;
int b;
int t;

void setup()
{
  pinMode(flexor_emg_pin, INPUT);
  pinMode(extensor_emg_pin, INPUT);

  Serial.begin(9600);
  Serial.println("date,                           extensor_emg, flexor_emg, sync_button_pressed");
}

void loop()
{
  f = flexor_emg();
  e = extensor_emg();
  b = sync_button_pressed();
  Serial.println(); 
  delay(1000);
}
