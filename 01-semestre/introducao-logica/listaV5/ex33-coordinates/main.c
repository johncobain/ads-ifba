/*33. Escreva um algoritmo que leia 2 valores (x e y), que devem representar as coordenadas
de um ponto em um plano. A seguir, determine qual o quadrante ao qual pertence o
ponto, ou se está sobre um dos eixos cartesianos ou na origem (x=y=0).*/

#include <stdio.h>

int main(){
    int x, y;
    scanf("%d %d", &x, &y);

    if((x==0&&y!=0)){
        printf("O ponto esta sobre o eixo y.");
    }else if(y==0&&x!=0){
        printf("O ponto esta sobre o eixo x.");
    }else if(x==0&&y==0){
        printf("O ponto esta na origem do plano (0,0).");
    }else if(x>0&&y>0){
        printf("O ponto esta no 1o. quadrante."); 
    }else if(x<0&&y>0){
        printf("O ponto esta no 2o. quadrante."); 
    }else if(x<0&&y<0){
        printf("O ponto esta no 3o. quadrante."); 
    }else if(x>0&&y<0){
        printf("O ponto esta no 4o. quadrante."); 
    }
    return 0 ;
}