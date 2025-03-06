//Nome: Marcos Lucas da Silva
//RA: 140782
//Tarefa 8 - p6

#include <stdio.h>

int main () {
    int n, k, i, soma, res;
    scanf("%d", &n);
    int mat[n][n], aux=0;

    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            scanf("%d", &mat[k][i]);
        }
    }
//======================================
    soma=0;
    res=0;
    for(k=0;k<n;k++){
        res=soma;
        soma=0;
        for(i=0;i<n;i++){
            soma = soma + mat[k][i];
        }
        if(res==soma){
            aux=res;
        }
        else{
            aux=0;
        }
    }
//=====================================
    res=0;
    for(i=0;i<n;i++){
        res=soma;
        soma=0;
        for(k=0;k<n;k++){
            soma = soma + mat[k][i];
        }
        if(res==soma){
            aux=res;
        }
        else{
            aux=0;
        }
    }
//======================================
    res=0;
    for(k=0;k<n;k++){
        res=soma;
        soma=0;
        soma = soma + mat[k][k];
    }
    if(res==soma){
        aux=res;
    }
    else{
        aux=0;
    }
//=====================================
    res=0;
    i=n;
    for(k=0;k<n;k++){
        i = i--;
        res=soma;
        soma=0;
        soma = soma + mat[i][k];
    }
    if(res==soma){
        aux=res;
    }
    else{
        aux=0;
    }
//===================================

    printf("%d", aux);

return 0;
}
