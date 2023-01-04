#define ZERO      0
#define R_sensor  A0
#define L_sensor  A1
int R_threshold = 200;
int L_threshold = 200;

int dValue = ZERO;
int sum = ZERO;
int ave = ZERO;


void setup(){
  pinMode(R_sensor,INPUT);
  pinMode(L_sensor,INPUT);
  Serial.begin(9600);
  for(int i=1;i<500;i++){
    dValue=analogRead(R_sensor);
    sum += dValue;
  }
  ave=sum/500;
  Serial.println(ave);
}

void loop() { }
