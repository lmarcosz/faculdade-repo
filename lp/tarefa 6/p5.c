//Nome: Marcos Lucas da Silva
//RA: 140782
//Tarefa 6 - p5

#include <stdio.h>

int main (){
    int n, i, x1, x2, x3;
    scanf("%d", &n); //Entrada
    if(n>=0){ //Condi��p p/ n ser positivo
        switch (n){
            case 0:
                printf("%d", n); //Sa�da
            break;
            case 1:
                printf("%d", n); //Sa�da
            break;
            case 2:
                printf("%d", 1); //Sa�da
            break;
            default:
                x1=1;
                x2=1;
                for(i=0;i<n-2;i++){ //Opera��o p/ realizar Fibonacci
                    x3=x1+x2;
                    x1=x2;
                    x2=x3;
                }
            printf("%d", x3); //Sa�da
        }
    }

return 0;
}
