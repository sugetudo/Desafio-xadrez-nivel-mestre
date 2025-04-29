#include <stdio.h>

int main(){
    int tabuleiro[10][10],i,j;
    int linha;
    int coluna;
    int diagonal;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            tabuleiro[i][j]=0;
            printf("%d ",tabuleiro[i][j]);
        };
        printf("\n");
    };
    int a;
    printf("Você quer que o navio seja oque:\nvertical->1\nhorizontal->2\ndiagonal->3\nopção:");
    scanf("%d",& a);
    switch (a)
    {
    case 1:
        printf("qual linha quer começa?(0-7):");
        scanf("%d",& linha);
        printf("qual coluna quer começa?(0-9):");
        scanf("%d",& coluna);
        if(linha>=0 && linha<8 && coluna>=0 && coluna<10){
            printf("alocando navio..\n");
            for (i = 0; i < 3; i++)
            {
                if(tabuleiro[linha+i][coluna]==0){
                tabuleiro[linha+i][coluna]=3;
                }else{
                    printf("error->sobreposição de navio");
                }
            }
        }
        break;
    case 2:
        printf("qual linha quer começa?(0-9):");
        scanf("%d",& linha);
        printf("qual coluna quer começa?(0-7):");
        scanf("%d",& coluna);
        if(linha>=0 && linha<10 && coluna>=0 && coluna<8){
            printf("alocando navio..\n");
            for (i = 0; i < 3; i++)
            {
                if(tabuleiro[linha][coluna+i]==0){
                tabuleiro[linha][coluna+i]=3;
                }else{
                    printf("error->sobreposição de navio");
                }
            }
        }
        break;
    case 3:
        printf("como quer o navio?:\ncima pra baixo;da direita a esquerda->1\ncima pra baixo,da esquerda para direita->2\nopção:");
        scanf("%d",& diagonal);
        if(diagonal==1){
            printf("qual linha quer começa?(0-7):");
            scanf("%d",& linha);
            printf("qual coluna quer começa?(2-9):");
            scanf("%d",& coluna);
            if(linha>=0 && linha<8 && coluna>=0 && coluna<10){
                for ( i = 0; i < 3; i++)
                {
                    tabuleiro[linha+i][coluna-i]=3;
                }
            }
        }else if(diagonal==2){
            printf("qual linha quer começa?(0-7):");
            scanf("%d",& linha);
            printf("qual coluna quer começa?(0-7):");
            scanf("%d",& coluna);
            if(linha>=0 && linha<8 && coluna>=0 && coluna<8){
                for ( i = 0; i < 3; i++)
                {
                    tabuleiro[linha+i][coluna+i]=3;
                }
            }        
        }
        
        break;
    default:
        printf("cai fora porra");
        break;
    }
    for (i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++){
            printf("%d ",tabuleiro[i][j]);
        };
        printf("\n");
    } 
    return 0;
}