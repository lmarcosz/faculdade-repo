#include<stdio.h>
#include<windows.h>

int main (){
	
	int j;
	
	for(j=0;j<30;j++){
		printf("\n%d", j);
		Beep((j*25), 2000);
	}
	
	return 0;
}
