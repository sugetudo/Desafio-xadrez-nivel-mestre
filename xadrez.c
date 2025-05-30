# include <stdio.h>
int main (){
    int i=0,casa_bispo=5,casa_torre=5,casa_rainha=8,casa_cavalo_vertical=2,casa_cavalo_horizontal=1;///ao todo
    //torre se move cinco casas a direita
    //bispo se move na diagonal direita cinco casas
    //rainha se move oito casas a esquerda
    char* direcao_cavalo_vertical = "baixo";
    char* direcao_cavalo_horizontal = "esquerda";
    char* direcao_torre = "direita";
    char* direcao_bispo = "cima,direita";
    char* direcao_rainha = "esquerda";
    //------------------------------------apresentação e TORRE:
    printf("Iniciando movimento de xadrez\n");
    printf("Torre está se mexendo para a %s em %d casas...:\n",direcao_torre,casa_torre);
    while (casa_torre>0)
    {
        printf("%s\n",casa_torre,direcao_torre);
        casa_torre--;
    }
    //-------------------------------------Bispo:
    printf("Bispo está se mexendo para diagonal %s em %d...:\n",direcao_bispo,casa_bispo);
    do{
        printf("%s\n",casa_bispo,direcao_bispo);
        casa_bispo --;
    }while (casa_bispo>0);
    //-------------------------------------Rainha:
    printf("Rainha está se mexendo para %s em %d casas...:\n",direcao_rainha,casa_rainha);
    for(casa_rainha;casa_rainha>0;casa_rainha--){
        printf("%s\n",casa_rainha,direcao_rainha);
    ;}
    //-------------------------------------Cavalo:
    printf("Cavalo está se mexendo para %s em %d verticais e %d horizontal....:\n",direcao_cavalo_vertical,casa_cavalo_vertical,casa_cavalo_horizontal);
    for (i; i < casa_cavalo_horizontal; i++)
    {
        while (casa_cavalo_vertical>0)
        {
            printf("%s\n",direcao_cavalo_vertical);
            casa_cavalo_vertical --;
        }
        printf("%s\n",direcao_cavalo_horizontal);
    }
    printf("\nfim dos movimentos de xadrez\n");
    return 0;
}