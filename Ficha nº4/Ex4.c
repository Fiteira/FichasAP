#include <stdio.h>
#include <locale.h>

	int main(){
	setlocale(LC_ALL, "Portuguese");
	
    int soma=0,f,i;
    for(i=1;i<=5;i++){
    
    f=f*i;
    soma=soma+f;
    
    printf("\n iteracao %d soma:%d",i,f);
}
    printf("\n soma:%d",soma);
  

	
	return 0;
}

