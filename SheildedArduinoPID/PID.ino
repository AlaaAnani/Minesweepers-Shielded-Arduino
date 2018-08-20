void PIDRun()
{switch(PilotSP)
{
case 0:
    if(roll > 180)
    Input = -(360 - roll);
    else
    Input = - (roll);
    break;
case 90:
     newroll = roll - 90;
    if(newroll < 0)
      newroll = 360+newroll;
    
      if(newroll > 180)
      Input =-( 360 - newroll);
      else
      Input = -(newroll);
      break;
case 180:
        newroll = roll - 180;
    if(newroll < 0)
      newroll = 360+newroll;
    
      if(newroll > 180)
      Input =-( 360 - newroll);
      else
      Input = -(newroll);
      break;
case 270:
          newroll = roll - 270;
    if(newroll < 0)
      newroll = 360+newroll;
    
      if(newroll > 180)
      Input =-( 360 - newroll);
      else
      Input = -(newroll);
      break;
      }
myPID.Compute();
Serial.print(roll); Serial.print("  "); Serial.print(Input); Serial.print("  "); Serial.println(Output);


   
value = PilotSP + 180;
if(value >=360)
value = value - 360;
else
value = value;  
p = 180 - PilotSP;
nnewroll = p + roll; 
if(nnewroll < 0)
nnewroll = 360 + nnewroll;
else if(nnewroll > 360)
nnewroll = nnewroll - 360;
Serial.println(nnewroll);
Output = (int) Output1;
Serial.println(Output);
 if(nnewroll > 181  && nnewroll <= 360) // moved left
   {  digitalWrite(Dir1, 1);
      analogWrite(PWM1,  ReceivedData[1]+ Output);
      digitalWrite(Dir2, 0);
      analogWrite(PWM2,ReceivedData[3]+ Output);
      Serial.println("left");    

    
   }
   else if(nnewroll < 179  && nnewroll >=0 ) 
   {
       digitalWrite(Dir2, 1);
      analogWrite(PWM2,ReceivedData[3]+ Output);
       digitalWrite(Dir1, 0);
      analogWrite(PWM1, ReceivedData[1]+ Output);
      Serial.println("Right");  
      
      
   }
   else 
   {
      digitalWrite(Dir1,ReceivedData[0]);
      analogWrite(PWM1, ReceivedData[1]);

      digitalWrite(Dir2, ReceivedData[2]);
      analogWrite(PWM2, ReceivedData[3]);
      Serial.println("Stop");
    
   }
}

