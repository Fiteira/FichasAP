//Exercicios 1, 2 e 3
#include<stdio.h>
/*void printStr(char* str)
{
	int i, fim, contador=0;
	printf("%s", str);
		
	printf("\n");
	fflush(stdin);
	
	while(str[contador]!='\0')
		contador++;
	fim=contador-1;
	for(i=0;i<contador;i++)
	{
		printf("%c", str[fim]);
		fim--;
	}
}
//ou
#include<stdio.h>

void trocarStr(char *p,int n){

    int i,j;
    char aux;
        for(i=0;i<n;i++){
            for(j=n;j<0;j--){
                aux=p[i];
                p[i]=p[j];
                p[j]=aux;
            }
        }
printf("%s",p);
}


void strLen(char *str)
{
	int contador;
	while(str[contador]!='\0')
		contador++;
	printf("\nO tamanho da string e: %d", contador);
}

void strConcat(char* str1, char* str2)
{
	while(*str1!='\0')
		str1++;
		
	while(*str2!='\0')
	{
		*str1=*str2;
		str1++;
		str2++;
	}
	*str1='\0';
}

*/
void main()
{
	char string[40];
	char string2[20];
	printf("Qual a string?");
	gets(string);
	printStr(string);
	strLen(string);
	printf("\nQual a segunda string?");
	gets(string2);
	strConcat(string, string2);
	puts(string);
}