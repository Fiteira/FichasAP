# include <stdio.h>
#include<locale.h>
# include <stdlib.h>


typedef struct lista
{
	char nome[50];
	int votos, lugares;
} LISTA;


//-----------------------------------------------------
LISTA *alocarLista (int n_listas)
//Aloca a mem�ria necess�ria para armazenar um vetor de LISTA
{
	LISTA *ptr;
	ptr=(LISTA *)malloc(n_listas*sizeof(LISTA));
	if (ptr==NULL)
	{
		printf("Mem�ria insuficiente");
		return NULL;	
	}
	else
		return ptr;	
}

//-----------------------------------------------------
void inicializarListas(LISTA *p, int n_listas)
{
	int i;
	for (i=0;i<n_listas;i++)
	{
		printf("Nome da lista ");
		fseek(stdin,0,2);
		gets(p->nome);
		printf("Votos ");
		scanf("%d",&p->votos);
		p++;
	}
}


//-----------------------------------------------------
void inicializarListas1 (LISTA *p, int n_listas)
{
	int i;
	for (i=0;i<n_listas;i++)
	{
		printf("Nome da lista ");
		fseek(stdin,0,2);
		gets((p+i)->nome);
		printf("Votos ");
		scanf("%d",&(p+i)->votos);
	}
}


//-----------------------------------------------------

void maximo(int * q,LISTA *p,int n_listas,int *pos)
{
	int i;
	*pos=0;
	for(i=1;i<n_listas;i++)
		if ((q[i]>q[*pos] || q[i]==q[*pos]) && (p[i].lugares < p[*pos].lugares))
			*pos=i;
	
}

//-----------------------------------------------------
void calcularLugaresHondt (LISTA *p, int n_listas, int n_lugares)
{
	int i, lugares_atrib=0,ind;
	
	int *quoc=(int *)malloc(n_listas*sizeof(int));
	
	for (i=0;i<n_listas;i++)
	{
		quoc[i]=(p+i)->votos;   //quoc[i]=*(quoc+i)
		(p+i)->lugares=0;
	}
	
	
	while (lugares_atrib<n_lugares)
	{
		maximo(quoc,p,n_listas,&ind);
		(p+ind)->lugares++;
		lugares_atrib++;
		*(quoc+ind)=(p+ind)->votos/((p+ind)->votos+1);		  //	quoc[ind]
	}	
    
}

//-----------------------------------------------------
void main()
{
	setlocale(LC_ALL, "Portuguese");//Dicion�rio de portugu�s
	int nc, nl;
	LISTA *ptr;

	printf("\nN�mero de listas (partidos): ");
    scanf("%d", &nc);
    ptr=alocarLista(nc);
    printf("\nN�mero de lugares a preencher: ");
    scanf("%d", &nl);
    
    ptr=alocarLista(nc);
    inicializarListas(ptr,nc);
    
	calcularLugaresHondt (ptr, nc, nl);
   
    free(ptr);
    
}
