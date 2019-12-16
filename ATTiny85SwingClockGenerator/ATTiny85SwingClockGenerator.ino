unsigned long delayDuration;
unsigned long next;
unsigned long off;
unsigned long offDuration = 10;
float swingRatio;
bool tick = true;



void setup() {
  // initialize digital pin 13 as an output.
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  delayDuration = analogRead(2) + 100;
  swingRatio = analogRead(3) / 1023.0;
  unsigned long rightNow= millis();
  if (rightNow >= next) {
    tick = !tick;
    if (tick == true) {
      delayDuration *= swingRatio; 
    } else {
      delayDuration *= (1.0 - swingRatio); 
    }
    next = rightNow + delayDuration;
    off = rightNow + offDuration;
    digitalWrite(0, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(1, HIGH);   // turn the LED on (HIGH is the voltage level)
  }

  if (rightNow >= off) {
    digitalWrite(0, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(1, LOW);   // turn the LED on (HIGH is the voltage level)
  }
  
}
