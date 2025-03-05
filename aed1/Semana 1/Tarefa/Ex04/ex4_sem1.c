//Nome: Marcos Lucas da Silva (140782)
//Data: 10/08/20
//Semana 1 - Exerc�cio 04
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Gravar(){ //FUN��O PARA GRAVAR OS NOMES 
	system("cls");
	char nome[30];
	int qtd, i=1;
	FILE *arquivo = fopen("arquivo_nomes.txt", "w");
	if(arquivo == NULL){
		printf("=====GRAVAR=====\n\nNao foi possivel abrir o arquivo!"); //Mensagem para erro
		system("pause"); exit(0);
	}
	printf("=====GRAVAR=====\n");
	do{
		printf("Nome [%d]: ", i); scanf("%s", nome);
		if(strcmp(nome, "FIM")!=0){
			fprintf(arquivo,"%s ", nome); //Grava��o dos nomes no arquivo (n�o permanente)
		}
		i++;
	} while(strcmp(nome, "FIM")!=0);
	fclose(arquivo); system("cls");
	main();
}

int Buscar(char nome[]){ //FUN��O PARA BUSCAR OS NOMES E RETORNAR A QUANTIDADE ENCONTRADA
	system("cls");
	char str[30];
	int i=0;
	FILE *arquivo = fopen("arquivo_nomes.txt", "r");
	if(arquivo == NULL){
		printf("=====BUSCAR=====\n\nNao foi possivel abrir o arquivo!"); //Mensagem para erro
		system("pause"); exit(0);
	}
	while(fscanf(arquivo,"%s ",str)!=EOF){
		if(strcmp(str,nome)==0){
			i++; //Busca dos nomes do arquivo semelhantes ao passado na string por refer�ncia
		}
	}
	fclose(arquivo);
	return i;
}

int main (){
	char op, nome[30];
	int qtd;
	system("cls");
	printf("=====MENU=====\n[1]Gravar\n[2]Buscar\n[0]Sair\n\n"); op = getch(); fflush(stdin); //MENU DO PROGRAMA
	switch(op){ //a��es das op��es escolhidas no menu
		case '1': Gravar(); break;
		case '2': system("cls"); printf("=====BUSCAR=====\nBuscar: "); scanf("%s", nome); 
				  qtd = Buscar(nome); //quantidade de nomes encontrados
		          printf("=====BUSCAR=====\n\nRegistros com esse nome: %d\n\n", qtd); //Sa�da
				  system("pause"); main(); break;
		case '0': break;
		default: main();
	}
	return 0;
}
