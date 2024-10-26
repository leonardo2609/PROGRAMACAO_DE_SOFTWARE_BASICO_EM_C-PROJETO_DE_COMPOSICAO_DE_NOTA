# Projeto de Transferência de Arquivos via TCP e UDP

Este projeto demonstra como transferir arquivos entre um cliente e um servidor utilizando os protocolos TCP e UDP. O código está dividido em dois componentes principais: um servidor e um cliente para cada protocolo.

## Estrutura do Projeto

- `tcp_server.c`: Implementação do servidor TCP.
- `tcp_client.c`: Implementação do cliente TCP.
- `udp_server.c`: Implementação do servidor UDP.
- `udp_client.c`: Implementação do cliente UDP.

## Funcionalidades

### Modelo TCP

#### Servidor TCP

- **Inicialização**: O servidor inicializa o Winsock e cria um socket TCP.
- **Configuração**: Solicita a porta ao usuário e associa o socket ao endereço e porta especificados.
- **Escuta**: O servidor aguarda conexões de clientes.
- **Recepção**: Após aceitar a conexão, recebe um arquivo em blocos e salva em `arquivo_recebido.txt`.

#### Cliente TCP

- **Conexão**: O cliente inicializa o Winsock, cria um socket TCP e solicita o endereço IP e a porta do servidor.
- **Envio**: Lê um arquivo e o envia para o servidor em blocos. Calcula o tempo de transmissão.

### Modelo UDP

#### Servidor UDP

- **Inicialização**: O servidor inicializa o Winsock e cria um socket UDP.
- **Recepção de Pacotes**: Aguarda pacotes e salva o conteúdo em `arquivo_recebido.txt`. O recebimento termina quando uma mensagem de finalização é recebida.

#### Cliente UDP

- **Conexão**: Inicializa o Winsock, cria um socket UDP e solicita o endereço IP e a porta do servidor.
- **Envio**: Lê um arquivo e o envia em blocos para o servidor, finalizando o envio com uma mensagem especial.

## Como Compilar e Executar

### Requisitos

- Ambiente Windows com suporte a Winsock.
- Compilador C (ex: MinGW).

### Compilação

1. Compile os arquivos do servidor e do cliente:
   ```bash
   gcc tcp_server.c -o tcp_server -lws2_32
   gcc tcp_client.c -o tcp_client -lws2_32
   gcc udp_server.c -o udp_server -lws2_32
   gcc udp_client.c -o udp_client -lws2_32
   ```

### Execução

1. **Servidor TCP**:
   - Execute o servidor:
     ```bash
     ./tcp_server
     ```

2. **Cliente TCP**:
   - Execute o cliente em outro terminal ou máquina:
     ```bash
     ./tcp_client
     ```

3. **Servidor UDP**:
   - Execute o servidor:
     ```bash
     ./udp_server
     ```

4. **Cliente UDP**:
   - Execute o cliente em outro terminal ou máquina:
     ```bash
     ./udp_client
     ```

## Considerações Finais

Este projeto é uma introdução prática ao uso de sockets em C, cobrindo tanto a transmissão confiável via TCP quanto a comunicação sem conexão via UDP. Ele pode ser expandido com funcionalidades adicionais, como tratamento de erros mais robusto, autenticação e criptografia.
