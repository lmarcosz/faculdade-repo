//Nome: Marcos Lucas da Silva
//RA: 140782
//Tarefa 8 - p3

#include <stdio.h>

int main () {
    int m, n, k, i, x, maior=0;
    scanf("%d %d", &m, &n); //Entrada(�ndices da matriz)
    int mat[m][n], ind1, ind2;
//========================================
    for(k=0;k<m;k++){
        for(i=0;i<n;i++){
            scanf("%d", &mat[k][i]); //Entrada(termos da matriz)
            if(mat[k][i]>maior){ //Condi��o para o maior n�mero
                maior = mat[k][i];
                ind1 = k;
                ind2 = i;
            }
        }
    }
//========================================
    printf("%d %d", ind1, ind2); //Sa�da(�ndices do maior n�mero)
return 0;
}
