//Nome: Marcos Lucas da Silva
//RA: 140782
//Tarefa 5 - p6

#include <stdio.h>

int main () {
    int num;
    printf("mamifero?\n");
    scanf("%d", &num);
    switch (num) {
        case 1:
            printf("quadrupede?\n");
            scanf("%d", &num);
            switch (num) {
                case 1:
                    printf("carnivoro?\n");
                    scanf("%d", &num);
                    switch (num) {
                        case 1:
                            printf("leao");
                        break;
                        case 0:
                            printf("herbivoro?\n");
                            scanf("%d", &num);
                            switch (num) {
                                case 1:
                                    printf("cavalo");
                                break;
                                case 0:
                                    printf("nao sei");
                                break;
                                default: printf("nao sei");
                            }
                    }
                break;
                case 0:
                    printf("bipede?\n");
                    scanf("%d", &num);
                    switch (num) {
                        case 1:
                            printf("onivoro?\n");
                            scanf("%d", &num);
                            switch (num) {
                                case 1:
                                    printf("homem");
                                break;
                                case 0:
                                    printf("frutifero?\n");
                                    scanf("%d", &num);
                                    switch (num) {
                                        case 1:
                                            printf("macaco");
                                        break;
                                        case 0:
                                            printf("nao sei");
                                        break;
                                    }
                                break;
                                default: printf("nao sei");
                            }
                        break;
                        case 0:
                            printf("voador?\n");
                            scanf("%d", &num);
                            switch (num) {
                                case 1:
                                    printf("morcego");
                                break;
                                case 0:
                                    printf("aquatico?\n");
                                    scanf("%d", &num);
                                    switch (num) {
                                        case 1:
                                            printf("baleia");
                                        break;
                                        case 0:
                                            printf("nao sei");
                                        break;
                                        default: printf("nao sei");
                                    }
                                break;
                                default: printf("nao sei");
                            }
                        break;
                        default: printf("nao sei");
                    }
                break;
                default: printf("nao sei");
            }
        break;

        case 0:
            printf("ave?\n");
            scanf("%d", &num);
            switch (num) {
                case 1:
                    printf("nao-voador?\n");
                    scanf("%d", &num);
                    switch (num) {
                        case 1:
                            printf("tropical?\n");
                            scanf("%d", &num);
                            switch (num) {
                                case 1:
                                    printf("avestruz");
                                break;
                                case 0:
                                    printf("polar?\n");
                                    scanf("%d", &num);
                                    switch (num) {
                                        case 1:
                                            printf("pinguim");
                                        break;
                                        case 0:
                                            printf("nao sei");
                                        break;
                                        default: printf("nao sei");
                                    }
                                break;
                                default: printf("nao sei");
                            }
                        break;
                        case 0:
                            printf("nadador?\n");
                            scanf("%d", &num);
                            switch (num) {
                                case 1:
                                    printf("pato");
                                break;
                                case 0:
                                    printf("rapina?\n");
                                    scanf("%d", &num);
                                    switch (num) {
                                        case 1:
                                            printf("aguia");
                                        break;
                                        case 0:
                                            printf("nao sei");
                                        break;
                                        default: printf("nao sei");
                                    }
                                break;
                                default: printf("nao sei");
                            }
                        break;
                        default: printf("nao sei");
                    }
                break;
                case 0:
                    printf("reptil?\n");
                    scanf("%d", &num);
                    switch (num) {
                        case 1:
                            printf("com-casco?\n");
                            scanf("%d", &num);
                            switch (num) {
                                case 1:
                                    printf("tartaruga");
                                break;
                                case 0:
                                    printf("carnivoro?\n");
                                    scanf("%d", &num);
                                    switch (num) {
                                        case 1:
                                            printf("crocodilo");
                                        break;
                                        case 0:
                                            printf("sem-patas?\n");
                                            scanf("%d", &num);
                                            switch (num) {
                                                case 1:
                                                    printf("cobra");
                                                break;
                                                case 0:
                                                    printf("nao sei");
                                                break;
                                                default: printf("nao sei");
                                            }
                                        break;
                                        default: printf("nao sei");
                                    }
                                break;
                                default: printf("nao sei");
                            }
                        break;
                        case 0:
                            printf("nao sei");
                        break;
                        default: printf("nao sei");
                    }
                break;
                default: printf("nao sei");
            }
        break;
        default: printf("nao sei");
    }
return 0;
}
