#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void isEqual(FILE *fp_test, FILE *fp_res);

int main(){
    FILE *fp_test1 = fopen("L2Q1.out", "r");
    FILE *fp_res1 = fopen("./X2/L2Q1.out", "r");
    
    
    FILE *fp_test2 = fopen("L2Q2.out", "r");
    FILE *fp_res2 = fopen("./X2/L2Q2.out", "r");
    
    FILE *fp_test3 = fopen("L2Q3.out", "r");
    FILE *fp_res3 = fopen("./X2/L2Q3.out", "r");

    printf("\033[1;34m--------TESTE 1--------\033[0m\n");
    if (fp_test1 == NULL || fp_res1 == NULL){
        printf("Arquivos nao podem ser abertos.");
        return EXIT_FAILURE;
    }
    
    isEqual(fp_test1, fp_res1);

    fclose(fp_test1);
    fclose(fp_res1);

    printf("\n\033[1;34m--------TESTE 2--------\033[0m\n");
    if (fp_test2 == NULL || fp_res2 == NULL){
        printf("Arquivos nao podem ser abertos.");
        return EXIT_FAILURE;
    }

    isEqual(fp_test2, fp_res2);
    
    fclose(fp_test2);
    fclose(fp_res2);

    printf("\n\033[1;34m--------TESTE 3--------\033[0m\n");
    if (fp_test3 == NULL || fp_res3 == NULL){
        printf("Arquivos nao podem ser abertos.");
        return EXIT_FAILURE;
    }

    isEqual(fp_test3, fp_res3);
    
    fclose(fp_test3);
    fclose(fp_res3);
    return EXIT_SUCCESS;
}

void isEqual(FILE *fp_test, FILE *fp_res){
    char equal = 1;
    char lineTest[1000];
    char lineRes[1000];
    int lineCount = 0;
    while (fgets(lineTest, sizeof(lineTest), fp_test) != NULL){
        lineCount++;
        if (fgets(lineRes, sizeof(lineRes), fp_res) != NULL){
            printf("T: %s\n", lineTest);
            printf("R: %s\n", lineRes);
            if (strcmp(lineTest, lineRes) == 0){
                printf("\033[1;32mA linha %d é igual.\033[0m\n\n", lineCount);
            }else{
                printf("\033[1;33mA linha %d nao é igual.\033[0m\n\n", lineCount);
                equal = 0;
            }
        }else{
            printf("T: %s", lineTest);
            printf("\033[1;33mLinha a mais.\033[0m\n\n");
            equal = 0;
        }
    }
    if(equal == 1){
        printf("\033[1;32mOs arquivos são iguais.\033[0m\n\n");
    }else{
        printf("\033[1;31mOs arquivos não são iguais.\033[0m\n\n");
    }
}