#include <stdio.h>
void main()
{
int num = 2000;
    printf("Introduza um caracter: ");
    scanf("%c\n", &num);
    printf("O valor de num = %d cujo caracter = '%c'\n", num, (char) num);
}