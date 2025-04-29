#include <stdio.h>
int main(){
    int tabuleiro[10][10],i,j,resposta,linha,coluna,diagonal,pode_colocar;
    //----------------------------------
    for(i = 0;i < 10 ;i++){
        for (j = 0; j < 10; j++)                //serve para preencher o tabuleiro de "água"
        {
            tabuleiro[i][j]=0;
        }
    }
    //-----------------------------------
    do{                                         //estrutura do-while para repetição
        pode_colocar=0;                         //resetando o pode_colocar a cada novo loop
        printf("vertical-1\nhorizontal-2\ndiagonal-3\nsair-4\nopção:");
        scanf("%d", & resposta);

        switch (resposta){                      //estrutura de switch para escolha das opções
        case 1:                                 //opção vertical
            printf("qual linha quer começa?(0-7):");
            scanf("%d",& linha);
            printf("qual coluna quer começa?(0-9):");
            scanf("%d",& coluna);
                                                             
            if(linha>=0 && linha<8 && coluna>=0 && coluna<10){  //estrutura if para verificar se cabe por o navio verticalmente dentro do tabuleiro
                printf("alocando navio..\n");
                for (i = 0; i < 3; i++){                        //estrutura for com if verificar se não terá sobreposição de navio e se houver ele soma para verificar depois
                    if(tabuleiro[linha+i][coluna]!=0){          //estrutura if que verificara se não tem sobreposição
                    printf("error->sobreposição de navio\n");
                    pode_colocar+=1;
                    break;
                    }
                }
                if(pode_colocar==0){                            //estrutura if que se verdadeira põe o navio dentro do tabuleiro verticalmente
                    for(i = 0;i < 3; i++){
                        tabuleiro[linha+i][coluna]=3;
                    }
                }
            }

            break;
            
        case 2:                                               //horizontal
            printf("qual linha quer começa?(0-9):");
            scanf("%d",& linha);
            printf("qual coluna quer começa?(0-7):");
            scanf("%d",& coluna);

            if(linha>=0 && linha<10 && coluna>=0 && coluna<8){ //estrutura if para verificar se o navio cabe no tabuleiro
                printf("alocando navio..\n");
                for (i = 0; i < 3; i++){                       //estrutura for com if verificar se não terá sobreposição de navio e se houver ele soma para verificar depois
                    if(tabuleiro[linha][coluna+i]!=0){         //estrutura if que verificara se não tem sobreposição
                        printf("error->sobreposição de navio\n");
                        pode_colocar+=1;
                        break;
                    }
                }
                if(pode_colocar==0){                          //estrutura if que se verdadeira põe o navio dentro do tabuleiro verticalmente
                    for(i = 0;i < 3; i++){
                        tabuleiro[linha][coluna+i]=3;
                    }
                }
            }

            break;
        case 3:                                             //diagonal
            printf("como quer o navio?:\ncima pra baixo;da direita a esquerda->1\ncima pra baixo,da esquerda para direita->2\nopção:");
            scanf("%d",& diagonal);
            if(diagonal==1){                                //verificar qual posição o usuario quer o navio diagonalmente,se for 1 é da direita a esquerda
                printf("qual linha quer começa?(0-7):");
                scanf("%d",& linha);
                printf("qual coluna quer começa?(2-9):");
                scanf("%d",& coluna);
                if(linha>=0 && linha<8 && coluna>=0 && coluna<10){ //estrutura if que verifica se o navio cabe diagonalmente dentro do tabuleiro
                    for ( i = 0; i < 3; i++){
                        if(tabuleiro[linha+i][coluna-i]!=0){       //estrutura if que irá verificar se tem sobreposiçâo
                            printf("error->sobreposição de navio\n"); 
                            pode_colocar+=1;
                            break;
                        }
                        if(pode_colocar==0){                       //estrutura if que irá por o navio dentro do tabuleiro se não houver sobreposição
                            for(i =0;i < 3;i++){
                            tabuleiro[linha+i][coluna-i]=3;
                            }
                        }
                }
            }else if(diagonal==2){                                 //estrutura else-if para o 2 caso de posição
                printf("qual linha quer começa?(0-7):");
                scanf("%d",& linha);
                printf("qual coluna quer começa?(0-7):");
                scanf("%d",& coluna);
                if(linha>=0 && linha<8 && coluna>=0 && coluna<8){  //estrutura if para verificar se cabe dentro do tabuleiro
                    for ( i = 0; i < 3; i++)
                    {
                        if(tabuleiro[linha+i][coluna+i]!=0){       //estrutura if que vai ver se não tem sobreposição
                            printf("error->sobreposição de navio\n");
                            pode_colocar+=1;
                            break;
                        }
                        if(pode_colocar==0){                      //estrutura if que vai por o navio no tabuleiro se não tiver sobreposição
                            for(i =0;i < 3;i++){
                                tabuleiro[linha+i][coluna+i]=3;
                            }
                        }
                    }
                }        
            }
            
            break;
        }
        for (i = 0; i < 10; i++)                                //estrutura for para mostrar como está o tabuleiro atual
        {
            for(j = 0; j < 10; j++){
                printf("%d ",tabuleiro[i][j]);
            };
            printf("\n");
        } 
            
        }
    return 0;
    }while (resposta<4);    
}