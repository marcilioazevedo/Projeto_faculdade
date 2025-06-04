
#include <stdio.h>
#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5  


void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; 
        }
    }

    tabuleiro[2][2] = 3;
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[3][2] = 3;
    tabuleiro[3][3] = 3;
}

void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) printf("~ ");       
            else if (tabuleiro[i][j] == 3) printf("N ");   
            else if (tabuleiro[i][j] == 5) printf("* ");   
        }
        printf("\n");
    }
}

void criarCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            habilidade[i][j] = 0;
        }
    }

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = TAM_HABILIDADE / 2 - i; j <= TAM_HABILIDADE / 2 + i; j++) {
            if (j >= 0 && j < TAM_HABILIDADE)
                habilidade[i][j] = 1;
        }
    }
}


void criarCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

void criarOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            habilidade[i][j] = 0;
        }
    }

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = abs(TAM_HABILIDADE / 2 - i); j < TAM_HABILIDADE - abs(TAM_HABILIDADE / 2 - i); j++) {
            habilidade[i][j] = 1;
        }
    }
}

void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                       int habilidade[TAM_HABILIDADE][TAM_HABILIDADE],
                       int origem_linha, int origem_coluna) {
    int offset = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linha_tab = origem_linha - offset + i;
            int col_tab = origem_coluna - offset + j;

            if (linha_tab >= 0 && linha_tab < TAM_TABULEIRO &&
                col_tab >= 0 && col_tab < TAM_TABULEIRO &&
                habilidade[i][j] == 1) {
                if (tabuleiro[linha_tab][col_tab] != 3) 
                    tabuleiro[linha_tab][col_tab] = 5;
            }
        }
    }
}


int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int habilidade[TAM_HABILIDADE][TAM_HABILIDADE];

    inicializarTabuleiro(tabuleiro);

    printf("=== Habilidade: CONE ===\n");
    criarCone(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 4, 4);
    exibirTabuleiro(tabuleiro);

    printf("\n=== Habilidade: CRUZ ===\n");
    inicializarTabuleiro(tabuleiro);
    criarCruz(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 5, 5);
    exibirTabuleiro(tabuleiro);

    printf("\n=== Habilidade: OCTAEDRO ===\n");
    inicializarTabuleiro(tabuleiro);
    criarOctaedro(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 5, 5);
    exibirTabuleiro(tabuleiro);

    return 0;
}
