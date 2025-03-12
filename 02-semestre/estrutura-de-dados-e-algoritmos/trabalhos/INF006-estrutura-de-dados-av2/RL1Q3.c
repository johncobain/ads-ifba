//Dupla: Gabriel Nascimento Miranda Dos Santos (20241160019), Andrey Gomes Da Silva Nascimento (20241160024);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LI
{
    float num;
    struct LI *prox;
    int ancorado;
}LI;

typedef struct LE
{
    int num;
    int qtdElementos;
    float elementosValores[100];
    struct LI elementos[100];
    struct LE *anterior;
    struct LE *prox;
}LE;


void OrdenarLE(LE arr[], int qtdL) {
    int i, j, temp;
    for (i = 0; i < qtdL - 1; i++) {
        for (j = 0; j < qtdL - i - 1 && arr[j].prox != NULL; j++) {
            if (arr[j].num > arr[j + 1].num) {
                temp = arr[j].num;
                arr[j].num = arr[j + 1].num;
                arr[j + 1].num = temp;
            }
        }
    }
}

void OrdenarLI(LI arr[], int qtdL) {
    int i, j;
    float tempF = 0;
    for (i = 0; i < qtdL - 1; i++) {
        for (j = 0; j < qtdL - i - 1 && arr[j].prox != NULL; j++) {
            if (arr[j].num > arr[j + 1].num) {
                tempF = arr[j].num;
                arr[j].num = arr[j + 1].num;
                arr[j + 1].num = tempF;
            }
        }
    }
}

int main(){
    FILE *fp_in = fopen("L1Q3.in", "r");
    FILE *fp_out = fopen("L1Q3.out", "w");
    char line[1000];
    char space[] = " ";
    int qtdLinhas = 0;
    if (fp_in == NULL || fp_out == NULL){
        printf("Arquivos nao podem ser abertos.");
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), fp_in) != NULL){
        qtdLinhas++;
        int qtdLE = 0, qtdLI = 0;
        LE *Ancora = malloc(sizeof(LE) * 1000);
        Ancora[0].anterior = NULL;

        LI *Elementos = malloc(sizeof(LI) * 1000);

        char *slice = strtok(line, space);

        //Adquirir todos os elementos da ancora após LE e antes de LI
        if(strcmp(slice, "LE") == 0){
            slice = strtok(NULL, space);
            for(int i = 0;slice != NULL && strcmp(slice, "LI") != 0; i++){
                if(i > 0){
                    Ancora[i-1].prox = &Ancora[i];
                    Ancora[i].anterior = &Ancora[i-1];
                } 
                Ancora[i].prox = NULL;
                Ancora[i].num = atoi(slice);
                qtdLE++;
                slice = strtok(NULL, space);
            }
        }

        OrdenarLE(Ancora, qtdLE);

        if(strcmp(slice, "LI") == 0){
            slice = strtok(NULL, space);
            for(int i = 0;slice != NULL; i++){
                if(i > 0){
                    Elementos[i - 1].prox = & Elementos[i];
                } 
                Elementos[i].num = atof(slice);
                Elementos[i].ancorado = 0;
                qtdLI++;
                slice = strtok(NULL, space);
            }
        }

        OrdenarLI(Elementos, qtdLI);

        //Adicionar os Elementos as suas ancoras
        for(int i = 0; i < qtdLE; i++){
            for(int j = 0; j < qtdLI; j++){
                float diff = (Ancora[i].num - Elementos[j].num);
                if(diff < 0) diff *= -1;
                if(diff <= 0.99){
                    if(Elementos[j].ancorado == 0){
                        Elementos[j].ancorado = 1;
                        Ancora[i].elementosValores[Ancora[i].qtdElementos] = Elementos[j].num;
                        Ancora[i].qtdElementos++;
                    }
                }
            }
        }

        //Organização das linhas

        if(qtdLinhas > 1) fprintf(fp_out, "\n");
        fprintf(fp_out, "[");

        for(int i = 0; i < qtdLE; i++){
            fprintf(fp_out, "%d(",Ancora[i].num);
            for(int j = 0; j < Ancora[i].qtdElementos; j++){
                fprintf(fp_out, "%g",Ancora[i].elementosValores[j]);
                if(j < Ancora[i].qtdElementos - 1) fprintf(fp_out, "->");
            }
            fprintf(fp_out, ")");
            if(i < qtdLE - 1) fprintf(fp_out, "->");
        }
        fprintf(fp_out, "]");

        // free(Ancora);
        // free(Elementos);
    }

    fclose(fp_in);
    fclose(fp_out);
    return 0;
}
