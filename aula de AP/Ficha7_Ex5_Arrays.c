# include <stdio.h>
# include<locale.h>
# include<stdbool.h>

# define n_filas 10
# define n_cadeiras 10

//Estrutura cadeira
typedef struct cadeira {
    char nome[50];
    bool reservada,paga;
} CADEIRA;


//-----------------------------------------------------
void inicializarReservas(CADEIRA sala[][n_cadeiras])
{
	int i, j;
	for (i=0;i<n_filas;i++)
		for (j=0;j<n_cadeiras;j++)
		{
			sala[i][j].nome[0]='\0';
			sala[i][j].reservada=false;
			sala[i][j].paga=false;
		}
}

//-----------------------------------------------------

void eliminarReserva(CADEIRA sala[][n_cadeiras])
{
	int i, j;
	char pgm;
	printf("Fila a libertar: ");
	scanf("%d",&i);
	printf("Cadeira a libertar: ");
	scanf("%d",&j);
	i--;j--;       // indices dos vetores começam em zero
	if (sala[i][j].reservada==true)
	{
		sala[i][j].nome[0]='\0';
		sala[i][j].reservada=false;
		sala[i][j].paga=false;
		printf("\nReserva eliminada!");
	}
	else
		printf("\nLugar não ocupado!");
}

//-----------------------------------------------------

void adicionarReserva(CADEIRA sala[][n_cadeiras])
{
	int i, j;
	char pgm;
	printf("Fila a reservar: ");
	scanf("%d",&i);
	printf("Cadeira a reservar: ");
	scanf("%d",&j);
	i--;j--;       // indices dos vetores começam em zero
	if (sala[i][j].reservada==true)
		printf("Lugar já ocupado!");
	else
	{
		sala[i][j].reservada=true;
		printf("Nome do cliente ");
		fseek(stdin,0,2); //fflush(stdin)
		gets(sala[i][j].nome);
		
		do
		{
			printf("Efetuou pagamento (s/n) ");
			scanf(" %c",&pgm);
		}while(pgm!='s' && pgm!='S' && pgm!='n' && pgm!='N');
		
		if (pgm=='s' || pgm=='S')
			sala[i][j].paga=true;
		printf("\nReserva efetuada");
	}
	
}

//-----------------------------------------------------
void listarMapaOcup(CADEIRA sala[][n_cadeiras])
{
	int i, j;
	printf("\nMapa de ocupação da sala\n\n");
	printf("    ");
  	for (j = 0; j < n_cadeiras; j++)  
    	printf("%3d ", j+1);
  	printf("\n");
  	for (i = 0; i < n_filas; i++)
  	{
    	printf("%3d ", i+1);
    	for (j = 0; j < n_cadeiras; j++)
      		printf("  %c ",sala[i][j].reservada? 'X':'-');  // operacor ponto interrogação
    	printf("\n");        
  	}
}

//-----------------------------------------------------
void listarReservas(CADEIRA sala[][n_cadeiras])
{
	int i, j;
	bool encontra=false;
  	for (i = 0; i < n_filas; i++)
    	for (j = 0; j < n_cadeiras; j++)
    		if (sala[i][j].reservada)
    		{
    			encontra=true;
				printf("\nLugar (%d,%d) reservado por: %s \n" 
				 "Pagamento efetuado: %s \n",i+1,j+1,sala[i][j].nome,sala[i][j].paga?"Sim":"Não");		
  			}
  	if (encontra==false)
  		printf("\nReservas ainda não efetuadas!\n");
}


//-----------------------------------------------------
void main()
{
	setlocale(LC_ALL,"Portuguese");
	CADEIRA sala[n_filas][n_cadeiras];
	int opcao;

	inicializarReservas(sala);
	
	do
	{
		printf("\n\nGestão de reserva de uma sala espetáculos:\n"
			  		"\t1 - Adicionar uma nova reserva \n"
			  		"\t2 - Eliminar uma reserva \n"
			  		"\t3 - Mapa de ocupação da sala\n"
			  		"\t4 - Listar reservas\n"
			  		"\t5 - Sair\n");
		scanf(" %d",&opcao);
		switch (opcao)
		{	
			case 1: adicionarReserva(sala); break;
			case 2: eliminarReserva(sala); break;
			case 3: listarMapaOcup(sala); break;
			case 4: listarReservas(sala); break;
			case 5: exit(0);
			default: printf("\n Opção inválida!\n"); break;
		} 
	
	}while(opcao !=5);
	
}
