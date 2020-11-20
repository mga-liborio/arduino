
//Declaração das constantes
int led[] = {9,10, 11};   //constante led refere-se ao pino digital 8.
const int botao = 8; //constante botão refere-se ao pino digital 2.
int contador=0;
 
//Variável que conterá os estados do botão (0 LOW, 1 HIGH).
int estadoBotao = 0;
 
//Método setup, executado uma vez ao ligar o Arduino.
void setup() {
  
  pinMode(botao,INPUT); //Definindo pino digital 2 como de entrada. 

  pinMode(led, OUTPUT);
  pinMode((led+1), OUTPUT);
  pinMode((led+2), OUTPUT);
}
 
//Método loop, executado enquanto o Arduino estiver ligado.
void loop() {  
  //Lendo o estado do pino 2, constante botao, e atribuindo 
  //o resultado a variável estadoBotao.
  
  estadoBotao = digitalRead(botao);          
   
  //Verificando o estado do botão para definir se acenderá ou
  //apagará o led.  
  if (estadoBotao == HIGH) {
    acenderLed(); //Botão pressionado, acende o led.
  } else {
    apagarLed();  //Botão não pressionado, apaga o led.    
  }       
}

void acenderLed(){

  if(contador >= 6)
    contador =0; 
  for(int i=0; i <= contador/2; i++)
      digitalWrite((led[i]),HIGH);
 
}

void apagarLed(){
  
  for(int x=0; x<3; x++)
      digitalWrite((led[x]),LOW);
 
}
