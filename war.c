#include <stdio.h>
#include <stdlib.h>


//Definição da estrutura do território
typedef struct{
    char nome[30];
    char cor[10];
    int tropas;

}Territorio;

int main(){
    //Vetor para armazenar 5 territórios
    Territorio territorios[5];
    int i;

    print("===CADASTRO DE TERRITÓRIOS===\n");

    //Laço para entrada de dados
    for (i = 0; i < 5; i++){
        printf("Territorio %d\n", i + 1);

        //Leitura do nome
        printf("Digite o nome do territorio: ");
        scanf("%29[^\n]", territorios[i].nome);

        //Leitura da cor do exercito
        printf("Digite a cor do exercito: ");
        scanf("%9s", territorios[i].cor);

        //Leitura da quantidade de tropas
        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);

        printf("\n");

    }

    //Exibição dos dados cadastrados
    printf("\n=== TERRITORIOS CADASTRADOS ===\n\n");

    for (i = 0; i < 5; i++){
        printf("Territorio %d\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do Exercito: %s\n", territorios[i].cor);
        printf("Quantidade de Tropas: %d\n", territorios[i].tropas);
        printf("-----------------------------\n");
    }

    return 0;
}