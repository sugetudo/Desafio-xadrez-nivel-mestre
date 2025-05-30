# include <stdio.h>
int main (){
    int casa_bispo=5,casa_torre=5,casa_rainha=8;
    //torre se move cinco casas a direita
    //bispo se move na diagonal direita cinco casas
    //rainha se move oito casas a esquerda
    char* direcao_torre = "direita";
    char* direcao_bispo = "cima,direita";
    char* direcao_rainha = "esquerda";
    printf("Iniciando movimento de xadrez\n");
    printf("Torre está se mexendo para a %s em %d casas...:\n",direcao_torre,casa_torre);
    while (casa_torre>0)
    {
        printf("%d-%s\n",casa_torre,direcao_torre);
        casa_torre--;
    }
    printf("Bispo está se mexendo para diagonal %s em %d...:\n",direcao_bispo,casa_bispo);
    do{
        printf("%d-%s\n",casa_bispo,direcao_bispo);
        casa_bispo --;
    }while (casa_bispo>0);
    printf("Rainha está se mexendo para %s em %d casas...:\n",direcao_rainha,casa_rainha);
    for(casa_rainha;casa_rainha>0;casa_rainha--){
        printf("%d-%s\n",casa_rainha,direcao_rainha);
    ;}
    printf("\nfim dos movimentos de xadrez\n");
    return 0;
}