int random(void){
    float i;
    srand((unsigned)time(0));
    i = rand()%100;
    return i;
}

float somaMatriz(float matriza[][100], float matrizb[][100], float matrizc[][100], int tamlin, int tamcol){
    int i, j;

    for(i=0; i<tamlin; i++){
        for(j=0; j<tamcol; j++){
            matrizc[i][j] = matriza[i][j] + matrizb[i][j];
        }
    }

    return matrizc[100][100];
}

float subtraiMatriz(float matriza[][100], float matrizb[][100], float matrizc[][100], int tamlin, int tamcol){
    int i, j;

    for(i=0; i<tamlin; i++){
        for(j=0; j<tamcol; j++){
            matrizc[i][j] = matriza[i][j] - matrizb[i][j];
        }
    }

    return matrizc[100][100];
}

float multiMatriz(float matriza[][100], float matrizb[][100], float matrizc[][100], int tamlin, int tamcol){
    int i, j;

    for(i=0; i<tamlin; i++){
        for(j=0; j<tamcol; j++){
            matrizc[i][j] = matriza[i][j] * matrizb[i][j] + matriza[i][j+1] * matrizb[i+1][j];
        }
    }

    return matrizc[100][100];
}

int salvar(float matriza[][100], float matrizb[][100], float matrizc[][100], int tamlina, int tamlinb, int tamlinc,
            int tamcola, int tamcolb, int tamcolc){
    char caminho[80];
    int i, j;
    FILE *arq;

    printf("Digite o caminho do arquivo: \n");
    scanf("%s", &caminho);

    arq = fopen(caminho, "w");

    fprintf(arq, "Matriz A\n");
    for(i=0; i<tamlina; i++){
        for(j=0; j<tamcola; j++){
            fprintf(arq, "%6.2f ", matriza[i][j]);
        }
        fprintf(arq, "\n");
    }

    fprintf(arq, "\nMatriz B\n");
    for(i=0; i<tamlinb; i++){
        for(j=0; j<tamcolb; j++){
            fprintf(arq, "%6.2f ", matrizb[i][j]);
        }
        fprintf(arq, "\n");
    }

    fprintf(arq, "\nMatriz C\n");
    for(i=0; i<tamlinc; i++){
        for(j=0; j<tamcolc; j++){
            fprintf(arq, "%6.2f ", matrizc[i][j]);
        }
        fprintf(arq, "\n");
    }

    printf("RESPOSTA DO SISTEMA: matrizes salvas com sucesso em %s \n", caminho);
    fclose(arq);
}

