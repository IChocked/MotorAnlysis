// Press a button to restart and continue logging
// Run for 10 seconds and collect data, printing it to the serial output, then reset
// When 10 seconds are up, stop logging and turn on the LED
// When button pushed, do the same thing again


const int BUTTON = 2;
const int HALL = 3;
const int LED = 4;

double pos = 0.0; // Angular position of the motor in radians 
double last = 0.0; // last time stamp

double zero_time = -1.0;

void setup() {
  pinMode(HALL, INPUT);
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(HALL), hall_ISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(BUTTON), button_trig, HIGH);

  Serial.begin(9600);

  zero_time = millis();
}

void loop() {
  double t = millis() - zero_time;

  if (t < 10000 && t != last) {
    String output = (String) t + "," + pos;
    Serial.println(output);
    digitalWrite(LED, LOW);
  }
  else {
    digitalWrite(LED, HIGH);
  }

  last = t;
}

void hall_ISR() {
  pos += PI; // For the side magnet bar configuration
}

void button_trig() {
  zero_time = millis();
  pos = 0.0;
}
