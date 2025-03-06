//Nome: Marcos Lucas da Silva
//RA: 140782
//Tarefa 6 - p1

#include <stdio.h>

int main() {
    int a, b, k, soma;
    scanf("%d %d", &a, &b); //Entrada
    soma = 0;
    k=0;

    if (a>0 && b>0 || a>0 && b<0) { //Condição 1
        do {
            k=k+1;
            soma = soma + b;
        } while (k<a); //Laço de repetição 1
    }

    if(a<0 && b<0 || a<0 && b>0) { //Condição 2
        do {
            k=k-1;
            soma = soma - b;
        } while (k>a); //Laço de repetição 2
    }

    printf("%d", soma); //(Saída)
return 0;
}
