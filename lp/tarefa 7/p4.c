//Nome: Marcos Lucas da Silva
//RA: 140782
//Tarefa 7 - p4

#include <stdio.h>

int main () {
    int k, n, a, vet[99], x, cont;
    cont=0;
    scanf("%d", &n); //Entrada(tamanho da sequencia)
    if(n>=1 && n<=100){

        for(k=0;k<n;k++){
            scanf("%d", &a); //Entrada(termos da sequencia)
            vet[k] = a; //Atribui��o do termo no vetor
        }

        scanf("%d", &x); //Entrada(n�mero X ser procurado)
        for(k=0;k<n;k++){
            if(vet[k]==x){
                cont=cont+1; //Contador de X
            }
        }
        printf("%d", cont); //Sa�da(quantas vezes x aparece no vetor)
        for(k=0;k<n;k++){
            if(vet[k]==x){
                printf("\n%d", k+1); //Sa�da(posi��o da X)
            }
        }
    }
return 0;
}
