#include <stdio.h>

int main () {
    int n;
    scanf("%d", &n);
    int vet[n], k;
    for(k=0;k<n;k++){
        scanf("%d", &vet[k]);
    }
    for(k=n-1;k>=0;k--){
        printf("%d ", vet[k]);
    }
return 0;
}
