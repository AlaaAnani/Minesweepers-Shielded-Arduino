#ifndef ETHERNETDECLARATIONS_H
#define ETHERNETDECLARATIONS_H
/*ETHERNET*/
// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02};
IPAddress ip(192, 168, 1, 23); 
unsigned int localPort = 8888;      // local port to listen on
char packetBuffer[64];  //buffer to hold incoming packet,
char  replyBuffer [50]; //string to send back
char * rPtr = &replyBuffer[0]; //point to the string
// An EthernetUDP instance to let us send and receive packets over UDP
EthernetUDP Udp;

#endif
