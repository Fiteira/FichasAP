#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <errno.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX 5
# define INC_LIVROS 3 // numero de livros a acrescentar � lista, em cada incremento

#define STRING char *
#define MAX_LINHA_FICHEIRO 150

typedef char LinhaTexto[MAX_LINHA_FICHEIRO];


typedef struct livro
{
    char ISBN[26];
    char titulo[31];
    char autor[31];
    char area[21];
    int ano;
} LIVRO;

typedef LIVRO Informacao;

typedef struct
{
    int nLivros;
    int tamLista;
    Informacao *dados_Inic;
    Informacao *dados;
} ListLivros;

ListLivros *AlocarLista(int nL,int nSize);
ListLivros *ReAlocarLista(ListLivros *L, int nElem);
int menu(void);
void inserir_ISBN(ListLivros *L);
void apagar_ISBN(ListLivros *L);
void apagar_Nome(ListLivros *L);
void mostrar_ISBN(ListLivros *L);
void mostrar_Nome(ListLivros *L) ;
void gravarListaFicheiroTexto_ISBN(ListLivros *L);
void escreveFicheiro_ISBN(ListLivros *L);
void leFicheiro_ISBN(ListLivros *L);
void leFicheiro_ISBN_princ(ListLivros *L);
void exportarFichTexto_ISBN(ListLivros *L, char *NFich, char *sep);
int importarFicheiroTexto_ISBN(ListLivros *L, char *NFich, char *sep);
int testaLeitura(void);
int main()  //:::::::::::::::::::::::::::::::::::::::::::::::::::::::
{
    ListLivros *List;
    ListLivros *ListCop;
    List = AlocarLista(0, INC_LIVROS);
    int opcao, resLeitura=0;
    do
    {
        // system("cls"); //em Windows
        //system("clear"); //em Linux e MacOS

        opcao = menu();
        switch (opcao)
        {
            case 1: inserir_ISBN(List);                      break;
            case 2: apagar_ISBN(List);                  break;
            case 3: apagar_Nome(List);                  break;
            case 4: mostrar_ISBN(List);                 break;
            case 5: mostrar_Nome(List);                 break;
            case 6: escreveFicheiro_ISBN(List);         break;
            case 7: ListCop = AlocarLista(List->nLivros, List->tamLista);
                    leFicheiro_ISBN(ListCop);
                    mostrar_ISBN(ListCop);
                    free(ListCop->dados); free(ListCop); break;
            case 8: leFicheiro_ISBN_princ(List);        break;
            case 9: gravarListaFicheiroTexto_ISBN(List); break;
            case 10: exportarFichTexto_ISBN(List, "fichExport.txt", "\t"); break;
            case 11: resLeitura=importarFicheiroTexto_ISBN(List, "fichExport.txt", "\t\r\n");
                    if (resLeitura==-1)
                        printf("Erro! N�o foi poss�vel abrir o ficheiro");
                                                        break;
            case 0: exit(0);
        }
        fflush(stdin);
        printf("\n\n");
        // system("pause");
    } while (opcao != 0);
    List->dados=List->dados_Inic;
    free(List->dados);
    free(List);
    printf("Digite <enter> para terminar...");
    getchar();

    return 0;
}



