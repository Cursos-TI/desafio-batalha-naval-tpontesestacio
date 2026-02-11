#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int tabuleiro[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Navio horizontal
    int navio1[3] = {3, 3, 3};
    // Navio vertical
    int navio2[3] = {3, 3, 3};
    // Posições iniciais do navio 1
    int posH1 = 6, posV1 = 0;
    // Posições iniciais do navio 2
    int posH2 = 7, posV2 = 2;

void gerarTabuleiro(){
    // Criar o tabuleiro
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(j < 9){
                printf("[ %d ]", tabuleiro[i][j]);
            } else{
                printf("[ %d ]\n", tabuleiro[i][j]);
            };
        };
    };

    printf("\n");
}

int validarPosicaoNavio(int posicaoH, int tamanhoH, int i){
    for(int x = posicaoH; x < posicaoH + tamanhoH; x++){
        if(tabuleiro[i][x] != 0){
            printf("A posição do navio coincide com a posição de outra embarcação. \n\n");
            return 0; // Retorna falso
        }
    };
    return 1; // Retorna verdadeiro
}

void posicionarNavios(int posicaoV, int tamanhoV, int posicaoH, int tamanhoH){

    // Posicionar os navios no tabuleiro
    for(int i = posicaoV; i < posicaoV + tamanhoV; i++){

        // Testa se a posição do navio respeita os limites do tabuleiro 
        if(posicaoH + tamanhoH > 10){
            printf("O navio ultrapassa os limites do tabuleiro. \n\n");
            break;
        };

        if(validarPosicaoNavio(posicaoH, tamanhoH, i) == 0){
            break;
        }else{

            for(int j = posicaoH; j < posicaoH + tamanhoH; j++){
                tabuleiro[i][j] = 3;
            }
        };
        
    };
}

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Configurar posição dos navios
    posicionarNavios(posV1, 1, posH1, 3);
    posicionarNavios(posV2, 3, posH2, 1);
    // Gerar tabuleiro com as embarcações validadas
    gerarTabuleiro();

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
