//Nome: Marcos Lucas da Silva
//RA: 140782
//Tarefa 5 - p4

#include <stdio.h>

int main () {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z); //Entrada

    if ((x<=0 || y<=0 || z<=0)||(x>y+z || y>x+z || z>x+y)) {
        printf("invalido");
    } //Sa�da (p/ tri�ngulo invalido)
    else {
        if (x==y && x!=z || y==z && y!=x || z==x && z!=y) {
            printf("isoceles");
        } //Sa�da (p/ tri�ngulo is�celes)
        else {
            if (x==y && y==z) {
                printf("equilatero");
            } //Sa�da (p/ tri�ngulo equil�tero)
            else {
                if (x!=y && x!=z || y!=x && y!=z || z!=x && z!=y) {
                printf("escaleno");
                } //Sa�da (p/ tri�ngulo escaleno)
            }
        }
    }
return 0;
}
