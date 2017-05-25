#include <stdio.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>

#include "menu.h"
#include "funcoes.h"


int main (void){

    setlocale(LC_ALL, "portuguese");    //SERVE PODER USAR ACENTOS NOS PRINTF

    float matriza[100][100], matrizb[100][100], matrizc[100][100];
    int tamlina=10, tamlinb=10, tamlinc=10, tamcola=10, tamcolb=10, tamcolc=10;
    int alternativa, i, j, lin, col;

    //CRIA UM LOOP PARA NÃO MATAR O PROGRAMA AO FINAL DA EXECUÇÃO
    while(1){
        alternativa = menu();   //CHAMA FUNCAO MENU

        //system("cls"); //LIMPA A TELA

        switch(alternativa){    //ALTERNATIVA EH O VALOR ESCOLHIDO NO MENU
        case 1:     //DEFINIR TAMANHO DE A
            printf("Defina a quantidade de linhas de A: ");
            scanf("%d", &tamlina);
            printf("Defina a quantidade de colunas de A: ");
            scanf("%d", &tamcola);

            if((tamlina==0) || (tamcola==0) || (tamlina>10) || (tamcola>10)){
                    //PQ NAO POSSO DEIXAR CRIAR MATRIZ COM LIN OU COL NULA OU MAIOR Q O PRE-DEFINIDO, ENTAO VOLTO AO TAMANHO PADRAO
                printf("\nRESPOSTA DO SISTEMA: tente preencher A novamente!\n");
                tamlina=10;
                tamcola=10;

            }else{
                printf("\nRESPOSTA DO SISTEMA: matriz A definida com sucesso.\n");
            }
            break;

        case 2:     //DEFINIR TAMANHO DE B
            printf("Defina a quantidade de linhas de B: ");
            scanf("%d", &tamlinb);
            printf("Defina a quantidade de colunas de B: ");
            scanf("%d", &tamcolb);


            if((tamlinb==0) || (tamcolb==0) || (tamlinb>10) || (tamcolb>10) ){
                    //PQ NAO POSSO DEIXAR CRIAR MATRIZ COM LIN OU COL NULA OU MAIOR Q O PRE-DEFINIDO, ENTAO VOLTO AO TAMANHO PADRAO
                printf("\nRESPOSTA DO SISTEMA: tente preencher B novamente!\n");
                tamlinb=10;
                tamcolb=10;
                //alternativa=2;

            }else{
                printf("\nRESPOSTA DO SISTEMA: matriz B definida com sucesso.\n");
            }
            break;

        case 3:     //PREENCHER A COM ALEATORIOS
            for(j = 0; j < tamcola; j++){
                for(i = 0; i < tamlina; i++){
                    matriza[i][j] = random();   //CHAMA FUNCAO RANDOM
                }
            }

            printf("RESPOSTA DO SISTEMA: matriz A preenchida com sucesso.\n");
            break;

        case 4:     //PREENCHER B COM ALEATORIOS
            for(i = 0; i < tamlinb; i++){
                for(j = 0; j < tamcolb; j++){
                    matrizb[i][j] = random();   //CHAMA FUNCAO RANDOM
                }
            }

            printf("RESPOSTA DO SISTEMA: matriz B preenchida com sucesso.\n");
            break;

        case 5:      //ATRIBUIR VALORES A UMA CASA DE A
            printf("Qual a linha em A do elemento que deseja atribuir um valor: ");
            scanf("%d", &lin);
            printf("Qual a coluna em A do elemento que deseja atribuir um valor: ");
            scanf("%d", &col);

            if(lin==0 || col==0 || lin>tamlina || col>tamcola){      //N POSSO DEIXAR MEXER EM LIN OU COL Q N "EXISTE"
                printf("\nRESPOSTA DO SISTEMA: tente preencher o elemento de A novamente!\n");
                lin=1;      //N PODE SER 0 POIS N EXISTE MATRIZ COM LUGAR 0
                col=1;

            }else{
                printf("Defina o valor para o elemento [%d,%d] da matriz A: ", lin, col);
                scanf("%f", &matriza[lin-1][col-1]);

                printf("\nRESPOSTA DO SISTEMA: valor %6.2f definido com sucesso para o elemento [%d,%d] da matriz A.\n", matriza[lin-1][col-1], lin, col);
            }
            break;

        case 6:     //ATRIBUIR VALORES A UMA CASA DE B
            printf("Qual a linha em B do elemento que deseja atribuir um valor: ");
            scanf("%d", &lin);
            printf("Qual a coluna em B do elemento que deseja atribuir um valor: ");
            scanf("%d", &col);

            if(lin==0 || col==0 || lin>tamlinb || col>tamcolb){      //N POSSO DEIXAR MEXER EM LIN OU COL Q N "EXISTE"
                printf("\nRESPOSTA DO SISTEMA: tente preencher o elemento de B novamente!\n");
                lin=1;      //N PODE SER 0 POIS N EXISTE MATRIZ COM LUGAR 0
                col=1;

            }else{
                printf("Defina o valor para o elemento [%d,%d] da matriz B: ", lin, col);
                scanf("%f", &matrizb[lin-1][col-1]);

                printf("\nRESPOSTA DO SISTEMA: valor %6.2f definido com sucesso para o elemento [%d,%d] da matriz B.\n", matrizb[lin-1][col-1], lin, col);
            }
            break;

        case 7:     //SOMAR MATRIZES
            if(tamlina==tamlinb && tamcola==tamcolb){   //SO SOMA MATRIZES DE MESMO TAMANHO
                tamlinc = tamlina;  //N IMPORTA DE QUAL MATRIZ USO AS LINS OU COLS
                tamcolc = tamcola;

                matrizc[tamlinc][tamcolc] = somaMatriz(matriza, matrizb, matrizc, tamlinc, tamcolc);
                printf("RESPOSTA DO SISTEMA: matrizes somadas com sucesso.\n");

            }else{
                printf("RESPOSTA DO SISTEMA: impossível realizar a operação com matrizes distintas\n");
            }
            break;

        case 8:     //SUBTRAIR MATRIZES
            if(tamlina==tamlinb && tamcola==tamcolb){   //SO SUBTRAI MATRIZES DE MESMO TAMANHO
                tamlinc = tamlina;  //N IMPORTA DE QUAL MATRIZ USO AS LINS OU COLS
                tamcolc = tamcola;

                matrizc[tamlinc][tamcolc] = subtraiMatriz(matriza, matrizb, matrizc, tamlinc, tamcolc);
                printf("RESPOSTA DO SISTEMA: matrizes subtraidas com sucesso.\n");

            }else{
                printf("RESPOSTA DO SISTEMA: impossível realizar a operação com matrizes distintas\n");
            }
            break;

        case 9:     //MULTIPLICAR MATRIZES
            if(tamcola==tamlinb){       //COLS DE A TEM QUE SER IGUAL A LINS DE B PRA MULTIPLICAR
                tamlinc = tamlina;
                tamcolc = tamcolb;

                matrizc[tamlinc][tamcolc] = multiMatriz(matriza, matrizb, matrizc, tamlinc, tamcolc);
                printf("RESPOSTA DO SISTEMA: matrizes multiplicadas com sucesso.\n");
            }else{
                printf("RESPOSTA DO SISTEMA: quant de colunas de A diferente da qunt de linhas de B\n");
            }
            break;

        case 10:    //IMPRIMIR A
            printf("Matriz A\n");

            for(i=0; i<tamlina; i++){
                printf(" %3d    |", i+1);   //ESCREVENDO QUANT DE LINHAS

                    for(j=0; j<tamcola; j++){
                        printf("%6.2f", matriza[i][j]);      //ESCREVENDO A MATRIZ
                    }

                printf(" |");
                printf("\n");
            }
            break;

        case 11:        //IMPRIMIR B
            printf("Matriz B\n");

            for(i=0; i<tamlinb; i++){
                printf(" %3d    |", i+1);   //ESCREVENDO QUANT DE LINHAS

                    for(j = 0; j < tamcolb; j++){
                        printf("%6.2f", matrizb[i][j]);     //ESCREVENDO A MATRIZ
                    }

                printf(" |");
                printf("\n");
            }
            break;

        case 12:        //IMPRIMIR C
            printf("Matriz C\n");

            for(i=0; i<tamlina; i++){
                printf(" %3d    |", i+1);   //ESCREVENDO QUANT DE LINHAS

                for(j = 0; j < tamcolb; j++){
                    printf("%6.2f", matrizc[i][j]);     //ESCREVENDO A MATRIZ
                }

                printf(" |");
                printf("\n");
            }
            break;

        case 13:        //SALVAR EM ARQUIVO
            salvar(matriza, matrizb, matrizc, tamlina, tamlinb, tamlinc, tamcola, tamcolb, tamcolc);
            break;

        case 14:    //SAIR
            exit(0);

        default:
            menu(); //EM OUTRO CASO CHAMA A FUNCAO MENU
        }
    }
    return 0;
}
