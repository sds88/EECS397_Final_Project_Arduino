#include <SoftwareSerial.h> 


void setup()
{
  Serial.begin(9600);  // Begin the serial monitor at 9600bps

  Serial1.begin(115200);  // The Bluetooth Mate defaults to 115200bps
}

void loop()
{
  if(Serial1.available())  // If the bluetooth sent any characters
  {
    char c = (char)Serial1.read();
    if(c == '0')
    {
      Serial.println("Congratz");
    }
    else
    {
      Serial.println("Fail");      
    }
    // Send any characters the bluetooth prints to the serial monitor
    //Serial.print((char)Serial1.read());  
  }
  if(Serial.available())  // If stuff was typed in the serial monitor
  {
    // Send any characters the Serial monitor prints to the bluetooth
    Serial1.print((char)Serial.read());
  }
  // and loop forever and ever!
}
