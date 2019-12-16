void setup() {
  randomSeed(analogRead(0));
}

int tonePin = 8;
int pause = 200;
int pattern[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void loop() {
  
  hit(4*analogRead(0), 4*analogRead(1), 4*analogRead(2), 200);
  delay(pause);
}

void hit(int aPitch, int rPitch, float noise, int sampleLength) {
  float steps = float(aPitch - rPitch)/sampleLength;
  for (int i = 0; i < sampleLength; i++) {
    tone(tonePin, aPitch + random(noise), 100);
    aPitch -= steps;
  }
  noTone(tonePin);
}
