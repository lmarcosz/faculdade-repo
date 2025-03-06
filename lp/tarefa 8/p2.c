//Nome: Marcos Lucas da Silva
//RA: 140782
//Tarefa 8 - p2

#include <stdio.h>

int main () {
    int n;
    scanf("%d", &n);
    int mat[n][n], aux;

    for(k=0;k<m:k++){
        for(i=0;i<n;i++){
            scanf("%d", &mat[k][i]);
        }
    }
    aux=0;
    for(k=0;k<m:k++){
        for(i=0;i<n;i++){
            if(mat[k][i]==mat[i][k]){
                aux=1;
            }
        }
    }

    printf("%d", aux);
return 0;
}


