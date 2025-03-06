//Nome: Marcos Lucas da Silva
//RA: 140782
//Tarefa 6 - p4

#include <stdio.h>

int main (){
    int n, k, soma, resto;
    scanf("%d", &n); //Entrada
    soma=0;
    if (n>0) { //Condição p/ n ser positivo
        k=0;
        while(k<n-1){ //Análise de números divisores de n
            k=k+1;
            if(n%k==0){
                soma=soma+k;
            }
        }
        if(soma==n){ //Condição p/ n ser perfeito
            printf("sim"); //Saída
        }
        else{ //Condição p/ n não ser perfeito
            printf("nao"); //Saída
        }
    }
    else{ //Condição p/ n ser nulo ou negativo
        printf("nao"); //Saída
    }
return 0;
}
