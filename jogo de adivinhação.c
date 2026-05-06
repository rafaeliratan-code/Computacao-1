#include<stdio.h>
#include<locale.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	srand(time(0));


	int numero_secreto = (rand()%10)+1;
	int chute=numero_secreto+1;

	while(chute != numero_secreto)
	{
		//        printf("O número secreto é %d \n", numero_secreto);
		printf("Digite o número secreto: ");
		scanf("%d", &chute);

		if (chute>numero_secreto)
			printf("O número que você chutou é maior que o número secreto!\n");
		else if (chute<numero_secreto)
			printf("O número que você chutou é menor que o número secreto!\n");
	}

	const int tentativa = tentativa+1;

	if(1<=tentativa<=3)
		printf("Você acertou! Ótimo", tentativa);

	else if(4<=tentativa<=6)
		printf("Você acertou! Bom", tentativa);

	else if(7<=tentativa<=10)
		printf("Você acertou! Fraco", tentativa);

	else if(tentativa>=10)
		printf("Você acertou! Péssimo", tentativa);

	return 0;
}
