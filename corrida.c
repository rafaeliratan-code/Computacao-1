/******************************************************************************

2024_2_Prova1.pdf
Questão 2)

*******************************************************************************/
#include <stdio.h>

int main()
{
    
    float dist;
    float min;
    float pace;
    
    printf("Qual é a distância em Km percorrido? \n");
    scanf("%f", &dist);
    
    printf("Em quantos minutos ao total percorreu? \n");
    scanf("%f", &min);
    
    pace = (min/dist);
    printf("Ritmo de %f\n", pace);
    
    return 0;
}
