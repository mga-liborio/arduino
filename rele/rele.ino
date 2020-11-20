
int led=10;
int rele= 9;
int push=8;
int estadoRele=0;
int estadoPush=0;

void setup()
{
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, INPUT);
  Serial.begin(9600);
  Serial.println("Bem vindo ao sistema de sensores e atuadores da escola do arduino");
}

void loop()
{
  estadoRele=digitalRead(rele);
  Serial.println("Rele: ");
  Serial.println(estadoRele);
  estadoPush=digitalRead(push);
  Serial.println(estadoPush);
  if (estadoPush==1){
    digitalWrite(rele, HIGH);
  }else{
    digitalWrite(rele, LOW);
  }
  delay(100);
}

