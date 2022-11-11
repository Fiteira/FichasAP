#include<stdio.h>
/*main(){

    
    int num,sum,i;
    float media;
    i=0;
    sum=0;



    printf("\nIntroduza um numero(para terminar digite '0'): ");
    scanf("%d",&num);
    sum=sum+num;
    while (num!=0)
    {
    printf("\nIntroduza um numero(para terminar digite '0'): ");
    scanf("%d",&num);
    sum=sum+num;
    i++;
    }
    

    printf("\nA soma e %d",sum);
    media=((float)sum / i);
    printf("\nA media e %0.2f",media);
}*/

int somatorio(int n){
    int i,sum;
    for(i=1;i<n;i++){
        sum=n;
    }
    return sum;
}

main(){
    int n;
    printf("Qual e o n:");
    scanf("%d",&n);
    printf("O somatorio de n %d e %d",n,somatorio(n));

}