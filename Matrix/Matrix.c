#include <stdio.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include "funcoes.h"
#include "menu.h"


int main (void){
setlocale(LC_ALL, "portuguese");
int alternativa;
float matriza[100][100];
float matrizb[100][100];
int tamlina, tamlinb;
int tamcola, tamcolb; //QUANTIDADE DE COLUNAS
int a, b, i, j, k; //SINALIZADORES EXTRAS
int l, c; //SINALIZADOR PARA USUÁRIO ATRIBUIR VALORES A ELEMENTOS

//SINALIZAM QUE O TAMANHO DAS MATRIZES FORAM ATRUBUÍDOS.
j = 0;
k = 0;

tamcola = 10;
tamcolb = 10;
tamlina = 10;
tamlinb = 10;

//CRIA UM LOOP PARA NÃO MATAR O PROGRAMA AO FINAL DA EXECUÇÃO
while(1){
    //FUNÇÃO QUE CHAMA O MENU PRINCIPAL DO PROGRAMA
    //SALVA NA VARIÁVEL ALTERNATIVA O VALOR ESCOLHIDO PELO USUÁRIO
    alternativa = menu();
    switch(alternativa){
    case 1:
        printf("\nDefina a quantidade de linhas da matriz A: ");
        scanf("%d", &tamlina);
        printf("Defina a quantidade de colunas da matriz A: ");
        scanf("%d", &tamcola);
        j = 1; //SINALIZA QUE O TAMANHO DA MATRIZ A FOI ATRUBUÍDO.
        printf("\nRESPOSTA DO SISTEMA: Sua matriz A foi definida com sucesso.\n");
        break;

    case 2:
        printf("\nDefina a quantidade de linhas da matriz B: ");
        scanf("%d", &tamlinb);
        printf("Defina a quantidade de colunas da matriz B: ");
        scanf("%d", &tamcolb);
        k = 1; //SINALIZA QUE O TAMANHO DA MATRIZ B FOI ATRUBUÍDO.
        printf("\nRESPOSTA DO SISTEMA: Sua matriz B foi definida com sucesso.\n");
        break;

    case 3:
        for(j = 0; j < tamcola; j++){
            for(i = 0; i < tamlina; i++){
                matriza[i][j] = random();
            }
        }
        printf("\nRESPOSTA DO SISTEMA: Sua matriz foi preenchida com valores aleatórios com sucesso.\n");
        break;

    case 4:
        for(j = 0; j < tamcolb; j++){
            for(i = 0; i < tamlinb; i++){
                matrizb[i][j] = random();
            }
        }
        printf("\nRESPOSTA DO SISTEMA: Sua matriz foi preenchida com valores aleatórios com sucesso.\n");
        break;


    case 5:
        printf("\nQual a linha do elemento que deseja atribuir um valor: ");
        scanf("%d", &l);
        printf("Qual a coluna do elemento que deseja atribuir um valor: ");
        scanf("%d", &c);
        printf("Defina o valor para o elemento [%d, %d] da matriz A: ", l, c);
        scanf("%f", &matriza[l-1][c-1]);

        printf("\nRESPOSTA DO SISTEMA: O valor %6.2f foi definido com sucesso para o elemento [%d, %d] da matriz A.\n", matriza[l-1][c-1], l, c);
        break;

    case 6:
        printf("\nQual a linha do elemento que deseja atribuir um valor: ");
        scanf("%d", &l);
        printf("Qual a coluna do elemento que deseja atribuir um valor: ");
        scanf("%d", &c);
        printf("Defina o valor para o elemento [%d, %d] da matriz B: ", l, c);
        scanf("%f", &matrizb[l-1][c-1]);

        printf("\nRESPOSTA DO SISTEMA: O valor %6.2f foi definido com sucesso para o elemento [%d, %d] da matriz B.\n", matrizb[l-1][c-1], l, c);
        break;

    case 10:
        printf("\n");
        for(i = 0; i < tamlina; i++){
                printf(" %3d |", i+1);
                for(j = 0; j < tamcola; j++){
                    printf("%6.2f", matriza[i][j]);
                }
                printf(" |");
                printf("\n");
        }
        printf("\n");
        break;

    case 11:
        printf("\n");
        for(i = 0; i < tamlinb; i++){
                printf(" %3d |", i+1);
                for(j = 0; j < tamcolb; j++){
                    printf("%6.2f", matrizb[i][j]);
                }
                printf(" |");
                printf("\n");
        }
        printf("\n");
        break;

    case 13:
        salvar(tamlina, tamlinb, tamcola, tamcolb, matriza, matrizb);
        break;
    case 14:
        exit(0);

    default:
        menu();

    }
    printf("\n"); //QUEBRA DE LINHA FINAL
}
return 0;
}
