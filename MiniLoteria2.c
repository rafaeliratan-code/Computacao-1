/******************************************************************************

Escreva um programa que sorteia 4 números diferentes entre 1 e 15.
O usuário deve adivinhar estes 4 números. Quando o usuário conseguir acertar os 4 números, o programa deverá classificar o usuário como:

ÓTIMO: se ele conseguiu em 1 a 10 tentativas;
BOM: 11 a 15 tentativas;
FRACO: 15 a 25 tentativas;
PÉSSIMO: Mais que 25 tentativas.
Uma tentativa é um conjunto de 4 números. Cada tentativa custa 6 reais.

Escreva a classificação do usuário na tela e quantos reais ele gastou.
Caso o usuário não tenha sido classificado como ÓTIMO ou BOM, pergunte ao usuário se ele quer tentar de novo em uma nova rodada.

*******************************************************************************/
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int contagem_de_acertos(int primeiro_numero, int segundo_numero, int terceiro_numero, int quarto_numero, int aposta1, int aposta2, int aposta3, int aposta4)
{

	int numero_de_acertos = 0;

	if (primeiro_numero == aposta1 || primeiro_numero == aposta2 || primeiro_numero == aposta3 || quarto_numero == aposta4)
	{
		printf("Você acertou! %d é um dos números sorteados!\n", primeiro_numero);
		numero_de_acertos++;
	}

	if (segundo_numero == aposta1 || segundo_numero == aposta2 || segundo_numero == aposta3 || segundo_numero == aposta4)
	{
		printf("Você acertou! %d é um dos números sorteados!\n", segundo_numero);
		numero_de_acertos++;
	}

	if (terceiro_numero == aposta1 || terceiro_numero == aposta2 || terceiro_numero == aposta3 || quarto_numero == aposta4)
	{
		printf("Você acertou! %d é um dos número(s) sorteados!\n", terceiro_numero);
		numero_de_acertos++;
	}

	if (quarto_numero == aposta1 || quarto_numero == aposta2 || quarto_numero == aposta3 || quarto_numero == aposta4)
	{
		printf("Você acertou! %d é um dos número(s) sorteados!\n", quarto_numero);
		numero_de_acertos++;
	}
	return numero_de_acertos;
}

void sorteia_numeros(int *pn, int *sn, int *tn, int *qn)
{

	*pn = rand()%15+1;
	*sn = rand()%15+1;

	while (*sn == *pn)
		*sn = rand()%15+1;

	*tn = rand()%15+1;
	while(*tn == *pn || *tn == *sn)
		*tn = rand()%15+1;

	*qn = rand()%15+1;
	while(*qn == *pn || *qn == *sn)
		*qn = rand()%15+1;
}


int main()
{
	int primeiro_numero, segundo_numero, terceiro_numero, quarto_numero;
	int aposta1, aposta2, aposta3, aposta4;
	int numero_de_acertos;
	int tentativas;


	setlocale(LC_ALL, "Portuguese");
	srand(time(0));

	while(1)
	{
		tentativas = 0;
		sorteia_numeros(&primeiro_numero, &segundo_numero, &terceiro_numero, &quarto_numero);

		printf("Resultado do sorteio: %d %d %d %d\n", primeiro_numero, segundo_numero, terceiro_numero, quarto_numero);

		do
		{
			tentativas++;
			printf("Digite três números entre 1 e 20 (tentativa %d): ", tentativas);
			scanf("%d %d %d %d", &aposta1, &aposta2, &aposta3, &aposta4);

			numero_de_acertos = contagem_de_acertos(primeiro_numero, segundo_numero, terceiro_numero, quarto_numero, aposta1, aposta2, aposta3, aposta4);

			printf("Você acertou %d números na sua aposta!\n", numero_de_acertos);
		}
		while (numero_de_acertos !=4);

		printf("Você conseguiu em %d tentativa(s) e gastou %d reais\n", tentativas, tentativas*6);

		if (tentativas <= 10)
		{
			printf("Você é ÓTIMO!\n");
			break;
		}
		else if (tentativas <=15)
		{
			printf("Você é BOM!\n");
			break;
		}
		else if (tentativas <=25)
		{
			printf("Você é FRACO!\n");
		}
		else
		{
			printf("Você é PÉSSIMO!\n");
		}

		while ( getchar() != '\n' );
		char c;
		printf("Deseja continuar? (S/N):");
		scanf("%c", &c);
		if (c != 'S')
		{
			break;
		}


	}
	return 0;
}
