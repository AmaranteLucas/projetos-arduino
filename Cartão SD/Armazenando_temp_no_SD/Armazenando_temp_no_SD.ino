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

float temp;

int cont=0;

void setup()
{
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


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
 
  
  // if the file opened okay, write to it:
  
  Serial.println("Apagando arquivos anteriores...");
  SD.remove("test.txt");
  Serial.println("Arquivos apagados");
  Serial.println("Pronto para armazenar novo arquivo");
  
}

void loop()
{
  
    myFile = SD.open("test.txt", FILE_WRITE);
  
    if (myFile) {
    Serial.print("Armazenando temperaturas...");
    myFile.println("Temperaturas:");
    myFile.println("");
    myFile.println("");
    
    while(cont<=20){
      
    temp=analogRead(A0);
    temp=temp*0.4887585533;
    
    myFile.print(cont);
    Serial.print(cont);
    
    myFile.print("  ");
    Serial.print("  ");
    
    myFile.println(temp);
    Serial.println(temp);
    
    myFile.println("");
    Serial.println("");
	
    cont++;
    delay(1000);
    }
    myFile.close();
    Serial.println("Armazenamento completo");
  }
  
  while(true)
  {
  }
  
}


