#include<stdio.h>

main(){
    int a;
    long int a1;
    short int a2;
    float b;
    double c;
    char d;
    printf("Um inteiro ocupa %d bits",sizeof(a));
    printf("\nUm inteiro longo ocupa %d bits",sizeof(a1));
    printf("\nUm inteiro curto ocupa %d bits",sizeof(a2));
    printf("\nUm float ocupa %d bits",sizeof(b));
    printf("\nUm double ocupa %d bits",sizeof(c));
    printf("\nUm char ocupa %d bits",sizeof(d));
}
