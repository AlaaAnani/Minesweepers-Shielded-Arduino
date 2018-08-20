char * ConcatenateStringToSend(int gyroX, int DeltaDistance, int MineR, int MineL, int RUSS, int LUSS, double accX, double accY)
{
  
  String ToSendBuffer = "";
  //Yaw,DD,RM,LM,RUSS,LUSS
  ToSendBuffer = String(gyroX)+ "," + String(DeltaDistance)+ "," + String(MineR) + "," + String(MineL) + "," + String(RUSS) + "," +String(LUSS) + ","+ String(accX) + "," + String(accY);
  char ToSendCharArrBuffer [35];
  ToSendBuffer.toCharArray(ToSendCharArrBuffer,26);
  return ToSendCharArrBuffer;
}

