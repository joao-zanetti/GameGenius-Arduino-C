
/*
    Devolep by João Zanetti
    https://github.com/joao-zanetti
*/

#define LED_VERMELHO 2
#define LED_AMARELO 3
#define LED_VERDE 4
#define BOTAO_VERMELHO 10
#define BOTAO_AMARELO 11
#define BOTAO_VERDE 12
#define TAMANHOSEQ 5
#define INDEFINIDO -1

int sequenciaLed[TAMANHOSEQ];
int estadoBotaoVERMELHO;
int estadoBotaoAMARELO;
int estadoBotaoVERDE;
int i,j,n,aux,aux2;
  
void setup() {
  Serial.begin(9600);
}

void iniciaPortas(){
  pinMode(LED_VERMELHO,OUTPUT);
  pinMode(LED_AMARELO,OUTPUT);
  pinMode(LED_VERDE,OUTPUT);
  pinMode(BOTAO_VERMELHO,INPUT_PULLUP);
  pinMode(BOTAO_AMARELO,INPUT_PULLUP);
  pinMode(BOTAO_VERDE,INPUT_PULLUP);
  
}
void iniciaSequencia(){
  for (i=0;i<TAMANHOSEQ;i++){
    sequenciaLed[i]=random(LED_VERMELHO,LED_VERDE+1);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  iniciaPortas();
  iniciaSequencia();
  startGame();
  for(i=1;i<=TAMANHOSEQ;i++){
    printaSequencia(i);
    Serial.println(i);
    lerBotoes(i);
  }
  aux=lerBotaoAcende();
  Serial.println(aux);
  endGame();
}

void printaSequencia(int rodada){
  delay(2000);
  for(j=0;j<rodada;j++){
    piscaLed(sequenciaLed[j]);
    delay(1000);
  }
  delay(2000);
}


void lerBotoes(int rodada){
  aux=INDEFINIDO;
  for(j=0;j<rodada;j++){
    while(aux==INDEFINIDO){
      aux=lerBotaoAcende();
      if(aux==sequenciaLed[j]){
      }
      else{
      }
    }
    aux=INDEFINIDO;
  }
}



int piscaLed(int led){
  digitalWrite(led,HIGH);
  delay(1000);
  digitalWrite(led,LOW);
  return led;
}

void endGame(){
    digitalWrite(LED_AMARELO,HIGH);
    digitalWrite(LED_VERMELHO,HIGH);
    digitalWrite(LED_VERDE,HIGH);
    delay(5000);
    digitalWrite(LED_AMARELO,LOW);
    digitalWrite(LED_VERMELHO,LOW);
    digitalWrite(LED_VERDE,LOW);
}

void startGame(){
    digitalWrite(LED_AMARELO,HIGH);
    digitalWrite(LED_VERMELHO,HIGH);
    digitalWrite(LED_VERDE,HIGH);
    delay(3000);
    digitalWrite(LED_AMARELO,LOW);
    digitalWrite(LED_VERMELHO,LOW);
    digitalWrite(LED_VERDE,LOW);
}


int lerBotaoAcende(){
  if(digitalRead(BOTAO_VERMELHO)==LOW){
    return piscaLed(LED_VERMELHO);
  }
  else if(digitalRead(BOTAO_AMARELO)==LOW){
    return piscaLed(LED_AMARELO);
  }
  else if(digitalRead(BOTAO_VERDE)==LOW){
    return piscaLed(LED_VERDE);
  }
  else{
    return INDEFINIDO;
  }
}
