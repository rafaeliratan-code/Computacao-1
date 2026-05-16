/******************************************************************************

2024_2_Prova1.pdf
Questão 3)
INCOMPLETO

*******************************************************************************/
#include <stdio.h>

int main()
{
	// força do personagem entre 1 a 100
	int fper;

	// nível da arma entre 1 a 50
	int narm;

	// multiplicador crítico entre 1.0 e 2.0
	float mcr;

	// dano total
	float dano;

	printf("Digite a força do personagem entre 1 a 100: \n");
	scanf("%d", &fper);

	printf("Digite o nível da arma: \n");
	scanf("%d", &narm);

	printf("Digite o multiplicador crítico: \n");
	scanf("%f", &mcr);

	printf("Força do personagem: %d \n", fper);
	printf("Nível da arma: %d \n", narm);
	printf("Multiplicador crítico: %.2f \n", mcr);

	dano = (fper*narm*mcr);
	printf("Dano total: %.2f \n", dano);

	if (dano >= 5000) {
		printf("DANO CRÍTICO MASSIVO!\n");
	} else if (dano <= 5000 || dano >= 1000) {
		printf("DANO CRÍTICO\n");
	} else {
		printf("Dano normal!\n");
	}

	return 0;
}
