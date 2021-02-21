String command = "";
String change = "";
int red =0;
int green =0;
int blue =0;
#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
void setup() {
  // put your setup code here, to run once:
ledcSetup(1, 5000, 8);
ledcSetup(2, 5000, 8);
ledcSetup(3, 5000, 8);

ledcAttachPin(32, 1); //blue
ledcAttachPin(33, 2); //red
ledcAttachPin(25, 3); //green
Serial.begin(9600);
SerialBT.begin("RGB CONTROLLER");
}

void loop() {
  // put your main code here, to run repeatedly:



  if (SerialBT.available() > 0) {
command = SerialBT.readString();



if (command = "RGB") 
{

while (true) {
if (SerialBT.available() > 0)
{
SerialBT.println("SEND VALUE");
DirectRGBControl(SerialBT.readString());
break;
}
}
}


if (command = "Help") 
{
SerialBT.println("-RGB");
SerialBT.println("-Music");
SerialBT.println("-RandomColors");
}

if (command = "RandomColors") 
{
while (true) 
{
if (SerialBT.available() > 0) {break;}  
ledcWrite(1, random(1,255));
ledcWrite(2, random(1,255));
ledcWrite(3, random(1,255));
delay(1000);
}
}














}


  




}




void DirectRGBControl(String command) 
{
red =0;
change = command[0];
red += change.toInt() * 100;
change = command[1];
red += change.toInt() * 10;
change = command[2];
red += change.toInt();
ledcWrite(1, red);

green =0;
change = command[4];
green += change.toInt() * 100;
change = command[5];
green += change.toInt() * 10;
change = command[6];
green += change.toInt();
ledcWrite(1, red);


blue =0;
change = command[8];
blue += change.toInt() * 100;
change = command[9];
blue += change.toInt() * 10;
change = command[10];
blue += change.toInt();

ledcWrite(3, green);
ledcWrite(1, blue);
ledcWrite(2, red);

  
  
  
  
  
  
  
  
  
  
  
}
