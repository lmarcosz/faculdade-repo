#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int valor;
	struct lista *prox;
}TLista;



void Insere(TLista *p, int val){
	TLista *nova = (TLista *) malloc(sizeof(TLista));
	nova->valor = val;
	if(p==NULL){
		p = nova;
		nova->prox = nova;
	}
	else{
		nova->prox = p->prox;
		p->prox = nova;
	}
}

int Imprime(TLista *p){
	if(p==NULL){
		printf("Lista vazia!"); return;
	}
	printf("\n%d", p->valor);
	Imprime(p->prox);
	return 0;
}

int main (){
	int i, n=0;
	TLista *lista = NULL;
	
	for(i=0;n>-1;i++){
		scanf("%d", &n);
		Insere(lista, n);
	}
	system("cls");
	Imprime(lista);	
	return 0;
}
