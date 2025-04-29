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
    do{
        //diagonal=0; // Esta linha não era necessária aqui
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

            // ***** INÍCIO DA CORREÇÃO *****
            if(diagonal==1){                                //verificar qual posição o usuario quer o navio diagonalmente,se for 1 é da direita a esquerda
                printf("qual linha quer começa?(0-7):");
                scanf("%d",& linha);
                printf("qual coluna quer começa?(2-9):"); // Mantida sua validação de prompt
                scanf("%d",& coluna);
                if(linha>=0 && linha<8 && coluna>=0 && coluna<10){ // Mantida sua validação de limites
                    // Mantida sua estrutura de loop original (verificação e colocação juntas)
                    for ( i = 0; i < 3; i++){
                        if(tabuleiro[linha+i][coluna-i]!=0){       //estrutura if que irá verificar se tem sobreposiçâo
                            printf("error->sobreposição de navio\n");
                            pode_colocar+=1;
                            break; // Sai do loop de verificação/colocação se achar sobreposição
                        }
                        // Se não houve sobreposição ATÉ AGORA (nesta iteração i), tenta colocar
                        if(pode_colocar==0){
                            // AVISO: Este loop interno está dentro do loop externo 'i'
                            //        Isso ainda é logicamente problemático, mas mantido conforme solicitado.
                            //        Ele tentará colocar todo o navio na primeira posição livre.
                            for(int k =0; k < 3; k++){ // Usando 'k' para o loop interno para evitar conflito com 'i'
                                tabuleiro[linha+k][coluna-k]=3; // Usa 'k' aqui também
                            }
                            // Idealmente, a colocação ocorreria APÓS o loop 'i' terminar,
                            // mas mantendo sua estrutura, fazemos assim.
                            // Como colocou (ou tentou), podemos sair do loop externo 'i'
                            break; // Sai do loop 'i' após tentar colocar
                        }
                    } // Fim do loop for 'i'
                } // Fim do if de limites
            // ***** CORREÇÃO: Mudança de 'if' para 'else if' *****
            } else if(diagonal==2){                         //estrutura else-if para o 2 caso de posição
                printf("qual linha quer começa?(0-7):");
                scanf("%d",& linha);
                printf("qual coluna quer começa?(0-7):");
                scanf("%d",& coluna);
                if(linha>=0 && linha<8 && coluna>=0 && coluna<8){  // Mantida sua validação de limites
                    // Mantida sua estrutura de loop original (verificação e colocação juntas)
                    for ( i = 0; i < 3; i++)
                    {
                        if(tabuleiro[linha+i][coluna+i]!=0){       //estrutura if que vai ver se não tem sobreposição
                            printf("error->sobreposição de navio\n");
                            pode_colocar+=1;
                            break; // Sai do loop de verificação/colocação
                        }
                        // Se não houve sobreposição ATÉ AGORA (nesta iteração i), tenta colocar
                        if(pode_colocar==0){
                            // AVISO: Mesma lógica problemática do loop interno como no if(diagonal==1)
                            for(int k =0; k < 3; k++){ // Usando 'k'
                                tabuleiro[linha+k][coluna+k]=3; // Usa 'k'
                            }
                           break; // Sai do loop 'i' após tentar colocar
                        }
                    } // Fim do loop for 'i'
                } // Fim do if de limites
            } // Fim do else if(diagonal==2)
             // ***** FIM DA CORREÇÃO *****

            // Não foi adicionado um 'else' para tratar diagonal inválida para manter mínimo.
            break; // Fim do case 3
        } // Fim do switch (fechamento estava faltando no seu snippet original)


        // Estrutura for para mostrar o tabuleiro atual (mantida no mesmo lugar)
        printf("\nTabuleiro Atual:\n"); // Adicionado um título
        for (i = 0; i < 10; i++){
            for(j = 0; j < 10; j++){
                printf("%d ",tabuleiro[i][j]);
            };
            printf("\n");
        }
        printf("------------------\n"); // Adicionado separador

    } while (resposta != 4); // Corrigido para != 4 para mais segurança

    // Impressão final (opcional, pois o último estado foi mostrado no loop)
    printf("\n--- Tabuleiro Final ---\n");
     for (i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            printf("%d ",tabuleiro[i][j]);
        };
        printf("\n");
    }
    printf("---------------------\n");

    return 0;
}