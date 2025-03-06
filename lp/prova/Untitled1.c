#include <stdio.h>

void tabela(int mat[2][2]){
    printf(" %c | %c | %c ", mat[0][0], mat[0][1], mat[0][2]);
    printf("----+----+----");
    printf(" %c | %c | %c ", mat[1][0], mat[1][1], mat[1][2]);
    printf("----+----+----");
    printf(" %c | %c | %c ", mat[2][0], mat[2][1], mat[2][2]);
}

int main (void) {
    char mat[2][2], figura;
    int k, i;

    for(k=0;k<3;k++){
        for(i=0;i<3;i++){
            mat[k][i] = ' ';
        }
    }
//=================================
    void tabela();

return 0;
}
