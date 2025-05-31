#include <stdio.h>
//------------------------------------------
/*espaçador usado para melhor leitura no terminal
*/
void space(){
    printf("-----------------------------\n");
}
//-------------------------------------------
/*função recursiva do bispo:
 - possue if para verificar se terminou
 - explicação:
    - recebe a quantidade de casa que irá se mover na diagonal junto a suas direções
    - possue loops aninhados:
        - loops externo é para movimento vertical e o interno para horizontal
    - ao final do loop aninhado ele automaticamente se chama novamente e refaz até dar 0 e mostrar movimento finalizado
*/
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
//-----------------------------
/*função recursiva da rainha onde printa o seu movimento e em seguida se autochama novamente.
 - possue if para verificar se terminou
*/
void rainha(int n,char* direcao){
    if(n==0){
        printf("movimento finalizado\n");
    }else{
        printf("%s\n",direcao);
        rainha(n-1,direcao);
    }
}
//---------------------------
/*função recursiva da torre onde printa o seu movimento e em seguida se autochama novamente.
 - possue if para verificar se terminou
*/
void torre(int n,char* direcao){
    if(n==0){
        printf("movimento finalizado\n");
    }else{
        printf("%s\n",direcao);
        torre(n-1,direcao);
    }
}
//---------------------------
int main(){
    //definindo numero de casas para cada peça assim como suas direções(OBSERVAÇÃO:o a é pra ser usado no loop do cavalo como variavel contadora)
    int torre_casas=5,bispo_casa=5,rainha_casa=8,cavalo_vertical=2,cavalo_horizontal=1,a=0;
    char* direcao_cavalo_vertical="cima";
    char* direcao_cavalo_horizontal="direita";
    char* direcao_torre="direita";
    char* direcao_bispo_horizontal="direita";
    char* direcao_bispo_vertical="cima";
    char* direcao_rainha="esquerda";
    space();

    //apresentações de movimento das peças e chamando as respectivas funções de cada um:
    printf("Bispo se move para %s e %s em %d casas:\n",direcao_bispo_vertical,direcao_bispo_horizontal,bispo_casa);
    bispo(bispo_casa,direcao_bispo_vertical,direcao_bispo_horizontal);
    space();
    printf("Rainha se moveu para %s em %d casas:\n",direcao_rainha,rainha_casa);
    rainha(rainha_casa,direcao_rainha);
    space();
    printf("Torre se moveu para %s em %d casas:\n",direcao_torre,torre_casas);
    torre(torre_casas,direcao_torre);
    space();

    //loop do cavalo:
    /*explicação:
    - começa com loop externo for que é voltado para controle de fluxo e também printar o movimento horizontal do cavalo
    - ao começar, o i==0,logo entra no primeiro if e mostra que o cavalo irá se mover e dá continue(Resetando o loop e fazendo que o i agora seja 1),ignorando todo o resto do código
    - com i=1 por conta do continue,ele ignora os ifs e executa o while que é o loop interno voltado para movimento vertical e executa o printf do loop externo
    - com i==2 ele foca no segundo if que mostra que o movimento do cavalo foi finalizado e automaticamente da break,ignorando todo o resto do codigo e saindo do loop
    - resultado:
        - cima
        - cima
        - direita
    */
    for(int i=0;i<=cavalo_horizontal+1;i++){

        if(i==0){   
            printf("Cavalo está se movendo:\n");
            continue;
        }else if(i==2){
            printf("fim do movimento do cavalo\n");
            break;
        }

        while (a<cavalo_vertical){
            printf("%s\n",direcao_cavalo_vertical);
            a++;
        }
        printf("%s\n",direcao_bispo_horizontal);
    }
    return 0;
}