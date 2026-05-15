/******************************************************************************

2024_2_Prova1.pdf
Questão 1)

*******************************************************************************/
#include <stdio.h>

int main()
{

	int base;
	int alt;
	float per;
	float area;

	printf("Digite a dimensão da base em metros: \n");
	scanf("%d", &base );
	printf("Base: %d\n", base);

	printf("Digite a altura em metros: \n");
	scanf("%d", &alt);
	printf("Altura: %d\n", alt);

	per = (2*base + 2*alt);
	printf("Quantidade necessária de rodapé %f\n", per);
	
	area = (base*alt);
	printf("Área do quarto: %f\n ", area);

	return 0;
}
