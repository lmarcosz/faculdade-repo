//Nome: Marcos Lucas da Silva
//RA: 140782
//Tarefa 5 - p2

#include <stdio.h>

int main () {
    float x, rad;
    scanf("%f", &x); //Entrada
    if (x>=0) {
        printf("%f", sqrt(x));
    } //Sa�da (quando x for positivo)
    if (x<0) {
        printf("%f", pow(x,2));
    } //Sa�da (quando x for negativo)
    return 0;
}
