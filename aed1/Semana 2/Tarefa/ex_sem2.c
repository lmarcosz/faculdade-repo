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
	int *votos = (int *) calloc(n, sizeof(int)); //Alocação inicial do vetor votos (com todas as posições zeradas)
	if(!votos){
		printf("Nao foi possivel alocar memoria !"); exit(1); //Verificação para erro na alocação
	}
	
	int *p, aux, i=1;
	p = votos; //Ponteiro 'p' apontando para o inicio do vetor 'votos'
	
	do{
		printf("===== ELEICOES 2020 =====\n\nVoto[%d]: ", i); scanf("%d", &aux); //Entrada: votos
		if(aux>=1 & aux<=n){
			*(p+(aux-1))+= 1; //Ponteiro somando voto de acordo com o numero do candidato
			system("cls"); i++; //Soma do contador 'i' para indicar a quantidade de votos
		} else{
			if(aux>n){ //Condição para erro (quando o numero do candidato nao existir)
				system("cls");
			}
		}
	} while(aux>0); //Condição para encerrar a votação
//==========================================================
	int vencedor;
	p = votos;
	for(i=0;i<n;i++){ //Verificação do vencedor
		if(i==0){
			vencedor = i; //Posição inicial
		} 
		else{
			if(*(p+vencedor) <= *(p+i)){ //Comparação com a posição seguinte
				vencedor = i; //Atribuição
			}	
		}
	}
//=========================================================
	system("cls");
	printf("===== ELEICOES 2020 =====\n\nCandidato numero %d ELEITO", vencedor+1); //Saida: numero do candidato vencedor
	
	free(votos); //Libera memória do vetor
	p = NULL; //Posiciona o ponteiro para nulo
	return 0;
}
