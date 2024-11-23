// To connect your ps3 controller,go to Tools-->Library Manager-->serach for ps3 host controller and install
// Remember to include <Ps3Controller.h>
// To configure your HC05 as a slave,connect it to your arduino board the connect the arduino to the laptop
//Run This code
#include <SoftwareSerial.h>
SoftwareSerial btSerial(0, 1); // RX | TX
 
void setup() 
{
    Serial.begin(9600);

    btSerial.begin(38400);      
    Serial.println("btSerial started at 38400");
}
 
void loop()
{
  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
  {
    btSerial.write(Serial.read()); 
  }
  
  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (btSerial.available())
  {  
    Serial.write(btSerial.read());
  }
}

/*
Upload the code
Once uploaded,remove the cable from Arduino hold the enable button on HC05 then connect cable to arduino 
Go to tools and select serial monitor,select baud rate as 9600 and select both NL & CR 
Slave Command:
AT
AT+RMAAD
AT+ROLE=0
AT+UART=38400,0,0
AT+ADDR
copy the address*/

// To get ps3controller macadress,download sixaxispair tool,install and open it, get the macaddress
// Take the address of the HC05 and copy paste it there and click update


