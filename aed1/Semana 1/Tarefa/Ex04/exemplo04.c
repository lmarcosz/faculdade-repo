//Nome: Marcos Lucas da Silva (140782)
//Data: 10/08/20
//Semana 1 - Exercício 04
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Gravar(){
	char nome[30];
	int qtd, i=1;
	FILE *arquivo = fopen("arquivo_nomes.txt", "w");
	if(arquivo == NULL){
		printf("Nao foi possivel abrir o arquivo!");
		system("pause"); exit(0);
	}
	do{
		printf("Nome [%d]: ", i); scanf("%s", nome);
		if(strcmp(nome, "FIM")!=0){
			fprintf(arquivo,"%s ", nome);
		}
		i++;
	} while(strcmp(nome, "FIM")!=0);
	fclose(arquivo); system("cls");
}

int Buscar(char nome[]){
	char str[30];
	int i=0;
	FILE *arquivo = fopen("arquivo_nomes.txt", "r");
	if(arquivo == NULL){
		printf("Nao foi possivel abrir o arquivo!");
		system("pause"); exit(0);
	}
	while(fscanf(arquivo,"%s ",str)!=EOF){
		if(strcmp(str,nome)==0){
			i++;
		}
	}
	fclose(arquivo);
	return i;
}

int main (){
	char nome[30];
	int qtd;
	Gravar();
	printf("Buscar: "); scanf("%s", nome);
	qtd = Buscar(nome);
	printf("Registros com esse nome: %d", qtd);
	return 0;
}
