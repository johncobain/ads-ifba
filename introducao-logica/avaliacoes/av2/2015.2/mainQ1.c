/*Questão I - Valor 2.0
Chico tem 1,50 metro e cresce 2 centímetros por ano, enquanto Zé tem 1,10 metro e
cresce 3 centímetros por ano. Construa um programa em C que calcule e imprima
quantos anos serão necessários para que Zé seja maior que Chico.*/
#include <stdio.h>

int main(){
    int qntAnos = 0, chicoH = 150, zeH = 110;
    while (zeH<=chicoH){
        chicoH+=2;
        zeH+=3;
        qntAnos++;
    }
    printf("Ze sera maior que Chico em %d anos.\nZe: %dcm\nChico: %dcm",qntAnos,zeH,chicoH);

    return 0;
}