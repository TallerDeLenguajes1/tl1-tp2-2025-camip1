#include<stdio.h>
#include<stdlib.h>
#define N 20

int main(){
    int i;
    double vt[N];
    double *punt=vt;
    for(i = 0; i<N; i++)
    {
        *(punt+i)=1+rand()%100;
        printf("\n%f", *(punt+i));  //notacion indexada
    }
    return 0;
}