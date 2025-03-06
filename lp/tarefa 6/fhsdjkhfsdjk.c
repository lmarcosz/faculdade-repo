#include <stdio.h>

int main (){
    int k, n, x, vet[100], a, cont;

    scanf("%d\n", &n);
    if(n>=1 && n<=100) {
        for(k=0;k<n;k++){
            scanf("\n%d", &x);
            vet[k] = x;
        }
        for(k=0;k<n;k++){
            cont=0;
            for(a=0;a<n;a++){
                if(vet[k]==vet[a]){
                    cont=cont+1;
                }
            }
            printf("%d %d\n", vet[k], cont-1);
        }
    }
return 0;
}
