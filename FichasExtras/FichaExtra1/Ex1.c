#include<stdio.h>
#include <locale.h>

int soma2numeros(int n1,int n2){
    return n1+n2;
}
int subtrair2numeros(int n1,int n2){
    return n1-n2;
}
int multiplicar2numeros(int n1,int n2){
    return n1*n2;
}
float dividir2numeros(float n1,float n2){
    return n1 / n2;
}

void operacoesbasicas(int n1,int n2){
    int opcao;

    do{
        printf("\n*******************************\n");
        printf("\n1-Soma");
        printf("\n2-Subtrair");
        printf("\n3-Multiplicar");
        printf("\n4-Dividir");
        printf("\n0-Sair");
        printf("\nQual a opcao que vai escolher");
        printf("\n*******************************\n");
        scanf("%d",&opcao);
        
        switch (opcao)
        {
        case 1:
            printf("A soma e %d",soma2numeros(n1,n2));
            break;
        case 2:
            printf("A subtracao e %d",subtrair2numeros(n1,n2));
            break;
        case 3:
            printf("A multiplicacao e %d",multiplicar2numeros(n1,n2));
            break;
        case 4:
            printf("A divisao e %.2f ",dividir2numeros(n1,n2));
            break;
        
        default:
            break;
        }

    }while(opcao!=0);
}


main(){
    int opcao,n1,n2;
    setlocale(LC_ALL, "Portuguese");
    do{
        printf("\n--------------------------------------------------\n");
        printf("\nOla a todos! Sou o C e espero que sejamos bons amigos");
        printf("\n1-dados 2 numeros inteiros, calcule e apresente a sua soma");
        printf("\n2-Mostre o numero indicado pelo utilizador e o seguinte");
        printf("\n3-Dados dois numeros indicados pelo utilizador, apresente o resultado das operacoes aritmeticas basicas");
        printf("\n0-Sair\n");
        scanf("%d",&opcao);
 
        switch (opcao)
        {
        case 1:printf("\nIntroduza 1 e o 2(numeros inteiros):");
                scanf("%d %d",&n1,&n2);
                printf("\nA soma e: %d",soma2numeros(n1,n2));
            break;
        case 2:printf("\nIntroduza um numero inteiro:");
                scanf("%d",&n1);
                printf("\nO numero indicado pelo utilizador foi %d e o seguinte e %d",n1,n1+1);
            break;
        case 3:printf("\nIntroduza 1 e o 2(numeros inteiros):");
                scanf("%d %d",&n1,&n2);
                operacoesbasicas(n1,n2);
            break;

        default:
            break;
        }
    }while(opcao!=0);
}
