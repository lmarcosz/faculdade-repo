#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <time.h>


int main (){

	char texto[1000];
	char letra, opcao;
	int i=0, j, erros=0, acertos=0;
	float taxa;
	
	printf("====== T E X T O =======\n");
	scanf("%[^\n]", texto);
	fflush(stdin);
	
	printf("\n\n====== C O P I A R =======\n");
	
	clock_t start_time, end_time;
	
	while(texto[i] != '\0'){
		
		letra = getch();
		if(i==0){
			start_time = clock();
		}
		if(letra == texto[i]){
			printf("%c", letra);
			i++;
			acertos++;
		}
		else{
			system("cls");
			erros++;
			Beep(1800,100);
			printf("====== T E X T O =======\n");
			for(j=0;texto[j] != '\0';j++){
				printf("%c", texto[j]);
			}
			
			printf("\n\n\n====== C O P I A R =======\n");
			for(j=0;j<i;j++){
				printf("%c", texto[j]);
			}
		}
	}
	
    end_time = clock();
    
    printf("\n\n======================================\nTempo: %.2f s",(end_time - start_time)/1000.0);
	printf("\nErros: %d", erros);
	taxa = (acertos*100.0)/(acertos+erros);
	printf("\nTaxa de acerto: %.2f%%\n", taxa);
	
	Beep((400),100);
	Beep((525),100);
	Beep((625),100);
	Beep((825),700);
	
    system("PAUSE");
	
	return 0;
}
