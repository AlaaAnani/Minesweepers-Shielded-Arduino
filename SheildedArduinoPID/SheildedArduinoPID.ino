#include <SPI.h>         // needed for Arduino versions later than 0018
#include <Ethernet.h>
#include <EthernetUdp.h>         // UDP library from: bjoern@cs.stanford.edu 12/30/2008
#include "EthernetDeclarations.h"
#include <PID_v1.h>
 

//Serial receive 
char  ReplyBuffer[] = "hello";       // a string to send back
char *replyPtr = &ReplyBuffer[0]; //reply ptr to the array of chars
char c; //to store byte by byte
#define MAX_BUF (64) // maximum buffer size
char buffer[MAX_BUF]; //buffer to receive data serially
int sofar=0; //index (order of byte)

//MOTOR DRIVER pins
#define Dir1 2
#define PWM1 3 
#define Dir2 4
#define PWM2 5

//Data from labview
long ReceivedData[6];

int MineR, MineL;
float yaw, DeltaDistance;

//PID
double Setpoint, Input, Output1;
int Output;
bool PIDon = 0;
double error=0;
String replyStr;
//double aggKp=4, aggKi=0.2, aggKd=1;
double Kp = 3, Ki= 0.1, Kd= 1; // 3 0.1  1
PID myPID(&Input, &Output1, &Setpoint, Kp, Ki, Kd, DIRECT);
int PilotSP; //From labview
int intSetpoint;
int roll, newroll, nnewroll;
int value, p;

//RST
#define RSTSensorsPin A5
int RSTSensors = 1;



void ready()
{
  sofar = 0; // clear input buffer
}

void setup() 
{
 pinMode(RSTSensorsPin, OUTPUT);
  
  /*ETHERNET*/  
 Serial.begin(115200);

 Ethernet.begin(mac, ip);
 Udp.begin(localPort);

pinMode(Dir1, OUTPUT);
pinMode(PWM1, OUTPUT);
pinMode(Dir2, OUTPUT);
pinMode(PWM2, OUTPUT);


//PID
 myPID.SetMode(AUTOMATIC);
 myPID.SetOutputLimits(0,55);
 Setpoint =0;

}

void loop() 
{

  
   /*ETHERNET*/
   //READ
  int packetSize = Udp.parsePacket(); //get num of bytes at port
  if (packetSize)  //if it's not zero, read the packet
  {
   IPAddress remote = Udp.remoteIP(); //get remote IP
    Serial.print("port ");
   Serial.println(Udp.remotePort());
    //read the packet into packetBufffer
   Udp.read(packetBuffer, 64);
   ParseString(packetBuffer); //Parse the string to use the data for control later in the code
  // Serial.println("Contents:");
  // Serial.println(packetBuffer);
 }
  //END OF READ


 //SERIAL READ
   while (Serial.available() > 0) 
   { //if there's a byte at serial pin, start reading 
     c = Serial.read(); // get byte
     //Serial.print(c);  // repeat it back so I know you got the message
    if (sofar < MAX_BUF - 1) 
    {
      buffer[sofar++] = c; // store it
    }
    if (c == '\n') 
    {
     buffer[sofar] = 0; // end the buffer so string functions work right
     // Serial.print(F("\r\n"));  // echo a return character for humans
      replyPtr = &buffer[0];
      ready();//set sofar to 0
    }
  }
  //END OF SERIAL READ

  
  
  //PID
  intSetpoint = (int)Setpoint; 
  replyStr = String(replyPtr);
  roll = (replyStr.substring(0, replyStr.indexOf(','))).toFloat(); //roll represents the yaw according to the IMU position in the robot
 // Serial.println(replyPtr);
 // Serial.print("roll"); Serial.println(roll);

//RST
if(RSTSensors)
digitalWrite(RSTSensorsPin, HIGH);
else
digitalWrite(RSTSensorsPin, LOW);


 
if(PIDon)
{  //Adjust joystick signal
      PIDRun();   
      
}
else
{
//Write joystick signal directly
/*MOTION*/
 digitalWrite(Dir1,ReceivedData[0]);
 analogWrite(PWM1, ReceivedData[1]);

 digitalWrite(Dir2, ReceivedData[2]);
 analogWrite(PWM2, ReceivedData[3]);
}


////////////////////
/*UDP Send*/
//////////////////

   Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
   Udp.write(replyPtr);
   Udp.endPacket();
   //Serial.flush();

  delay(10);
}

