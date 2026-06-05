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
int pulou_rodada[3] = {0, 0, 0};

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
        printf("[Erro] Não foi possivel salvar o histórico no arquivo.\n");
        return;
    }

    fprintf(arquivo, "Pontuacao final: X=%d | O=%d | Computador=%d\n", 
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
    
    printf("\n Partida gravada com sucesso em 'historico.txt'!\n");
}

// preenche o tabuleiro com espaços vazios
void inicializarTabuleiro() {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

// desenha o tabuleiro na tela de forma organizada
void desenharTabuleiro() {
    printf("\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%c", tabuleiro[i][j]);
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

// verfica se tem espaço sobrando
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
    
    // regra estranha 1: Se jogar ao lado de um símbolo igual ao seu, ganha +2 pontos
    if ((linha > 0 && tabuleiro[linha - 1][coluna] == simbolo) ||
        (linha < TAMANHO_TABULEIRO - 1 && tabuleiro[linha + 1][coluna] == simbolo) ||
        (coluna > 0 && tabuleiro[linha][coluna - 1] == simbolo) ||
        (coluna < TAMANHO_TABULEIRO - 1 && tabuleiro[linha][coluna + 1] == simbolo)) 
    {
        pontuacao[ID_jogador] += 2;
        printf("Regra estranha 1 aplicada. Bonus de +2 pontos\n");
    }

    // regra estrahna 2: Se jogar um símbolo e ficar cercado horizontalmente, perde a vez
    if (coluna > 0 && coluna < TAMANHO_TABULEIRO - 1) {
        char esquerda = tabuleiro[linha][coluna - 1];
        char direita = tabuleiro[linha][coluna + 1];

        if (esquerda != ' ' && direita != ' ' &&
            esquerda != simbolo && direita != simbolo) 
        {
            pulou_rodada[ID_jogador] = 1;
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

    printf("Tabuleiro estranho 4x4  \n");


    while (TabuleiroCheio() == 0) {

        for (int i = 0; i < 3; i++) {
            // Varredura de segurança caso o tabuleiro lote no meio da rodada
            if (TabuleiroCheio()) {
                break;
            }

            // Tratamento de penalidade (perda de vez)
            if (pulou_rodada[i]) {
                printf("\n[!] O participante '%c' esta penalizado e passou a vez.\n", simbolos[i]);
                pulou_rodada[i] = 0; // Penalidade paga, reseta o estado
                continue;
            }

            desenharTabuleiro();

            // Turno do Computador
            if (i == COMPUTADOR) {
                printf("Turno do Computador... Pensando...\n");
                do {
                    linha = rand() % TAMANHO_TABULEIRO;
                    coluna = rand() % TAMANHO_TABULEIRO;
                } while (tabuleiro[linha][coluna] != ' ');

                printf("O Computador escolheu a posicao: L%d, C%d\n", linha, coluna);

            // Turno dos Jogadores Humanos
            } else {
                printf("Sua vez, Jogador '%c'!\n", simbolos[i]);
                do {
                    printf("Escolha a Linha (0-3): ");
                    scanf("%d", &linha);

                    printf("Escolha a Coluna (0-3): ");
                    scanf("%d", &coluna);

                    if (linha < 0 || linha > 3 || coluna < 0 || coluna > 3) {
                        printf("[Aviso] Coordenadas invalidas! Use numeros de 0 a 3.\n");
                    } else if (tabuleiro[linha][coluna] != ' ') {
                        printf("[Aviso] Essa posicao ja esta ocupada! Escolha outra.\n");
                    }

                } while (linha < 0 || linha > 3 || 
                         coluna < 0 || coluna > 3 || 
                         tabuleiro[linha][coluna] != ' ');
            }

            // Efetivação da jogada
            tabuleiro[linha][coluna] = simbolos[i];
            pontuacao[i]++; // Cada peça posicionada vale 1 ponto base

            // Disparo dos gatilhos de regras extras
            processarRegrasEstranhas(linha, coluna, simbolos[i], i);
            exibirPlacar();
        }
    }

    // Fim de jogo e encerramento
    desenharTabuleiro();
    printf("FIM DE JOGO! TABULEIRO CHEIO\n");
    printf("\nResultado Final:\n");
    printf("Jogador X  : %d pontos\n", pontuacao[JOGADOR_X]);
    printf("Jogador O  : %d pontos\n", pontuacao[JOGADOR_O]);
    printf("Computador : %d pontos\n", pontuacao[COMPUTADOR]);

    if (pontuacao[JOGADOR_X] > pontuacao[JOGADOR_O] && pontuacao[JOGADOR_X] > pontuacao[COMPUTADOR])
        printf(" Parabens! O Jogador X venceu o confronto!\n");
    else if (pontuacao[JOGADOR_O] > pontuacao[JOGADOR_X] && pontuacao[JOGADOR_O] > pontuacao[COMPUTADOR])
        printf(" Parabens! O Jogador O venceu o confronto!\n");
    else if (pontuacao[COMPUTADOR] > pontuacao[JOGADOR_X] && pontuacao[COMPUTADOR] > pontuacao[JOGADOR_O])
        printf(" O Computador venceu a partida desta vez!\n");
    else
        printf(" Temos um empate técnico na rodada!\n");
        

    salvarHistorico();

    return 0;
}
