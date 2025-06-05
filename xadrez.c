#include <stdio.h>


const int movimento_torre = 4;
const int movimento_bispo = 3;
const int movimento_rainha = 2;


void moverTorre(int casas, char direcao[]) {
    if (casas == 0) return;
    printf("%s\n", direcao);
    moverTorre(casas - 1, direcao);
}


void moverRainha(int casas, char direcao[]) {
    if (casas == 0) return;
    printf("%s\n", direcao);
    moverRainha(casas - 1, direcao);
}

void moverBispoRecursivo(int casas) {
    if (casas == 0) return;
    printf("Diagonal Superior Direita\n");
    moverBispoRecursivo(casas - 1);
}

void moverBispoLoops(int limiteVertical, int limiteHorizontal) {
    for (int i = 0; i < limiteVertical; i++) {
        for (int j = 0; j < limiteHorizontal; j++) {
            if (i == j) {
                printf("Diagonal [%d, %d]\n", i, j);
            }
        }
    }
}


void moverCavalo(int linhas, int colunas) {
    for (int i = linhas; i >= 2; i--) {
        for (int j = 0; j < colunas; j++) {
            if (i - 2 >= 0 && j + 1 < colunas) {
                printf("Cavalo salta para [%d, %d]\n", i - 2, j + 1);
            } else {
                continue;
            }
        }
    }
}

int main() {
    printf("Movimento da Torre:\n");
    moverTorre(movimento_torre, "Cima");
    printf("\n");

    printf("Movimento da Rainha - Direita:\n");
    moverRainha(movimento_rainha, "Direita");
    printf("\n");

    printf("Movimento do Bispo - Recursivo:\n");
    moverBispoRecursivo(movimento_bispo);
    printf("\n");

    printf("Movimento do Bispo - Loops Aninhados:\n");
    moverBispoLoops(4, 4);
    printf("\n");

    printf("Movimento do Cavalo:\n");
    moverCavalo(8, 8);
    printf("\n");

    return 0;
}
