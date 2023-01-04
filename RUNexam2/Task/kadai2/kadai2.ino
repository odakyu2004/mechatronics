#define ZERO 0
#define D_InPin 2
#define D_OutPin 13

int dValue = ZERO;

void setup() {
  pinMode(D_OutPin,OUTPUT);
  pinMode(D_InPin,INPUT);
}

void loop() {
  dValue = digitalRead(D_InPin);
  if(dValue == HIGH){
    digitalWrite(D_OutPin,HIGH);
  }else {
    digitalWrite(D_OutPin,LOW);
  }
}
