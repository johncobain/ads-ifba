#include <stdio.h>

int main(){
    float dist, vMax, vMaxM, a, vel, newDist;
    int time = 0;
    printf("Qual e a distancia entre os semaforos?(m) ");
    scanf("%f", &dist);
    printf("Qual e a velocidade maxima da rodovia?(Km/h) ");
    scanf("%f", &vMax);
    printf("Qual e a aceleracao do carro?(m/s) ");
    scanf("%f", &a);
    vMaxM = vMax/3.6;//km/h -> m/s
    newDist = dist-(vMaxM*3); //descontar 3 segundos
    vel = 0; //velocidade inicial
    while (vel<vMaxM){
        vel+=a;
        newDist -= vel;
        time++;
    }
    while(newDist>0){
        newDist-=vel;
        time++;
    }

    printf("A %.2fKm/h (%.2fm/s) com uma aceleracao de %.2fm/s, numa distancia de %.0f metros, o semaforo abrira em %d segundos, 3 segundos antes de voce passar por ele.", vMax, vMaxM, a, dist, time);
    

    return 0;
}