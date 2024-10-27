# Projeto: Notas Musicais com Arduino

Este projeto implementa uma melodia simples usando um Arduino e um buzzer. O código define uma sequência de notas e suas durações para tocar uma música básica. É ideal para iniciantes que desejam entender o uso de tons e da função `tone()` no Arduino.

## Visão Geral

Neste projeto, um buzzer é conectado ao Arduino e reproduz uma melodia específica. Utilizamos a função `tone()` para emitir diferentes frequências sonoras, correspondentes a notas musicais. Cada nota tem uma duração associada, o que permite a criação de uma sequência musical.

### Componentes Necessários

- 1 Arduino (ou um simulador como o Tinkercad)
- 1 Buzzer passivo
- Fios de conexão

### Montagem

1. Conecte o pino positivo do buzzer ao pino digital 10 do Arduino.
2. Conecte o pino negativo do buzzer ao GND.

### Código

O código consiste em três partes principais:
1. Definição das notas musicais e suas frequências.
2. Vetores para armazenar as notas (`melodia[]`) e suas durações (`duracaoNota[]`).
3. Funções `setup()` e `loop()` para configurar o pino e tocar a sequência de notas.

```cpp
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
```

### Explicação do Código

1. **Notas e Durações:** As notas são definidas por suas frequências (em Hertz), e cada nota possui uma duração proporcional a seu valor.
2. **Função `setup()`:** Define o pino 10 como saída para o buzzer.
3. **Função `loop()`:** 
   - Reproduz cada nota da melodia, utilizando a função `tone()` para emitir a frequência correspondente.
   - Define uma pausa entre as notas e finaliza o som com `noTone()`.
   - Após a execução da melodia completa, aguarda 3 segundos antes de repetir.

### Simulação

Este projeto pode ser facilmente simulado no [Tinkercad](https://www.tinkercad.com/), permitindo que os usuários testem o código e a configuração sem hardware físico.

---

## Autor

Projeto disponível em: [Tinkercad - Notas Musicais com Arduino](https://www.tinkercad.com/things/aSQ2VGbaSUx-notas-musicais-com-arduino-)
