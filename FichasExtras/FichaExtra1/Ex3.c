#include<stdio.h>

main(){
    int r;
    float area,area1,perimetro,perimetro1;
    printf("Introduza o raio: ");
    scanf("%d",&r);

    perimetro=2*3.14159*r;
    perimetro1=2*3.141592653*r;
    area=3.14159*r*r;
    area1=3.141592653*r*r;
    printf("\nPerimetro 1: %0.2f",perimetro);
    printf("\nPerimetro 2: %0.4f",perimetro1);
    printf("\nArea 1: %0.7f",area);
    printf("\nArea 2: %f",area1);
}