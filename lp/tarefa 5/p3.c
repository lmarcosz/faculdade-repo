//Nome: Marcos Lucas da Silva
//RA: 140782
//Tarefa 5 - p3

#include <stdio.h>

int main () {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z); //Entrada

    if (x>y && x>z) {
        printf ("%d", x);
    } //Saída (quando x for o maior número)

    if (y>x && y>z) {
        printf("%d", y);
    } //Saída (quando y for o maior número)

    if (z>x && z>y) {
        printf("%d", z);
    } //Saída (quando z for o maior número)

    if (x==y && x==z) {
        printf("%d", x);
    } //Saída (quando todos os números são iguais)
return 0;
}
