#include <stdio.h>

int menu(int op){
    do{
        printf("+--------+\n|  MENU  |\n+--------+");
        printf("\n\n[1] Inserir\n[2] Remover\n[3] Visualizar\n[4] Buscar\n[0] Sair\n");
        scanf("%d", &op);
        system("cls");
    }while(op!=1&&op!=2&&op!=3&&op!=4&&op!=0);
    return op;
}

int main (){
    int op;
    int k, n, total=0;
    struct info{
        char nome[100];
        int ra;
        double nota;
        double freq;
    }pessoas[1000];

    menu(op);

        switch(op){
            case 1: //Inserir
                printf("Quantidade: ");
                scanf("%d", &n);
                total += n;
                system("cls");
                if(n>0){
                    for(k=0;k<n;k++){
                        printf("|%d|", k+1);
                        printf("\nNome: ");
                        scanf("%s", pessoas[k].nome);
                        printf("RA: ");
                        scanf("%d", &pessoas[k].ra);
                        printf("Nota: ");
                        scanf("%lf", &pessoas[k].nota);
                        printf("Frequencia: ");
                        scanf("%lf", &pessoas[k].freq);
                        system("cls");
                    }
                }
            break;

            case 2: //Remover

            break;

            case 3: //Visualizar
                for(k=0;k<total;k++){
                    printf("|%d|", k+1);
                    printf("\nNome: %s", pessoas[k].nome);
                    printf("\nRA: %d", pessoas[k].ra);
                    printf("\nNota: %lf", pessoas[k].nota);
                    printf("\nFrequencia: %lf", pessoas[k].freq);
                }
            break;

            case 4: //Buscar

            break;

            case 0: //Saír

            break;


        }
return 0;
}
