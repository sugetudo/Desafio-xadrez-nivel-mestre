#include <stdio.h>

void space(){
    printf("-----------------------------");
}
void bispo(int n,char* vertical,char* horizontal){
    if(n==0){
        printf("Movimento Finalizado");
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

int main(){
    int torre_casas=5,bispo_casa=5,rainha_casa=8;
    char* direcao_torre="direita";
    char* direcao_bispo_horizontal="direita";
    char* direcao_bispo_vertical="cima";
    char* direcao_rainha="esquerda";
    space();
    printf("Bispo se move para %s e %s em %d casas:\n",direcao_bispo_vertical,direcao_bispo_horizontal,bispo_casa);
    bispo(bispo_casa,direcao_bispo_vertical,direcao_bispo_horizontal);
    return 0;
}