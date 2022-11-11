/*#include<stdio.h>
void main()
{
int i, val, sum, prod;
    printf("Insira um número: ");
    scanf("%d", &val);
    for (sum=0, i=prod=1; i<=val; i=i+1)
    {
        sum+=i;
        prod*=i;
    }
    printf("A Soma=%d; o Produto=%d\n\n", sum, prod);
}*/
#include<stdio.h>
void main()
{
int i, val, sum, prod;

    printf("Insira um número para terminar introduza o '0': ");
    scanf("%d", &val);
    for (sum=0, i=prod=1; i<=val; i=i+1)
    {
        sum+=i;
        prod*=i;
    }
    printf("A Soma=%d; o Produto=%d\n\n", sum, prod);  
    
    while (val!=0)
    {
    printf("Insira um número para terminar introduza o '0': ");
    scanf("%d", &val);
    for (sum=0, i=prod=1; i<=val; i=i+1)
    {
        sum+=i;
        prod*=i;
    }
    printf("A Soma=%d; o Produto=%d\n\n", sum, prod);
    }

    
    
}