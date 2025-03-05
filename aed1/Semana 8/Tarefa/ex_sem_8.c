//Nome: Marcos Lucas da Silva (RA: 140782)
//AED I - Integral (ADE) - 2020/1
//Tarefa da semana 8 - Matriz Esparsa
#include <stdio.h>
#include <stdlib.h>
#define MAX_LINHA 100

typedef struct no *pme;
struct no{
	int col;
	char genero;
	pme prox;
};
typedef pme matriz[MAX_LINHA];

//Inicializa matriz
void Inicializar(matriz m, int lin){
	do{
		lin--;
		m[lin] = NULL;
	}while(lin>=0);
}

//Inserir matriz
void Inserir(matriz m, int i,int fa, char gen){
	pme aux;
	pme novo = (pme) malloc(sizeof(struct no));
	novo->col = fa-1;
	novo->genero = gen;
	novo->prox = NULL;
	if(aux==NULL){
		m[i] = novo;
	}
	else{
		aux = m[i];
		while(aux->prox!=NULL){
			aux = aux->prox;
		}
		aux->prox = novo;
	}
}

//Imprimir
void Imprimir(matriz m, int c, int f){
	int i, j;
	pme aux;
	printf("\nMatriz Inteira:\n");
	for(i=0;i<c;i++){
		aux = m[i];
		for(j=0;j<f;j++){
			if(aux!=NULL && aux->col==j){
				printf("1 ");
				aux = aux->prox;
			}
			else{
				printf("0 ");
			}
		}
	}
}

int main (){
	int f, c, i, j, n, cont, fa;
	char gen;
	matriz m;
	
	do{
		printf("Quantidade de filmes disponiveis no catalogo: ");
		scanf("%d", &f);
		fflush(stdin);
	} while(f<1);
	do{
		printf("\nQuantidade de clientes: ");
		scanf("%d", &c);
		fflush(stdin);
	} while(c<1 || c>MAX_LINHA+1);
	
	Inicializar(m, c);
	
	for(i=0;i<c;i++){
		do{
			printf("\nCliente %d assistiu quantos filmes ?: ", i+1);
			scanf("%d", &n);
			fflush(stdin);
		} while(n<0 || n>f);
		
		for(j=0;j<n;j++){
			do{
				printf("Numero do %do filme assistido: ", j+1);
				scanf("%d", &fa);
				fflush(stdin);
				if(fa<1 || fa>f){
					fa=0;
					printf("FILME INVALIDO\n");
				}
			} while(fa==0);
			
			
			do{
				printf("Genero do filme: ");
				scanf("%c", &gen);
				fflush(stdin);
				switch(gen){
					case 'A': break;
					case 'R': break;
					case 'S': break;
					case 'C': break;
					case 'M': break;
					case 'D': break;
					case 'F': break;
					case 'P': break;
					default: 
						printf("\nGenero invalido!\n");
						gen='0';
				}
			} while(gen=='0');
			Inserir(m,i,fa,gen);
		}
	}
	Imprimir(m, c, f);
	return 0;
}
