#include <stdio.h>

//1 - Implemente uma fun��o que permita trocar o valor de duas vari�veis. Teste a fun��o num pequeno programa para o efeito.

/*void troca(int* a, int *b)
{
	int aux=0;
	
	aux=*a;
	*a=*b;
	*b=aux;
}

void main()
{
	int var1, var2;
	int *ptr_var1=&var1;
	int *ptr_var2=&var2;
	printf("Qual o valor de var1?");
	scanf("%d", &var1);
	printf("\nQual o valor de var2?");
	scanf("%d", &var2);
	troca(ptr_var1, ptr_var2);
	printf("\nVar1= %d, Var2= %d", var1, var2);
}*/

//2 - Elabore um programa que leia uma string e escreva os dois primeiros caracteres no monitor.

/*void main()
{
	char string[20];
	int i;
	printf("Qual a string?");
	gets(string);
	for(i=0; i<2; i++)
	{
		printf("%c", string[i]);
	}
}*/

//3 - Escreva uma fun��o, utilizando ponteiros, que, dadas duas string's, str1 e str2, como par�metros de entrada fa�a a sua concatena��o, devolvendo a string resultante em str1.
//Por exemplo, se str1 for "Aula" e str2 for "pratica" a fun��o dever� devolver "Aulapratica" em str1.

/*void concatena(char* string1, char* string2)
{
	while(*string1!='\0')
	{
		string1++;
	}
	
	while(*string2!='\0')
	{
		*string1=*string2;
		string1++;
		string2++;
	}
	*string1='\0';
}

void main()
{
	char str1[40], str2[20];
	printf("Qual a str1?");
	gets(str1);
	printf("Qual a str2?");
	gets(str2);
	concatena(str1, str2);
	puts(str1);
}*/

//4 - Elabore um programa que leia dois vectores de n elementos cada (inteiros) e determine um
//terceiro com 2n elementos que contenha os elementos do primeiro vector intercalados com os
//do segundo vector, mas estes pela ordem inversa da original. Mostre o vector final no monitor.
//Considere n = 4 elementos por ex.:
//vector x = [1 3 5 7]
//=> vector final = [1 8 3 6 5 4 7 2]
//vector y = [2 4 6 8]

/*void junta_vetor(int* vector1, int* vector2, int* vector3, int tamanho)
{
	int i;
	
	vector2=vector2+tamanho-1;
	
	for(i=0; i<tamanho; i++)
	{
		*vector3 = *vector1;
		vector3++;
		*vector3 = *vector2;
		vector3++;
		vector1++;
		vector2--;
	}
}
void main()
{
	int tamanho, vector1[tamanho], vector2[tamanho], vector3[2*tamanho],i;
	printf("Qual o tamanho do vetor1 e vetor2?");
	scanf("%d", &tamanho);
	
	printf("Qual o vector1?");
	for(i=0; i<tamanho; i++)
	{
	scanf("%d", &vector1[i]);
	}
	for(i=0; i<tamanho; i++)
	{
	printf("%d", vector1[i]);
	}
	printf("\nVector2:");

	for(i=0; i<tamanho; i++)
	{
	scanf("%d", &vector2[i]);
	}
	for(i=0; i<tamanho; i++)
	{
	printf("%d", vector2[i]);
	}
	printf("\n");
	junta_vetor(vector1, vector2, vector3, tamanho);

	for(i=0; i<tamanho*2; i++)
	{
	printf("%d", vector3[i]);
	}
}*/


//5 - Elabore fun��es, utilizando ponteiros, que:
//a) Leia um vector de n elementos inteiros ( n � especificado pelo utilizador);
//b) Apresente no monitor os elementos do vector;
//c) Apresente no monitor os elementos do vector pela ordem inversa;
//d) Determine o m�ximo do vector;
//e) Determine o m�nimo do vector;
//f) Determine a soma das componentes;
//g) Determine a m�dia dos elementos do vector;
//h) Determine quantos elementos do vector s�o superiores � m�dia e quantos s�o inferiores;
//i) Duplique para outro vector os valores lidos;
//j) Intercale os dois vectores (o 2.� por ordem inversa) e disponibilize um terceiro vector
//resultante.

