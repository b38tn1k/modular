float a1, a2, a3, a4, a5, a6, fTime;
long oldTime, currentTime, deltaTime;
int counter = 0;
float steps[] = {0.9, 0.0, 0.9, 0.0};

void setup() {
  randomSeed(analogRead(1));
  randomSeed(random());
  // put your setup code here, to run once:
  Serial.begin(9600);
  a1 = 0.9;
  a2 = 0.9;
  a3 = 0.9;
  a4 = 0.9;
  a5 = 0.9;
  a6 = 0.9;
  pinMode(12, INPUT_PULLUP);

}

void loop() {
  counter++;
  Serial.println(a1);
  oldTime = currentTime;
  currentTime = millis();
  deltaTime = currentTime - oldTime;
  fTime += deltaTime/1000.0;
  a1 = sin(fTime);
  a2 = sin(fTime);
  a3 = sin(fTime);
  a4 = sin(fTime);
  a5 = sin(fTime);
  a6 = sin(fTime);
//  if (digitalRead(12) == LOW){
//    a1 = random(100)/100.0;
//    a2 = random(100)/100.0;
//    a3 = random(100)/100.0;
//    a4 = random(100)/100.0;
//    a5 = random(100)/100.0;
//    a6 = random(100)/100.0;
//  }
  // put your main code here, to run repeatedly:
  analogWrite(3, int(a1*127) + 127);
  analogWrite(5, int(a2*127) + 127);
  analogWrite(6, int(a3*127) + 127);
  analogWrite(9, int(a4*127) + 127);
  analogWrite(10, int(a5*127) + 127);
  analogWrite(11, int(a6*127) + 127);
  delay(500);

}
