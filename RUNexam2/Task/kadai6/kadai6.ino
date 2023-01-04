#define ZERO 0
#define D_InPin A0
#define RValue 100
#define D_OutPin 13

int dValue = ZERO;

void setup() {
  pinMode(D_OutPin,OUTPUT);
  pinMode(D_InPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  dValue = analogRead(D_InPin);
  if(RValue <= dValue){
    digitalWrite(D_OutPin,HIGH);
  }else {
    digitalWrite(D_OutPin,LOW);
  }
  dValue=map(dValue,0,1023,0,500)/100;
  Serial.println(dValue);
}
