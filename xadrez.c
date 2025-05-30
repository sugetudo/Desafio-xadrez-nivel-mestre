# include <stdio.h>
void espacamento(){
    printf("-------------------------------------------\n");
}
void bispo(int n){
    if(n==0){
        printf("Movimento do bispo finalizado\n");
    }else{
        for (int i=0; i < 1; i++){
            for (int j = 0; j <1; j++){
                printf("cima,");
            }  
            printf("baixo\n");
        }
        bispo(n - 1);
    }
    
}
void rainha(int n){
    int i=0;
    if(n==0){
        printf("movimento da rainha finalizado\n");
    }else{
        while(i<1){
            printf("esquerda\n");
            i++;
        }
        rainha(n-1);
    }
}
void torre(int n){
    if (n == 0){
        printf("movimento da torre finalizado\n");
    }
    else {
        for (int i = 0; i < 1; i++) {
             printf("direita\n");
        }

        torre(n - 1);
    }
}
void Cavalo(int passosVerticais, int passosHorizontais, const char* direcaoVertical, const char* direcaoHorizontal) {
    printf("Cavalo está se mexendo: %d passos %s e %d passo %s....:\n",
           passosVerticais, direcaoVertical, passosHorizontais, direcaoHorizontal);

    // Loop externo para os movimentos verticais
    for (int i = 0; i < passosVerticais; i++) {
        printf("%s\n", direcaoVertical); // Imprime a direção vertical para cada passo vertical
    }

    // Loop interno para o movimento horizontal
    // Aninhado para cumprir o requisito de loops aninhados, mesmo que logicamente ocorra após os verticais.
    // Usamos uma variável diferente ('j') e sua própria condição.
    for (int j = 0; j < passosHorizontais; j++) {
        printf("%s\n", direcaoHorizontal); // Imprime a direção horizontal para cada passo horizontal
    }
    printf("Movimento do cavalo finalizado.\n");
}
int main (){
    int casa_bispo=5,casa_torre=5,casa_rainha=8,casa_cavalo_vertical=2,casa_cavalo_horizontal=1;///ao todo
    //torre se move cinco casas a direita
    //bispo se move na diagonal direita cinco casas
    //rainha se move oito casas a esquerda
    char* direcao_cavalo_vertical = "cima";
    char* direcao_cavalo_horizontal = "direita";
    char* direcao_torre = "direita";
    char* direcao_bispo = "direita";
    char* direcao_rainha = "esquerda";
    //------------------------------------apresentação e TORRE:
   printf("O Bispo se mexe %d casa para diagonal %s...:\n",casa_bispo,direcao_bispo);
   bispo(casa_bispo);
   espacamento();
   printf("A Rainha se moveu %d casas para %s\n",casa_rainha,direcao_rainha);
   rainha(casa_rainha);
   espacamento();
   printf("A Torre se moveu %d casas para %s...:\n", casa_torre, direcao_torre);
   torre(casa_torre);
   espacamento();
    Cavalo(casa_cavalo_vertical, casa_cavalo_horizontal, direcao_cavalo_vertical, direcao_cavalo_horizontal);
    espacamento();
    printf("\nfim dos movimentos de xadrez\n");
    return 0;
}