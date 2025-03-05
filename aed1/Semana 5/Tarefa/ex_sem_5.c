//Nome: Marcos Lucas da Silva (RA:140782)
//AED I - Integral (ADE)
//05/09/20 - Semana 5 - Tarefa de Lista Encadeada
#include <stdio.h>
#include <stdlib.h>

//Estrutura tipo lista
typedef struct lista{
	int cod;
	char nome[30];
	float preco;
	struct lista *prox;
}TLista;

//Fun��o para inserir produto
void Insere(TLista **p){
	TLista *nova;
	nova = (TLista *) malloc(sizeof(TLista));
	printf("Codigo: "); scanf("%d", &nova->cod); //Entradas de inser��o
	printf("Nome: "); scanf("%s", nova->nome); fflush(stdin);
	printf("Preco: R$  "); scanf("%f", &nova->preco);
	
	TLista *aux = *p;
	TLista *auxx = NULL;
	
	while(aux!=NULL && nova->cod > aux->cod){
		auxx = aux;
		aux = aux->prox;
	}
	if(aux==NULL){
		nova->prox = *p;
		*p = nova;
	} 
	else{
		nova->prox = auxx->prox;
		auxx->prox = nova;
	}
	printf("\nProduto inserido com sucesso!\n");
}

//Fun��o para buscar o pre�o do produto
void Buscar(TLista *p){
	TLista *aux;
	int cod;
	float valor=-1;
	printf("Codigo: "); scanf("%d", &cod); //Entrada: codigo do produto a ser buscado
	for(aux=p;aux!=NULL;aux = aux->prox){
		if(aux->cod == cod){
			valor = aux->preco;
		}
	}
	if(valor==-1){
		printf("Produto nao encontrado!\n"); //Caso o produto nao seja encontrado
	} else{
		printf("R$ %.2f\n", valor); //Saida: caso seja encontrado
	}
	system("pause");
}

//Fun��o para excluir produto
int Excluir(TLista **p){
	int v;
	printf("Codigo: "); scanf("%d", &v); //Entrada: codigo do produto a ser excluido
	TLista *ant=NULL;
	TLista *aux;
	for(aux=*p;aux!=NULL && aux->cod!=v;aux=aux->prox){
		ant = aux;
	}
	if(aux==NULL){
		printf("Produto nao encontrado!\n"); return -1; //Caso o produto n�o seja encotrado
	} 
	if(ant==NULL){
		*p = aux->prox;
	} else{
		ant->prox = aux->prox;
	}
	free(aux); //Libera��o do n�
	printf("Produto excluido com sucesso!\n");
	return 0;
}

//Fun��o para excluir toda a lista (recursiva)
void Kill(TLista *p){
	if(p!=NULL){
		Kill(p->prox);
		free(p); //Libera��o do n�
	}
}

int main (){
	TLista *produto = NULL; //Inicializando a cabe�a da lista
	char op;
	do{
		printf("== M E N U ==\n[1] Inserir\n[2] Buscar\n[3] Excluir\n[4] Deletar lista\n[0] Sair\n\n(Pressione uma das teclas)\n");
		op = getche(); fflush(stdin); //Op��o do menu (basta somente apertar a tecla para a op��o desejada)
		switch(op){
			case '1':
				system("cls"); //Apagar tela
				Insere(&produto); //Fun��o para inserir produto
				system("pause"); //Pausar programa para visualizar a sa�da
			break;
			case '2':
				system("cls"); //Apagar tela
				Buscar(produto); //Fun��o para buscar o pre�o do produto
			break;
			case '3': 
				system("cls"); //Apagar tela
				Excluir(&produto); //Fun��o para excluir produto
				system("pause"); //Pausar programa para visualizar a sa�da
			break;
			case '4': 
				system("cls"); //Apagar tela
				Kill(produto); //Fun��o para apagar toda a lista
				printf("Lista deletada!\n");
				system("pause"); //Pausar programa para visualizar a sa�da
			break;
			case '0': break; //Op��o para sair do la�o
		}
		system("cls");
	} while(op!='0'); //Enquanto a tecla de op��o n�o for igual a 0, o menu continua aparecendo
	Kill(produto); //Libera toda a memoria da lista criada
	return 0;
}
