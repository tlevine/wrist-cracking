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

void setup()
{
  pinMode(flexor_emg_pin, INPUT);
  pinMode(extensor_emg_pin, INPUT);

  Serial.begin(9600);
  Serial.println("date,                           extensor_emg, flexor_emg, sync_button_pressed");
}

void loop()
{
  Serial.println("2012-11-21 11:20:43.007000000,           123,        123, 0");
  i = iso_date();
  f = flexor_emg();
  e = extensor_emg();
  b = sync_button_pressed();
  // How do I do printf?
  Serial.println("%s,%014d,%014d,%d", i,f,e,b);
  delay(1000);
}
