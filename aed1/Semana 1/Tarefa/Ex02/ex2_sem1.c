//Nome: Marcos Lucas da Silva (140782)
//Data: 08/08/20
//Semana 1 - Exercício 02
#include <stdio.h>
#include <stdlib.h>

//Estrutura do tipo T_Pessoa
typedef struct{
	char nome[30];
	int idade;
	double altura;
}T_Pessoa;

void Imprima_Dados(T_Pessoa *ptr){
	system("cls");
	//Saídas
	printf("[DADOS]");
	printf("\nNome: %s", ptr->nome);
	printf("\nIdade: %d ano(s)", ptr->idade);
	printf("\nAltura: %.2lf m", ptr->altura);	
	free(ptr);
}

int main () {
	T_Pessoa *estrutura = (T_Pessoa *) malloc(sizeof(T_Pessoa));
	//Entradas
	printf("[INSIRA OS SEGUINTES DADOS]\n");
	printf("Nome: "); scanf("%[^\n]", estrutura->nome); fflush(stdin); //Limpa buffer
	printf("Idade: "); scanf("%d", &estrutura->idade);
	printf("Altura(em m): "); scanf("%lf", &estrutura->altura);
	
	Imprima_Dados (estrutura); //Chama a função para imprimir os dados
	
	free(estrutura);
	return 0;
}
