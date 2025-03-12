//Dupla: Gabriel Nascimento Miranda Dos Santos (20241160019), Andrey Gomes Da Silva Nascimento (20241160024);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct points{
    int ordem_entrada;
    float distancia_origem;
    int x;
    int y;
} points;

void bubble(points p[], int n){
    for(int i = 0; i < n; i++){    
        for(int j = 0; j < n-1-i; j++){
            points aux;
            if(p[j].distancia_origem > p[j+1].distancia_origem){
                aux = p[j];
                p[j] = p[j+1];
                p[j+1] = aux;
            }
        }
    }
}

int main() {
    FILE *fp_in = fopen("L0Q1.in", "r");
    FILE *fp_out = fopen("L0Q1.out", "w");
    char line[1000];
    if (fp_in == NULL || fp_out == NULL){
        printf("Arquivos não podem ser abertos.");
        return EXIT_FAILURE;
    }

    char space[] = " ";
    int lineCount = 0;

    while (fgets(line, sizeof(line), fp_in) != NULL) {
        points p[200];
        char text[1000];
        int count = 0;
        float distanciaTotal = 0;
        float distanciaShortcut = 0;

        char *slice = strtok(line, space); // Quebra inicial por espaços

        // Ignorar a palavra "points"
        if (strcmp(slice, "points") == 0) {
            slice = strtok(NULL, space); // Avançar para o próximo token
        }

        // Processar todos os pontos na linha
        while (slice != NULL) {
            // Verifica se o token começa com '('
            if (slice[0] == '(') {
                // Usar sscanf para extrair x e y diretamente
                int x, y;
                if (sscanf(slice, "(%d,%d)", &x, &y) == 2) {
                    p[count].x = x;
                    p[count].y = y;
                    p[count].ordem_entrada = count;
                    // Calcular a distância Euclidiana até a origem
                    p[count].distancia_origem = sqrt((float)(x * x + y * y));
                    count++;
                }
            }
            slice = strtok(NULL, space); // Avança para o próximo token
        }
        
        for(int i = 0; i < count-1; i++){
            distanciaTotal += sqrt((float)(pow(p[i+1].x-p[i].x,2)+pow(p[i+1].y-p[i].y,2)));
        }
        distanciaShortcut = sqrt((float)(pow(p[count-1].x-p[0].x,2)+pow(p[count-1].y-p[0].y,2)));
        //ordena
        bubble(p, count);
        // Escrever os pontos da linha no arquivo de saída
        if(lineCount==0)sprintf(text, "points");
        else sprintf(text, "\npoints");
 
        for(int i = 0; i<count; i++){
            sprintf(text, "%s (%d,%d)", text, p[i].x, p[i].y);
        }
        sprintf(text, "%s distance %.2f", text, distanciaTotal);
        sprintf(text, "%s shortcut %.2f", text, distanciaShortcut);
        fputs(text, fp_out);
        lineCount++;
    }// fim da linha
    fclose(fp_in);
    fclose(fp_out);
    return EXIT_SUCCESS;
}
    

