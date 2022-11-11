#include<stdio.h>


main(){

    int num1,num2,i;

    do
    {
        printf("\nIntroduza o intervalo: ");
        scanf("%d %d",&num1,&num2);
    } while (num1>num2);
    
    for (i = num1; i <= num2; i++)
    {
        if(i%2 == 0){
            printf("\nO numero %d e par",i);
        }else{
            printf("\nO numero %d e impar",i);
        }
    }

    printf("\n-----------------------------");
    for (i = num1; i <= num2; i++)
    {
        if(i%2 == 0 && i%10!=0){
            printf("\nO numero %d e par e nao e divisivel por 10",i);
    }
    }


    printf("\n-----------------------------");

    int num_mult;
    printf("\nQual o n que ver ver os seu multipos e exceto quando estes forem divisiveis por 2 e 3 e 5: ");
    scanf("%d",&num_mult);

    for (i = num1; i <= num2; i++)
    {
        if(i%num_mult==0 && i%2!=0 && i%3!=0 && i%5!=0 ){ 
            printf("\nOs multipos de %d sao %d",num_mult,i);
        }
    }
  

}