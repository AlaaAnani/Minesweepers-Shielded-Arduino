void ParseString(String inp)  //  this void required to separate the string data into motor values
{
  //MOTION
  ReceivedData [0] = (inp.substring(inp.indexOf('A') + 1, inp.indexOf('B'))).toInt(); //dir1
  ReceivedData [1] = (inp.substring(inp.indexOf('B') + 1, inp.indexOf('C'))).toInt(); //PWM1
  ReceivedData [2] = (inp.substring(inp.indexOf('C') + 1, inp.indexOf('D'))).toInt(); //dir2
  ReceivedData [3] = (inp.substring(inp.indexOf('D') + 1, inp.indexOf('E'))).toInt(); //PWM2
  PIDon  =           (inp.substring(inp.indexOf('E') + 1, inp.indexOf('F'))).toInt(); //PID on
  PilotSP  =          (inp.substring(inp.indexOf('F') + 1, inp.indexOf('G'))).toInt(); //Setpoint
  Kp = (inp.substring(inp.indexOf('G') + 1, inp.indexOf('H'))).toDouble();
  Ki = (inp.substring(inp.indexOf('H') + 1, inp.indexOf('I'))).toDouble();
  Kd = (inp.substring(inp.indexOf('I') + 1, inp.indexOf('J'))).toDouble();
  RSTSensors = (inp.substring(inp.indexOf('J') + 1, inp.indexOf('K'))).toInt();
  //Serial.print(Kp); Serial.print("  " ); Serial.print (Ki); Serial.print(" "); Serial.println(Kd);

}
