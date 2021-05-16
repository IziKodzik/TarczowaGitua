int pin = A0;
int resetPin = A1;
int count = 0;
int last = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin, INPUT);
  pinMode(resetPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int current = analogRead(pin);
  if(current == 0 && last > 0 ){
    ++count;
  }
  int resetCur = analogRead(resetPin);
  if(resetCur == 0 && count != 0 && current == 0){
    if(count == 11) 
      count = 1;
    Serial.println(count -1);
    count=0;
  }

  last = current;  
}
