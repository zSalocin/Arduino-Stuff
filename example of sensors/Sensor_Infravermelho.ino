int led = 3;//declara pino 3 como led
int infra = 2;//declara pino 3 como infra
 
void setup(){//função de declaração
pinMode(led,OUTPUT);//declara led como saida
pinMode(infra,INPUT);//declara infra como entrada
}
 
void loop(){//função de repetição
  if(digitalRead(infra)==HIGH)//caso a leitura de infra seja positiva
    digitalWrite(led,HIGH);//envia carga a led
  else//caso a leitura de infra seja negativa
    digitalWrite(led,LOW);//retira carga de led
  delay(10);//pausa o programa por 10 milisegundos
}