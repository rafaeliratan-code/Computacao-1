// criando o código pelo gdb...
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define TAMANHO_TABULEIRO 4
#define JOGADOR_X 0
#define JOGADOR_O 1
#define COMPUTADOR 2

char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
int pontuacao[3] = {0, 0, 0};

void PreencherTabuleiro() {
	for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
		for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
			tabuleiro[i][j] = ' ';
		}
	}
}
void DesenharTabuleiro() {
	printf("\n");
	for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
		for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
			printf(" %c ", tabuleiro[i][j]);
			if (j < TAMANHO_TABULEIRO - 1) {
				printf("|");
			}
		}
		printf("\n");

		if (i < TAMANHO_TABULEIRO - 1) {
			printf("-----------------\n");
		}
	}
	printf("\n");
}

void ExibirPlacar() {
    printf("\nPLACAR ATUAL: \n");
    printf("Jogador X: %d pts | Jogador O: %d pts | Computador: %d pts\n", 
            pontuacao[JOGADOR_X], pontuacao[JOGADOR_O], pontuacao[COMPUTADOR]);
}

int main() {
	int linha, coluna;
	char simbolos[3] = {'X', 'O', 'A'};
	setlocale(LC_ALL, "PORTUGUESE");
    
    DesenharTabuleiro();
	PreencherTabuleiro();
	ExibirPlacar();
}
