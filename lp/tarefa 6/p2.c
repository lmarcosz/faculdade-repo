//Nome: Marcos Lucas da Silva
//RA: 140782
//Tarefa 6 - p2

#include <stdio.h>

int main() {
    int num, k, resto, cont;
    scanf("%d", &num); //Entrada
    k=0;
    cont=0;
    if (num>0) { //Condi��o para num ser positivo
        do { //La�o de repeti��o para analisar o resto da divis�o de n�meros<num e >0
            k=k+1;
            if((num%k)==0) {
                cont=cont+1;
            }
        } while(k<num);
        if (cont==2) { //Condi��o para num ser primo
            printf("sim"); //Sa�da
        }
        else {
            printf("nao"); //Sa�da
        }
    }
    else { //Condi��o para num n�o ser positivo
        printf("nao"); //Sa�da
    }
return 0;
}
