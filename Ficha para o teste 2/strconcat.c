#include<stdio.h>

void juntarString(char *s1, char *s2){
	
	while(*(s1++)!='\0');
	s1--;
	while((*(s1++)=*(s2++))!='\0');
}
main(){
	char a[21];
	char b[11];
	char *ptr1=a;
	char *ptr2=b;
	printf("Introduza a 1 String: ");
	fflush(stdin);
	gets(a);
	
	printf("Introduza a 2 String: ");
	fflush(stdin);
	gets(b);
	juntarString(ptr1,ptr2);
	printf("\n %s",ptr1);
	
}
