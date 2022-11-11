#include<stdio.h>


void escreva2primeiros(char str[30]){
	
	printf("%c %c",str[0],str[1]);
	
}


main(){
	char str[30];
	printf("Introduza uma string:");
	fflush(stdin);
	gets(str);
	escreva2primeiros(str);
		
	}
