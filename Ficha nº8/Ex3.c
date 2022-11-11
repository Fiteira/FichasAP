#include<stdio.h>
#include <stdlib.h>

typedef struct lista{
	char nome[50];
	int votos;
	int lugares;
	
}LISTA;


LISTA *alocarLista(int n_listas){
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

void inicializarListas(LISTA *p,int n_listas){
	int i;
	
	for(i=0;i<n_listas;i++){
		printf("Nome da lista ");
		fflush(stdin);
		gets((p+i)->nome);
		printf("Votos ");
		scanf("%d",&(p+i)->votos);
	}
}

void maximo(int *q, LISTA *p ,int n_listas,int *pos){
	int i;
	*pos=0;
	for(i=1;i<n_listas;i++)
		if (q[i]>q[*pos] || q[i]==q[*pos] && (p[i].lugares) < p[*pos].lugares)
			*pos=i;

}

void calcularLugaresHondt(LISTA *p,int n_listas,int n_lugares){
	int i,ind,lugares_atrib=0;
	int *quoc=(int *)malloc(n_listas*sizeof(int));
	
	
	for(i=0;i<n_listas;i++){
		quoc[i]=(p+i)->votos; //quoc[i]=*(quoc+i)
		(p+i)->votos=0;
		ind=i;
	}
	while(lugares_atrib<n_lugares);
	{
		maximo(quoc,p,n_listas,&ind);
		printf("Quocinete %d - %d lugar atribuido a lista %s",*(quoc+ind),lugares_atrib+1,(p+ind)->nome);
		(p+ind)->lugares++;
		lugares_atrib++;
		*(quoc+ind)=(p+ind)->votos/((p+ind)->votos+1);
	}
		
}

void listarResultados(LISTA *p,int n_listas){
	int i;
	printf("\n\nLista votos lugares");
	for (i=0;i<n_listas;i++)
		printf("\n%s %d %d",(p+i)->nome,(p+i)->votos,(p+i)->lugares);
}

main(){
	int nc,nl;
	LISTA *ptr;
	
	printf("\Numero de listas:");
	scanf("%d",&nc);
	printf("\Numero de lugares:");
	scanf("%d",&nl);
	
	ptr=alocarLista(nc);
	inicializarListas(ptr,nc);
}
