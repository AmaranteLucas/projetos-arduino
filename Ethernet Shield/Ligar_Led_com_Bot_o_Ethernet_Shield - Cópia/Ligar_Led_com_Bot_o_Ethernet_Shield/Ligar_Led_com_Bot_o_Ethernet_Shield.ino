

#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,4);


EthernetServer server(80);

int led=8;



void setup() {
 
  Serial.begin(9600);

  
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
  
  pinMode(led,OUTPUT);
}


void loop() {
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    String vars;
    int teste=0;
    
    while (client.connected()) {
      
      if (client.available()) {
        char c = client.read();
        Serial.print(c);
        
        vars.concat(c);
        
        if(vars.endsWith("/on")){
          teste=1;
        }else{
          if(vars.endsWith("/off")){
            teste=2;
          }
        }
        
//#######################################################
        
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connnection: close");
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          client.println("<p><center><h1>Servidor Arduino Lucas</h1></center></p>");
          client.println("<center><img src=http://missionduke.com/wordpress/wp-content/uploads/2010/11/Arduino-logo1.png></center>");
          client.println("<hr/>");
          
          
         
         if(teste==1){
            digitalWrite(led,HIGH);

               client.println("<p><h2>Led Ligado</h2></p>");
               client.println("<FORM METHOD='LINK' ACTION='http://192.168.1.4/off'><INPUT TYPE='submit' VALUE='DESLIGAR LED'></FORM>");
          
          }else{
              if(teste==2){
                 digitalWrite(led,LOW);
                 
                     client.println("<p><h2>Led Desligado</h2></p>");
                     client.println("<FORM METHOD='LINK' ACTION='http://192.168.1.4/on'><INPUT TYPE='submit' VALUE='LIGAR LED'></FORM>");         
               }
                  else{
                     client.println("<FORM METHOD='LINK' ACTION='http://192.168.1.4/on'><INPUT TYPE='submit' VALUE='LIGAR LED'></FORM>");
                     client.println("<FORM METHOD='LINK' ACTION='http://192.168.1.4/off'><INPUT TYPE='submit' VALUE='DESLIGAR LED'></FORM>");
                   }
           }
        
         
          client.println("</html>");
          break;
          
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } 
        else if (c != '\r') {
         //Essa porra sempre tem que ser true, caralho!
          currentLineIsBlank = true;
        }
      }
     
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disonnected");
  }
}


