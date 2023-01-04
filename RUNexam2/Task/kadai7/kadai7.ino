#define ZERO 0
#define D_InPin A0
#define RValue 50
#define D_OutPin 9
#define L_Motor_F 10
#define R_Motor_F 11
#define L_Motor_B 12
#define R_Motor_B 13

int dValue = ZERO;

void setup() {
  pinMode(L_Motor_F,OUTPUT); //set the L_Motor_F(pin10)
  pinMode(R_Motor_F,OUTPUT); //set the R_Motor_F(pin11)
  pinMode(L_Motor_B,OUTPUT); //set the L_Motor_B(pin12)
  pinMode(R_Motor_B,OUTPUT); //set the R_Motor_B(pin13)
  digitalWrite(L_Motor_F,LOW); //set the L_Motor_F (pin10) off
  digitalWrite(R_Motor_F,LOW); //set the R_Motor_F (pin11) off

}

void loop() {
  dValue = analogRead(D_InPin);
  if(RValue <= dValue){
    analogWrite(L_Motor_F,255);
    analogWrite(R_Motor_F,255);
  }else {
    analogWrite(L_Motor_F,0);
    analogWrite(R_Motor_F,0);
  }
}
