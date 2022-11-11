#include<stdio.h>
main(){
    
    char a,b;
    int n;
    printf("Introduza um caratere:");
    scanf("%c",&a);
    printf("\nIntroduza outro caratere:");
    scanf(" %c",&b);

   printf("%c - %c",a,b);
   printf("\nO codigo de ASCII do carater '%c' e %d",a,a);

   do
   {
       printf("\nIntroduza um numero enter [0...255]: ");
       scanf("%d",&n);
   } while (n<0 || n>255);
   printf("O numero introduzido e %d",n);

   


}