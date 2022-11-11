#include<stdio.h>


void escreva2juntos(char *str1,char *str2){
	
while(*str1!='\0'){
	str1++;
}
while(*str2!='\0'){
    *str1=*str2;
	str1++;
	str2++;
}
*str1='\0';
	
}
	



main(){
	char str1[50],str2[50];
	printf("Escreva 1 string:");
	fflush(stdin);
	gets(str1);
	
	printf("Escreva 2 string:");
	fflush(stdin);
	gets(str2);
	
	
	escreva2juntos(str1,str2);
	printf("%s\n",str1);
	
	} 
