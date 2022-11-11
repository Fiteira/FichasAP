#include<stdio.h>

main(){
    int num;
        printf("Introduza um numero: ");
        scanf("%d",&num);

        if(num <=10)
            printf("falta: %d",10-num);
        else if(num <=100)
            printf("falta: %d",100-num);
        else if(num <=1000)
            printf("falta: %d",1000-num);
        else if(num <=10000)
            printf("falta: %d",10000-num);

}