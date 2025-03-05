//Nome: Marcos Lucas da Silva (RA: 140782)
//AED I - Integral
//Exercício Semana 3 - Pilha Sequencial
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//=====================================================
//Estrutura tipo TPilha
typedef struct{
	float vet[30];
	int topo;
}TPilha;
//Função para criar uma pilha
TPilha *nova(){
	TPilha *np = (TPilha *) malloc(sizeof(TPilha));
	np->topo = -1;
	return np;
}

//Função para empilhar
int push(TPilha *p, float val){
	if(p->topo >= 30){
		printf("\nERRO AO EMPLIHAR!"); return -1;
	}
	(p->topo)++;
	p->vet[p->topo] = val;
	return 0;
}
//Função para desempilhar
float pop(TPilha *p){
	float val;
	if(p->topo < 0){
		return -1;
	}
	val = p->vet[p->topo];
	(p->topo)--;
	return val;
}
//======================================================
//Estrutura T_Pilha2 para guardar os operadores
typedef struct{
	char str[30];
	int topo2;
}T_Pilha2;

T_Pilha2* nova2(){
	T_Pilha2 *nptr = (T_Pilha2 *) malloc(sizeof(T_Pilha2));
	nptr->topo2 = -1;
	return nptr;
}

int push_2(T_Pilha2 *p, char val){
	if(p->topo2 >= 30){
		printf("\nERRO AO EMPLIHAR!"); return -1;
	}
	(p->topo2)++;
	p->str[p->topo2] = val;
	return 0;
}

char pop_2(T_Pilha2 *p){
	char val;
	if(p->topo2 < 0){
		printf("PILHA VAZIA!"); exit(-1);
	}
	val = p->str[p->topo2];
	p->topo2--;
	return val;
}

//Função para verificar o balanceamento dos parenteses
void Verif_Par(char *exp, int exp_quant){
	int i, aux;
	TPilha *parenteses = nova();
	if(!parenteses){
		printf("Erro de alocacao!"); exit(-1);
	}
	if(!parenteses){
		printf("Erro ao alocar memoria !"); exit(-1);
	}
	for(i=0;i<exp_quant;i++){
		if(exp[i]=='('){
			push(parenteses, i);
		}
		if(exp[i]==')'){
			if(parenteses->topo < 0){
				printf("\nEXPRESSÃO INVALIDA!"); exit(-1);
			} else{
				pop(parenteses);
			}
		}
	}
	if(parenteses->topo >= 0){
		printf("EXPRESSAO INVALIDA!"); exit(-1);
	}
	free(parenteses);
}

