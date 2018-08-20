void MoveFunc(int Dir1Value, int PWM1Value, int Dir2Value, int PWM2Value)
{
  digitalWrite(Dir1,Dir1Value);
  analogWrite(PWM1, PWM1Value);

  digitalWrite(Dir2, Dir2Value);
  analogWrite(PWM2, PWM2Value);
  
}
/*
void moveF(int pwmR, int pwmL)
{
  digitalWrite(Dir1, HIGH);
  analogWrite(PWM1, pwmR);
 
  
   digitalWrite(Dir2, HIGH);
  analogWrite(PWM2, pwmL);

}
void moveB(int pwmR, int pwmL)
{
  digitalWrite(Dir1, LOW);
  analogWrite(PWM1, pwmR);
  
  digitalWrite(Dir2, LOW);
  analogWrite(PWM2, pwmL);

}
void moveR(int pwmR, int pwmL)
{
  digitalWrite(Dir1, LOW);
  analogWrite(PWM1, pwmR);

  digitalWrite(Dir2, HIGH);
  analogWrite(PWM2, pwmL);
}
void moveL(int pwmR, int pwmL)
{
   digitalWrite(Dir1, HIGH);
  analogWrite(PWM1, pwmR);

  digitalWrite(Dir2, LOW);
  analogWrite(PWM2, pwmL);
}*/
