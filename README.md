# Projetos com Arduino e Sockets em C

Este repositório contém três projetos distintos, cada um explorando conceitos de programação com Arduino e sockets em C.

---

## Projeto 1: Calculadora Serial Simples com Arduino

[Link do Projeto no Tinkercad](https://www.tinkercad.com/things/bavkcCIkFdj-calculadorasimples/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fcircuits&sharecode=d6SRgywW3BVtEwpWs6RFbBZC_pC5s_fkOQm-OF4h9JQ)

### Descrição
Esta calculadora básica emula operações matemáticas através da comunicação serial do Arduino. O usuário pode realizar operações de adição, subtração, multiplicação e divisão.

### Funcionamento do Código
- O valor inicial de `x` é definido pelo usuário e atualizado conforme operações são realizadas.
- O código exibe um menu com as operações disponíveis. O usuário escolhe uma operação e insere o valor necessário para efetuar o cálculo.
- O código suporta operações de adição (`a`), subtração (`s`), multiplicação (`m`), divisão (`d`), troca do valor de `x` (`t`) e opção de fechar (`q`).

### Componentes
- Arduino Uno (sem componentes externos adicionais)

### Como Executar
1. Carregue o código no Arduino.
2. Abra o Monitor Serial a uma taxa de 9600 bps.
3. Siga as instruções no monitor para inserir valores e selecionar operações.

---

## Projeto 2: Notas Musicais com Arduino

[Link do Projeto no Tinkercad](https://www.tinkercad.com/things/hlDFiHaVunb-notas-musicais-com-arduino-)

### Descrição
Este projeto utiliza um Arduino para tocar uma melodia simples em um buzzer. As notas musicais são representadas como frequências específicas, e o código envia estas frequências ao buzzer, gerando a melodia.

### Funcionamento do Código
- As notas da melodia são armazenadas no array `melodia`, enquanto as durações correspondentes são armazenadas no array `duracaoNota`.
- O Arduino percorre cada nota e toca a frequência correspondente no pino 10, onde o buzzer está conectado.
- Após tocar cada nota, uma pequena pausa é inserida para dar ritmo à melodia.

### Componentes
- Arduino Uno
- Buzzer (conectado ao pino 10)

### Como Executar
1. Monte o circuito com o buzzer no pino 10 do Arduino.
2. Carregue o código no Arduino.
3. O Arduino tocará automaticamente a melodia assim que o código iniciar.

---

## Projeto 3: Transferência de Arquivo com Sockets TCP e UDP em C

Este projeto é dividido em duas partes, com implementações TCP e UDP para comunicação entre cliente e servidor para transferência de arquivos.

### A) TCP

#### Descrição
Este projeto estabelece uma conexão TCP entre cliente e servidor para transferência de arquivos. O servidor escuta em uma porta específica e aceita conexões de um cliente que deseja enviar um arquivo.

#### Funcionamento do Código
1. **Servidor TCP**:
   - Configura uma porta e espera por conexões.
   - Recebe o arquivo em blocos e salva-o localmente.
2. **Cliente TCP**:
   - Lê o arquivo especificado e o envia ao servidor em blocos de dados.

#### Como Executar
1. Compile e inicie o servidor, inserindo a porta de escuta desejada.
2. Em outro terminal, inicie o cliente, insira o IP do servidor, a porta de destino e o nome do arquivo a ser enviado.
3. O arquivo será transmitido do cliente para o servidor.

---

### B) UDP

#### Descrição
Esta versão do projeto usa sockets UDP para a transferência de arquivos. O cliente envia pacotes contendo os dados do arquivo para o servidor, que os armazena localmente.

#### Funcionamento do Código
1. **Servidor UDP**:
   - Configura uma porta e espera por pacotes UDP.
   - Recebe pacotes e os escreve em um arquivo até receber o comando de término (`#fim`).
2. **Cliente UDP**:
   - Lê o arquivo e envia pacotes para o servidor até que todo o arquivo seja transmitido.
   - Após a transferência, envia um comando de término para indicar o fim.

#### Como Executar
1. Compile e execute o servidor, definindo a porta de escuta.
2. Em outro terminal, inicie o cliente, insira o IP do servidor, a porta e o nome do arquivo a ser enviado.
3. O servidor salvará o arquivo recebido.

---

## Pré-Requisitos

- **Arduino IDE** para carregar os códigos dos projetos Arduino.
- **Compilador C/C++** para os projetos de sockets, como GCC (Linux) ou MinGW (Windows).
- **Winsock Library**: Necessário para os projetos de sockets em ambientes Windows.

## Instalação

1. Clone o repositório:

```bash
git clone https://github.com/seu_usuario/seu_repositorio.git
```

2. Para os projetos Arduino, abra o código `.ino` na Arduino IDE e faça upload.
3. Para os projetos em C, compile os arquivos `.c` e siga as instruções de execução.
