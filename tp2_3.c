#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 5
#define M 7

int main(){
    int i,j;
    int mt[N][M];
    int *punt=&mt[0][0];
    srand(time(NULL));
    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            *(punt + (i * M + j))=1+rand()%100;
            printf("%d\t", *(punt + (i * M + j))); //notacion indexada
        }
        printf("\n");
    }
    printf("\n");
    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {            
            printf("%d\t", mt[i][j]); //notacion indexada
        }
        printf("\n");
    }

    return 0;
}
