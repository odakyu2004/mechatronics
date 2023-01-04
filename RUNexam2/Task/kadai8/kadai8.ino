#define ZERO 0
#define L_D_InPin A0
#define R_D_InPin A1
#define T_Value 200
#define D_OutPin 9
#define LED 7

int L_dValue = ZERO;
int R_dValue = ZERO;

void setup() {
  pinMode(L_D_InPin,INPUT);
  pinMode(R_D_InPin,INPUT);
  digitalWrite(LED,LOW);
  Serial.begin(9600);
}

void loop() {
  L_dValue = analogRead(L_D_InPin);
  R_dValue = analogRead(R_D_InPin);
  Serial.print("L=");
  Serial.print(L_dValue);
  Serial.print("  R=");
  Serial.println(R_dValue);
  if(T_Value < L_dValue && T_Value < R_dValue ){
    digitalWrite(LED,HIGH);
    delay(300);
    digitalWrite(LED,LOW);
    delay(1000);
  }else if(T_Value < L_dValue && T_Value >= R_dValue ){
    digitalWrite(LED,HIGH);
    delay(300);
    digitalWrite(LED,LOW);
    delay(300);
    digitalWrite(LED,HIGH);
    delay(300);
    digitalWrite(LED,LOW);
    delay(1000);
  }else if(T_Value >= L_dValue && T_Value < R_dValue){
    digitalWrite(LED,HIGH);
    delay(300);
    digitalWrite(LED,LOW);
    delay(300);
    digitalWrite(LED,HIGH);
    delay(300);
    digitalWrite(LED,LOW);
    delay(300);
    digitalWrite(LED,HIGH);
    delay(300);
    digitalWrite(LED,LOW);
    delay(1000);
  }else if(T_Value >= L_dValue && T_Value >= R_dValue){
    digitalWrite(LED,HIGH);
    delay(300);
    digitalWrite(LED,LOW);
    delay(300);
    digitalWrite(LED,HIGH);
    delay(300);
    digitalWrite(LED,LOW);
    delay(300);
    digitalWrite(LED,HIGH);
    delay(300);
    digitalWrite(LED,LOW);
    delay(300);
    digitalWrite(LED,HIGH);
    delay(300);
    digitalWrite(LED,LOW);
    delay(1000);
  }
}
