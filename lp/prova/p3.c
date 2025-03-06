#include <stdio.h>

int main () {
    char cad[100];
    int k, i, aux, n;
    scanf("%d", &n);
    scanf("%s", cad[100]);

    for(k=0;k<n;k++){
        for(i=n;i>=0;i--){
            if(cad[k]==cad[i]){
                aux=1;
            }
            else{
                aux=0;
            }
        }
    }
    if(aux==0){
        printf("nao");
    }
    else{
        printf("sim");
    }
return 0;
}
