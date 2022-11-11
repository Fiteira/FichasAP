#include<stdio.h>
void main()
{
    int i;
    for (i=1; i<=100; i=i+1)
    if(i==70)
        break;
    else
        if (i%2 == 0)
            continue;
        else
            printf("%2d\n", i);
    printf("Fim do Ciclo e do Programa!");
}