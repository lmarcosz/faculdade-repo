//Nome: Marcos Lucas da Silva
//RA: 140782
//Tarefa 6 - p7

#include <stdio.h>

int main(){
    int canal, np, tp;
    double can[22], aud[22];
    can[17]=0;
    can[18]=0;
    can[19]=0;
    can[20]=0;
    can[22]=0;
//=====================================
    do{
        scanf("%d", &canal);
        if (canal==0){
            np = 0;
        }
        else{
            scanf("%d", &np);
            if(np>0){
                tp = tp + np;
            }
        }
    //================================
        switch(canal){
            case 17:
                can[17]=can[17]+np;
            break;
            case 18:
                can[18]=can[18]+np;
            break;
            case 19:
                can[19]=can[19]+np;
            break;
            case 20:
                can[20]=can[20]+np;
            break;
            case 22:
                can[22]=can[22]+np;
            break;
        }
    } while(canal!=0);
//===================================
    aud[17]=(can[17]*100.0)/tp;
    aud[18]=(can[18]*100.0)/tp;
    aud[19]=(can[19]*100.0)/tp;
    aud[20]=(can[20]*100.0)/tp;
    aud[22]=(can[22]*100.0)/tp;
//===================================
    if(aud[17] > 0.0){
        printf("17 %lf\n", aud[17]);
    }
    if(aud[18]>0.0){
        printf("18 %lf\n", aud[18]);
    }
    if(aud[19]>0.0){
        printf("19 %lf\n", aud[19]);
    }
    if(aud[20]>0.0){
        printf("20 %lf\n", aud[20]);
    }
    if(aud[22]>0.0){
        printf("22 %lf", aud[22]);
    }
return 0;
}
