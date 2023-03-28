void setup() {//função de declaração
pinMode(2,OUTPUT);//declara pino 2 como saida
pinMode(3,INPUT);//declara pino 3 como entrada
}

void loop() {//função de repetição
if(digitalRead(3))//caso a leitura de pino 3 seja positiva
  digitalWrite(2,HIGH);//envia carga a pino 2
  else//caso a leitura de pino 3 seja negativa
    digitalWrite(2,LOW);//retira carga de pino 2
}
