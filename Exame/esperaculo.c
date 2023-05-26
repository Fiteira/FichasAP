#include<stdio.h>
#include<stdlib.h>



typedef struct espetaculos{

	int codigo;
	char titulo [10];
	char genero [10];
	float custo;
	SALA sala;
	
}ESPETACULOS;


typedef struct sala
{
	int codigo;
	char localidade [10];
	int filas;
	int cadeiras;
	RESERVAS reservas;	
}SALA;


typedef struct reservas
{
	
	int filas;
	int cadeiras;
	char nome [10];	
}RESERVAS;


//Fun��o para alocar a mem�ria necess�ria para armazenar uma matriz de CADEIRAS
SALA *alocarSala(int n_filas, int n_cadeiras)
{
	SALA *ptr;
	ptr=(SALA *)malloc(n_filas*n_cadeiras*sizeof(SALA));
	if (ptr==NULL)
	{
		printf("Mem�ria insuficiente");
		return NULL;	
	}
	else
		return ptr;	
}
