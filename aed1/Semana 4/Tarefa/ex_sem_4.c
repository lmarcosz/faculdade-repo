//Nome: Marcos Lucas da Silva (RA:140782)
//AED I - Integral 2020/1
//Tarefa da Semana 4 - 30/08/2020
#include <stdio.h>
#include <stdlib.h>
#define MAX_FILA 100

typedef struct{ //Estrutura tipo TCandidato
	int id;
	int nota;
}TCandidato;

typedef struct{ //Estrutura tipo TFila
	TCandidato candidato[100];
	int n;
	int ini;
}TFila;
//=========================================================================
TFila *nova_fila(){ //Função para criar uma fila
	TFila *nf = (TFila *) malloc(sizeof(TFila));
	nf->n = 0;
	nf->ini = 0;
	return nf;
}

int Insere_fila(TFila *p, TCandidato val){ //Função para inserir na fila
	int fim;
	if(p==NULL){
		printf("FILA NAO INICIALIZADA!"); return -1;
	}
	if(p->n == MAX_FILA){
		printf("FILA CHEIA!"); return -1;
	}
	fim = (p->ini+p->n)%MAX_FILA;
	p->candidato[fim] = val;
	p->n++;
	return 0;
}

TCandidato Retira_fila(TFila *p){ //Função para retirar da fila
	TCandidato val;
	if(p==NULL){
		printf("FILA NAO INICIALIZADA!"); exit(-1);
	}
	if(p->n == 0){
		printf("FILA VAZIA!"); exit(-1);
	}
	val = p->candidato[p->ini];
	p->ini = indice(p->ini);
	(p->n)--;
	return val;
}

int indice(int i){ //Correcao para garantir a fila circular
	if(i==MAX_FILA-1){
		return 0;
	} else{
		return i+1;
	}
}

void Listar_fila(TFila *p){ //Função para listar uma fila
	int i;
	for(i=0;i<p->n;i++){
		printf("\nID: %d, Nota: %d", p->candidato[i].id, p->candidato[i].nota);
	}
}
//=======================================================================
int main(){
	int i, k ,n_cand, n_vagas;
	char resp;
	
	printf("Numero de candidatos: "); scanf("%d", &n_cand); //Entrada: Número de candidatos
	if(n_cand<=0){
		return -1;		
	}
	printf("Numero de vagas: "); scanf("%d", &n_vagas); //Entrada: Número de vagas
	if(n_vagas<=0){
		return -1;
	}
	
	TCandidato candidato[n_cand], aux, *ptr=NULL; //Vetores para auxiliar no armazenamento das informações
	TFila *classif = nova_fila(); //Criando a fila de classificação
	TFila *vagas = nova_fila();
	
	for(i=0;i<n_cand;i++){
		printf("\nID do candidato: "); scanf("%d", &candidato[i].id); //Entrada: ID do candidato
		do{
			printf("Nota: ", candidato[i].id); scanf("%d", &candidato[i].nota); //Entrada: nota do candidato
		} while(candidato[i].nota < 0 || candidato[i].nota > 100);
		printf("CANDIDATO INSERIDO!\n");
		fflush(stdin);
	}
	
	for(i=0;i<n_cand;i++){ //Ordenando o vetor
		for(k=i+1;k<n_cand;k++){
			if(candidato[i].nota < candidato[k].nota){
				aux = candidato[i];
				candidato [i] = candidato[k];
				candidato[k] = aux;
			}
		}
	}
	for(i=0;i<n_cand;i++){ //Implementando os elementos do vetor ordenado em uma fila
		Insere_fila(classif, candidato[i]); 
	}
	
	printf("\n===== CLASSIFICACAO =====");
	Listar_fila(classif); //Saida: listando os candidatos na classificação
	printf("\n===========================");
	
	k=0;
	for(i=0;i<n_cand;i++){ //Convite para os candidatos
			printf("\nCandidato %d\n[s] Matricular\n[n] Nao matricular\nPressione uma das teclas: ", candidato[i].id);
			do{
				resp = getche(); fflush(stdin); //Entrada: Resposta do candidato
			} while(resp!='s' && resp!='n');
			
			if(resp=='s'){ //Se aceitar, inserir o candidato na fila de vagas
				Insere_fila(vagas, Retira_fila(classif)); //Inserção na fila de vagas
				k++;
			} else{	
				if(resp=='n'){ //Se não aceitar, não inserir o candidato na fila de vagas
					Retira_fila(classif);
				}
			}
			if(k==n_vagas){ //Quando o numero de vagas for preenchido, sair do laço
				break;
			}
	}
	
	printf("\n======NOVOS ALUNOS=====");
	Listar_fila(vagas); //Saida: listando os alunos matriculados
	free(classif);
	free(vagas);
	return 0;
}
