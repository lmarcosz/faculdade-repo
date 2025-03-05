//Nome: Marcos Lucas da Silva (RA: 140782)
//AED I 28/08/20 - Semana 4 - Ex01
#include <stdio.h>
#include <stdlib.h>
#define MAX_FILA 50

typedef struct{
	int vet[MAX_FILA];
	int ini;
	int n;
}TFila;

TFila* nova(){
	TFila* nf = (TFila *) malloc(sizeof(TFila));
	nf->ini = 0;
	nf->n = 0;
	return nf;
}

int push(TFila *p, int val){
	if(p==NULL){
		printf("FILA NAO INICIALIZADA!"); return -1;
	}
	if(p->n == MAX_FILA){
		printf("FILA CHEIA!"); return -1;
	}
	p->vet[(p->ini+p->n)%MAX_FILA] = val;
	(p->n)++;
	return 0;
}

int main (){
	int i, aux, cont=1, contt=1;
	TFila *fila1 = nova();
	TFila *fila2 = nova();
	TFila *fila3 = nova();
	do{
		printf("Digite os elementos da FILA 1 (em ordem crescente) [PARA SAIR, DIGITE: -9999]\n-> ");
		scanf("%d", &aux); 
		if(aux>(-9999)){
			push(fila1, aux); 
		}
		if(cont==25){
			aux = -9999;
		}
		cont++;
		system("cls");
	} while(aux>(-9999));
	do{
		printf("Digite os elementos da FILA 2 (em ordem crescente) [PARA SAIR, DIGITE: -9999]\n-> ");
		scanf("%d", &aux); 
		if(aux>(-9999)){
			push(fila2, aux); 
		}
		if(contt==25){
			aux = -9999;
		}
		contt++;
		system("cls");
	} while(aux>(-9999));
	cont = cont + contt;
	aux = -9998;
	
	
	
	free(fila1);
	free(fila2);
	free(fila3);
	return 0;
}
