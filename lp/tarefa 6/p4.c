//Nome: Marcos Lucas da Silva
//RA: 140782
//Tarefa 6 - p4

#include <stdio.h>

int main (){
    int n, k, soma, resto;
    scanf("%d", &n); //Entrada
    soma=0;
    if (n>0) { //Condi��o p/ n ser positivo
        k=0;
        while(k<n-1){ //An�lise de n�meros divisores de n
            k=k+1;
            if(n%k==0){
                soma=soma+k;
            }
        }
        if(soma==n){ //Condi��o p/ n ser perfeito
            printf("sim"); //Sa�da
        }
        else{ //Condi��o p/ n n�o ser perfeito
            printf("nao"); //Sa�da
        }
    }
    else{ //Condi��o p/ n ser nulo ou negativo
        printf("nao"); //Sa�da
    }
return 0;
}
