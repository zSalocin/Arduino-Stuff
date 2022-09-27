int led = 2;//declara o pino 2 como led
int ldr = A5;//declara ldr como pino A5
int padrao = 100;//declara a variavel padrao com um valor
void setup()//função de declaração
{
Serial.begin(9600);//inicia comunicação serial
pinMode(ldr,INPUT);//declara ldr como entrada
pinMode(led,OUTPUT);//declara led como saida
}

void loop()
{
Serial.println(analogRead(ldr));
  //imprime no monitor serial o valor de leitura de ldr
if(analogRead(ldr)>padrao)
  //caso o valor de leitura de ldr seja maior que o padrao
  digitalWrite(led,HIGH);//envia carga a led
  else
    //caso o valor de leitura de ldr nao seja maior que o padrao
    digitalWrite(led,LOW);//retira carga de led
delay(10);//pausa o programa por 10 milisegundos
}