bool estavel; // Guarda o último estado estável do botão;
bool instavel; // Guarda o último estado instável do botão;
uint32_t bounce_timer;
uint8_t contador = 0;

int led[] = {9,10, 11};
int botao = 8; 
int estadoBotao =0;

int ldrPin = 0; // LDR porta 

void acenderLed(); // chamada de funcao para acender led
void apagarLed(); // chamada de funcao para apagar led
bool changed(); // chamada de funcao estabilizador push button



void setup(){

  pinMode(botao, INPUT_PULLUP);
  estavel= digitalRead(botao);

  pinMode(led[0], OUTPUT);
  pinMode((led[1]), OUTPUT);
  pinMode((led[2]), OUTPUT);

  Serial.begin(9600); //Inicia a comunicação serial
}


void loop(){

  int ldrValor =0;

  if (changed()) {
    contador++;
    }
  
  estadoBotao = digitalRead(botao);

  if (estadoBotao == HIGH){
    acenderLed();
  }else{
    apagarLed();}


    ///ler o valor do LDR
    ldrValor = analogRead(ldrPin);

   //imprime o valor lido do LDR no monitor serial
   Serial.println(ldrValor);
   delay(100);
    
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

//
bool changed() {
 bool now = digitalRead(botao); // Lê o estado atual do botão;
 if (instavel != now) { // Checa se houve mudança;
  bounce_timer = millis(); // Atualiza timer;
  instavel = now; // Atualiza estado instável;
 }
 else if (millis() - bounce_timer > 10) { // Checa o tempo de trepidação acabou;
  if (estavel!= now) { // Checa se a mudança ainda persiste;
   estavel= now; // Atualiza estado estável;
   return 1;
  }
 }
 return 0;
}


