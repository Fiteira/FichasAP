
#include<stdio.h>

typedef struct numero
{
    float numero;
}NUMERO;

void lerNumero(NUMERO *p,int n){

        for (int i = 0; i < n; i++)
    {
        printf("\n%d:",i+1);
        scanf("%f",&p[i].numero);
    }

}

//esta mal
void minMaxNumeros(NUMERO *p, int n)
{
	int i;
	float max=p[0].numero, min=p[0].numero;
	
		for(i=0; i<n; i++){
				if(p[i].numero>=max)
					max=p[i].numero;
        }
        
		for(i=0; i<n; i++){
				if(p[i].numero<=min)
					min=p[i].numero;
        }

    printf("Maximo:%.2f",max);
    printf("Minimo:%.2f",min);
}

main(){
    NUMERO numeros[20];
    int n;
    printf("Quantos numero vai escrever: ");
    scanf("%d",&n);
    lerNumero(numeros,n);
    minMaxNumeros(numeros,n);
    

}