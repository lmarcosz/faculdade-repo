//Nome: Marcos Lucas da Silva
//RA: 140782
//Tarefa 6 - p3

#include <stdio.h>

int main (){
    int x, i, multi, res;
    scanf("%d", &x); //Entrada
    res=0;
//=======================================================
    for(i=1;i<x;i++){ //La�o de repeti��o de an�lise
        multi = (i)*(i+1)*(i+2);

        if (multi==x){
            res = res+1;
        }
    }
//=======================================================
    if(res==1){ //Codi��o p/ x ser triangular
        printf("sim"); //Sa�da
    }
    else { //Condi��o p/ x n�o ser triangular
        printf("nao"); //Sa�da
    }
return 0;
}
