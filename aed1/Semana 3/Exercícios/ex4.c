//Nome: Marcos Lucas da Silva (RA: 140782)
//AED I 21/08/20 - Semana 3 - Exercício 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PILHA 30

typedef struct{
	char str[MAX_PILHA];
	int topo;
}TPilha;

TPilha* nova(){
	TPilha* np = (TPilha *) malloc(sizeof(TPilha));
	np->topo = -1;
	return np;
}

int push(TPilha *p, char val){
	if(p->topo>=MAX_PILHA){
		printf("Error: full stack!"); exit(-1);
	}
	(p->topo)++;
	p->str[p->topo] = val;
	return p->topo;
}

char pop(TPilha *p){
	char val;
	if(p->topo < 0){
		printf("Error: empty stack!");
	}
	val = p->str[p->topo];
	(p->topo)--;
	return val;
}

void Listar(TPilha *p){
	int i;
	printf("\n==");
	for(i=p->topo;i>=0;i--){
		printf("%c\n", p->str[i]);
	}
	printf("==");
}
int main (){
	char str[30];
	int i, tam=1;
	printf("-> "); scanf("%[^\n]", str); fflush(stdin);
	
	if((strlen(str)%2)==0){
		printf("\nNAO PERTENCE ao conjunto WcM"); return 0;
	}
	
	TPilha *pilha = nova();
	if(!nova){
		printf("Allocation error!"); return 0;
	}
	
	for(i=0;i<strlen(str);i++){
		if(i==(strlen(str)/2)+1){
			if(str[i]!='c'){
				printf("\nNAO PERTENCE ao conjunto WcM");return 0;
			}
		} else{
			tam = push(pilha, str[i]);
		}
	}
	
	TPilha *pilha2 = nova();
	
	while(pilha->topo > tam/2){
		push(pilha2, pop(pilha));
	}
	
	Listar(pilha);
	Listar(pilha2);
	
	return 0;
}

