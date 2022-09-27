int led =3;//declara pino 3 como led
int pir =2;//declara pino 2 como pir
void setup()//funçao de declaração
{
  pinMode(led,OUTPUT);//declara led como saida
  pinMode(pir,INPUT);//declara pir como entrada
}

void loop()//função de repetição
{
 if(digitalRead(pir)==HIGH)//se a leitura de pir for 1 faz
   digitalWrite(led,HIGH);//envia carga a led
  else//se a leitura de pir nao for 1
    digitalWrite(led,LOW);//retira carga de led
  delay(10);//pausa o programa por 10 milisegundo
}