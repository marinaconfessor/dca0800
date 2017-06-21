void cabecalho(void){
    printf("PROGRAMA MATRIX - MANIPULADOR DE MATRIZES\n");
    printf("    UNIVERSIDADE FEDERAL DO RIO GRANDE DO NORTE - UFRN\n");
    printf("    DEPARTAMENTO DE ENGENHARIA ELÉTRICA\n");
    printf("    DESENVOLVIDO POR: MATEUS ALENCAR E MARINA CONFESSOR\n");
}
float random(float inferior, float superior){
    float i;
    i = ((rand()%100)/99.0)*(superior - inferior) + inferior;
    //printf("%f\n", i);
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
    int i, j, k;
    float temp;

    for(i=0; i<tamlin; i++){
        for(j=0; j<tamcol; j++){
            temp=0;

            for(k=0; k<tamlin; k++){    //FAZ MEMBRO A MEMBRO
                temp = temp + matriza[i][k] * matrizb[k][j];
            }
            matrizc[i][j] = temp;

        }
    }

    return matrizc[100][100];
}

int imprimir(float matriz[][100], int tamlin, int tamcol){
    int i, j;

    for(i=0; i<tamlin; i++){
        printf(" %3d    |", i+1);   //ESCREVENDO QUANT DE LINHAS

            for(j=0; j<tamcol; j++){
                printf("%10.2f", matriz[i][j]);      //ESCREVENDO A MATRIZ
            }

        printf(" |");
        printf("\n");
    }
}

