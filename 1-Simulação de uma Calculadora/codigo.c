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