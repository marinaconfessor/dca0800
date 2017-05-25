int menu(void){
    int alternativa;
    printf("MATRIX\nPROGRAMA DE MANIPULAÇÃO DE MATRIZES\n");
    printf("(1) Definir o tamanho da matriz A\n");
    printf("(2) Definir o tamanho da matriz B\n");
    printf("(3) Preencher a matriz A com valores aleatórios\n");
    printf("(4) Preencher a matriz B com valores aleatórios\n");
    printf("(5) Atribuir valor para um elemento da matriz A\n");
    printf("(6) Atribuir valor para um elemento da matriz B\n");
    printf("(7) Calcular A+B\n");
    printf("(8) Calcular A-B\n");
    printf("(9) Calcular A*B\n");
    printf("(10) Imprimir matriz A\n");
    printf("(11) Imprimir matriz B\n");
    printf("(12) Imprimir matriz C\n");
    printf("(13) Salvar a matriz em um Arquivo\n");
    printf("(14) Sair\n");
    printf("\nDigite sua Operação: ");
    scanf("%d", &alternativa);
    return alternativa;
}
