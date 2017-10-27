
/***************************************************************************
 Example Code to move the motor of a 2 or 4 wheel robot driven by the Kimat Mobile Robot Shield.
 This is meant as a first test code. It moves the robot forward, backward, left and right with certain time intervals.
 
 This software is free provided that this notice is not removed and proper attribution 
 is accorded to Layad Circuits and its Author(s).
 Layad Circuits invests resources in producing free software. By purchasing Layad Circuits'
 products or utilizing its services, you support the continuing development of free software
 for all.
  
 Author(s): C.D.Malecdan for Layad Circuits Electronics Engineering
 Revision: 1.0 - 2017/08/17 - initial creation
 Layad Circuits Electronics Engineering Supplies and Services
 B314 Lopez Bldg., Session Rd. cor. Assumption Rd., Baguio City, Philippines
 www.layadcircuits.com
 general: info@layadcircuits.com
 sales: sales@layadcircuits.com
 +63-916-442-8565

 * NOTES:
 * Install right motor(s) on AIN1 & AIN2
 * Install left motor(s) on BIN1 & BIN2
 * When the Single Supply microjumper is installed, install just ONE power source for 
 * both Arduino (6-12V) and Motors(voltage dependes on motors). This single power source must be a voltage accepted by both Arduino and motors
 ***************************************************************************/

#define AIN1 2 
#define BIN1 7
#define AIN2 4
#define BIN2 5
#define PWMA 3
#define PWMB 6
#define STBY 8

void speedSetting(byte val)
{
  // set speed of motor A
  analogWrite(PWMA,val);
  // set speed of motor B
  analogWrite(PWMB,val);
}

void forward()
{
  // move right motor(s) forward
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,HIGH);
  // move left motor(s) forward
  digitalWrite(BIN1,LOW);
  digitalWrite(BIN2,HIGH);
}

void backward()
{
  // move right motor(s) backward
  digitalWrite(AIN1,HIGH);
  digitalWrite(AIN2,LOW);
  // move right motor(s) backward
  digitalWrite(BIN1,HIGH);
  digitalWrite(BIN2,LOW);
}

void turnleft()
{
  // move right motor(s) forward
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,HIGH);
  // move left motor(s) backward
  digitalWrite(BIN1,HIGH);
  digitalWrite(BIN2,LOW);
}

void turnright()
{
  // move right motor(s) backward
  digitalWrite(AIN1,HIGH);
  digitalWrite(AIN2,LOW);
  // move left motor(s) forward
  digitalWrite(BIN1,LOW);
  digitalWrite(BIN2,HIGH);
}

void motorstop()
{
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,LOW);
  digitalWrite(BIN1,LOW);
  digitalWrite(BIN2,LOW);
}

void shortbreak()
{
  digitalWrite(AIN1,HIGH);
  digitalWrite(AIN2,HIGH);
  digitalWrite(BIN1,HIGH);
  digitalWrite(BIN2,HIGH);
}


void setup() {
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  pinMode(BIN1,OUTPUT);
  pinMode(BIN2,OUTPUT);
  pinMode(STBY,OUTPUT);
  digitalWrite(STBY,HIGH);//enable driver
  speedSetting(255); //set to full speed
  delay(3000); // add 3s delay
}


void loop() {
  forward();delay(1000);
  shortbreak();delay(100);
  motorstop();delay(2000);
  
  backward();delay(1000);
  shortbreak();delay(100);
  motorstop();delay(2000);

  turnleft();delay(1000);
  shortbreak();delay(100);
  motorstop();delay(2000);
  
  turnright();delay(1000);
  shortbreak();delay(100);
  motorstop();delay(2000);

  
}
