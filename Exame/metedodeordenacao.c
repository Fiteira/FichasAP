#include<stdio.h>


void ordenarvetor(int *v,int n)
{
int i,j,menor,aux;
    for(i=0;i<n-1;i++)
    {
        menor=i;
        for (j=i+1;j<n;j++)
        {
            if(v[menor]>v[j])
            menor=j;
        }
        if(i!=menor){
            aux=v[i];
            v[i]=v[menor];
            v[menor]=aux;
        }
    }
}

main(){
    int n,i;
    printf("Quantos numeros vai ter o vetor: ");
    scanf("%d",&n);
    int v[n];
        for(i=0;i<n;i++){
            printf("\n%d: ",i+1);
            scanf("%d",&v[i]);
        }
    printf("Ordenar os numeros dados");
    ordenarvetor(v,n);
        for(i=0;i<n;i++){
            printf("\n%d ",v[i]);
        }
}