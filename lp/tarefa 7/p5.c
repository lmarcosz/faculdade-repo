//Nome: Marcos Lucas da Silva
//RA: 140782
//Tarefa 7 - p5

#include <stdio.h>

int main () {
    int k, n, x, vet[99];
    scanf("%d", &n); //Entrada(tamanho da sequencia)
    if(n>=1 && n<=100){
        for(k=0;k<n;k++){
            scanf("%d", &x); //Entrada(termos da sequencia)
            vet[k] = x; //Atribuição dos termos no vetor
        }
        for(k=n-1;k>=0;k--){
            printf("%d ", vet[k]); //Saída
        }
    }
return 0;
}
