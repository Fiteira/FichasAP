#include<stdio.h>
/*
int strlen(char *s){
	char *ptr=s;
	while(*s!='\0'){
	 s++;
	}
	return (int)(s-ptr);
}
*/
int strlen(char *s){
 int i;
 for(i=0; s[i]!='\0'; i++);
 
 return i;	
}

main(){

char nome[40];

printf("Introduza uma string: ");
gets(nome);

printf("%d",strlen(nome));

}

