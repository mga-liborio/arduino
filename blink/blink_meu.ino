#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
int temp;
char a = '9';


void setup() {
  
  lcd.begin(16,1);
  
  lcd.setCursor(0,1);
  lcd.print("Arduino");
}

// the loop function runs over and over again forever
void loop() {

  lcd.setCursor(0,0);
  lcd.print(a);
  a++;
  
  lcd.setCursor(13,1);
  lcd.print(temp);
  delay(1000);
  temp++;
  

  if(temp == 600){
  temp = 0;
  }                 
}

