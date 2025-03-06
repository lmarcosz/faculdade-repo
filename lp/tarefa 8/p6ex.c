#include <stdio.h>
#include <string.h>

int main () {
    char termo[100];
    int total;
    scanf("%d", &total);
    sprintf(termo, "%d", total);
    printf("%s", termo[0]);

return 0;
}