void le_vetor(int* vetor, int tamanho)
{
	int i;
	for(i=0; i<tamanho; i++)
	{
		printf("v[%d]?", i);
		scanf("%d", &vetor[i]);
	}
}
void escreve_vetor(int* vetor, int tamanho)
{
	int i;
	for(i=0; i<tamanho; i++)
	{
		printf("\nv[%d]=%d",i, vetor[i]);
	}
}

void escreve_vetor_inverso(int* vetor, int tamanho)
{
	int i;
	vetor= vetor + tamanho-1;
	for(i=0; i<tamanho; i++)
	{
		printf("%d", *vetor);
		vetor--;
	}
}
int max_vetor(int *vetor, int tamanho)
{
	int maximo=vetor[0];
	int i;
	for(i=0; i< tamanho; i++)
	{
		if(maximo<vetor[i])
		{
			maximo=vetor[i];
		}
	}
	return(maximo);
}
int min_vetor(int* vetor, int tamanho)
{
	int minimo=vetor[0];
	int i;
	for(i=0; i< tamanho; i++)
	{
		if(minimo>vetor[i])
		{
			minimo=vetor[i];
		}
	}
	return(minimo);
}
int soma_comp(int* vetor, int tamanho)
{
	int i, somatorio=0;
	for(i=0; i< tamanho; i++)
	{
		somatorio=somatorio+*vetor;
		vetor++;
	}
	return(somatorio);
}
float media_comp(int* vetor, int tamanho)
{	
	return(soma_comp(vetor, tamanho)/tamanho);
}
int sup_media(int* vetor, int tamanho)
{
	int i, superiores=0;
	for(i=0; i< tamanho; i++)
	{
		if(vetor[i]>media_comp(vetor, tamanho))
			superiores++;
	}
	return(superiores);
}

int inf_media(int* vetor, int tamanho)
{
	int i, inferiores=0;
	for(i=0; i< tamanho; i++)
	{
		if(vetor[i]<=media_comp(vetor, tamanho))
			inferiores++;
	}
	return(inferiores);
}

void duplicar_vetor(int* vetor1, int tamanho, int* vetor2)
{
	int i;
	for(i=0; i<tamanho; i++)
	{
		*vetor2=*vetor1;
		vetor2++;
		vetor1++;
	}
}
void intercalar_vetor(int* vetor1, int tamanho, int* vetor2, int* vetor3)
{
	int i;
	vetor2=vetor2+tamanho-1;
	
	for(i=0; i<tamanho; i++)
	{
		*vetor3 = *vetor1;
		vetor3++;
		*vetor3 = *vetor2;
		vetor3++;
		vetor1++;
		vetor2--;
	}
}
void main()
{
	int tamanho, vetor[tamanho], vetor2[tamanho], vetor3[2*tamanho];
	int i;
	
	printf("Qual o tamanho?");
	scanf("%d", &tamanho);
	le_vetor(vetor, tamanho);
	printf("\nVetor inserido:");
	escreve_vetor(vetor, tamanho);
	printf("\nVetor inverso:");
	escreve_vetor_inverso(vetor, tamanho);
	printf("\nMax: %d",	max_vetor(vetor, tamanho));
	printf("\nMin: %d", min_vetor(vetor, tamanho));
	printf("\nA soma e: %d", soma_comp(vetor, tamanho));
	printf("\nA media e: %f", media_comp(vetor, tamanho));
	printf("\n%d sao inferiores a media", inf_media(vetor, tamanho));
	printf("\n%d sao superiores a media", sup_media(vetor, tamanho));
	duplicar_vetor(vetor, tamanho, vetor2);
	printf("\nVetor 2:");
	escreve_vetor(vetor2, tamanho);
	printf("\nVetor 3:");
	intercalar_vetor(vetor, tamanho, vetor2, vetor3);
	escreve_vetor(vetor3, 2*tamanho);
}
