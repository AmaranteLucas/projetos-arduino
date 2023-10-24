/* ---------------------------------------------
 * DTMF HOME CONTROL V1.0 Rev0.0
 * Controle de dispositivos através de telefone
 * Arduino-ce
 * Comunidade Cearense de Hardware Livre
 * http://groups.google.com/group/arduino-ce?hl=pt-br
 * http://arduino-ce.blogspot.com
 * março de 2011
 ---------------------------------------------*/

#define RELE1 8 // Conectado ao fio branco do módulo Relé(Figura4)
#define RELE2 9
#define RELE3 10
#define RELE4 11
#define RELE5 12

#define pinBit01  7 // Q0
#define pinBit02  6 // Q1
#define pinBit03  5 // Q2
#define pinBit04  4 // Q3
#define pinBitStd 3 // STD

int tecla = 0;

int bit01 = 0;   
int bit02 = 0; 
int bit03 = 0; 
int bit04 = 0; 
int bitStd= 0; 

int RELE1_STATE = LOW; // Estado do Relé LOW (Desligado)
int RELE2_STATE = LOW;
int RELE3_STATE = LOW;
int RELE4_STATE = LOW;
int RELE5_STATE = LOW;

void setup() { 
  Serial.begin(9600); // Iniciamos a Serial com Baudrate 9600
  pinMode(RELE1, OUTPUT); // Definimos o pino do Relé como Saída
  pinMode(RELE2, OUTPUT);
  pinMode(RELE3, OUTPUT);
  pinMode(RELE4, OUTPUT);
  pinMode(RELE5, OUTPUT);
  Serial.println("Aguardando tecla de comando..."); // Exibimos a mensagem no terminal...
}

void loop(){ 

  bitStd = digitalRead(pinBitStd); //Lê o estado do pino STD e armazena em 'bitStd' 

  if (bitStd == HIGH) {//Se estiver em nível alto fará as leituras 
                       //dos bits dos pinos Q3, Q2, Q1 e Q0

    bit01 = digitalRead(pinBit01);   
    bit02 = digitalRead(pinBit02); 
    bit03 = digitalRead(pinBit03); 
    bit04 = digitalRead(pinBit04); 

    tecla = (bit04 * 8) + (bit03 * 4) + (bit02 * 2) + (bit01 * 1);//Conversão binária para 
                                                                  //decimal (ver Vídeo1)

    Serial.print("Recebido: "); // Exibe a mensagem

    switch (tecla){ // Seleciona a tecla pressionada

    case 1: // Tecla 1
      Serial.println("1");     
      /* COMANDO PARA RELE1 */
      RELE1_STATE = !RELE1_STATE; // Guarda o estado INVERTIDO do Relé.     
      break;

    case 2: // Tecla 2
      Serial.println("2"); 
      RELE2_STATE = !RELE2_STATE;      
      break;

    case 3: // Tecla 3
      Serial.println("3");
      RELE3_STATE = !RELE3_STATE;
      break;

    case 4: // Tecla 4
      Serial.println("4");
      RELE4_STATE = !RELE4_STATE;
      break;

    case 5: // Tecla 5
      Serial.println("5");
      RELE5_STATE = !RELE5_STATE;
      break;

    case 6: // Tecla 6
      Serial.println("6");
      break;

    case 7: // Tecla 7
      Serial.println("7");
      break;

    case 8: // Tecla 8
      Serial.println("8");
      break;

    case 9: // Tecla 9
      Serial.println("9");
      break;

    case 10: // Tecla 0
      Serial.println("0");
      break;

    case 11: // Tecla *
      Serial.println("*");
      break;

    case 12: // Tecla #
      Serial.println("#");
      break; 
    }

    digitalWrite(RELE1, RELE1_STATE);//Liga ou desliga o Relé1 conforme o estado (HIGH/ LOW)
    digitalWrite(RELE2, RELE2_STATE);
    digitalWrite(RELE3, RELE3_STATE);
    digitalWrite(RELE4, RELE4_STATE);
    digitalWrite(RELE5, RELE5_STATE);
    // Zeram-se todas as variáveis 
    tecla = 0;
    bit01 = 0;   
    bit02 = 0; 
    bit03 = 0; 
    bit04 = 0; 
    bitStd= 0; 
    delay (500); // Aguarda 500 milissegundos
  } // Sai do switch
} // Volta pro loop...
