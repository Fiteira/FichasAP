#include<stdio.h>
#include<stdlib.h>

int *alocarMatriz(int nl,int nc){
int *M;
    M=(int *)malloc(nl*nc*sizeof(int));
    if(M!=NULL)
        return 0;
    else
        return NULL;
}

void lerMatriz(int *M,int nl,int nc){
    int i,j;
        for(i=0;i<nl;i++){
            for(j=0;j<nc;j++){
                printf("M[%d][%d]: ",i,j);
                scanf("%d",M);
                M++;
            }
    }       
}
