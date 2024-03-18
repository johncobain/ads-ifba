/*QUESTÃO II (5.0)
Chronos possui um relógio muito antigo e valioso. Contudo, embora seus ponteiros ainda
funcionem perfeitamente, seus marcadores e números se tornaram ilegíveis. Para a sorte de
Chronos, o relógio foi construído com um mostrador que indica o valor dos ângulos medidos entre
os ponteiros de hora e minutos e a posição de repouso, equivalente a 00:00. Assim, quando for
00:00 o marcador indica de ângulos indica 000 e 000. Às 06:00, o marcador de ângulos, indicará:
180 e 000. Às 06:30, contudo o valor do marcador de ângulos será: 195 e 180. Você deve escrever
um programa, que leia os valores do marcador de ângulos e calcule a hora indicada pelo relógio. */
#include <stdio.h>

int main(){
    int aHora, aMinuto, hora, minuto;
    scanf("%d %d", &aHora, &aMinuto);
    hora = aHora/30;
    minuto = aMinuto/6;
    printf("%02d:%02d",hora,minuto);
    return 0;
}