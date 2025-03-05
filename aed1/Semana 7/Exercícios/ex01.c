#include <stdio.h>
#include <stdlib.h>

typedef struct list{
	int num;
	struct list *prox;
	struct list *ant;
}TLista;

TLista *Inserir(TLista *p){
	TLista *novo = (TLista *) malloc(sizeof(TLista));
	novo->ant = NULL;
	novo->prox = NULL;
	printf("Elemento (numero inteiro): "); scanf("%d", &novo->num); fflush(stdin);
	if(p==NULL){
		p = novo;
	} else{
		p->ant = novo;
		novo->prox = p;
		p = novo;
	}
	system("cls");
	return p;
}

void Vizualizar(TLista *p){
	if(p==NULL){
		printf("LISTA VAZIA!");
	} else{
		while(p!=NULL){
			printf("%d ", p->num);
			p = p->prox;
		}
	}
		printf("\nPressione qualquer tecla para sair...");
		getch();
		system("cls");
}

TLista *Remover(TLista *p){
	if(p==NULL){
		printf("LISTA VAZIA!");
		printf("\nPressione qualquer tecla para sair...");
		getch(); system("cls");
	} 
	else{
		int n;
		TLista *aux = p;
		printf("Buscar elemento: ");
		scanf("%d", &n); fflush(stdin);
		if(p->num==n && p->ant==NULL && p->prox==NULL){
			TLista *aux = p;
			free(aux);
			p = NULL;
		}
		else{
			while(aux!=NULL){
				if(aux->num==n){
					//INICIO
					if(aux->ant==NULL){
						aux=aux->prox;
						p = aux;
						free(aux->ant);
						aux->ant = NULL;
					}
					//MEIO
					
					
					//FIM
					if(aux->prox==NULL){
						aux=aux->ant;
						free(aux->prox);
						aux->prox = NULL;
						aux=aux->prox;
					}				
				}else{
					aux=aux->prox;
				}
			}
		}
	}
	return p;
}

void Liberar(TLista *p){
	p = p->prox;
	do{
		free(p->ant);
		p = p->prox;
	} while(p->prox!=NULL);
	printf("LISTA LIBERADA COM SUCESSO!");
	printf("\nPressione qualquer tecla para sair...");
	getch(); system("cls");
}

int main (){
	TLista *p = NULL;
	char op;
	do{
		printf("\n[1] Inserir Elemento\n[2] Vizualizar Lista\n[3] Remover Elemento\n[4] Liberar lista\n[0] Sair\n");
		op = getch();
		switch(op){
			case '1':
				system("cls");
				p = Inserir(p);
				break;
			case '2':
				system("cls");
				Vizualizar(p);
				break;
			case '3': 
				system("cls");
				p = Remover(p);
				break;
			case '4': 
				system("cls");
				break;
			case '0': return 0;
			default: 
				system("cls");
				printf("VALOR INVALIDO ! TECLE UMA DAS OPCOES ABAIXO !");
		}
	} while(op!='0');
	
	return 0;
}
