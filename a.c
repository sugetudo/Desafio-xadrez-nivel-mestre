#include <stdio.h>
int main(){
    int tabuleiro[10][10];
//--------------------------------------
    printf("tabuleiro inicialmente:\n");
    printf("--------------------------------------\n");
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            tabuleiro[i][j]=0;
        };
    };
//--------------------------------------
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            printf("%d",tabuleiro[i][j]);
        };
        printf("\n");
    };
    printf("--------------------------------------\n");
    printf("\n");
//--------------------------------------
    int navio=3;
    int linha,coluna;
    printf("--------------------------------------\n");
    printf("inserindo o primeiro barco que será horizontalmente\ndiga qual coluna você quer que ele comece:");
    scanf("%d",&coluna);
    printf("diga qual linha você quer que ele comece:");
    scanf("%d",&linha);
//--------------------------------------
/*if para o barco horizontal onde ja limita que o usuario escolha as ultimas 2 linhas assim não dando error
*/
    if(coluna>=0 && coluna<10 && linha>=0 && linha<8){
        printf("alocando ele...feito\n");
        printf("--------------------------------------\n");
        for(int i=0;i<3;i++){
            if(tabuleiro[coluna][linha+i]==0){
                tabuleiro[coluna][linha+i]=navio;
            }else{
                printf("sobreposição de navio\n");
            };
        };
    }
//--------------------------------------
    printf("--------------------------------------\n");
    printf("inserindo o segundo barco que será verticalmente\ndiga qual coluna você quer que ele esteja:");
    scanf("%d",&coluna);
    printf("diga qual linha você quer que ele esteja:");
    scanf("%d",&linha);
/*if para o barco vertical onde ja limita que o usuario escolha as ultimas 2 colunas assim não dando error
*/
    if(coluna>=0 && coluna<8 && linha>=0 && linha<10){
        printf("alocando ele...feito\n");
        printf("--------------------------------------\n");
        for(int i=0;i<3;i++){
            if(tabuleiro[coluna+i][linha]==0){
                tabuleiro[coluna+i][linha]=navio;
            }else{
                printf("sobreposição de navio\n");
            };
        };
    }
    printf("Exibindo tabuleiro:\n");
    printf("--------------------------------------\n");
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            printf("%d",tabuleiro[i][j]);
        };
        printf("\n");
    };
    printf("--------------------------------------");
    printf("\n");
    return 0;
}