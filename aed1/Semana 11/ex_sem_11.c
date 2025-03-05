//Nome: Marcos Lucas da Silva (RA: 140782)
//AED I - (ADE 2020/1)
//Tarefa da semana 11 - �rvore Bin�ria de Busca

int verf_se_ABB(PArv a){
	if(a==NULL){ //Quando a chega no final, � ABB
		return 1;
	}
	else if(a->info > a->esq){
		verf_se_ABB(a->esq); //Percorre p/ a esquerda de info for maior que o pr�ximo da esquerda
	}
	else if(a->info < a->dir){
		verf_se_ABB(a->dir); //Percorre p/ a direita de info for menor que o pr�ximo da direita
	}
	else{
		return 0; //Nenhuma das op��es, n�o � ABB (INV�LIDO !)
	}
}


PArv une_ABB(PArv a, PArv b){
	if(a->info == b->info){ //Se forem iguais, os dois percorrem juntos
		une_ABB(a->esq, b->esq);
		une_ABB(a->dir, b->dir);
	}
	else if(a->info > b->info){
		une_ABB(a->esq, b); //Se info a for maior que info b, no final da recurs�o, a esquerda recebe b
		a->esq = b;
	}
	else if(a->info < b->info){
		une_ABB(a->dir, b); //Se info a for menor que info b, no final da recurs�o, a direita recebe b
		a->dir = b;
	}
	return a; //A uni�o entre a e b � moldada no a
}
