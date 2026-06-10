// criando o código pelo gdb...
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define TAMANHO_TABULEIRO 4

char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
int pontuacao[3] = {0, 0, 0};
int pulou_rodada[3] = {0, 0, 0};

void PreencherTabuleiro() {
	for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
		for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
			tabuleiro[i][j] = ' ';
		}
	}
}
