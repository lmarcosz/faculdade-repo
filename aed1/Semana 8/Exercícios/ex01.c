#include <stdio.h>
#include <stdlib.h>
#define MAX_LINHA 100

//Implementacao de matriz esparsa
typedef struct no *pme;
struct no{
	int col, val;
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

//Insere na matriz
void Inserir(matriz m,int l, int c, int val){
	pme aux;
	pme novo = (pme) malloc(sizeof(struct no));
	novo->col = c;
	novo->val = val;
	novo->prox = NULL;
	if(m[l]==NULL){
		m[l] = novo;
	}
	else{
		aux = m[l];
		while(aux->prox!=NULL){
			aux = aux->prox;
		}
		aux->prox = novo;
	}
}

//Imprime matriz
void Imprimir(matriz m, int lin, int col){
	int i, j;
	pme aux;
	printf("Matriz:\n\n");
	for(i=0;i<lin;i++){
		aux = m[i];
		for(j=1;j<=col;j++){
			if(aux!=NULL && aux->col==j){
				printf("%d ", aux->val);
				aux = aux->prox;
			}
			else{
				printf("0 ");
			}
		}
		printf("\n");
	}
}

//Liberar matriz
void Liberar(matriz m, int l){
	pme p, q;
	int i;
	for(i=0;i<l;i++){
		p = m[i];
		while(p!=NULL){
			q = p;
			p = p->prox;
			free(q);
		}
	}
}

int main (){
	int lin, col, i, j, val, l, c, max;
	matriz m;
	
	do{
		printf("Insira o numero de linhas: "); scanf("%d", &lin);	
	}while(lin<1 || lin>MAX_LINHA);
	do{
		printf("Insira o numero de colunas: "); scanf("%d", &col);
	}while(col<1);
	Inicializar(m, lin);
	system("cls");
	
	do{
		printf("Deseja inserir quantos numeros na matriz ?(entre 0 e %d):", lin*col);
		scanf("%d", &max);
		if(max<0 || max>(lin*col)){
			system("cls");
			printf("VALOR INCORRETO ! INSIRA OUTRO!\n");
		}
	} while(max<0 || max>(lin*col));
	
	if(max>0){
		for(i=0;i<max;i++){
			system("cls");
			printf("Valor desejado: ");
			scanf("%d", &val);
			do{
				printf("Linha(de 1 a %d): ", lin);
				scanf("%d", &l);
				if(l<1 || l>lin){
					printf("VALOR INCORRETO! INSIRA NOVAMENTE\n");
				}
			} while(l<1 || l>lin);
			
			do{
				printf("Coluna(de 1 a %d): ", col);
				scanf("%d", &c);
				if(c<1 || c>lin){
					printf("VALOR INCORRETO! INSIRA NOVAMENTE\n");
				}
			} while(c<1 || c>col);
			
			Inserir(m, l-1, c, val);
		}
	}
	system("cls");
	
	Imprimir(m, lin, col);
	
	Liberar(m, lin);
	return 0;
}
