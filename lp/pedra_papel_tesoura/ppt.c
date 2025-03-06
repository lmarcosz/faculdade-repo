#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void ppt();

int main (){
    char a;

    ppt();
    printf("Pressione Enter para iniciar");
    scanf("%c", &a);
    system("cls");
return 0;
}

void ppt(){
    Sleep(400);
    printf("PEDRA");
    Sleep(400);
    system("cls");
    printf("PAPEL");
    Sleep(400);
    system("cls");
    printf("TESOURA");
    Sleep(400);
    system("cls");
}
