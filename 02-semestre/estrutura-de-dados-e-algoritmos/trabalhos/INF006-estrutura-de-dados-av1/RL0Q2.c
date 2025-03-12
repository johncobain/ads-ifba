//Dupla: Gabriel Nascimento Miranda Dos Santos (20241160019), Andrey Gomes Da Silva Nascimento (20241160024);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct points{
    int ordem_entrada;
    float distancia_origem;
    float x;
    float y;
} points;

typedef struct nomes{
    char nome[100];
} nomes;

void bubbleStr(nomes str[], int n){
    for(int i = 0; i < n; i++){    
        for(int j = 0; j < n-1-i; j++){
            nomes aux;
            if(strcmp(str[j].nome, str[j+1].nome) > 0){
                aux = str[j];
                str[j] = str[j+1];
                str[j+1] = aux;
            }
        }
    }
}

void bubbleInt(int inteiros[], int n){
    for(int i = 0; i < n; i++){    
        for(int j = 0; j < n-1-i; j++){
            int aux;
            if(inteiros[j] > inteiros[j+1]){
                aux = inteiros[j];
                inteiros[j] = inteiros[j+1];
                inteiros[j+1] = aux;
            }
        }
    }
}

void bubbleReal(float reais[], int n){
    for(int i = 0; i < n; i++){    
        for(int j = 0; j < n-1-i; j++){
            float aux;
            if(reais[j] > reais[j+1]){
                aux = reais[j];
                reais[j] = reais[j+1];
                reais[j+1] = aux;
            }
        }
    }
}

void bubblePoints(points p[], int n){
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
    FILE *fp_in = fopen("L0Q2.in", "r");
    FILE *fp_out = fopen("L0Q2.out", "w");
    char line[1000];
    if (fp_in == NULL || fp_out == NULL){
        printf("Arquivos não podem ser abertos.");
        return EXIT_FAILURE;
    }

    char space[] = " ";
    int lineCount = 0;

    while (fgets(line, sizeof(line), fp_in) != NULL) {
        points p[200];
        nomes str[200];
        int inteiros[200];
        float reais[200];
        char text[1000];
        
        int countP = 0;
        int countStr = 0;
        int countInt = 0;
        int countReal = 0;

        char *slice = strtok(line, space); // Quebra inicial por espaços

        // Ignorar a palavra "points"
        if (strcmp(slice, "points") == 0) {
            slice = strtok(NULL, space); // Avançar para o próximo token
        }

        // Processar todos os pontos na linha
        while (slice != NULL) {
            int eh_float = 0;
            // Verifica se o token começa com '(', se sim é ponto
            if (slice[0] == '(') {
                // Usar sscanf para extrair x e y diretamente
                float x, y;
                if (sscanf(slice, "(%f,%f)", &x, &y) == 2) {
                    p[countP].x = x;
                    p[countP].y = y;
                    p[countP].ordem_entrada = countP;
                    // Calcular a distância Euclidiana até a origem
                    p[countP].distancia_origem = sqrt(x * x + y * y);
                    countP++;
                }
            }else if(slice[0] >= 'a' && slice[0] <= 'z' || slice[0] >= 'A' && slice[0] <= 'Z'){
                for(int i = 0; i < strlen(slice); i++){
                    if(slice[i] == '\n') slice[i] = '\0';
                }
                strcpy(str[countStr].nome, slice);
                countStr++;
            }else{
                for(int i = 0; i < strlen(slice); i++){
                    if(slice[i] == '.') eh_float = 1;
                }
                if(eh_float == 1){
                    reais[countReal] = atof(slice);
                    countReal++;
                }else{
                    inteiros[countInt] = atoi(slice);
                    countInt++;
                }
            }
            slice = strtok(NULL, space); // Avança para o próximo token
        }
        
        //ordena
        bubbleStr(str, countStr);
        bubbleInt(inteiros, countInt);
        bubbleReal(reais, countReal);
        bubblePoints(p, countP);
        // Escrever os pontos da linha no arquivo de saída
        if(lineCount==0)sprintf(text, "str:" );
        else sprintf(text, "\nstr:");
        for(int i = 0; i<countStr; i++){
            if(i==0)sprintf(text, "%s%s", text, str[i].nome);
            else sprintf(text, "%s %s", text, str[i].nome);
        }

        sprintf(text, "%s %s", text, "int:");
        for(int i = 0; i<countInt; i++){
            if(i==0)sprintf(text, "%s%d", text, inteiros[i]);
            else sprintf(text, "%s %d", text, inteiros[i]);
        }

        sprintf(text, "%s %s", text, "float:");
        for(int i = 0; i<countReal; i++){
            if(i==0)sprintf(text, "%s%.5g", text, reais[i]);
            else sprintf(text, "%s %.5g", text, reais[i]);
        }

        sprintf(text, "%s %s", text, "p:");
        for(int i = 0; i<countP; i++){
            if(i==0)sprintf(text, "%s(%.5g,%.5g)", text, p[i].x, p[i].y);
            else sprintf(text, "%s (%.5g,%.5g)", text, p[i].x, p[i].y);
        }

        fputs(text, fp_out);
        lineCount++;
    }// fim da linha
    fclose(fp_in);
    fclose(fp_out);
    return EXIT_SUCCESS;
}
    

