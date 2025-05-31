#include <stdio.h>

void space(){
    printf("-----------------------------\n");
}
void bispo(int n,char* vertical,char* horizontal){
    if(n==0){
        printf("Movimento Finalizado\n");
    }else{
            for(int i=0;i<1;i++){
                printf("%s, ",vertical);
                for(int j=0;j<1;j++){
                    printf("%s\n",horizontal);
                }
            }
        bispo(n-1,vertical,horizontal);
    }
}
void rainha(int n,char* direcao){
    if(n==0){
        printf("movimento finalizado\n");
    }else{
        printf("%s\n",direcao);
        rainha(n-1,direcao);
    }
}
void torre(int n,char* direcao){
    if(n==0){
        printf("movimento finalizado\n");
    }else{
        printf("%s\n",direcao);
        rainha(n-1,direcao);
    }
}
int main(){
    int torre_casas=5,bispo_casa=5,rainha_casa=8;
    char* direcao_torre="direita";
    char* direcao_bispo_horizontal="direita";
    char* direcao_bispo_vertical="cima";
    char* direcao_rainha="esquerda";
    space();
    printf("Bispo se move para %s e %s em %d casas:\n",direcao_bispo_vertical,direcao_bispo_horizontal,bispo_casa);
    bispo(bispo_casa,direcao_bispo_vertical,direcao_bispo_horizontal);
    space();
    printf("Rainha se moveu para %s em %d casas:\n",direcao_rainha,rainha_casa);
    rainha(rainha_casa,direcao_rainha);
    space();
    printf("Torre se moveu para %s em %d casas:\n",direcao_torre,torre_casas);
    torre(torre_casas,direcao_torre);


    return 0;
}