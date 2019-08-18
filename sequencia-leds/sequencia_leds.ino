#define TEMPO 1500

int leds[9];

void setup()
{
  for(int i = 0, j = 10; i < 9; i++, j--){
    leds[i] = j;
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], HIGH);
  }
  delay(TEMPO);
  for(int i = 0; i < 9; i++){
    digitalWrite(leds[i], LOW);
  }   
}

void sequencia(int arr[], int a, int b){
  digitalWrite(arr[a], HIGH);
  digitalWrite(arr[b], HIGH);
  delay(TEMPO);
  digitalWrite(arr[a], LOW);
  digitalWrite(arr[b], LOW);
  if(a != b){
    teste(arr, a+1, b-1);
    digitalWrite(arr[a], HIGH);
    digitalWrite(arr[b], HIGH);
    delay(TEMPO);
    digitalWrite(arr[a], LOW);
    digitalWrite(arr[b], LOW);
  }
}

void loop()
{
  sequencia(leds, 0, 8);
}
