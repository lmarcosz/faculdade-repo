#include <stdio.h>

int main () {
    int fat, x;
    unsigned int res;
    res = 1;
    printf("Digite um valor: ");
    scanf("%d", &fat);
    x = fat;
    for ( ;fat >= 1; --fat) {
        res = res * fat;
    }
    printf("O fatorial de %d e %u", x, res);
return 0;
}
