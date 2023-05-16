//Private variables
char t;
//Potentiometer pins
int enA=9;
int enB=3;
int pwmOutput=0;
//Setup function
void setup()
{
  //Declaring the pinmodes of all the pins
  pinMode(A0,INPUT);
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  //Beginning serial communication
  Serial.begin(9600);  
}
//Starting loop function
void loop()
{ 
  //Starting serial communication
  if(Serial.available())
  {
    //Reading the commands
    t=Serial.read();
    Serial.println(t);
  }
  //Reading the potentiometer value
  int potentiometerValue=analogRead(A0);
 //Mapping the value to a value between 0 and 255
  pwmOutput=map(potentiometerValue,0,1023,0,255);
//If 'F' command is recieved then the rover moves forward
  if(t=='F')
  {
    analogWrite(enA,pwmOutput);//Send PWM signal to L298N motor driver
    analogWrite(enB,pwmOutput);
    move_Forward();
  }
//If 'B' command is recieved then the rover moves Backward
  else if(t=='B')
  {
    analogWrite(enA,pwmOutput);//Send PWM signal to L298N motor driver
    analogWrite(enB,pwmOutput);
    move_Backward();
  }
//If 'L' command is recieved then the rover takes a left turn
  else if (t=='L')
  {
    analogWrite(enA,pwmOutput);//Send PWM signal to L298N motor driver
    analogWrite(enB,pwmOutput);
    move_left();
  }
//If 'R' command is recieved then the rover takes a right turn
  else if(t=='R')
  {
    analogWrite(enA,pwmOutput);//Send PWM signal to L298N motor driver
    analogWrite(enB,pwmOutput);
    move_right();
  }
  else if(t=='S')
  {
    analogWrite(enA,pwmOutput);//Send PWM signal to L298N motor driver
    analogWrite(enB,pwmOutput);
    stop();
  }
}
//Function for turning the robot left
void move_left()
{ 
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
}
//Function for turning the robot right
void move_right()
{
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
}
//Function for moving the robot forward
void move_Forward()
{
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
}
//Function for moving the robot Backward
void move_Backward()
{
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
}
//Function for stopping the motors
void stop()
{
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
}