/*
  SD card read/write
 
 This example shows how to read and write data to and from an SD card file 	
 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4
 
 created   Nov 2010
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe
 
 This example code is in the public domain.
 	 
 */
 
#include <SD.h>

File myFile;

int teste=1;
int n=0;
float temperatura;

void setup()
{
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
  
  Serial.print("Initializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin 
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output 
  // or the SD library functions will not work. 
   pinMode(10, OUTPUT);
   
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("log_temp.txt", FILE_WRITE);
  
  
}

void loop()
{

  // if the file opened okay, write to it:
  if ((myFile==1)&&(teste==1)) {
    Serial.print("Gravando as temperaturas.txt...");
    
    while(n<=30)
    {
      
      temperatura=analogRead(A0);
      temperatura=temperatura*0.4887585533;
    
    myFile.print(n);
    myFile.print("   ");
    myFile.println(temperatura);
    
    delay(1000);
    
    n=n+1;
    }
    teste=0;
    myFile.close();
    Serial.println("done.");
  } 
}


