#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock.h>
#include <time.h>  // Para medir o tempo

#define BUFFER_SIZE 128

WSADATA wsa_data;
SOCKET client_socket;
struct sockaddr_in server_address;

void msg_err_exit(char *msg) {
    fprintf(stderr, "%s", msg);
    system("PAUSE");
    exit(EXIT_FAILURE);
}

int main() {
    // Inicia o Winsock 2.0
    if (WSAStartup(MAKEWORD(2, 0), &wsa_data) != 0)
        msg_err_exit("WSAStartup() falhou\n");

    // Cria o socket TCP
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == INVALID_SOCKET) {
        WSACleanup();
        msg_err_exit("socket() falhou\n");
    }

    // Configura o endereço do servidor
    char server_ip[16];
    unsigned short server_port;
    printf("Endereço IP do servidor: ");
    scanf("%15s", server_ip);
    printf("Porta do servidor: ");
    scanf("%hu", &server_port);
    fflush(stdin);

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(server_port);
    server_address.sin_addr.s_addr = inet_addr(server_ip);

    // Conecta ao servidor
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == SOCKET_ERROR) {
        closesocket(client_socket);
        WSACleanup();
        msg_err_exit("connect() falhou\n");
    }

    // Abre o arquivo para leitura
    char filename[BUFFER_SIZE];
    printf("Nome do arquivo para enviar: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "rb");
    if (file == NULL) msg_err_exit("Erro ao abrir o arquivo\n");

    // Mede o tempo de início
    clock_t start_time = clock();

    // Envia o arquivo em blocos
    char buffer[BUFFER_SIZE];
    int bytes_read;
    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0) {
        if (send(client_socket, buffer, bytes_read, 0) == SOCKET_ERROR) {
            msg_err_exit("send() falhou\n");
        }
    }

    // Fecha o arquivo e o socket
    fclose(file);
    closesocket(client_socket);
    WSACleanup();

    // Calcula e exibe o tempo de transmissão
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Arquivo enviado com sucesso em %.2f segundos.\n", elapsed_time);

    system("PAUSE");
    return 0;
}

