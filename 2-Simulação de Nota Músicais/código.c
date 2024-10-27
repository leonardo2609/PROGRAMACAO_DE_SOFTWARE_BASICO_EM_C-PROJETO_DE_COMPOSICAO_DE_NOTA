#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_DS5 622

int melodia[] = {
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_AS4, NOTE_B4, NOTE_DS5, NOTE_AS4, NOTE_AS4
}; 

int duracaoNota[] = {
  4, 4 ,4 ,4 ,6 ,6 ,6 ,4 ,4
}; 

void setup() {
  pinMode(10, OUTPUT);
}

void loop() {
  for (int nota = 0; nota < 9; nota++) {
    int duracao = 1000 / duracaoNota[nota];
    tone(10, melodia[nota], duracao);

    int pausaNotas = duracao * 1.70;
    delay(pausaNotas);

    noTone(10); 
  }
  delay(3000); 
}
