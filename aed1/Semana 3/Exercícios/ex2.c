//Nome: Marcos Lucas da Silva (RA: 140782)
//AED I 21/08/20 - Semana 3 - Exercício 2
#include <stdio.h>
#include <stdlib.h>
#define MAX_PILHA 100
//Estrutura tipo pilha
typedef struct{
	char str[MAX_PILHA];
	int topo;
}T_Pilha;

//Criando uma pilha
T_Pilha* nova(){
	T_Pilha* np = (T_Pilha *) malloc(sizeof(T_Pilha));
	np->topo = -1;
	return np;
}

//Empilhar
int push(T_Pilha* p, char letra){
	if(p->topo >= MAX_PILHA-1){
		return -1;
	}
	(p->topo)++;
	p->str[p->topo] = letra;
	return 0;
}

//Listar
void Listar(T_Pilha *p){
	int i;
	for(i=p->topo;i>=0;i--){
		printf("%c", p->str[i]);
	}
}

//Desempilhar
int pop(T_Pilha *p){
	if(p->topo < 0){
		return -1;
	}
	p->topo--;
	return 0;
}

int main (){
	char frase[50];
	int i;
	T_Pilha *pilha = nova();
	if(pilha == NULL){
		printf("Nao foi possivel criar uma pilha!"); exit(-1);
	}
	
	printf("Digite uma frase: "); scanf("%[^\n]", frase); fflush(stdin);
	
	for(i=0;frase[i]!='\0';i++){
		push(pilha, frase[i]);
	}
	
	Listar(pilha);
	
	for(i=0;pilha->topo >= 0;i++){
		pop(pilha);
	}
	
	free(pilha);
	return 0;
}
