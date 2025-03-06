//Nome: Marcos Lucas da Silva
//RA: 140782
//Tarefa 6 - p2

#include <stdio.h>

int main() {
    int num, k, resto, cont;
    scanf("%d", &num); //Entrada
    k=0;
    cont=0;
    if (num>0) { //Condição para num ser positivo
        do { //Laço de repetição para analisar o resto da divisão de números<num e >0
            k=k+1;
            if((num%k)==0) {
                cont=cont+1;
            }
        } while(k<num);
        if (cont==2) { //Condição para num ser primo
            printf("sim"); //Saída
        }
        else {
            printf("nao"); //Saída
        }
    }
    else { //Condição para num não ser positivo
        printf("nao"); //Saída
    }
return 0;
}
