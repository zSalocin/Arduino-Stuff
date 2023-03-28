
//latch pin
int latchPin = 3;
//clock pin
int clockPin = 2;
//data pin
int dataPin = 4;
//latch pin2
int latchPin2 = 3;
//clock pin2
int clockPin2 = 2;
//data pin2
int dataPin2 = 4;
//botao
int bot = 13;
//led de controle
int val = 12;
int i;
//variavel do tipo byte de nome dado
byte dado;

byte dado2;
//vetor do tipo byte
byte dataArray[8];
byte dataArray2[8];

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(latchPin2, OUTPUT);
  pinMode(bot, OUTPUT);
  pinMode(val, OUTPUT);
  Serial.begin(9600);

  //setando o vetor com binario
  dataArray[0] = 0b10000000;
  dataArray[1] = 0b01000000;
  dataArray[2] = 0b00100000;
  dataArray[3] = 0b00010000;
  dataArray[4] = 0b00001000;
  dataArray[5] = 0b00000100;
  dataArray[6] = 0b00000010;
  dataArray[7] = 0b00000001;
}

void loop() {
  for (int j = 0; j < 8; j++) {
    //carregando a sequencia de acordo com o vetor
    dado = dataArray[j];
    //colocando lath pin para Low para transmissao
    digitalWrite(latchPin, 0);
    shiftOut(dataPin, clockPin, dado);
    //colocando lath pin para High para encerrar transmissao
    digitalWrite(latchPin, 1);
    delay(300);
  }
    for (int j = 0; j < 8; j++) {
    //carregando a sequencia de acordo com o vetor
    dado2 = dataArray2[j];
    //colocando lath pin para Low para transmissao
    digitalWrite(latchPin2, 0);
    shiftOut(dataPin2, clockPin2, dado2);
    //colocando lath pin para High para encerrar transmissao
    digitalWrite(latchPin2, 1);
    delay(300);
  }
}


void shiftOut(int myDataPin, int myClockPin, byte myDataOut) {
  int i=0;
  int pinState;
  pinMode(myClockPin, OUTPUT);
  pinMode(myDataPin, OUTPUT);
  digitalWrite(myDataPin, 0);
  digitalWrite(myClockPin, 0);
  for (i=7; i>=0; i--)  {
    digitalWrite(myClockPin, 0);
    if ( myDataOut & (1<<i) ) {
      pinState= 1;
    }
    else {  
      pinState= 0;
    }
    digitalWrite(myDataPin, pinState);
    digitalWrite(myClockPin, 1);
    digitalWrite(myDataPin, 0);
  }
  digitalWrite(myClockPin, 0);
}