//Função transformar em pós-fixa
char* Pos_Fixa(char* exp, int exp_quant){
	int i,k=0, aux=1;
	char pos_fixa[30], val='0', *ptr;
	T_Pilha2 *p = nova2();
	if(!p){
		printf("Erro de alocacao!"); exit(-1);
	}
	for(i=0;i<exp_quant;i++){
		switch(exp[i]){ //condição quando encontrar operandos ou operadores
			case '0': pos_fixa[k] = '0'; k++; break;
			case '1': pos_fixa[k] = '1'; k++; break;
			case '2': pos_fixa[k] = '2'; k++; break;
			case '3': pos_fixa[k] = '3'; k++; break;
			case '4': pos_fixa[k] = '4'; k++; break;
			case '5': pos_fixa[k] = '5'; k++; break;
			case '6': pos_fixa[k] = '6'; k++; break;
			case '7': pos_fixa[k] = '7'; k++; break;
			case '8': pos_fixa[k] = '8'; k++; break;
			case '9': pos_fixa[k] = '9'; k++; break;
			case '(': push_2(p, exp[i]); break;
			case ')':
				while(val != '('){
					val = pop_2(p);
					pos_fixa[k] = val;
					k++;
				}
				pop_2(p);
			break;
			case '+':
				aux==1;
				do{
					if(p->topo2<0 || p->str[p->topo2]!='*' && p->str[p->topo2]!='/' && p->str[p->topo2]!='^' && p->str[p->topo2]!='(' && p->str[p->topo2]!=')'){
						aux = push_2(p, exp[i]);
					} else{
						pos_fixa[k] = pop_2(p);
						k++;
					}
				} while(aux!=0);
			break;
			case '-':
				aux==1;
				do{
					if(p->topo2<0 || p->str[p->topo2]!='*' && p->str[p->topo2]!='/' && p->str[p->topo2]!='^' && p->str[p->topo2]!='(' && p->str[p->topo2]!=')'){
						aux = push_2(p, exp[i]);
					} else{
						pos_fixa[k] = pop_2(p);
						k++;
					}
				} while(aux!=0);
			break;
			case '*':
				aux==1;
				do{
					if(p->topo2<0 || p->str[p->topo2]!='^' && p->str[p->topo2]!='(' && p->str[p->topo2]!=')'){
						aux = push_2(p, exp[i]);
					} else{
						pos_fixa[k] = pop_2(p);
						k++;
					}
				} while(aux!=0);
			break;
			case '/':
				aux==1;
				do{
					if(p->topo2<0 || p->str[p->topo2]!='^' && p->str[p->topo2]!='(' && p->str[p->topo2]!=')'){
						aux = push_2(p, exp[i]);
					} else{
						pos_fixa[k] = pop_2(p);
						k++;
					}
				} while(aux!=0);
			break;
			case '^':
				aux==1;
				do{
					if(p->topo2<0 || p->str[p->topo2]!='(' && p->str[p->topo2]!=')'){
						aux = push_2(p, exp[i]);
					} else{
						pos_fixa[k] = pop_2(p);
						k++;
					}
				} while(aux!=0);
			break;
		}
	}
	while(p->topo2 >= 0){
		pos_fixa[k] = pop_2(p);
		k++;
	}
	ptr = pos_fixa;
	printf("Expressao Pos-Fixa: %s", pos_fixa);
	free(p);
	return ptr;
}
//Função para calcular o resultado da expressão
int Resultado(char *p_fixa){
	int i;
	float res, aux;
	TPilha *calculo = nova();
	if(!calculo){
		printf("Erro de alocacao!"); exit(-1);
	}
	for(i=0;*p_fixa!='\0';i++){
		switch(*p_fixa){
			case '0': push(calculo, 0.0); break;
			case '1': push(calculo, 1.0); break;
			case '2': push(calculo, 2.0); break;
			case '3': push(calculo, 3.0); break;
			case '4': push(calculo, 4.0); break;
			case '5': push(calculo, 5.0); break;
			case '6': push(calculo, 6.0); break;
			case '7': push(calculo, 7.0); break;
			case '8': push(calculo, 8.0); break;
			case '9': push(calculo, 9.0); break;
			case '+':
				aux = pop(calculo);
				res = pop(calculo) + aux;
				push(calculo, res);
			break;
			case '-':
				aux = pop(calculo);
				res = pop(calculo) - aux;
				push(calculo, res);
			break;
			case '*':
				aux = pop(calculo);
				res = pop(calculo) * aux;
				push(calculo, res);
			break;
			case '/':
				aux = pop(calculo);
				res = pop(calculo) / aux;
				push(calculo, res);
			break;
			case '^':
				aux = pop(calculo);
				res = pow(pop(calculo), aux);
				push(calculo, res);
			break;
		}
		(p_fixa)++;
	}
	printf("\nResultado da Expressao: %.2f", calculo->vet[calculo->topo]);
	return 0;
}
//==========================Função MAIN=================================
int main (){
	char exp[30];
	char *ptr_fixa;
	//Entrada: Expressão infixada
	printf("Expressao Infixa: "); scanf("%[^\n]", exp); fflush(stdin);
	//Chama função dos parenteses
	Verif_Par(exp, strlen(exp));
	//Função Resultado que chama a função para transformar a expressão para pós-fixa
	Resultado(Pos_Fixa(exp, strlen(exp)));
	return 0;
}


