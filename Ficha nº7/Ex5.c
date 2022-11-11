#include<stdio.h>
#include<stdbool.h>
#include<locale.h>

#define n_filas 10
#define n_cadeiras 10

typedef struct cadeira{
	char nome [50];
	bool reservada;
	bool paga;
	
}CADEIRA;


void inicializarReservas(CADEIRA sala[][n_cadeiras]){
	int i,j;
	for(i=0;i<n_filas;i++){
		for(j=0;j<n_cadeiras;j++)
		{
			sala[i][j].nome[0]='\0';
			sala[i][j].reservada=false;
			sala[i][j].paga=false;
		}
	}
}

void adicionarReservas(CADEIRA sala[][n_cadeiras]){
	int i,j;
	char pgm;
	printf("Fila a reservar:");
	scanf("%d",&i);
	printf("Cadeira a reservar:");
	scanf("%d",&j);
	i--;
	j--;	//indices dos vetores comecam em zero;
	
	if(sala[i][j].reservada==true)
		printf("Lugar ja ocupado");		
	else{
		sala[i][j].reservada==true;
		printf("Nome do cliente: ");
		fflush(stdin);
		gets(sala[i][j].nome);
		
		do{
			printf("Efetuou pagamento(s/n) ");
			scanf(" %c",&pgm);
		}while(pgm!='s' && pgm!='S' && pgm!='n' && pgm!='N');
			
			if(pgm=='s' || pgm=='S'){
				sala[i][j].paga=true;
				printf("Pagamento efetuado");
			}
		}

}

void eliminarReserva(CADEIRA sala[][n_cadeiras]){
	int i,j;
	char pgm;
	printf("Fila a eliminar reservar:");
	scanf("%d",&i);
	printf("Cadeira a eliminar reservar:");
	scanf("%d",&j);
	i--;
	j--;	//indices dos vetores comecam em zero;
	
	if(sala[i][j].reservada==true){
		
		sala[i][j].nome[0]='\0';
		sala[i][j].reservada=false;
		sala[i][j].paga=false;
		printf("Reserva eliminada");
	}
				
	else
		printf("Lugar nao ocupado");	
	
}


void listarMapaOcup(CADEIRA sala[][n_cadeiras]){
	int i,j;
	printf("\nMapa de ocupacao da sala\n\n");
	printf("    ");
	for(j=0; j<n_cadeiras; j++)
		printf("%3d", j+1);
	printf("\n");
	for(i=0;i<n_filas;i++){
		printf(" %c",sala[i][j].reservada? 'X':'-'); // e a mesma coisa o ? com "if" e um operador "?"
		printf("\n");
	
	}
	

}
void listarReserva(CADEIRA sala[][n_cadeiras]){

	int i, j;
	bool encontra=false;
  	for (i = 0; i < n_filas; i++)
    	for (j = 0; j < n_cadeiras; j++)
    		if (sala[i][j].reservada)
    		{
    			encontra=true;
				printf("\nLugar (%d,%d) reservado por: %s \n" 
				 "Pagamento efetuado: %s \n",i+1,j+1,sala[i][j].nome,sala[i][j].paga?"Sim":"Nao");		
  			}
  	if (encontra==false)
  		printf("\nReservas ainda nao efetuadas!\n");
}


main(){
	CADEIRA sala[n_filas][n_cadeiras];
	int opcao;
	
	inicializarReservas(sala);
	
	do{
		
		printf("\n \nGestao de uma sala espectaculos");
		printf("\n 1 - Criar uma nova reserva num lugar vago");
		printf("\n 2 - Eliminar uma reserva");
		printf("\n 3 - Apresentar um mapa da ocupacao da sala");
		printf("\n 4 - Listar as reservas");
		printf("\n 5 - Sair\n");
		scanf("%d",&opcao);
		
		switch(opcao){
			case 1:
				adicionarReservas(sala);
			break;	
			
			case 2:
				eliminarReserva(sala);
			break;
			
			case 3:	
				listarMapaOcup(sala);
			break;
			
			case 4:	
				listarReserva(sala);
			break;
			
			case 5:	
			break;
				
			default: 
				printf("\n Opcao invalida");
			break;
	}
				
	}while(opcao!=5);




}
