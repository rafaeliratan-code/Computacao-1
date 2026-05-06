/*
Leia um valor inteiro n, que representa o número de casos de teste que vem a seguir. Cada caso de teste consiste de 3
valores reais. Faça um programa que leia os 3 valores de cada caso de teste e apresente a média ponderada para cada
caso, sendo que o primeiro valor tem peso 2, o segundo valor tem peso 3 e o terceiro valor tem peso 5. No exemplo a
seguir temos n=4, ou seja, 4 casos de teste, cada um deles com 3 variáveis fornecidas como entrada e a média ponderada
apresentada como saída:
Exemplo de Entrada Exemplo da Saída correspondente
1.0 2.0 3.0   2.3
6.5 4.3 6.2   5.7
5.1 4.2 8.1   6.3
8.0 9.0 10.0  9.3
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");

	float a, b, c, media;
	const int n = 4;
	const int peso1 = 2;
	const int peso2 = 3;
	const int peso3 = 5;
	int i;

	for (i=1; i<=n; i++)
	{
		printf("\nEscreva três valores: ");
		scanf ("%f %f %f", &a, &b, &c);
		printf("Valores digitados: %.1f %.1f %.1f \n", a, b, c);

		media = (a * peso1 + b * peso2 + c * peso3) / (peso1 + peso2 + peso3);
		printf("média ponderada: %.1f", media);
	}
}
