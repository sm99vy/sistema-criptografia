#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NSVERDE    "\033[1;4;32m"
#define NSVERMELHO "\033[1;4;31m"
#define NSAZUL     "\033[1;4;34m"
#define NSROXO     "\033[1;4;35m"
#define NSFAZUL    "\033[1;4;37;44m"
#define NSCIANO    "\033[1;4;36m"
#define NSFROXO    "\033[1;4;37;45m"
#define NSFpreto   "\033[1;4;37;40m"
#define R          "\033[m"

int main() {

    char cesar[16] = "";
    char result[16] = "";
    char tipo[50] = "";
    char tittle[] = "SISTEMA DE CRIPTOGRAFIA";
    char word[16];

    int menu = 0;
    int options = 0;
    int volta = 0;
    int running = 1;

    int shift;
    int position;
    int term;
    int ratio;
    int pos;
    int prime_number;
    int i;
    int increment;

    int pa[16];
    int pg[16];
    int prime[16];
    int fibonacci[16];
    int increment_list[16];

    FILE *archive;
    FILE *log;

    printf(NSFpreto);
    for (i = 0; i < 40; i++) {
        printf("═");
    }
    printf("%s\n", R);
    printf("%s        %s        %s\n", NSFAZUL, tittle, R);
    printf(NSFpreto);
    for (i = 0; i < 40; i++) {
        printf("═");
    }
    printf("%s\n", R);
    while (running) {
        if (volta == 0) {
            while (menu != 1 && menu != 2) {
                printf("\n%s [1] Criptografar\n [2] Sair\n Escolha sua opção: %s",
                       NSROXO, R);
                scanf("%d", &menu);
                if (menu < 1 || menu > 2) {
                    printf("\n\n\n\n%sOpção inválida! Tente novamente.%s\n",
                           NSVERMELHO, R);
                }
                if (menu == 2) {
                    printf("%s\n", R);
                    running = 0;
                    break;
                }
                else if (menu == 1) {
                    volta += 1;
                    while (volta == 1) {
                        printf("\n\n\n\n\n\n\n\n%sDigite a palavra que deseja criptografar: %s",
                               NSROXO, R);
                        scanf("%15s", word);
                        int valido = 1;
                        if (strlen(word) > 15) {
                            valido = 0;
                        }
                        for (pos = 0; pos < strlen(word); pos++) {
                            if (!isalpha((unsigned char)word[pos]) ||
                                !isascii((unsigned char)word[pos])) {
                                valido = 0;
                            }
                        }
                        if (valido == 0) {
                            printf("\n\n\n\n%sA palavra deve ter no máximo 15 letras, sem acentos ou caracteres especiais! Tente novamente.%s\n",
                                   NSVERMELHO, R);
                            volta = 0;
                        }
                        else {
                            printf("%sDigite o valor de SHIFT (1 a 25): %s",
                                   NSROXO, R);
                            scanf("%d", &shift);
                            if (shift < 1 || shift > 25) {
                                printf("\n\n\n\n%sValor de SHIFT inválido! Tente novamente.%s\n",
                                       NSVERMELHO, R);
                                volta = 0;
                            }
                            else {
                                for (pos = 0; pos < strlen(word); pos++) {
                                    if (isupper((unsigned char)word[pos])) {
                                        position = (word[pos] - 'A' + shift) % 26;
                                        cesar[pos] = position + 'A';
                                    }
                                    else if (islower((unsigned char)word[pos])) {
                                        position = (word[pos] - 'a' + shift) % 26;
                                        cesar[pos] = position + 'a';
                                    }
                                }
                                cesar[strlen(word)] = '\0';
                                while (options != 1 && options != 2 &&
                                       options != 3 && options != 4 &&
                                       options != 5 && options != 6) {
                                    printf("\n\n%s [1] Progressão Aritmética (PA)\n"
                                           " [2] Progressão Geométrica (PG)\n"
                                           " [3] Números Primos\n"
                                           " [4] Série de Fibonacci\n"
                                           " [5] Incremento em Progressão\n"
                                           " [6] Voltar\n"
                                           " Escolha sua opção: %s",
                                           NSROXO, R);
                                    scanf("%d", &options);
                                    if (options < 1 || options > 6) {
                                        printf("\n\n\n\n%sOpção inválida! Tente novamente.%s\n",
                                               NSVERMELHO, R);
                                    }
                                    if (options == 6) {
                                        printf("%s\n\n\n", R);
                                        volta = 0;
                                        options = 0;
                                        menu = 0;
                                        cesar[0] = '\0';
                                        result[0] = '\0';
                                        break;
                                    }
                                    if (options == 1) {
                                        strcpy(tipo, "Progressão Aritmética");
                                        term = 1;
                                        printf("\n\n\n\n\n\n\n\n%sDigite a razão da P.A: %s",
                                               NSROXO, R);
                                        scanf("%d", &ratio);
                                        for (pos = 0; pos < strlen(word); pos++) {
                                            pa[pos] = term;
                                            term += ratio;
                                        }
                                        for (pos = 0; pos < strlen(word); pos++) {
                                            if (isupper((unsigned char)cesar[pos])) {
                                                position =
                                                    (cesar[pos] - 'A' + pa[pos]) % 26;
                                                result[pos] =
                                                    position + 'A';
                                            }
                                            else if (islower((unsigned char)cesar[pos])) {
                                                position =
                                                    (cesar[pos] - 'a' + pa[pos]) % 26;
                                                result[pos] =
                                                    position + 'a';
                                            }
                                        }
                                        result[strlen(word)] = '\0';
                                        volta = 0;
                                        running = 0;
                                    }
                                    if (options == 2) {
                                        strcpy(tipo, "Progressão Geométrica");
                                        term = 1;
                                        printf("\n\n\n\n\n\n\n\n%sDigite a razão da P.G: %s",
                                               NSROXO, R);
                                        scanf("%d", &ratio);
                                        for (pos = 0; pos < strlen(word); pos++) {
                                            pg[pos] = term;
                                            term *= ratio;
                                        }
                                        for (pos = 0; pos < strlen(word); pos++) {
                                            if (isupper((unsigned char)cesar[pos])) {
                                                position =
                                                    (cesar[pos] - 'A' + pg[pos]) % 26;
                                                result[pos] =
                                                    position + 'A';
                                            }
                                            else if (islower((unsigned char)cesar[pos])) {
                                                position =
                                                    (cesar[pos] - 'a' + pg[pos]) % 26;
                                                result[pos] =
                                                    position + 'a';
                                            }
                                        }
                                        result[strlen(word)] = '\0';
                                        volta = 0;
                                        running = 0;
                                    }
                                    if (options == 3) {
                                        strcpy(tipo, "Números Primos");
                                        prime_number = 1;
                                        while (1) {
                                            int quantidade = 0;
                                            for (pos = 0; pos < strlen(word); pos++) {
                                                quantidade++;
                                            }
                                            int contador_primos = 0;
                                            for (i = 0; i < 16; i++) {
                                                prime[i] = 0;
                                            }
                                            prime_number = 1;
                                            while (contador_primos < quantidade) {
                                                prime_number += 1;
                                                for (i = 2;
                                                     i <= prime_number;
                                                     i++) {
                                                    if (prime_number % i == 0) {
                                                        break;
                                                    }
                                                }
                                                if (prime_number == i) {
                                                    prime[contador_primos] =
                                                        prime_number;
                                                    contador_primos++;
                                                }
                                            }
                                            break;
                                        }
                                        for (pos = 0; pos < strlen(word); pos++) {
                                            if (isupper((unsigned char)cesar[pos])) {
                                                position =
                                                    (cesar[pos] - 'A' + prime[pos]) % 26;
                                                result[pos] =
                                                    position + 'A';
                                            }
                                            else if (islower((unsigned char)cesar[pos])) {
                                                position =
                                                    (cesar[pos] - 'a' + prime[pos]) % 26;
                                                result[pos] =
                                                    position + 'a';
                                            }
                                        }
                                        result[strlen(word)] = '\0';
                                        volta = 0;
                                        running = 0;
                                    }
                                    if (options == 4) {
                                        strcpy(tipo, "Fibonacci");
                                        int previous = 1;
                                        int current = 1;
                                        for (pos = 0; pos < strlen(word); pos++) {
                                            fibonacci[pos] = previous;
                                            int next = previous + current;
                                            previous = current;
                                            current = next;
                                        }
                                        for (pos = 0; pos < strlen(word); pos++) {
                                            if (isupper((unsigned char)cesar[pos])) {
                                                position =
                                                    (cesar[pos] - 'A' + fibonacci[pos]) % 26;
                                                result[pos] =
                                                    position + 'A';
                                            }
                                            else if (islower((unsigned char)cesar[pos])) {
                                                position =
                                                    (cesar[pos] - 'a' + fibonacci[pos]) % 26;
                                                result[pos] =
                                                    position + 'a';
                                            }
                                        }
                                        result[strlen(word)] = '\0';
                                        volta = 0;
                                        running = 0;
                                    }
                                    if (options == 5) {
                                        strcpy(tipo, "Incremento em Progressão");
                                        printf("\n\n\n\n\n\n\n\n%sDigite o valor do incremento: %s",
                                               NSROXO, R);
                                        scanf("%d", &increment);
                                        int incremento_atual = increment;
                                        term = 1;
                                        for (pos = 0; pos < strlen(word); pos++) {
                                            increment_list[pos] = term;
                                            term += incremento_atual;
                                            incremento_atual += 1;
                                        }
                                        for (pos = 0; pos < strlen(word); pos++) {
                                            if (isupper((unsigned char)cesar[pos])) {
                                                position =
                                                    (cesar[pos] - 'A' + increment_list[pos]) % 26;

                                                result[pos] =
                                                    position + 'A';
                                            }
                                            else if (islower((unsigned char)cesar[pos])) {
                                                position =
                                                    (cesar[pos] - 'a' + increment_list[pos]) % 26;
                                                result[pos] =
                                                    position + 'a';
                                            }
                                        }
                                        result[strlen(word)] = '\0';
                                        volta = 0;
                                        running = 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    char cryptography[16];
    strcpy(cryptography, result);
    if (cryptography[0] != '\0') {
        archive = fopen("resultado_criptografia.txt", "w");
        if (archive != NULL) {
            fprintf(archive,
                    "Palavra codificada: %s | SHIFT: %d | Tipo: %s | Letras: %lu\n",
                    cryptography,
                    shift,
                    tipo,
                    strlen(word));
            fclose(archive);
        }
        log = fopen("log_criptografia.txt", "a");
        if (log != NULL) {
            fprintf(log, "Palavra original: %s\n", word);
            fprintf(log, "SHIFT: %d\n", shift);
            fprintf(log, "Tipo: %s\n", tipo);
            fprintf(log, "Resultado: %s\n", cryptography);
            fprintf(log, "Letras: %lu\n", strlen(word));
            fprintf(log, "------------------------------\n");

            fclose(log);
        }
        printf("\n\n\n\n\n\n%sPalavra criptografada: %s | SHIFT: %d\n"
               "Obrigado por utilizar o programa, volte sempre ! %s\n",
               NSVERDE,
               cryptography,
               shift,
               R);
    }
    else {
        printf("\n\n\n\n\n\n%sNenhuma palavra foi criptografada, tente novamente ! %s\n",
               NSVERMELHO, R);
    }
    return 0;
}