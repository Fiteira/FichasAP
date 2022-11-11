#include<stdio.h>
void main()
{
    printf("Início do Programa \n\n\n");
    int i = 1;
        for ( ; ;i++)
        {
        int resto = i%10;
            if(resto == 0)
                system("Pause");
        printf("Número = %d \n", i);
        }
    printf("Fim do Ciclo e do Programa!");
}