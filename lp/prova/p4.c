// 5. Na teoria dos sistemas, define-se o elemento MINMAX de uma matriz, composta de
//    elementos distintos, como sendo o maior elemento da linha onde se encontra o menor
//    elemento da matriz. Escreva um programa que leia dois nu´meros inteiros M (1 ≤ M ≤
//    100) e N (1 ≤ N ≤ 100) indicando, respectivamente, o nu´mero de linhas e de colunas
//    de uma matriz e, em seguida, leia e armazene uma matriz de M × N nu´meros inteiros e
//    encontre a posi¸c˜ao do seu elemento MINMAX, imprimindo o ´ındice da linha e da coluna
//    desse elemento, separando-os com um espa¸co em branco.


#include <stdio.h>

int main (){
    int m, n, k, i, menor, maior, linha, coluna;
    scanf("%d %d", &m, &n);
    int mat[m][n];

    for(k=0;k<m;k++){
        for(i=0;i<n;i++){
            scanf("%d", &mat[k][i]);
            if(k==0 && i==0){
                menor = mat[k][i];
            }
            else{
                if(mat[k][i]<menor){
                    menor = mat[k][i];
                    linha = k;
                }
            }
        }
    }

    for(i=0;i<n;i++){
        if(i==0){
            maior = mat[linha][0];
        }
        else{
            if(maior < mat[linha][i]){
                maior = mat[linha][i];
                coluna = i;
            }
        }
    }

    printf("%d %d\n%d", linha, coluna, maior);

return 0;
}
