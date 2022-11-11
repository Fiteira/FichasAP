#include<stdio.h>

main(){
    
    int num;

    printf("\nIntroduza um numero(inteiro): ");
    scanf("%d",&num);
        if (num<0)
        {
            printf("O numero e negativo!");
        }else if (num>0)
        {
            printf("O numero e positivo!");
        }else if(num==0){
            printf("O numero e zero!");
        }

}