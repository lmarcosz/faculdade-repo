#include <stdio.h>
#include <windows.h>

int main() {
    char figura, vet[20];
    int k, num, fim, aux;

        vet[1] = ' ';
        vet[2] = ' ';
        vet[3] = ' ';
        vet[4] = ' ';
        vet[5] = ' ';
        vet[6] = ' ';
        vet[7] = ' ';
        vet[8] = ' ';
        vet[9] = ' ';
        fim = 0;

    do {
    //=====================================================================
        printf(" +-------------------------+");
        printf("\n |J O G O   D A   V E L H A|");
        printf("\n +-------------------------+");
        printf("\n");
        printf("\n     |     |     ");
        printf("\n  %c  |  %c  |  %c  ", vet[7], vet[8], vet[9]);
        printf("\n-----+-----+-----");
        printf("\n  %c  |  %c  |  %c  ", vet[4], vet[5], vet[6]);
        printf("\n-----+-----+-----");
        printf("\n  %c  |  %c  |  %c  ", vet[1], vet[2], vet[3]);
        printf("\n     |     |     ");
        printf("\n");


    //=====================================================================
            k = k+1;
            aux=0;
            do{
                if (k%2==0) {
                    figura = 'O';
                    printf("\n%c -> ", figura);
                    scanf("%d", &num);
                    if(vet[num]==' ' || vet[num]==' '){
                        aux=0;
                        vet[num] = figura;
                    }
                    else{
                        aux=1;
                    }
                }

                if (k%2==1) {
                    figura = 'X';
                    printf("\n%c -> ", figura);
                    scanf("%d", &num);
                    if(vet[num]==' ' || vet[num]==' '){
                        aux=0;
                        vet[num] = figura;
                    }
                    else{
                        aux=1;
                    }
                }
            }while(aux==1);
        //=====================================================================
        if(figura==vet[1] && figura==vet[2] && figura==vet[3] || figura==vet[4] && figura==vet[5] && figura==vet[6] || figura==vet[7] && figura==vet[8] && figura==vet[9]) {
            system("cls");
            printf(" +-------------------------+");
            printf("\n |J O G O   D A   V E L H A|");
            printf("\n +-------------------------+");
            printf("\n");
            printf("\n     |     |     ");
            printf("\n  %c  |  %c  |  %c  ", vet[7], vet[8], vet[9]);
            printf("\n-----+-----+-----");
            printf("\n  %c  |  %c  |  %c  ", vet[4], vet[5], vet[6]);
            printf("\n-----+-----+-----");
            printf("\n  %c  |  %c  |  %c  ", vet[1], vet[2], vet[3]);
            printf("\n     |     |     ");
            printf("\n");
            printf("\nO JOGADOR [%c] E O VENCEDOR !", figura);
            Sleep(10000);
            fim=5;

        }
        if(figura==vet[1] && figura==vet[4] && figura==vet[7] || figura==vet[2] && figura==vet[5] && figura==vet[8] || figura==vet[3] && figura==vet[6] && figura==vet[9]) {
            system("cls");
            printf(" +-------------------------+");
            printf("\n |J O G O   D A   V E L H A|");
            printf("\n +-------------------------+");
            printf("\n");
            printf("\n     |     |     ");
            printf("\n  %c  |  %c  |  %c  ", vet[7], vet[8], vet[9]);
            printf("\n-----+-----+-----");
            printf("\n  %c  |  %c  |  %c  ", vet[4], vet[5], vet[6]);
            printf("\n-----+-----+-----");
            printf("\n  %c  |  %c  |  %c  ", vet[1], vet[2], vet[3]);
            printf("\n     |     |     ");
            printf("\n");
            printf("\nO JOGADOR [%c] E O VENCEDOR !", figura);
            Sleep(10000);
            fim = 5;
        }
        if(figura==vet[1] && figura==vet[5] && figura==vet[9] || figura==vet[7] && figura==vet[5] && figura==vet[3]) {
            system("cls");
            printf(" +-------------------------+");
            printf("\n |J O G O   D A   V E L H A|");
            printf("\n +-------------------------+");
            printf("\n");
            printf("\n     |     |     ");
            printf("\n  %c  |  %c  |  %c  ", vet[7], vet[8], vet[9]);
            printf("\n-----+-----+-----");
            printf("\n  %c  |  %c  |  %c  ", vet[4], vet[5], vet[6]);
            printf("\n-----+-----+-----");
            printf("\n  %c  |  %c  |  %c  ", vet[1], vet[2], vet[3]);
            printf("\n     |     |     ");
            printf("\n");
            printf("\nO JOGADOR [%c] E O VENCEDOR !", figura);
            Sleep(10000);
            fim = 5;
        }

        else {
            if (vet[1]!=' ' & vet[2]!=' ' & vet[3]!=' ' & vet[4]!=' ' & vet[5]!=' ' & vet[6]!=' ' & vet[7]!=' ' & vet[8]!=' ' & vet[9]!=' ') {
                system("cls");
                printf(" +-------------------------+");
                printf("\n |J O G O   D A   V E L H A|");
                printf("\n +-------------------------+");
                printf("\n");
                printf("\n     |     |     ");
                printf("\n  %c  |  %c  |  %c  ", vet[7], vet[8], vet[9]);
                printf("\n-----+-----+-----");
                printf("\n  %c  |  %c  |  %c  ", vet[4], vet[5], vet[6]);
                printf("\n-----+-----+-----");
                printf("\n  %c  |  %c  |  %c  ", vet[1], vet[2], vet[3]);
                printf("\n     |     |     ");
                printf("\n");
                printf("\nV E L H A");
                Sleep(10000);
                fim = 5;
            }
        }
        system("cls");
    }while(fim!=5);

return 0;
}
