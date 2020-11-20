#include <LiquidCrystal.h> // inclusao de biblioteca - funcoes para o LCD

LiquidCrystal lcd (12,11,5,4,3,2); // portas no arduino
int temp; // variavel global de incrementacao

void setup() {
  
  lcd.begin(16,2); // tamanho do LCD - 2 linhas, 16 colunas
  lcd.setCursor(0,0); // seta na posicao 0,0
  lcd.print("Arduino"); // printa na tela na posicao 0,0
  lcd.setCursor(0,1); // seta na posicao 0,1
  lcd.print("Marilia"); // printa na tela na posicao 0,1

}

void loop() {
  
  lcd.setCursor(13,1); // seta curso na posicao 13,1 
  
  lcd.print(temp); // imprime a variavel temp
  delay(500); // espera 500
  temp++; // incrementa temp
  
  if (temp==99){ // se temp passar de 99 faca
    temp=0; // atribua a temp 0
  }

}

