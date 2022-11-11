# include <stdio.h>
# include<locale.h>
# include<stdbool.h>
#include <stdlib.h>


//Estrutura cadeira
typedef struct cadeira {
    char nome[50];
    bool reservada,paga;
} CADEIRA;


//-----------------------------------------------------
//Função para alocar a memória necessária para armazenar uma matriz de CADEIRAS
CADEIRA *alocarSala(int n_filas, int n_cadeiras)
{
	CADEIRA *ptr;
	ptr=(CADEIRA *)malloc(n_filas*n_cadeiras*sizeof(CADEIRA));
	if (ptr==NULL)
	{
		printf("Memória insuficiente");
		return NULL;	
	}
	else
		return ptr;	
}

//-----------------------------------------------------

void inicializarReservas(CADEIRA *p,int n_f, int n_c)
{
	int i, j;
	for (i=0;i<n_f;i++)
		for(j=0;j<n_c;j++)
		{
			p->nome[0]='\0';    
			p->reservada=false;
			p->paga=false;
			p++;
		}
}

//-----------------------------------------------------
	
void adicionarReserva(CADEIRA *p,int n_f, int n_c)
{
	int i, j;
	char pgm;
	printf("\nFila a reservar: ");  
	scanf("%d",&i);		
	printf("Cadeira a reservar: ");  
	scanf("%d",&j);
	i--;j--;
	if ((p+i*n_c+j)->reservada)    //(p+i*n_c+j)->reservada = (*(p+i*n_c+j)).reservada=p[i*n_c+j].reservada
		printf("\nLugar já reservado!");
	else
	{
		(p+i*n_c+j)->reservada=true;
		printf("Nome cliente: ");
		fseek(stdin,0,2);
		gets(p->nome);
		do
		{
			printf("Pagamento efetuado (s/n): ");
			scanf(" %c",&pgm);
		}while(pgm!='s' && pgm!='S' && pgm!='n' && pgm!='N');
		if (pgm!='s' || pgm!='S')
			(p+i*n_c+j)->paga=true;
		printf("Reserva efetuada!\n");
	}	
}

//-----------------------------------------------------
void eliminarReserva(CADEIRA *p,int n_f, int n_c)
{
	int i, j;
	printf("\nFila a libertar: ");  
	scanf("%d",&i);		
	printf("Cadeira a libertar: ");  
	scanf("%d",&j);
	i--;j--;
	if ((p+i*n_c+j)->reservada)
	{
		printf("Reserva eliminada!\n");
		(p+i*n_c+j)->nome[0]='\0';
		(p+i*n_c+j)->reservada=false;
		(p+i*n_c+j)->paga=false;
		
	}
	else
		printf("Lugar não está ocupado!\n");	
}

//-----------------------------------------------------
void mostrarMapaOcup(CADEIRA *p,int n_f, int n_c)
{
	int i, j;
	printf("\nMapa de ocupação da sala\n\n");
	printf("    ");
  	for (j = 0; j < n_c; j++)
    	printf("%3d ", j+1);
  	printf("\n");
  	for (i = 0; i < n_f; i++)
  	{
    	printf("%3d ", i+1);
    	for (j = 0; j < n_c; j++) // esta-se a mostrar pela ordem pela qual aparecem na memoria, não é preciso p+i*n_c+j;  
    	{
			printf("  %c ",p->reservada?'X':'-');
			p++;
		}
    	printf("\n");        
  	}
}

//-----------------------------------------------------
void listarReservas(CADEIRA *p,int n_f,int n_c)
{
	int i, j;
	bool encontra=false;
  	for (i = 0; i < n_f; i++)
    	for (j = 0; j < n_c; j++)
    	{
    		if (p->reservada)
    		{
    			encontra=true;
				printf("\nLugar (%d,%d) reservado por: %s \n" 
				 "Pagamento efetuado: %s \n",i+1,j+1,p->nome,p->paga?"Sim":"Não");		
  			}
  			p++;
  		}
  	if (encontra==false)
  		printf("\nReservas ainda não efetuadas!\n");
}

//-----------------------------------------------------
void main()
{
	setlocale(LC_ALL,"Portuguese");
	CADEIRA *ptr;
	int opcao, n_filas,n_cadeiras;
	printf("\n Numero de filas da sala: ");
    scanf("%d", &n_filas);
    printf("\n Numero de cadeiras de cada fila: ");
    scanf("%d", &n_cadeiras);
	ptr=alocarSala(n_filas,n_cadeiras);
	inicializarReservas(ptr,n_filas,n_cadeiras);
	do
	{
		printf("\nGestão de reserva de uma sala espetáculos:\n"
			  		"\t1 - Adicionar uma nova reserva \n"
			  		"\t2 - Eliminar uma reserva \n"
			  		"\t3 - Mapa de ocupação da sala\n"
			  		"\t4 - Listar reservas\n"
			  		"\t5 - Sair\n");
		scanf(" %d",&opcao);
		switch (opcao)
		{	
			case 1: adicionarReserva(ptr,n_filas,n_cadeiras); break;
			case 2: eliminarReserva(ptr,n_filas,n_cadeiras); break;
			case 3: mostrarMapaOcup(ptr,n_filas,n_cadeiras); break;
			case 4: listarReservas(ptr,n_filas,n_cadeiras); break;
			default: printf("\n Opção inválida!\n"); break;
		} 
	}while(opcao !=5);
	
}
