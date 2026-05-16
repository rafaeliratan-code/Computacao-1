/******************************************************************************

2024_2_Prova1.pdf
Questão 4)

*******************************************************************************/
#include <stdio.h>

int main()
{
	int num, i;

	printf("Digite um número para ver a tabuada:\n");
	scanf("%d", &num);

	for (i = 1; i <=10; i++){
		printf("%d x %d = %d\n", num, i, num*i);
	}
	return 0;
}
