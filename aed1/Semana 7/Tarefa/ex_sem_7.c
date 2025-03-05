//Nome: Marcos Lucas da Silva (RA: 140782)
//AED I - Integral (ADE) - 2020/1
//Tarefa da semana 7 - Lista duplamente encadeada - 22
#include <stdio.h>
#include <stdlib.h>

//Estrutura da lista
typedef struct list{
	char letra;
	struct list *ant;
	struct list *prox;
}TLista;

//Funcao para inserir a letra em cada lista
TLista *Inserir(TLista *p, char letra){
	TLista *novo = (TLista *) malloc(sizeof(TLista));
	novo->ant = NULL;
	novo->prox = NULL;
	novo->letra = letra;
	if(p==NULL){
		p = novo; //Insercao do nó caso a lista esteja vazia
	}
	else{
		TLista *aux = p;
		while(aux->prox!=NULL){
			aux = aux->prox;
		}
		aux->prox = novo;
		novo->ant = aux; //Insercao do nó no final da lista
	}
	return p;
}

//Funcao para visualizar a palavra
void Visualizar(TLista *p){
	TLista *aux = p;
	printf("\nPalavra: ");
	while(aux!=NULL){
		printf("%c", aux->letra); //Imprime a palavra
		aux=aux->prox;
	}
	printf("\n");
}

//Funcao de verificacao
int Verificar(TLista *p, char op){
	TLista *aux = p;
	while(aux!=NULL){
		if(aux->letra==op){
			return 1; //Retorna o valor 1 se a palavra tiver a letra inserida pelo usuario
		}
		aux=aux->prox;
	}
	free(aux);
	return 0; //Retorna o valor 1 se a palavra nao tiver a letra inserida pelo usuario
}

//Funcao para trocar as letras
TLista *trocaLetras(TLista *p,char op1,char op2){
	TLista *aux = p;
	while(aux!=NULL){ //Verifica ate o final da lista
		if(aux->letra==op1){ //Se achar a letra da palavra igual a letra 1
			aux->letra = op2; //Troca a letra 1 pela letra 2
			aux = aux->prox; //Vai para o proximo no
		} 
		else{
			if(aux->letra==op2){ //Se achar a letra da palavra igual a letra 2
				aux->letra = op1; //Troca a letra 2 pela letra 1
				aux = aux->prox; //Vai para o proximo no
			}
			else{ //Nenhuma condicao safisfeita
				aux = aux->prox; //Vai para o proximo no
			}
		}
	}
	return p; //Retorna a lista atualizada
}

//Funcao para liberar toda a memoria da lista
void Kill(TLista *p){
	if(p!=NULL){
		Kill(p->prox);
	}
	free(p);
}

//Funcao main
int main (){
	int i, aux;
	char palavra[20], op1, op2;
	TLista *p = NULL; //Inicializacao da lista
	
	printf("======TROCA LETRAS=====\n\n");
	printf("Digite uma palavra: ");
	scanf("%[^\n]", palavra); //Entrada: palavra
	fflush(stdin); //Limpa buffer
	system("cls"); //Limpa tela
	
	//Insercao de cada letra da string em uma lista
	for(i=0;palavra[i]!='\0';i++){
		p = Inserir(p, palavra[i]);
	}
	
	//Verifica se a letra 1 inserida existe na palavra
	do{
		Visualizar(p); //Imprime a palavra
		printf("\nTecle a Letra 1: "); 
		scanf("%c", &op1); //Entrada: letra 1
		fflush(stdin);
		aux = Verificar(p, op1);
		system("cls");
		if(aux==0){
			printf("LETRA NAO ENCONTRADA! TECLE NOVAMENTE!"); //Mensagem de aviso
		}
	} while(aux==0);
	
	//Verifica se a letra 2 inserida existe na palavra e nao seja igual a letra 1
	do{
		Visualizar(p); //Imprime a palavra
		printf("\nTecle a Letra 2: "); 
		scanf("%c", &op2);  //Entrada: letra 2
		fflush(stdin);
		if(op1==op2){
			system("cls");
			printf("LETRAS IGUAIS! TECLE UMA LETRA DIFERENTE DA LETRA 1!"); //Mensagem de aviso
		} else{
			aux = Verificar(p, op2);
			system("cls");
			if(aux==0){
				printf("LETRA NAO ENCONTRADA! TECLE NOVAMENTE!"); //Mensagem de aviso
			}
		}
	} while(aux==0 || op1==op2);
	
	p = trocaLetras(p, op1, op2); //Chama a funcao para realizar a troca das letras
	Visualizar(p); //Imprime a palavra atualizada
	Kill(p); //Libera a lista
	system("pause");
	return 0;
}
