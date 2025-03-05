//Nome: Marcos Lucas da Silva (140782)
//Data: 08/08/20
//Semana 1 - Exercício 03
#include <stdio.h>
#include <stdlib.h>

//Estrutura do tipo T_Pessoa
typedef struct{
	char nome[30];
	int idade;
	double altura;
}T_Pessoa;

//Impressão das saídas
void Imprima_Dados(T_Pessoa *ptr,int n){
	int i;
	system("cls");
	for(i=0;i<n;i++){
		printf("[DADOS DA PESSOA %d]", i+1);
		printf("\nNome: %s", ptr[i].nome);
		printf("\nIdade: %d ano(s)", ptr[i].idade);
		printf("\nAltura: %.2lf m\n\n", ptr[i].altura);	
	}
	free(ptr);
}

int main () {
	int n, i;
	printf("INSIRA A QUANTIDADE DE PESSOAS: "); scanf("%d", &n); //Entrada da quantidade de pessoas
	if(n<=0){
		system("cls");
		printf("[DADOS VAZIOS]");
	} else {
		T_Pessoa estrutura[n];
		
		//Entradas dos dados de cada pessoa
		for(i=0;i<n;i++){
			system("cls");
			printf("[INSIRA OS SEGUINTES DADOS DA PESSOA %d]\n", i+1);
			printf("Nome: "); scanf("%s", estrutura[i].nome); fflush(stdin); //Limpa buffer
			printf("Idade: "); scanf("%d", &estrutura[i].idade);
			printf("Altura(em m): "); scanf("%lf", &estrutura[i].altura);
		}
		fflush(stdin); //Limpa buffer
		Imprima_Dados(&estrutura[0], n); //Chama a função para imprimir as saídas
	}
	return 0;
}
