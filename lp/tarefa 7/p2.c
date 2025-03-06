//Nome: Marcos Lucas da Silva
//RA: 140782
//Tarefa 7 - p2

#include <stdio.h>

int main(){
    int n;
    scanf("%d\n", &n);
    int k, vet[n], a, cont;

    if(n>=1 && n<=100) {

        for(k=0;k<n;k++){
            scanf("\n%d", &vet[k]);
        }

        for(k=0;k<n;k++){
            cont=0;
            for(a=0;a<n;a++){
                if(vet[k]==vet[a]){
                    cont=cont+1;
                }
            }
            printf("%d %d\n", vet[k], cont);
        }
    }
return 0;
}
