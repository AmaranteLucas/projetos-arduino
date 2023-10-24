

#include <SPI.h>
#include <Ethernet.h>
#include <Servo.h>

Servo myservo;

int val=0;

byte mac[] = { 
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,4);


EthernetServer server(80);


void setup() {

  
  Ethernet.begin(mac, ip);
  server.begin();
  
  myservo.attach(3);
  
}


void loop() {
          
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    String vars;
    int teste=0;
    
    while (client.connected()) {
      
      if (client.available()) {
        char c = client.read();
        
        
        vars.concat(c);
        
        if(vars.endsWith("/v0")){
          teste=1;
        }
        else{
          if(vars.endsWith("/v180")){
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
          
          client.println("<p><h2>Controle do Servo</h2></p>");
         
          
          
          
         
         if(teste==1){
              myservo.write(0);
              client.println("<FORM METHOD='LINK' ACTION='http://192.168.1.4/v180'><INPUT TYPE='submit' VALUE='Mover para 180 graus'></FORM>"); 
          }
          else{
            client.println("<FORM METHOD='LINK' ACTION='http://192.168.1.4/v0'><INPUT TYPE='submit' VALUE='Mover para 0 grau'></FORM>");
          }
          
          if(teste==2){
            myservo.write(170);
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
  }
  
}



