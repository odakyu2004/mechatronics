#define ZERO      0
#define R_sensor  A0
#define L_sensor  A1
#define L_Motor_F 10
#define R_Motor_F 11
int R_threshold = 200;
int L_threshold = 200;

int dValue = ZERO;

void setup(){
  pinMode(L_Motor_F,OUTPUT);
  pinMode(R_Motor_F,OUTPUT);
  pinMode(R_sensor,INPUT);
  pinMode(L_sensor,INPUT);
}

void loop() {
  if(analogRead(R_sensor) < R_threshold && analogRead(L_sensor) < L_threshold){
    straight();
  }
  
  else if(analogRead(R_sensor) < R_threshold && analogRead(L_sensor) >= L_threshold){
    R_senkai();
  }
  
  else if(analogRead(R_sensor) >= R_threshold && analogRead(L_sensor) < L_threshold){
    L_senkai()
  }
  else if(analogRead(R_sensor) > R_threshold && analogRead(L_sensor) > L_threshold){
    stop();
  }
}

void straight(){
  analogWrite(R_Motor_F,255);
  analogWrite(L_Motor_F,255);
}
void R_senkai(){
  analogWrite(R_Motor_F,0);
  analogWrite(L_Motor_F,255);
}
void L_senkai(){
  analogWrite(R_Motor_F,255);
  analogWrite(L_Motor_F,0);
}
void stop(){
  analogWrite(R_Motor_F,0);
  analogWrite(L_Motor_F,0);
}
