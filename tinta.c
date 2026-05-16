/******************************************************************************

2024_2_Prova1Recuperacao.pdf
Questão 6)

*******************************************************************************/
#include <stdio.h>

int main()
{

    int alt;
    int larg;
    float area;
    float tinta;

    printf("Digite a altura da parede em metros: ");
        scanf("%d", &alt);
        
    printf("Digite a largura da parede em metros: ");
        scanf("%d", &larg);
        
    printf("Altura: %dm\n", alt);
    printf("Largura: %dm\n", larg);
    
    area = (alt*larg);
    printf("Área total da parede: %.2fm\n", area);
    
    tinta = (area/2);
    printf("Tinta necessária: %.2fL\n", tinta);
    

}
