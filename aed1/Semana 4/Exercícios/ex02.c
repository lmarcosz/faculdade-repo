//Nome: Marcos Lucas da Silva (RA:140782)
//AED I - Integral - Ex2 do slide (Semana 4)
//04/09/2020
#include <stdio.h>
#include <stdlib.h>
#define MAX_FILA 100
//===========================================================
//Estrutura tipo TFila
typedef struct{
	int vet[MAX_FILA];
	int n;
	int ini;
}TFila;

//Função para criar uma fila
TFila *nova_fila(){
	TFila *nf = (TFila *) malloc(sizeof(TFila));
	nf->n = 0;
	nf->ini = 0;
	return nf;
}

//Função para inserir na fila
int Insere_fila(TFila *p){
	int fim;
	if(p==NULL){
		printf("Fila nao inicializada!"); return -1;
	}
	if(p->n==MAX_FILA){
		printf("Fila cheia!"); return -1;
	}
	fim = (p->n+p->ini)%MAX_FILA;
	p->vet[fim] = 1;
	p->n++;
	return 0;
}

//Função para retirar da fila
int Retira_fila(TFila*p){
	if(p==NULL){
		printf("Fila nao inicializada!"); return -1;
	}
	if(p->n==MAX_FILA){
		printf("Fila cheia!"); return -1;
	}
	
	p->ini = incr_indice(p->ini);
	(p->n)--;
	return 0;
}
int incr_indice(int i){
	if(i==MAX_FILA-1){
		return 0;
	} else{
		return i+1;
	}
}
//=========================================================
int main (){
	TFila *fila_outros = nova_fila();
	if(!fila_outros){
		printf("Erro de alocacao!"); return -1;
	}
	TFila *fila_prioridade = nova_fila();
	if(!fila_prioridade){
		printf("Erro de alocacao!"); return -1;
	}
	char op; 
	int i;
	do{
		do{
			printf("=====CONTROLE DE FILA======\nFILA:");
			for(i=fila_prioridade->ini+1;i<=fila_prioridade->n;i++){
				if(fila_prioridade->n>fila_prioridade->ini){
					printf(" P");
				}
			}
			for(i=fila_outros->ini+1;i<=fila_outros->n;i++){
				if(fila_outros->n>fila_outros->ini){
					printf(" O");
				}
			}
			printf("\n[1] Inserir Outros\n[2] Inserir Prioritario\n[3] Retirar da fila\n[0] Sair\n");
			scanf("%c", &op); fflush(stdin);
			switch(op){
				case '1': Insere_fila(fila_outros); break;
				case '2': Insere_fila(fila_prioridade); break;
				case '3': 
					if((fila_prioridade->ini)<(fila_prioridade->n)){
						Retira_fila(fila_prioridade);
					} else{
						Retira_fila(fila_outros);
					}
				break;
				case '0': break;
			}
			system("cls");
		} while(op!='1' && op!='2' && op!='3' && op!='0');
	} while(op!='0');
	
	return 0;
}
