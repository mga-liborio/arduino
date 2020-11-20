
bool stable; // Guarda o último estado estável do botão;
bool unstable; // Guarda o último estado instável do botão;
uint32_t bounce_timer;
uint8_t contador = 0;

int led[] = {9,10, 11};
int botao = 8; 
int estadoBotao =0;

void acenderLed();
void apagarLed();
bool changed();

void setup(){

  pinMode(botao, INPUT_PULLUP);
  //stable = digitalRead(botao);

  pinMode(led[0], OUTPUT);
  pinMode((led[1]), OUTPUT);
  pinMode((led[2]), OUTPUT);

}


void loop(){

  if (changed()) {
    contador++;
    }
  
  estadoBotao = digitalRead(botao);

  if (estadoBotao == HIGH){
    acenderLed();
  }else{
    apagarLed();}
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

bool changed() {
 bool now = digitalRead(botao); // Lê o estado atual do botão;
 if (unstable != now) { // Checa se houve mudança;
  bounce_timer = millis(); // Atualiza timer;
  unstable = now; // Atualiza estado instável;
 }
 else if (millis() - bounce_timer > 10) { // Checa o tempo de trepidação acabou;
  if (stable != now) { // Checa se a mudança ainda persiste;
   stable = now; // Atualiza estado estável;
   return 1;
  }
 }
 return 0;
}


