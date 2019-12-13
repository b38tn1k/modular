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

void discoBeat() {
  kick1();
  delay(pause);
  hat();
  delay(pause);
  hat();
  delay(pause);
  kick2();
  delay(pause);
  snare1();
  delay(pause);
  hat();
  delay(pause);
  hat();
  delay(pause);
  hat();
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

void kick1() {
  for (int i = 234; i > 34; i--) {
    tone(tonePin, i, 100);
    tone(tonePin, i, 100);
  }
  noTone(tonePin);
}

void kick2() {
  for (int i = 234; i > 34; i--) {
    tone(tonePin, i, 100);
    tone(tonePin, i, 100);
    tone(tonePin, i, 100);
    tone(tonePin, i, 100);
  }
  noTone(tonePin);
}

void click1() {
  for (int i = 234; i > 34; i--) {
    tone(tonePin, random(700, 800), 100);
  }
  noTone(tonePin);
}

void ratchet1() {
  for (int j = 0; j < 6; j++) {
    for (int i = 0; i < 7; i++) {
      tone(tonePin, random(1000, 1500), 100);
      delay(1);
    }
    noTone(tonePin);
    delay(40);
  }
}

void ratchet2() {
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 5; i++) {
      tone(tonePin, random(1600, 2000), 100);
      tone(tonePin, random(1600, 2000), 100);
    }
    noTone(tonePin);
    noTone(tonePin);
    delay(40);
  }
}

void ratchet3() {
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 7; i++) {
      tone(tonePin, random(1400, 5000), 100);
      delay(1);
    }
    noTone(tonePin);
    delay(60);
  }
}

void ratchet7() {
  for (int j = 0; j < 3; j++) {
    int lo = 500;
    int hi = 1000;
    for (int i = 0; i < 3; i++) {
      tone(tonePin, random(lo, hi), 100);
      lo += 100;
      hi += 100;
      delay(1);
    }
    noTone(tonePin);
    delay(60);
  }
}

void ratchet4() {
  int lo = 500;
  int hi = 1000;
  for (int j = 0; j < 3; j++) {
    int lo = 500;
    int hi = 1000;
    for (int i = 0; i < 6; i++) {
      tone(tonePin, random(lo, hi), 100);
      lo += 300;
      hi += 300;
      delay(1);
    }
    noTone(tonePin);
    delay(60);
  }
}

void click2() {
  for (int i = 0; i < 100; i++) {
    tone(tonePin, random(2000, 5999), 100);
  }
  noTone(tonePin);
}

void click3() {
  int hi = 6000;
  for (int i = 0; i < 50 ; i++) {
    tone(tonePin, random(2000, hi), 100);
    hi -= 60;
  }
  noTone(tonePin);
}

void click4() {
  int lo = 2000;
  for (int i = 0; i < 100; i++) {
    tone(tonePin, random(lo, 7000), 100);
    lo += 60  ;
  }
  noTone(tonePin);
}

void click5() {
  for (int i = 0; i < 50; i++) {
    tone(tonePin, random(2000, 5999), 100);
  }
  noTone(tonePin);
}

void ratchet6() {
  for (int k = 0; k < 4; k++) {
    for (int i = 0; i < 10; i++) {
      tone(tonePin, random(2000, 5999), 100);
    }
    for (int i = 0; i < 10; i++) {
      noTone(tonePin);
    }
  }
}

void ratchet5() {
  for (int j = 0; j < 3; j++) {
    int lo = 1000;
    int hi = 2000;
    for (int i = 0; i < 3; i++) {
      tone(tonePin, random(lo, hi), 1);
      lo += 1;
      hi += 10;
      delay(1);
    }
    noTone(tonePin);
    noTone(tonePin);
    noTone(tonePin);
    //    delay(5);
  }
}
void loTom() {
  for (int i = 700; i > 534; i--) {
    int glitchy = random(-50, 50);
    tone(tonePin, i + glitchy, 10);
  }
  noTone(tonePin);
}

void hiTom() {
  for (int i = 0; i < 1034; i++) {
    int glitchy = random(-50, 6000);
    tone(tonePin, i + glitchy, 10);
  }
  noTone(tonePin);
}

void snare1() {
  int lo = 500;
  for (int i = 400; i > 34; i--) {
    tone(tonePin, random(lo, 3000), 100);
    lo += 1;
  }
  noTone(tonePin);
}

void snare2() {
  int lo = 1000;
  for (int i = 300; i > 34; i--) {
    tone(tonePin, random(lo, 6000), 100);
    lo += 10;
  }
  noTone(tonePin);
}

void hat() {
  for (int i = 100; i > 0; i--) {
    tone(tonePin, random(3000, 6000), 1);
  }
  noTone(tonePin);
}
