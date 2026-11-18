#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Retorna o nome da jogada a partir do número */
const char* nome_jogada(int jogada) {
    if (jogada == 1) return "Pedra";
    if (jogada == 2) return "Papel";
    return "Tesoura";
}

/* Retorna 0 = empate, 1 = jogador vence, 2 = computador vence */
int resultado(int jogador, int computador) {
    if (jogador == computador) return 0;

    if ((jogador == 1 && computador == 3) ||  /* Pedra quebra Tesoura */
        (jogador == 2 && computador == 1) ||  /* Papel cobre Pedra */
        (jogador == 3 && computador == 2))    /* Tesoura corta Papel */
        return 1;

    return 2;
}

int main() {
    int jogador, computador, res;
    int vitorias = 0, derrotas = 0, empates = 0;
    char continuar;

    srand(time(NULL)); /* muda a sequência aleatória a cada execução */

    printf("=== PEDRA, PAPEL E TESOURA ===\n");

    do {
        printf("\n1 - Pedra\n2 - Papel\n3 - Tesoura\n");
        printf("Sua jogada: ");

        if (scanf("%d", &jogador) != 1 || jogador < 1 || jogador > 3) {
            printf("Opcao invalida! Digite 1, 2 ou 3.\n");
            while (getchar() != '\n'); /* limpa o buffer */
            continue;
        }

        computador = rand() % 3 + 1;

        printf("\nVoce: %s\n", nome_jogada(jogador));
        printf("Computador: %s\n", nome_jogada(computador));

        res = resultado(jogador, computador);

        if (res == 0) {
            printf("Empate!\n");
            empates++;
        } else if (res == 1) {
            printf("Voce venceu!\n");
            vitorias++;
        } else {
            printf("Voce perdeu!\n");
            derrotas++;
        }

        printf("\nPlacar -> Vitorias: %d | Derrotas: %d | Empates: %d\n",
               vitorias, derrotas, empates);

        printf("Jogar novamente? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    printf("\nObrigada por jogar!\n");
    return 0;
}