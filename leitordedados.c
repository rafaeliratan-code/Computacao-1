#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

int main(){

setlocale(LC_ALL, "Portuguese");

    char nome[50];
    printf("Qual o seu nome?\n");
    scanf("%s", &nome);
    printf("\nOlá, %s", nome);

    char primeira_letra;
    scanf("%c", &primeira_letra);
    printf("\nA primeira letra do seu nome é: %c\n", primeira_letra);

    char genero_masculino = 'M';
    char genero_feminino = 'F';
    printf("Qual é o seu gênero? (M/F)?\n");
    scanf("%c", &genero_masculino, &genero_feminino);

    if (genero_masculino == 'M' || genero_masculino == 'm')
    {
        printf("Seu gênero é: Masculino\n");
    }
    else if (genero_feminino == 'F' || genero_feminino == 'f')
    {
        printf("Seu gênero é: Feminino\n");
    }
    else 
    {
        printf("Opção inválida!\n");
    }

    printf("=== RESUMO DOS DADOS OBTIDOS ===\n");
    printf("Nome: %s\n", nome);
    printf("Primeira letra: %c", primeira_letra);
    printf("Gênero: %c\n", genero_masculino, genero_feminino);
}
