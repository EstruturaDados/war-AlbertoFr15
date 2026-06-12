#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura do território
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// Função para cadastrar territórios
void cadastrarTerritorios(Territorio *territorios, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("\n=== Territorio %d ===\n", i + 1);

        printf("Nome: ");
        scanf(" %29[^\n]", territorios[i].nome);

        printf("Cor do exercito: ");
        scanf("%9s", territorios[i].cor);

        printf("Quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);
    }
}

// Função para exibir territórios
void exibirTerritorios(Territorio *territorios, int quantidade) {
    printf("\n===== TERRITORIOS =====\n");

    for (int i = 0; i < quantidade; i++) {
        printf("\n[%d]\n", i);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
    }
}

// Função de ataque
void atacar(Territorio *atacante, Territorio *defensor) {

    if (atacante->tropas < 2) {
        printf("\nO atacante nao possui tropas suficientes!\n");
        return;
    }

    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    printf("\n=== BATALHA ===\n");
    printf("%s rolou: %d\n", atacante->nome, dadoAtacante);
    printf("%s rolou: %d\n", defensor->nome, dadoDefensor);

    if (dadoAtacante > dadoDefensor) {

        printf("\n%s venceu o ataque!\n", atacante->nome);

        strcpy(defensor->cor, atacante->cor);

        defensor->tropas = atacante->tropas / 2;
        atacante->tropas -= defensor->tropas;

    } else {

        printf("\n%s defendeu com sucesso!\n", defensor->nome);

        atacante->tropas--;

        if (atacante->tropas < 1)
            atacante->tropas = 1;
    }
}

// Liberação de memória
void liberarMemoria(Territorio *territorios) {
    free(territorios);
}

int main() {

    srand(time(NULL));

    int quantidade;

    printf("Quantos territorios deseja cadastrar? ");
    scanf("%d", &quantidade);

    // Alocação dinâmica
    Territorio *territorios =
        (Territorio *) calloc(quantidade, sizeof(Territorio));

    if (territorios == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    cadastrarTerritorios(territorios, quantidade);

    exibirTerritorios(territorios, quantidade);

    int atacante, defensor;

    printf("\n===== ATAQUE =====\n");

    printf("Escolha o indice do territorio atacante: ");
    scanf("%d", &atacante);

    printf("Escolha o indice do territorio defensor: ");
    scanf("%d", &defensor);

    if (atacante >= 0 && atacante < quantidade &&
        defensor >= 0 && defensor < quantidade &&
        atacante != defensor) {

        atacar(&territorios[atacante],
               &territorios[defensor]);

        printf("\n===== RESULTADO APOS O ATAQUE =====\n");
        exibirTerritorios(territorios, quantidade);

    } else {
        printf("\nIndices invalidos!\n");
    }

    liberarMemoria(territorios);

    return 0;
}