int salvar(float matriza[][100], float matrizb[][100], float matrizc[][100], int tamlina, int tamlinb, int tamlinc, int tamcola, int tamcolb, int tamcolc){
    char caminho[120];
    char nome[120];
    int i, j;
    int a, b, c, d, e;
    FILE *arq;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;

    //ENTRADA DO ENDEREÇO DO ARQUIVO
    printf("Digite o caminho do seu Arquivo (ex. c:/user/desktop): ");
    scanf("%s", &caminho);

    //CONFERE SE O CAMINHO POSSUI TODAS AS BARRAS NAS POSIÇÕES CERTAS
    //ASSIM "/" E NÃO ASSIM "\"
    for(i = 0; i < strlen(caminho); i++){
        if(caminho[i] == 92){
            caminho[i] = 47;
        }
    }

    //VERIFICA SE O USUÁRIO NÃO COLOCOU O NOME E A EXTENSÃO DO ARQUIVO NO CAMINHO
    //SE TIVER FEITO ISSO O CÓDIGO VARRE O FINAL E PROCURA A ÚLTIMA BARRA PARA FINALIZAR A STRING
    //E APAGAR O NOME E EXTENSÃO
    if(caminho[strlen(caminho) - 1] == 84 || caminho[strlen(caminho) - 1] == 116 ){
        if(caminho[strlen(caminho) - 2] == 88 || caminho[strlen(caminho) - 2] == 120 ){
            if(caminho[strlen(caminho) - 3] == 84 || caminho[strlen(caminho) - 3] == 116 ){
                if(caminho[strlen(caminho) - 4] == 46){
                    j = 1;
                    for(i = strlen(caminho) - 1; j != 0; i--){
                        if(caminho[i] == 47 || caminho[i] == 92){
                            caminho[i + 1] = 0;
                            j = 0;
                        }
                    }
                }
            }
        }
    }

    //VERIFICA SE O USUÁRIO COLOCOU UMA BARRA NO FINAL DO ENDEREÇO
    if(caminho[strlen(caminho) - 1] != 47){
        caminho[strlen(caminho)] = 47;
        caminho[strlen(caminho) + 1] = 0;
    }

    //PEDE PARA O USUÁRIO INSERIR O NOME DO ARQUIVO
    printf("Digite o nome do seu Arquivo: ");
    scanf("%s", &nome);

    //VERIFICA SE O USUÁRIO COLOCOU A EXTENSÃO ".txt"
    //SE SIM APAGA
    if(nome[strlen(nome) - 1] == 84 || nome[strlen(nome) - 1] == 116 ){
        if(nome[strlen(nome) - 2] == 88 || nome[strlen(nome) - 2] == 120 ){
            if(nome[strlen(nome) - 3] == 84 || nome[strlen(nome) - 3] == 116 ){
                if(nome[strlen(nome) - 4] == 46){
                    nome[strlen(nome) - 4] = 0;
                }
            }
        }
    }

    //CONCATENA A STRING NOME COM A EXTENSÃO
    strcat(nome, ".txt");
    //CONCATENA AS DUAS STRING NA STRING CAMINHO
    strcat(caminho, nome);

    //PERGUNTA QUAIS MATRIZ O USUÁRIO DESEJA SALVAR NO .TXT
    //AS VARIÁVEIS SINALIZADORAS ESTÃO MARCADAS COMO "0" INICIALMENTE
    //SE O USUÁRIO DECIDIR SALVAR A MATRIZ ELE SINALIZA COM "1"
    printf("\nDeseja salvar no seu arquivo quais matrizes? \n");
    printf("(0) Não\n(1) Sim\n");

    //CRIA O ARQUIVO NO ENDEREÇO INDICADO NA VARIÁVEL CAMINHO
    arq = fopen(caminho, "w");

    printf("Matriz A: ");
    scanf("%d", &a);
    if(a == 1){
        fprintf(arq, "Matriz (%d x %d)\n", tamlina, tamcola);
        fprintf(arq, "Matriz A\n\n");
        for(i = 0; i < tamlina; i++){
            for(j = 0; j < tamcola; j++){
                fprintf(arq, "%10.2f ", matriza[i][j]);
            }
            fprintf(arq, "\n");
        }
        fprintf(arq, "\n");
    }

    printf("Matriz B: ");
    scanf("%d", &b);
    if(b == 1){
        fprintf(arq, "Matriz (%d x %d)\n", tamlinb, tamcolb);
        fprintf(arq, "Matriz B\n\n");
        for(i = 0; i < tamlinb; i++){
            for(j = 0; j < tamcolb; j++){
                fprintf(arq, "%10.2f ", matrizb[i][j]);
            }
            fprintf(arq, "\n");
        }
        fprintf(arq, "\n");
    }

    printf("Matriz A + B: ");
    scanf("%d", &c);
    if(c == 1){
        if(tamlina == tamlinb && tamcola == tamcolb){   //SO SOMA MATRIZES DE MESMO TAMANHO
            tamlinc = tamlina;  //N IMPORTA DE QUAL MATRIZ USO AS LINS OU COLS
            tamcolc = tamcola;

            matrizc[tamlinc][tamcolc] = somaMatriz(matriza, matrizb, matrizc, tamlinc, tamcolc);

        }else{
            printf("Impossível realizar a operação com matrizes distintas.\n");
        }
        fprintf(arq, "Matriz (%d x %d)\n", tamlinc, tamcolc);
        fprintf(arq, "Matriz (A + B)\n\n");
        for(i = 0; i < tamlinc; i++){
            for(j = 0; j < tamcolc; j++){
                fprintf(arq, "%10.2f ", matrizc[i][j]);
            }
            fprintf(arq, "\n");
        }
        fprintf(arq, "\n");
    }

    printf("Matriz A - B: ");
    scanf("%d", &d);
    if(d == 1){
        if(tamlina==tamlinb && tamcola==tamcolb){   //SO SUBTRAI MATRIZES DE MESMO TAMANHO
            tamlinc = tamlina;  //N IMPORTA DE QUAL MATRIZ USO AS LINS OU COLS
            tamcolc = tamcola;

            matrizc[tamlinc][tamcolc] = subtraiMatriz(matriza, matrizb, matrizc, tamlinc, tamcolc);
        }else{
            printf("Impossível realizar a operação com matrizes distintas\n");
        }
        fprintf(arq, "Matriz (%d x %d)\n", tamlinc, tamcolc);
        fprintf(arq, "Matriz (A - B)\n\n");
        for(i = 0; i < tamlinc; i++){
            for(j = 0; j < tamcolc; j++){
                fprintf(arq, "%10.2f ", matrizc[i][j]);
            }
            fprintf(arq, "\n");
        }
        fprintf(arq, "\n");
    }

    printf("Matriz A * B: ");
    scanf("%d", &e);
    if(e == 1){
        if(tamcola==tamlinb){       //COLS DE A TEM QUE SER IGUAL A LINS DE B PRA MULTIPLICAR
            tamlinc = tamlina;
            tamcolc = tamcolb;

            matrizc[tamlinc][tamcolc] = multiMatriz(matriza, matrizb, matrizc, tamlinc, tamcolc);
        }else{
            printf("Impossível realizar a operação com matrizes distintas\n");
        }
        fprintf(arq, "Matriz (%d x %d)\n", tamlinc, tamcolc);
        fprintf(arq, "Matriz (A * B)\n\n");
        for(i = 0; i < tamlinc; i++){
            for(j = 0; j < tamcolc; j++){
                fprintf(arq, "%10.2f ", matrizc[i][j]);
            }
            fprintf(arq, "\n");
        }
        fprintf(arq, "\n");
    }

    //arq = fopen();
    printf("Matrizes salvas com sucesso.\n");
    fclose(arq);
}
