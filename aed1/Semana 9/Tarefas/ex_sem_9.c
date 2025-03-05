//Nome: Marcos Lucas da Silva (RA:140782)
//AED I - Intetral (ADE) 2020/1
//Tarefa da Semana 9 - Grafos
#include <stdio.h>
#include <stdlib.h>

int main (){
	int num_v;
	char op;
	char e[7];
	
	do{
		printf("\nNumero de vertices: ");
		scanf("%d", &num_v);
		fflush(stdin);
		if(num_v<0){
			system("cls");
			printf("ERRO! INFORME UM NUMERO VALIDO!(>=0)");
		} else{
			system("cls");
		}
	} while(num_v<0);
	
	do{
		printf("\Escolha uma das opcoes\n[1] Grafo ORIENTADO\n[2] Grafo NAO ORIENTADO\n");
		op = getch();
		if(op!='1' && op!='2'){
			system("cls");
			printf("ERRO! DIGITE UMA OPCAO VALIDA! (1 ou 2)");
		} else{
			system("cls");
		}
	} while(op!='1' && op!='2');
	
	if(op=='1'){
		
		
		
		
		
	}
	if(op=='2'){
		
		
		
		
		
	}
	
	return 0;
}
