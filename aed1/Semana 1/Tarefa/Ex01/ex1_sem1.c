//Nome: Marcos Lucas da Silva (140782)
//Data: 06/08/20
//Semana 1 - Exercício 01
#include <stdio.h>
#include <stdlib.h>

//Estrutura do tipo T_Pessoa
typedef struct{
	char nome[30];
	int idade;
	double altura;
}T_Pessoa;

int main () {
	T_Pessoa *estrutura = (T_Pessoa *) malloc(sizeof(T_Pessoa));
	
	//Entradas
	printf("[INSIRA OS SEGUINTES DADOS]\n");
	printf("Nome: "); scanf("%[^\n]", estrutura->nome); fflush(stdin); //Limpa buffer
	printf("Idade: "); scanf("%d", &estrutura->idade);
	printf("Altura(em m): "); scanf("%lf", &estrutura->altura);
	system("cls");
	//Saídas
	printf("[DADOS]");
	printf("\nNome: %s", estrutura->nome);
	printf("\nIdade: %d ano(s)", estrutura->idade);
	printf("\nAltura: %.2lf m", estrutura->altura);
	
	free(estrutura);
	return 0;
}
