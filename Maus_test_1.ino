
int lDrive = 12;
int lin1 = 14;
int lin2 = 16;

int rDrive = 13;
int rin1 = 15;
int rin2 = 17;

void setup() {
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  int forward = analogRead(A2);
  forward = analogRead(A2);
  int sides = analogRead(A3);
  sides = analogRead(A3);
  
  drive(forward,sides);
}

void drive(int vx, int vy){
  int lval;
  int rval;

  lval = vx;
  rval = vy;

  Serial.print(lval);
  Serial.print(",");
  Serial.println(rval);
    
  driveL298N(lDrive, lin1, lin2, lval);
  driveL298N(rDrive, rin1, rin2, rval);
}

void driveL298N(int drivePin, int in1, int in2, int value){
   
  int val;
  int deadZone = 25;

  val = map(value, 0, 1023, -255, 255);

  boolean dir = 0;

  if((abs(val) - deadZone) < 0){
    val = 0;
  }

  if(val < 0){
    dir = 1;
    val = abs(val);
  }
    
  digitalWrite(in1, dir);
  digitalWrite(in2, !dir);
  analogWrite(drivePin, val);
}
