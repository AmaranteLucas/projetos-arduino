

#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,4);


EthernetServer server(80);

int led=5,led2=6,led3=7,led4=8;

int teste=0,teste2=0,teste3=0,teste4=0;


void setup() {
 
  Serial.begin(9600);

  
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
  
  pinMode(led,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
}


void loop() {
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    String vars;
    
    
    while (client.connected()) {
      
      if (client.available()) {
        char c = client.read();
        Serial.print(c);
        
        vars.concat(c);
        
        if(vars.endsWith("/1on")){
          teste=1;
        }
        else{
          if(vars.endsWith("/1off")){
            teste=2;
          }
          else{
            if(vars.endsWith("/2on")){
            teste2=3;
            }
             else{
               if(vars.endsWith("/2off")){
               teste2=4;
               }
                 else{
                   if(vars.endsWith("/3on")){
                     teste3=1;
                  }
                     else{
                        if(vars.endsWith("/3off")){
                        teste3=2;
                        }
                        else{
                          if(vars.endsWith("/4on")){
                           teste4=1;
                          }
                          else{
                            if(vars.endsWith("/4off")){
                              teste4=2;
                            }
                          }
                        }
                     }
                  }  
                }
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
          
          client.print("<center>");
          client.print("<table border='1' width='50%'>");
          client.print("<tr>");
          client.print("<td align='center' valign='middle'>");
          
         // ############################################################# Dispositivo 1 ################################################################
         client.println("<p><h3>Dispositivo 1 </h3></p>");
         if(teste==1){
            digitalWrite(led,HIGH);

               client.println("<p><h2>Ligado</h2></p>");
               client.println("<FORM METHOD='LINK' ACTION='http://192.168.1.4/1off'><INPUT TYPE='submit' VALUE='DESLIGAR'></FORM>");
          
          }else{
              if(teste==2){
                 digitalWrite(led,LOW);
                 
                     client.println("<p><h2>Desligado</h2></p>");
                     client.println("<FORM METHOD='LINK' ACTION='http://192.168.1.4/1on'><INPUT TYPE='submit' VALUE='LIGAR'></FORM>");         
               }
                  else{
                     client.println("<p><h2>Desligado</h2></p>");
                     client.println("<FORM METHOD='LINK' ACTION='http://192.168.1.4/1on'><INPUT TYPE='submit' VALUE='LIGAR'></FORM>");
                    
                  }
           }
           
          
           
           
          //#############################################################################################################################################
          
          client.print("</td>");
          client.print("<td align='center' valign='middle'>");
          
          // ############################################################# Dispositivo 2 ################################################################
         client.println("<p><h3>Dispositivo 2 </h3></p>");
         if(teste2==3){
            digitalWrite(led2,HIGH);

               client.println("<p><h2>Ligado</h2></p>");
               client.println("<FORM METHOD='LINK' ACTION='http://192.168.1.4/2off'><INPUT TYPE='submit' VALUE='DESLIGAR'></FORM>");
          
          }else{
              if(teste2==4){
                 digitalWrite(led2,LOW);
                 
                     client.println("<p><h2>Desligado</h2></p>");
                     client.println("<FORM METHOD='LINK' ACTION='http://192.168.1.4/2on'><INPUT TYPE='submit' VALUE='LIGAR'></FORM>");         
               }
                  else{
                     client.println("<p><h2>Desligado</h2></p>");
                     client.println("<FORM METHOD='LINK' ACTION='http://192.168.1.4/2on'><INPUT TYPE='submit' VALUE='LIGAR'></FORM>");
                     
                  }
           }
           
          client.print("</td>");
          client.print("</tr>");
          
          //#####################################################################################################################################
          
          client.print("<tr>");
          client.print("<td align='center' valign='middle'>");
          
           // ############################################################# Dispositivo 3 ################################################################
         client.println("<p><h3>Dispositivo 3 </h3></p>");
         if(teste3==1){
            digitalWrite(led3,HIGH);

               client.println("<p><h2>Ligado</h2></p>");
               client.println("<FORM METHOD='LINK' ACTION='http://192.168.1.4/3off'><INPUT TYPE='submit' VALUE='DESLIGAR'></FORM>");
          
          }else{
              if(teste3==2){
                 digitalWrite(led3,LOW);
                 
                     client.println("<p><h2>Desligado</h2></p>");
                     client.println("<FORM METHOD='LINK' ACTION='http://192.168.1.4/3on'><INPUT TYPE='submit' VALUE='LIGAR'></FORM>");         
               }
                  else{
                     client.println("<p><h2>Desligado</h2></p>");
                     client.println("<FORM METHOD='LINK' ACTION='http://192.168.1.4/3on'><INPUT TYPE='submit' VALUE='LIGAR'></FORM>");
                     
                  }
           }
           
          client.print("</td>");
          
           
          //#####################################################################################################################################
          
           
          client.print("<td align='center' valign='middle'>");
          
           // ############################################################# Dispositivo 4 ################################################################
         client.println("<p><h3>Dispositivo 4 </h3></p>");
         if(teste4==1){
            digitalWrite(led4,HIGH);

               client.println("<p><h2>Ligado</h2></p>");
               client.println("<FORM METHOD='LINK' ACTION='http://192.168.1.4/4off'><INPUT TYPE='submit' VALUE='DESLIGAR'></FORM>");
          
          }else{
              if(teste4==2){
                 digitalWrite(led4,LOW);
                 
                     client.println("<p><h2>Desligado</h2></p>");
                     client.println("<FORM METHOD='LINK' ACTION='http://192.168.1.4/4on'><INPUT TYPE='submit' VALUE='LIGAR'></FORM>");         
               }
                  else{
                     client.println("<p><h2>Desligado</h2></p>");
                     client.println("<FORM METHOD='LINK' ACTION='http://192.168.1.4/4on'><INPUT TYPE='submit' VALUE='LIGAR'></FORM>");
                     
                  }
           }
           
          client.print("</td>");
          
           
          //#####################################################################################################################################
          
          client.print("</tr>");
          client.print("</table>");
          client.print("</center>");
          
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


