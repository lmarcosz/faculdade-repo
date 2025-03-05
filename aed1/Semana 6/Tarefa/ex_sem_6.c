//Nome: Marcos Lucas da Silva (RA:140782)
//AED I - Intetral (ADE) 2020/1
//Tarefa Semana 6
#include <stdio.h>
#include <stdlib.h>

//Estrutura tipo lista
typedef struct lista{
	int id;
	int pont;
	struct lista *prox;
}TLista;

//Função para inserir uma lista
TLista *Inserir(TLista *ultimo, int n){
	int i;
	for(i=n;i>0;i--){
		TLista *novo = (TLista *) malloc(sizeof(TLista));
		novo->id = i;
		if(ultimo==NULL){
			ultimo = novo;
			novo->prox = novo;
		} else{
			novo->prox = ultimo->prox;
			ultimo->prox = novo;
		}
	}
	return ultimo;
}

//Função para inserir as cartas
TLista *Cartas(TLista *p, int n){
	int i;
	char op[2];
	for(i=1;i<=n;i++){
		do{
			printf("Carta do jogador %d [2 a 9,A,K,Q ou J]: ", p->id);
			scanf("%[^\n]", op);
			fflush(stdin); //Limpador de buffer
			if(op)
			switch(op[0]){
				case '2': p->pont += 2;  break;
				case '3': p->pont += 3; break;
				case '4': p->pont += 4;  break;
				case '5': p->pont += 5; break;
				case '6': p->pont += 6;  break;
				case '7': p->pont += 7; break;
				case '8': p->pont += 8; break;
				case '9': p->pont += 9; break;
				case '1':
					if(op[1]=='0'){
						p->pont += 10; break;
					}
					else{
						op[0] = 'E'; system("cls");
						printf("CARTA INVALIDA! DIGITE NOVAMENTE!\n");
					}
				break;
				case 'K': p->pont += 10; system("cls"); break;
				case 'Q': p->pont += 10; system("cls"); break;
				case 'J': p->pont += 10; system("cls"); break;
				case 'A': p->pont += 11; system("cls"); break;
				default: 
					op[0] = 'E'; system("cls");
					printf("CARTA INVALIDA! DIGITE NOVAMENTE!\n");
			}
		} while(op[0]=='E');
		if(i!=n){
			p = p->prox;
		}
	}
	return p;
}

//Função para imprimir pontuação
int Pontuacao(TLista *p, int n){
	int i;
	for(i=1;i<=n;i++){
		printf("\nJogador: %d | Pontuacao: %d", p->id, p->pont);
		p = p->prox;
	}
	
	for(i=1;i<=n;i++){
		if(p->pont == 21){
			printf("\n\nJogador %d VENCEDOR !!!", p->id);
			return 1;
		}
		p = p->prox;
	}	
	printf("\n\n");
	return 0;
}

//Função para remover uma lista
TLista *Pop(TLista *p, int n){
	int i;
	TLista *aux;
	if(p==NULL){
		printf("Lista vazia!!"); exit(-1);
	} else{	
		for(i=1;i<=n;i++){
			aux = p->prox;
			if(aux>21){
				p = aux->prox;
				aux=NULL;
				free(aux);
			}
			p = p->prox;
		}
		return p;
	}
}

//Função para liberar a memória ocupada pela lista
void Liberar(TLista *p, TLista *q){
	TLista *aux = q->prox;
	do{
		free(q);
		q = aux;
		aux = q->prox;
	} while(aux!=p);
	free(p);
}

int main (){
	int i, n, aux, *ptr=NULL;
	TLista *p = NULL;
	do{
		printf("Quantidade de Jogadores: "); scanf("%d", &n); fflush(stdin); //Entrada: quantidadee de jogadores
		if(n<2){
			system("cls"); printf("VALOR INVALIDO ! DIGITE NOVAMENTE !\n");
		}
	} while(n<2); 
	system("cls");
	
	p = Inserir(p, n); //é atribuído em p o ultimo elemento da lista
	
	do{
		p = Pop(p, n); //Remover um elemento da lista
		p = Cartas(p->prox, n); //Inserir cartas
		aux = Pontuacao(p->prox, n); //Imprime a pontuação
	} while(aux==0);
	Liberar(p, p->prox); //Libera toda a lista
	return 0;
}
