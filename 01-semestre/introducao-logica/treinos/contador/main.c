#include <stdio.h>

int main(){
    int r, i;
    do
    {
        printf("--------------------------\n");
        printf("|----CONTADOR--MAGICO----|\n");
        printf("--------------------------\n");
        printf("| Digite uma opcao: \n");
        printf("| [1] De 1 ate 10\n");
        printf("| [2] De 10 ate 1\n");
        printf("| [3] Sair\n");
        printf("| ");
        scanf("%d", &r);

        switch (r)
        {
        case 1:
            for (i = 1; i <= 10; i++){
                printf("%d... ", i);
            }
            printf("\n--------------------------\n");
            break;
        case 2:
            for (i = 10; i >= 1; i--){
                printf("%d... ", i);
            }
            printf("\n--------------------------\n");
            break;
        case 3:
            printf("|Encerrando o programa...\n");
            printf("\n--------------------------\n");
            break;
        default:
            printf("|Digite uma opcao valida\n");
            printf("\n--------------------------\n");
            break;
        }
    } while (r!=3);
    

    return 0;
}