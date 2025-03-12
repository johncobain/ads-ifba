//Dupla: Gabriel Nascimento Miranda Dos Santos (20241160019), Andrey Gomes Da Silva Nascimento (20241160024);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list{
    int values[512];
    int size;
    int sum;
} List;

void bubble(int values[], int size);
void bubbleList(List list[], int size);


int main(){
    FILE *fp_in = fopen("L1Q1.in", "r");
    FILE *fp_out = fopen("L1Q1.out", "w");
    char line[1000];
    if (fp_in == NULL || fp_out == NULL){
        printf("Arquivos nao podem ser abertos.");
        return EXIT_FAILURE;
    }

    char space[] = " ";
    int lineCount = 0;

    while (fgets(line, sizeof(line), fp_in) != NULL){
        List lists[512];
        int count = -1;
        char text[1000];

        char *slice = strtok(line, space); // Quebra inicial por espaços


        // Processar todas as listas na linha
        while (slice != NULL){
            // Ignorar a palavra "start"
            if(strcmp(slice, "start") == 0){
                count++;
                lists[count].size = 0;
                lists[count].sum = 0;
            }else{
                lists[count].values[lists[count].size] = atoi(slice);
                lists[count].size++;
                lists[count].sum += atoi(slice);
            }
            slice = strtok(NULL, space);
        }

        // ordenar cada lista internamente
        for(int i = 0; i<=count; i++){
            bubble(lists[i].values, lists[i].size);
        }

        // ordenar as listas por soma total
        bubbleList(lists, count+1);
        // escrever as listas no arquivo
        // se duas listas tiverem a mesma soma, considerar apenas a ultima
        if(lineCount!=0)sprintf(text, "\n");
        else sprintf(text, "");
        for(int i = 0; i<=count; i++){
            if(lists[i].sum != lists[i+1].sum){
                if(i==0)sprintf(text, "%sstart", text);
                else sprintf(text, "%s start", text);
                for(int j = 0; j < lists[i].size; j++){
                    sprintf(text, "%s %d", text, lists[i].values[j]);
                }
            }
        }
        fputs(text, fp_out);
        lineCount++;
    }

    fclose(fp_in);
    fclose(fp_out);
    return 0;
}

void bubble(int values[], int size){
    for(int i = 0; i < size; i++){    
        for(int j = 0; j < size-1-i; j++){
            int aux;
            if(values[j] > values[j+1]){
                aux = values[j];
                values[j] = values[j+1];
                values[j+1] = aux;
            }
        }
    }
}

void bubbleList(List list[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size-1-i; j++){
            List aux;
            if(list[j].sum > list[j+1].sum){
                aux = list[j];
                list[j] = list[j+1];
                list[j+1] = aux;
            }
        }
    }
}
