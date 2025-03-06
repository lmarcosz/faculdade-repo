//Nome: Marcos Lucas da Silva
//RA: 140782
//Tarefa 7 - p1

#include <stdio.h>

int main(){
    int n, k, vet[99], x, maior;
    maior=0;
    scanf("%d", &n); //Entrada(tamanho do conjunto)
    if(n>=1 && n<=100){ //Intervalo de n
    //==================================
        for (k=0;k<n;k++){ //Laço de repetição
            scanf("%d", &x); //Entrada(números do conjunto)
            if(x>maior){ //Análise do maior número
                maior=x;
            }
        }
    //==================================
    }
    printf("%d", maior); //Saída
return 0;
}
