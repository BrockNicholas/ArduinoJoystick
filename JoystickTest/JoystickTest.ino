// Arduino pin numbers
const int A = 3; // digital pin connected to switch output
const int X = 0; // analog pin connected to X output
const int Y = 2; // analog pin connected to Y output
bool aReset = 1;
bool xReset = 1;
bool yReset = 1;

void setup() {
  pinMode(A, INPUT);
  digitalWrite(A, HIGH);
  Serial.begin(9600);
}

void loop() {
  getVals();
  
}

bool aValue(){
  bool val = digitalRead(A);
  if (val == 1){
    aReset = 1;
  }
  else if (val == 0 && aReset == 1){
    aReset = 0;
    return 1;
  }
  
  return 0;
}

int xValue(){
  long val = analogRead(X);
  if (val > 400 && val < 600){
    xReset = 1;
    return 0;
  }
  else if (val <= 400 && xReset == 1){
    xReset = 0;
    return -1;
  }
  else if (val >= 600 && xReset == 1){
    xReset = 0;
    return 1;
  }
  return 0;
}

int yValue(){
  long val = analogRead(Y);
  if (val > 400 && val < 600){
    yReset = 1;
    return 0;
  }
  else if (val <= 400 && yReset == 1){
    yReset = 0;
    return -1;
  }
  else if (val >= 600 && yReset == 1){
    yReset = 0;
    return 1;
  }
  return 0;
}

void getVals(){
  if (aValue()){
    Serial.println("A");
  }
  
  if (xValue() == -1){
    Serial.println("Left");
  }
  
  if (xValue() == 1){
    Serial.println("Right");  
  }
  
  if (yValue() == -1){
    Serial.println("Down");
  }
  
  if (yValue() == 1){
    Serial.println("Up");  
  }
  
}
