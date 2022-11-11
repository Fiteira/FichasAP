#include <stdio.h>
#include <locale.h>

int main()
{
 	setlocale(LC_ALL, "Portuguese");
    int i,j,count;
    int n;
    printf("O valor de n para o tamanho da pirâmide:");
    scanf("%d",&n);
    	for(i=1;i<=n;i++){
    		
        for(j=1;j<=n-i;j++){
            printf(" ");
        }
        for(count=1;count<=i;count++)
            printf("%d",count);
        for(count=i-1;count>=1;count--)
            printf("%d",count);
            printf("\n");

}
    return 0;
}
