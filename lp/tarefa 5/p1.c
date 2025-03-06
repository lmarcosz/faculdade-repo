//Nome: Marcos Lucas da Silva
//RA: 140782
//Tarefa 5 - p1

#include <stdio.h>

int main () {
    int x, y, soma;

    scanf("%d %d", &x, &y); //Entrada
    soma = x+y; //Soma

    if (soma>20) {
        printf("%d", soma+8);
    } //Saída (p/ soma maior que 20)

    if (soma<=20) {
        printf("%d", soma-5);
    } //Saída (p/ soma menor ou igual a 20)
return 0;
}
