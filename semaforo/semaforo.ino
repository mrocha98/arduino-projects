#define TEMPO_VERDE 2000
#define TEMPO_AMARELO 1500

/* eu poderia ter feito sem struct, mas acredito que ela facilita na adição
 * de mais ruas, caso seja preciso, bastando aumentar o valor do array Ruas
 * e adaptar a função iniciaSemaforos.
 */
struct RUA{
 int vermelho, amarelo, verde; 
};

RUA ruas[3];

void acendeRua(struct RUA r)
{
   digitalWrite(r.vermelho, LOW);
  digitalWrite(r.verde, HIGH);
}

void avisaRua(struct RUA r)
{
  digitalWrite(r.verde, LOW);
    digitalWrite(r.amarelo, HIGH);
}

void apagaRua(struct RUA r)
{
  digitalWrite(r.amarelo, LOW);
  digitalWrite(r.vermelho, HIGH);
}

/* a lógica dos semáforos é a seguinte, um semáforo vermelho fica acesso
 * por um tempo igual a soma do vermelho e do amarelo, e conforme uma rua
 * transita entre vermelho e amarelo, as outras permanecem vermelhas.
 */
void iniciaSemaforos(){
  acendeRua(ruas[0]);
    apagaRua(ruas[1]);
    apagaRua(ruas[2]);
    delay(TEMPO_VERDE);
    avisaRua(ruas[0]);
    delay(TEMPO_AMARELO);
    apagaRua(ruas[0]);
    acendeRua(ruas[1]);
    delay(TEMPO_VERDE);
    avisaRua(ruas[1]);
    delay(TEMPO_AMARELO);
    apagaRua(ruas[1]);
    acendeRua(ruas[2]);
    delay(TEMPO_VERDE);
    avisaRua(ruas[2]);
    delay(TEMPO_AMARELO);
}

void acendeTodos(){
  for(int i = 10; i >= 2; i--){
    digitalWrite(i, HIGH);
  }
  delay(TEMPO_AMARELO);
  for(int i = 10; i >= 2; i--){
    digitalWrite(i, LOW);
  }
  delay(TEMPO_AMARELO);
}

void setup()
{
    /* aqui é feita a inicialização dos structs e a pinagem dos leds
     * eu optei por seguir uma sequência, indo de 10 a 2, assim é
     * possível fazer uma repetição, usando variáveis que se decrementam
     * de 3 em 3.
     */
  for(int i = 0, vermelho = 10, amarelo = 9, verde = 8; i < 3; i++, vermelho-=3, amarelo-=3, verde-=3){
      pinMode(vermelho, OUTPUT);
      pinMode(amarelo, OUTPUT);
      pinMode(verde, OUTPUT);
      ruas[i].vermelho = vermelho;
      ruas[i].amarelo = amarelo;
      ruas[i].verde = verde;
  }
  acendeTodos();
}

void loop()
{
  iniciaSemaforos();
}
