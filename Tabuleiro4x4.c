#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define TAMANHO_TABULEIRO 4

#define JOGADOR_X  0
#define JOGADOR_O  1
#define COMPUTADOR 2

char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
int pontuacao[3] = {0, 0, 0};
int pulou_X = 0;
int pulou_O = 0;
int pulou_Computador = 0;
int linhaPremiada;
int colunaPremiada;

// mostra o placar do jogo
void exibirPlacar() {
    printf("\nPLACAR ATUAL: \n");
    printf("Jogador X: %d pts | Jogador O: %d pts | Computador: %d pts\n", 
            pontuacao[JOGADOR_X], pontuacao[JOGADOR_O], pontuacao[COMPUTADOR]);
}

// sistema de salvar historico em arquivo txt
void salvarHistorico() {
    FILE *arquivo = fopen("historico.txt", "a");

    if (arquivo == NULL) {
        printf("Erro! Não foi possivel salvar o histórico no arquivo.\n");
        return;
    }

    fprintf(arquivo, "Pontuação final: X=%d | O=%d | Computador=%d\n", 
            pontuacao[JOGADOR_X], pontuacao[JOGADOR_O], pontuacao[COMPUTADOR]);

    if (pontuacao[JOGADOR_X] > pontuacao[JOGADOR_O] && pontuacao[JOGADOR_X] > pontuacao[COMPUTADOR])
        fprintf(arquivo, "Resultado: Vitória do Jogador X\n");
    else if (pontuacao[JOGADOR_O] > pontuacao[JOGADOR_X] && pontuacao[JOGADOR_O] > pontuacao[COMPUTADOR])
        fprintf(arquivo, "Resultado: Vitória do Jogador O\n");
    else if (pontuacao[COMPUTADOR] > pontuacao[JOGADOR_X] && pontuacao[COMPUTADOR] > pontuacao[JOGADOR_O])
        fprintf(arquivo, "Resultado: Vitória do Computador\n");
    else
        fprintf(arquivo, "Resultado: Partida terminou em empate\n");

    fclose(arquivo);
    
    printf("\n Partida gravada em 'historico.txt'\n");
}

void inicializarTabuleiro() {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}


void desenharTabuleiro() {
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


int TabuleiroCheio() {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

void processarRegrasEstranhas(int linha, int coluna, char simbolo, int ID_jogador) {
    
    // regra estranha 1: Casa secreta premiada (+5 pontos)
    if (linha == linhaPremiada && coluna == colunaPremiada) 
    {
        pontuacao[ID_jogador] += 5;
        printf("\n[BÔNUS SURPRESA] Incrível! Você jogou na Casa Secreta Premiada e ganhou +5 pontos!\n");
    }

    // regra estrahna 2: Se jogar um símbolo e ficar cercado horizontalmente, perde a vez
    if (coluna > 0 && coluna < TAMANHO_TABULEIRO - 1) {
        char esquerda = tabuleiro[linha][coluna - 1];
        char direita = tabuleiro[linha][coluna + 1];

        if (esquerda != ' ' && direita != ' ' && esquerda != simbolo && direita != simbolo) 
        {
            if (simbolo == 'X') {
                pulou_X = 1;
            } else if (simbolo == 'O') {
                pulou_O = 1;
            } else if (simbolo == 'A') {
                pulou_Computador = 1;
            }
            printf("Você foi cercado por símbolos diferentes e perdera a próxima rodada.\n");
        }
    }
}

int main() {
    int linha, coluna;
    char simbolos[3] = {'X', 'O', 'A'};
    setlocale(LC_ALL, "PORTUGUESE");
    srand(time(NULL));
    
    inicializarTabuleiro();
    linhaPremiada = rand() % TAMANHO_TABULEIRO;
    colunaPremiada = rand() % TAMANHO_TABULEIRO;
    printf("Tabuleiro estranho 4x4  \n");
    printf("COORDENADA SECRETA PREMIADA: Linha %d, Coluna %d\n", linhaPremiada, colunaPremiada);

    while (TabuleiroCheio() == 0) {

        for (int vez = 0; vez < 3; vez++) {
            if (TabuleiroCheio()) {
                break;
            }
            if (simbolos[vez] == 'X' && pulou_X) {
                printf("\nO participante 'X' está penalizado e passou a vez.\n");
                pulou_X = 0;
                continue;
            } 
            else if (simbolos[vez] == 'O' && pulou_O) {
                printf("\nO participante 'O' está penalizado e passou a vez.\n");
                pulou_O = 0;
                continue;
            } 
            else if (simbolos[vez] == 'A' && pulou_Computador) {
                printf("\nO Computador ('A') está penalizado e passou a vez.\n");
                pulou_Computador = 0;
                continue;
            }

            desenharTabuleiro();

            // turno do computador
            if (vez == COMPUTADOR) {
                printf("Vez do Computador! Aguarde\n");
                do {
                    linha = rand() % TAMANHO_TABULEIRO;
                    coluna = rand() % TAMANHO_TABULEIRO;
                } while (tabuleiro[linha][coluna] != ' ');

                printf("O Computador escolheu a posição: Linha %d, Coluna %d\n", linha, coluna);

            // turno dos jogadores humanos
            } else {
                printf("Sua vez, Jogador '%c'!\n", simbolos[vez]);
                do {
                    printf("Escolha a Linha (0-3): ");
                    scanf("%d", &linha);

                    printf("Escolha a Coluna (0-3): ");
                    scanf("%d", &coluna);

                    if (linha < 0 || linha > 3 || coluna < 0 || coluna > 3) {
                        printf("Aviso!!! Coordenadas inválidas! Digite números de 0 a 3\n");
                    } else if (tabuleiro[linha][coluna] != ' ') {
                        printf("Aviso!!! Essa posição já está ocupada!\n");
                    }

                } while (linha < 0 || linha > 3 || coluna < 0 || coluna > 3 || tabuleiro[linha][coluna] != ' ');
            }

            tabuleiro[linha][coluna] = simbolos[vez];
            pontuacao[vez]++;

            processarRegrasEstranhas(linha, coluna, simbolos[vez], vez);
            exibirPlacar();
        }
    }

    // fim do jogo
    desenharTabuleiro();
    printf("FIM DE JOGO! TABULEIRO CHEIO\n");
    printf("\nResultado Final:\n");
    printf("Jogador X: %d pontos\n", pontuacao[JOGADOR_X]);
    printf("Jogador O: %d pontos\n", pontuacao[JOGADOR_O]);
    printf("Computador: %d pontos\n", pontuacao[COMPUTADOR]);

    if (pontuacao[JOGADOR_X] > pontuacao[JOGADOR_O] && pontuacao[JOGADOR_X] > pontuacao[COMPUTADOR])
        printf("Parabéns! O Jogador X venceu a partida!\n");
    else if (pontuacao[JOGADOR_O] > pontuacao[JOGADOR_X] && pontuacao[JOGADOR_O] > pontuacao[COMPUTADOR])
        printf("Parabéns! O Jogador O venceu a partida!\n");
    else if (pontuacao[COMPUTADOR] > pontuacao[JOGADOR_X] && pontuacao[COMPUTADOR] > pontuacao[JOGADOR_O])
        printf("O Computador venceu a partida!\n");
    else
        printf("Temos um empate técnico na rodada!\n");
        

    salvarHistorico();

    return 0;
}
