//Nome: Marcos Lucas da Silva (RA: 140782)
//AED I 21/08/20 - Semana 3 - Exercício 1
#include <stdio.h>
#include <stdlib.h>
#define MAX_PILHA 100
//Estrutura tipo pilha
typedef struct{
	int vet[MAX_PILHA];
	int topo;
}T_Pilha;

//Criando uma pilha
T_Pilha* nova(){
	T_Pilha* np = (T_Pilha *) malloc(sizeof(T_Pilha));
	np->topo = -1;
	return np;
}

//Empilhar
int push(T_Pilha* p, int val){
	
}

int main (){
	char frase[50];
	int i;
	T_Pilha *pilha = nova();
	
	printf("Digite uma frase: "); scanf("%[^\n]", frase); fflush(stdin);
	
	return 0;
}
