#include<stdio.h>

typedef struct data
{
    int ano;
    int mes;
    int dia;
}DATA;

typedef struct livro
{
    char titulo[30];
    char autor[30];
    char area[20];
    DATA data;
    int ocopacao;
}LIVRO;
 
void inicializacao(LIVRO *p,int n){

    int i;
        for(i=0;i<n;i++){
         p[i].ocopacao=0;   
        }
}
void adicionarLivro(LIVRO *p, int n){
    int i;
        while (p[i].ocopacao!=0 && i<n)
        {
            i++;
            }
        if (i<n){
            p[i].ocopacao=1;
            printf("\nTitulo:");
            fflush(stdin);
            gets(p[i].titulo);
            printf("\nAutor:");
            fflush(stdin);
            gets(p[i].autor);
            printf("\nArea:");
            fflush(stdin);
            gets(p[i].area);
            printf("\nData de Chegado do livro:");
            printf("\nDia:");
            scanf("%d",&p[i].data.dia);
            printf("\nMes:");
            scanf("%d",&p[i].data.mes);
            printf("\nAno:");
            scanf("%d",&p[i].data.ano);
        }else
        printf("A biblioteca esta cheia");
}

void listarLivro(LIVRO *p,int n){
    int i;
        for(i=0;i<n;i++){
            if(p[i].ocopacao==1){
                printf("\nTitulo:%s",p[i].titulo);
                printf("\nAutor:%s",p[i].autor);
                printf("\nArea:%s",p[i].area);
                printf("\nData");
                printf("\n %d/%d/%d",p[i].data.dia,p[i].data.mes,p[i].data.ano);
                printf("\n-------------------------");
            }
        }
}
void removerLivro(LIVRO *p,int n){
    int i;
    char tituloremo[30];
    printf("\nQual e o titulo do livro que quer remover:");
    fflush(stdin);
    gets(tituloremo);
        for(i=0;i<n;i++){
            if(strcmp(tituloremo,p[i].titulo)==0){
                p[i].ocopacao=0;
            }

        }
}
main(){
    int n,opcao;
    printf("\nQuantos livros a biblioteca consegue ter:");
    scanf("%d",&n);

    LIVRO bilio[n];
    inicializacao(bilio,n);
    do{
        printf("\nMENU");
        printf("\n1-Inserir Livro");
        printf("\n2-Listar Livro");
        printf("\n3-Remover Livro");
        printf("\n Qual opcao escolhe:");
        scanf("%d",&opcao);
        switch (opcao){
        case 1:
            adicionarLivro(bilio,n);
            break;
        case 2:
            listarLivro(bilio,n);
            break;
        case 3:
            removerLivro(bilio,n);
            break;
        default:
            break;
        }  
    }while (opcao!= 0);
 
 
}
