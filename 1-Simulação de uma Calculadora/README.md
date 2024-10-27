# Projeto: Calculadora Simples com Arduino

Este projeto implementa uma calculadora básica no Arduino, permitindo que o usuário realize operações matemáticas (adição, subtração, multiplicação, e divisão) via comunicação serial. O projeto também permite redefinir o valor inicial da variável e encerrar o programa.

## Visão Geral

A calculadora recebe entradas do usuário por meio do monitor serial e realiza as operações desejadas com base em um valor inicial, `x`, que pode ser alterado ao longo da execução. Esse projeto é ideal para iniciantes em Arduino, pois demonstra o uso de variáveis, manipulação de entrada/saída serial e estrutura de controle.

### Componentes Necessários

- 1 Arduino (ou um simulador como o Tinkercad)

### Funcionamento

1. **Valor Inicial de `x`:** O programa solicita ao usuário um valor inicial para `x`.
2. **Menu de Operações:** O menu lista as operações disponíveis:
   - `a`: Adição
   - `s`: Subtração
   - `d`: Divisão
   - `m`: Multiplicação
   - `t`: Trocar o valor de `x`
   - `q`: Encerrar o programa
3. **Execução das Operações:** Após escolher a operação, o usuário deve fornecer um valor adicional (por exemplo, `y` para adição), e o Arduino exibirá o resultado.
4. **Tratamento de Erros:** Inclui verificação para evitar divisão por zero e erro caso o usuário insira valores não numéricos.

### Código

O código é dividido nas seguintes funções:

1. **`setup()`:** Inicializa o monitor serial e define o valor inicial de `x`.
2. **`loop()`:** Recebe a entrada do usuário para executar a operação selecionada. Controla a execução de operações e chama funções de exibição e manipulação de entrada.
3. **`exibirMenu()`:** Mostra as opções de operação disponíveis.
4. **`lerNumero()`:** Lê e valida o valor numérico inserido pelo usuário, garantindo que apenas números sejam aceitos.
5. **`limparBuffer()`:** Limpa o buffer serial para evitar entradas inválidas.

### Código Completo

```cpp
float x, y, z, w, m;
char opcao;

void setup() {
  Serial.begin(9600);  

  Serial.println("O valor de x sera alterado conforme voce vai utilizando as funcoes\nPara alterar basta digitar t depois de definir o valor de x\nDigite o valor inicial de x: ");
  x = lerNumero();  
  exibirMenu();     
}

void loop() {
  if (Serial.available() > 0) {
    opcao = Serial.read();
    
    if (opcao != 'a' && opcao != 's' && opcao != 'd' && opcao != 'm' && opcao != 't' && opcao != 'q') {
      Serial.println("Opcao invalida. Escolha uma operacao valida.");
      exibirMenu();
      return; 
    }

    switch (opcao) {
      case 'a':  
        Serial.println("Digite o valor de y para adicionar a x: ");
        y = lerNumero();
        x = x + y;
        Serial.print("Resultado: ");
        Serial.println(x);
        break;

      case 's':  
        Serial.println("Digite o valor de z para subtrair de x: ");
        z = lerNumero();
        x = x - z;
        Serial.print("Resultado: ");
        Serial.println(x);
        break;

      case 'd':  
        Serial.println("Digite o valor de w (Divisor) para dividir x (Dividendo): ");
        w = lerNumero();
        if (x == 0 || w == 0) {
          Serial.println("Erro: Nao e possivel dividir por zero.");
        } else {
          x = x / w;
          Serial.print("Resultado: ");
          Serial.println(x);
        }
        break;

      case 'm':  
        Serial.println("Digite o valor de m para multiplicar com x: ");
        m = lerNumero();
        x = x * m;
        Serial.print("Resultado: ");
        Serial.println(x);
        break;

      case 't':  
        Serial.println("Digite o novo valor de x: ");
        x = lerNumero();
        Serial.print("Novo valor de x: ");
        Serial.println(x);
        break;

      case 'q':  
        Serial.println("Fechando o programa...");
        while (true);  
        break;
    } 
    exibirMenu();
  }
}

void exibirMenu() {
  Serial.println("Escolha uma operacao: ");
  Serial.println("a - Adicao");
  Serial.println("s - Subtracao");
  Serial.println("d - Divisao");
  Serial.println("m - Multiplicacao");
  Serial.println("t - Trocar o valor de x");
  Serial.println("q - Fechar o programa");
}

float lerNumero() {
  while (true) {
    while (Serial.available() == 0) {}  
    if (Serial.peek() == '\n') {        
      Serial.read();  
    }

    if (Serial.available() > 0 && (isDigit(Serial.peek()) || Serial.peek() == '-')) {
      return Serial.parseFloat();  
    } else {
      limparBuffer(); 
      Serial.println("Erro: Apenas numeros sao aceitos. Digite um numero, por favor: ");
    }
  }
}

void limparBuffer() {
  while (Serial.available() > 0) {
    Serial.read(); 
  }
}
```

### Simulação

Este projeto pode ser simulado no [Tinkercad](https://www.tinkercad.com/), permitindo que os usuários testem a calculadora e vejam o resultado diretamente no monitor serial.

---

## Autor

Projeto disponível em: [Tinkercad - Calculadora Simples](https://www.tinkercad.com/things/bavkcCIkFdj-calculadorasimples/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fcircuits&sharecode=d6SRgywW3BVtEwpWs6RFbBZC_pC5s_fkOQm-OF4h9JQ)
