//Nome: Marcos Lucas da Silva (RA: 140782)
//Turma: AED I - Integral
//17/08/20 - Tarefa da Semana 2
#include <stdio.h>
#include <stdlib.h>

int main (){
	int n;
	printf("===== ELEICOES 2020 =====\n\nQuantidade de candidatos: ");
	scanf("%d",&n); //Entrada: Quantidade de candidatos
	
	if(n<1){
		exit(0); //Fim do programa se a quantidade de candidatos for negativa ou nula
	}
	system("cls"); //Limpa tela
	
	if(n==1){
		printf("===== ELEICOES 2020 =====\n\nCandidato: %d ELEITO", 1); //Saida: numero do candidato vencedor (caso n=1)
		exit(0);
	}
//========================================================
	int *votos = (int *) calloc(n, sizeof(int)); //Aloca��o inicial do vetor votos (com todas as posi��es zeradas)
	if(!votos){
		printf("Nao foi possivel alocar memoria !"); exit(1); //Verifica��o para erro na aloca��o
	}
	
	int *p, aux, i=1;
	p = votos; //Ponteiro 'p' apontando para o inicio do vetor 'votos'
	
	do{
		printf("===== ELEICOES 2020 =====\n\nVoto[%d]: ", i); scanf("%d", &aux); //Entrada: votos
		if(aux>=1 & aux<=n){
			*(p+(aux-1))+= 1; //Ponteiro somando voto de acordo com o numero do candidato
			system("cls"); i++; //Soma do contador 'i' para indicar a quantidade de votos
		} else{
			if(aux>n){ //Condi��o para erro (quando o numero do candidato nao existir)
				system("cls");
			}
		}
	} while(aux>0); //Condi��o para encerrar a vota��o
//==========================================================
	int vencedor;
	p = votos;
	for(i=0;i<n;i++){ //Verifica��o do vencedor
		if(i==0){
			vencedor = i; //Posi��o inicial
		} 
		else{
			if(*(p+vencedor) <= *(p+i)){ //Compara��o com a posi��o seguinte
				vencedor = i; //Atribui��o
			}	
		}
	}
//=========================================================
	system("cls");
	printf("===== ELEICOES 2020 =====\n\nCandidato numero %d ELEITO", vencedor+1); //Saida: numero do candidato vencedor
	
	free(votos); //Libera mem�ria do vetor
	p = NULL; //Posiciona o ponteiro para nulo
	return 0;
}
