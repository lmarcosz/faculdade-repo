//Nome: Marcos Lucas da Silva
//RA: 140782
//Tarefa 6 - p3

#include <stdio.h>

int main (){
    int x, i, multi, res;
    scanf("%d", &x); //Entrada
    res=0;
//=======================================================
    for(i=1;i<x;i++){ //Laço de repetição de análise
        multi = (i)*(i+1)*(i+2);

        if (multi==x){
            res = res+1;
        }
    }
//=======================================================
    if(res==1){ //Codição p/ x ser triangular
        printf("sim"); //Saída
    }
    else { //Condição p/ x não ser triangular
        printf("nao"); //Saída
    }
return 0;
}
