/*
 *  EECS397 - Hardware Security
 *  Final Project
 *  Team: Sam Schneider, Eric King, Eric Luan, Michael Harkins, Matthew Prosser
 *  Nov. 12, 2014
 */
 
#include <SoftwareSerial.h> 

#define AUTH_CHAR '$'

void setup()
{
  Serial1.begin(115200);  // The Bluetooth Mate defaults to 115200bps
}

void loop()
{
  if(Serial1.available())  // If the bluetooth sent any characters
  {
    char c = (char)Serial1.read();  // Pull out the recieved character
    if(c == AUTH_CHAR)  // If the recieved character is the correct authorization character
    {
      Serial1.println("Congratz");  // Reply back with a PUF
    }
  }
}
