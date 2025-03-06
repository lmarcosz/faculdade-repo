#include <stdio.h>
#include <windows.h>
int main (){
    int a=1
    ,89, h, m, s;
//===================================================
    while(a==1){
        for(h=0;h<=23;h++){
            for(m=0;m<=59;m++){
                for(s=0;s<=59;s++){
                    if(s<10&&m<10&&h<10){
                        printf("0%d:0%d:0%d", h, m, s);
                        Sleep(1000);
                        system("cls");
                    }
                    if(s>=10&&m<10&&h<10){
                        printf("0%d:0%d:%d", h, m, s);
                        Sleep(1000);
                        system("cls");
                    }

                    if(s<10&&m>=10&&h<10){
                        printf("0%d:%d:0%d", h, m, s);
                        Sleep(1000);
                        system("cls");
                    }
                    if(s>=10&&m>=10&&h<10){
                        printf("0%d:%d:%d", h, m, s);
                        Sleep(1000);
                        system("cls");
                    }

                    if(s<10&&m>=10&&h>=10){
                        printf("0%d:%d:%d", h, m, s);
                        Sleep(1000);
                        system("cls");
                    }
                    if(s>=10&&m>=10&&h>=10){
                        printf("%d:%d:%d", h, m, s);
                        Sleep(1000);
                        system("cls");
                    }
                }
            }
        }
    }

return 0;
}
