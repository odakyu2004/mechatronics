#define ZERO      0
#define R_sensor  A0
#define L_sensor  A1
#define L_Motor_F 10
#define R_Motor_F 11
int R_threshold = 0;
int L_threshold = 0;
int i = ZERO;

int dValue = ZERO;
int sum1 = ZERO;
int sum2 = ZERO;
int ave1 = ZERO;
int ave2 = ZERO;

void setup(){
  pinMode(L_Motor_F,OUTPUT);
  pinMode(R_Motor_F,OUTPUT);
  pinMode(R_sensor,INPUT);
  pinMode(L_sensor,INPUT);
  
  Serial.begin(9600);
  R_Bluck();
  R_threshold = ave1 * 1.3;
  L_Bluck();
  L_threshold = ave2 * 1.3;
}

void loop() {
  if(analogRead(R_sensor) > R_threshold && analogRead(L_sensor) > L_threshold){
    straight();
  }
  
  else if(analogRead(R_sensor) > R_threshold && analogRead(L_sensor) <= L_threshold){
    R_senkai();
  }
  
  else if(analogRead(R_sensor) <= R_threshold && analogRead(L_sensor) > L_threshold){
    L_senkai();
  }
  else if(analogRead(R_sensor) < R_threshold && analogRead(L_sensor) < L_threshold){
    stop();
  }
  delay(100);
}

void R_Bluck(){
    delay(500);
    for(i=0;i<100;i++){
        dValue=analogRead(R_sensor);
        sum1+=dValue;
    }
    ave1 = sum1/i;
    Serial.println(ave1);
}

void L_Bluck(){
    delay(500);
    for(i=0;i<100;i++){
        dValue=analogRead(L_sensor);
        sum2+=dValue;
    }
    ave2= sum2/i;
    Serial.println(ave2);
}

void straight(){
  analogWrite(R_Motor_F,100);
  analogWrite(L_Motor_F,100);
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
