//Nome: Marcos Lucas da Silva (RA:140782)
//AED I (ADE) - 2020/1
//Tarefa da semana 10 - �rvores Bin�rias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrutura tipo �rvore
typedef struct arv{
	char id;
	struct arv *esq;
	struct arv *dir;
}TArv;
typedef TArv *PArv;

//Inicializa a �rvore
PArv Inicializar(){
	return NULL;
}

//Insere n� na �rvore
PArv Inserir(PArv No, char item[]){
	if(No==NULL){
		PArv p = (PArv) malloc(sizeof(TArv));
		p->id = item[0];
		p->esq = NULL;
		p->dir = NULL;
		return p;
	} else{
		No->esq = Inserir(No->esq, item);
	}
}

//Imprime a �rvore (Pr�-Ordem)
void ImprimirPrefixa(PArv No){
	if(No!=NULL){
		printf("%c", No->id);
		ImprimirPrefixa(No->esq);
		ImprimirPrefixa(No->dir);
	}
}
//Imprime a �rvore (Em-ordem)
void ImprimirInfixa(PArv No){
	if(No!=NULL){
		ImprimirInfixa(No->esq);
		printf("%c", No->id);
		ImprimirInfixa(No->dir);
	}
}

//Libera a mem�ria da �rvore
PArv Liberar(PArv No){
	if(No!=NULL){
		Liberar(No->esq);
		Liberar(No->dir);
		free(No);
	}
	return NULL;
}

int main (){
	FILE *arquivo = fopen("arv.txt","r"); //Abertura do arquivo
	
	if(arquivo==NULL){ //Verifica��o de erro ao abrir arquivo
		printf("Nao foi possivel abrir o arquivo!");
		getch();
		exit(0);
	}
	
	PArv No = Inicializar(); //Inicializa a �rvore
	
	char item[20], op;
	int i, aux;
	while(fscanf(arquivo,"%s", item)!=EOF){ //Leitura de cada linha do arquivo
		No = Inserir(No, item);
	}
	
	ImprimirPrefixa(No); //Saida: prefixa
	printf("\n");
	ImprimirInfixa(No); //Saida: infixa
	No = Liberar(No); //Libera mem�ria da �rvore
	fclose(arquivo); //Fechamento do arquivo
	return 0;
}
