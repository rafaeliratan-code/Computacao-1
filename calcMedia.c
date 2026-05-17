#include <stdio.h>

int main()
{
    
    int n1, n2, n3;
    float media, ponderada;
    
    printf("Digite 3 números para calcular a média aritmética:\n");
    scanf("%d %d %d", &n1, &n2, &n3);
    
    media = (n1 + n2 + n3/3);
    printf("Média aritmética igual a: %f\n", media);
    
    ponderada = (n1*2 + n2*3 + n3*1/2+3+1);
    printf("Média ponderada igual a: %f\n", ponderada);
    
    return 0;
}
