/*
 *  EECS397 - Hardware Security
 *  Final Project
 *  Team: Sam Schneider, Eric King, Eric Luan, Michael Harkins, Matthew Prosser
 *  Nov. 12, 2014
 */
 
#include <SoftwareSerial.h> 

#define AUTH_CHAR '$'
#define SRAM_SIZE 2048
#define SRAM_START (4 * (SRAM_SIZE / 6))
#define SRAM_END (5 * (SRAM_SIZE / 6))

uint8_t const * p = 0;
int i = SRAM_START;
String puf = "";

void setup()
{
  while(i < SRAM_END) // Create the puf at startup
  {
    puf += *p;
    i++;
    p++;        
  }
  Serial1.begin(115200);  // The Bluetooth Mate defaults to 115200bps
}

void loop()
{
  if(Serial1.available())  // If the bluetooth sent any characters
  {
    char c = (char)Serial1.read();  // Pull out the recieved character
    if(c == AUTH_CHAR)  // If the recieved character is the correct authorization character, send the puf over serial
    {
      Serial1.println(puf);
    }
  }
}
