//Nome: Marcos Lucas da Silva
//RA: 140782
//Tarefa 5 - p3

#include <stdio.h>

int main () {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z); //Entrada

    if (x>y && x>z) {
        printf ("%d", x);
    } //Sa�da (quando x for o maior n�mero)

    if (y>x && y>z) {
        printf("%d", y);
    } //Sa�da (quando y for o maior n�mero)

    if (z>x && z>y) {
        printf("%d", z);
    } //Sa�da (quando z for o maior n�mero)

    if (x==y && x==z) {
        printf("%d", x);
    } //Sa�da (quando todos os n�meros s�o iguais)
return 0;
}
