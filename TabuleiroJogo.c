#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define TAM 4

char tabuleiro[TAM][TAM];
int pontos[3] = {0, 0, 0};
int perdeVez[3] = {0, 0, 0};

// sistema de "guardar" o histórico
void gravarHistorico() {
	FILE *arquivo = fopen("historico.txt", "a");

	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo de historico!\n");
		return;
	}

	fprintf(arquivo, "Pontuacao: X=%d | O=%d | A=%d\n", pontos[0], pontos[1], pontos[2]);

	if(pontos[0] > pontos[1] && pontos[0] > pontos[2])
		fprintf(arquivo, "Ganhador: Jogador X\n");
	else if(pontos[1] > pontos[0] && pontos[1] > pontos[2])
		fprintf(arquivo, "Ganhador: Jogador O\n");
	else if(pontos[2] > pontos[0] && pontos[2] > pontos[1])
		fprintf(arquivo, "Ganhador: Computador\n");
	else
		fprintf(arquivo, "Resultado: Empate\n");


	fclose(arquivo);
	printf("\nResultado: 'historico.txt'!\n");
}

void inicializarTabuleiro() {
	int i, j;

	for(i = 0; i < TAM; i++) {
		for(j = 0; j < TAM; j++) {
			tabuleiro[i][j] = ' ';
		}
	}
}

void mostrarTabuleiro() {
	int i, j;

	printf("\n");

	for(i = 0; i < TAM; i++) {
		for(j = 0; j < TAM; j++) {
			printf(" %c ", tabuleiro[i][j]);

			if(j < TAM - 1)
				printf("|");
		}

		printf("\n");

		if(i < TAM - 1)
			printf("-----------------\n");
	}

	printf("\n");
}

int tabuleiroCheio() {
	int i, j;

	for(i = 0; i < TAM; i++) {
		for(j = 0; j < TAM; j++) {
			if(tabuleiro[i][j] == ' ')
				return 0;
		}
	}

	return 1;
}

void verificarRegras(int linha, int coluna, char simbolo, int jogador) {

	// regra estranha 1
	if((linha > 0 && tabuleiro[linha-1][coluna] == simbolo) ||
	        (linha < TAM-1 && tabuleiro[linha+1][coluna] == simbolo) ||
	        (coluna > 0 && tabuleiro[linha][coluna-1] == simbolo) ||
	        (coluna < TAM-1 && tabuleiro[linha][coluna+1] == simbolo))
	{
		pontos[jogador] += 2;
		printf("Bonus! +2 pontos\n");
	}

	// regra estranha 2
	if(coluna > 0 && coluna < TAM-1) {

		char esq = tabuleiro[linha][coluna-1];
		char dir = tabuleiro[linha][coluna+1];

		if(esq != ' ' && dir != ' ' &&
		        esq != simbolo && dir != simbolo)
		{
			perdeVez[jogador] = 1;
			printf("Voce ficou entre dois simbolos diferentes!\n");
			printf("Perdera a proxima rodada.\n");
		}
	}
}

int main() {
	
	int linha, coluna;
	int i;
	char simbolos[3] = {'X', 'O', 'A'};

	srand(time(NULL));

	inicializarTabuleiro();

	while(!tabuleiroCheio()) {

		for(i = 0; i < 3; i++) {

			if(tabuleiroCheio())
				break;

			if(perdeVez[i]) {
				printf("\nJogador %c perdeu a vez!\n", simbolos[i]);
				perdeVez[i] = 0;
				continue;
			}

			mostrarTabuleiro();

			if(i == 2) {

				do {
					linha = rand() % TAM;
					coluna = rand() % TAM;
				} while(tabuleiro[linha][coluna] != ' ');

				printf("Computador jogou em (%d,%d)\n",
				       linha, coluna);

			} else {

				printf("Jogador %c\n", simbolos[i]);

				do {
					printf("Linha (0-3): ");
					scanf("%d", &linha);

					printf("Coluna (0-3): ");
					scanf("%d", &coluna);

				} while(linha < 0 || linha > 3 ||
				        coluna < 0 || coluna > 3 ||
				        tabuleiro[linha][coluna] != ' ');
			}

			tabuleiro[linha][coluna] = simbolos[i];
			pontos[i]++;

			verificarRegras(linha, coluna, simbolos[i], i);
		}
	}

	mostrarTabuleiro();

	// pontuações dos jogadores
	printf("\nPontuacao Final:\n");
	printf("X = %d pontos\n", pontos[0]);
	printf("O = %d pontos\n", pontos[1]);
	printf("A = %d pontos\n", pontos[2]);

	if(pontos[0] > pontos[1] && pontos[0] > pontos[2])
		printf("Jogador X venceu!\n");
	else if(pontos[1] > pontos[0] && pontos[1] > pontos[2])
		printf("Jogador O venceu!\n");
	else if(pontos[2] > pontos[0] && pontos[2] > pontos[1])
		printf("Computador venceu!\n");
	else
		printf("Empate!\n");

	gravarHistorico();

	return 0;
}
