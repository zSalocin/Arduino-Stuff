int led[5]={2,3,4,5,6};
//declara um vetor de inteiros como led
//o vetor tem 5 posições sendo essas os pinos 2,3,4,5,6
//que correspondem no vetor as posiçoes
//0:2, 1:3, 2:4, 3:5, 4:6
int i,j;//declara as variaveis i e j como inteiras
int bot= 8;//declara o pino 8 como bot
void setup()//função de declaração
{
  for(i=0;i<5;i++)//inicia um repetição de i=0 a i menor que 5
  pinMode(led[i], OUTPUT);//declara o vetor led na posição i
  //como saida
  pinMode(bot,INPUT);//declara bot como entrada
}

void loop()//função de repetição
{
  for(i=0;i<5;i++){//repetição de i=0 ate i menor que 5
    digitalWrite(led[i],HIGH);//envia carga a led na posição i
    for(j=0;j<7;j++){//repetição de j=0 ate menor que 7
      if(i==2 & digitalRead(bot)==1){
        //caso i=2 e a leitura de bot seja 1 faz
        for(i=0;i<5;i++)//repetição de i=0 ate i menor que 5
          digitalWrite(led[i],HIGH);
        //envia carga a led na posição i
        delay(500);//pausa o programa por 500 milisegundos
        for(i=0;i<5;i++)//repetição de i=0 ate i menor que 5
          digitalWrite(led[i],LOW);
        //retira carga a led na posição i
        delay(500);//pausa o programa por 500 milisegundos
      }
      delay(50);//pausa o programa por 50 milisegundos
    }
    digitalWrite(led[i],LOW);//retira carga a led na posição i
  }
}