//Nome: Marcos Lucas da Silva
//RA: 140782
//Tarefa 8 - p4

#include <stdio.h>

int main () {
    int m, n;
    scanf("%d %d", &n, &m); //Entrada(�ndices da matriz)
    int mat[m][n], k, i, vet[m], soma;
//==================================================================
    for(k=0;k<n;k++){
        soma=0;
        for(i=0;i<m;i++){
            scanf("%d", &mat[m][n]); //Entrada(termos da matriz)
            soma = soma + mat[m][n]; //Opera��o de soma dos termos
        }
        vet[k]= soma;
        printf("%d ", soma); //Sa�da(soma dos termos de cada linha)
    }
return 0;
}

