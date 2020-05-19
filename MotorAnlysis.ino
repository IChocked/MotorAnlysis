// Press a button to restart and continue logging
// Run for 10 seconds and collect data, printing it to the serial output, then reset
// When button pushed, do the same thing again


int hall = 11;
double pos = 0.0; // Angular position of the motor in number of rotations 
double t = 0.0;

void setup() {
  pinMode(hall, INPUT);
  attachInterrupt(digitalPinToInterrupt(hallPin), hall_ISR, CHANGE);
}

void loop() {
  
  
}

void hall_ISR() {
  pos += PI; // Or HALF_PI or TWO_PI or whatever it is 
}

void reset() {
  
}
