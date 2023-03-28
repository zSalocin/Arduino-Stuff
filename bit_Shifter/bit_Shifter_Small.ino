//latch pin
int latchPin = 3;
//clock pin
int clockPin = 2;
//data pin
int dataPin = 4;
//variavel do tipo byte de nome dado
byte dado;
//vetor do tipo byte
byte dataArray[8];
void setup() {
  pinMode(latchPin, OUTPUT);
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
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, dado);
    //colocando lath pin para High para encerrar transmissao
    digitalWrite(latchPin, HIGH);
    delay(300);
  }
}
void shiftOut(int myDataPin, int myClockPin, byte myDataOut) {
  int i=0;
  int pinState;
  pinMode(myClockPin, OUTPUT);
  pinMode(myDataPin, OUTPUT);
  digitalWrite(myDataPin, LOW);
  digitalWrite(myClockPin, LOW);
  for (i=7; i>=0; i--)  {
    digitalWrite(myClockPin, LOW);
    if ( myDataOut & (1<<i) ) {
      pinState= 1;
    }
    else {  
      pinState= 0;
    }
    digitalWrite(myDataPin, pinState);
    digitalWrite(myClockPin, HIGH);
    digitalWrite(myDataPin, LOW);
  }
  digitalWrite(myClockPin, LOW);
}