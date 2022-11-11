//
//  funcs.c
//  OrdenEPesquisaVectStructV2
//
//  Created by Jorge Alexandre de Albuquerque Loureiro on 18/12/18.
//  Copyright © 2018 Jorge Alexandre de Albuquerque Loureiro. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#define MAX 999

typedef int dado;
typedef struct 
{
    int ano, mes, dia;
}DATA;
typedef struct pessoa
{
//poder-se-ia declarar a estrutura, independente do tipo, para uso posterior
    short num;
    char nome[60];
    DATA nascimento;
    char genero;
    float altura;
    float peso;
    char habilitacoes[40];
    float salario;
    DATA dtActualizacao;
} PESSOA;

typedef char Inf[50];
typedef struct Habil
{
    char str[50];
} HABIL;

typedef struct vectPess
{
    int nl;
    Inf *dad;
} VECTPESSOA;
void mostrarP(PESSOA x);
// alocar memoria para o vector onde ficam os nomes das pessoas provindos dos ficheiros texto
Inf *alocarMemoria(int n)
{
    // alocar memoria para o vector onde ficam os nomes
    Inf* p;
    p = (Inf*) malloc(n * sizeof(Inf));
    return p;
}

void mostraErro(void)
{
    int errnum;
    fprintf(stderr, "\n\nImpossivel abrir o ficheiro!!!\n");
    errnum = errno;
    fprintf(stderr, "Código do erro: %d\n", errno);
    perror("Descrição do erro havido: ");
    fprintf(stderr, "Erro na abertura do ficheiro: %s\n", strerror( errnum ));
}

// Função que vai ler o ficheiro e devolve o número de linhas existentes no ficheiro
int leFichTxt(VECTPESSOA *p, char *nome, int grava)
{
    FILE *file;
    char str[MAX];
    char *teste;
    int i=0;
    file=fopen(nome, "r");
    if(file == NULL)
    {
        mostraErro();
    }
    else
        do
        {
            teste=fgets(str, MAX, file);
            if (teste != NULL)
            {
                if (grava==1)
                {
                    strcpy(p->dad[i], str);
                }
                i++;
            }
        } while (!feof(file));
    fclose(file);
    return i;
}

/* função que vai gerar a informação relativa a cada pessoa (correspndente aos campos da estrutura PESSOA)
 Gera:  o cod. da pessoa, um número aleatório entre 1 e 1000;
 o género (M/F), gerado igualmente de forma aleatória
 o nome da pessoa, utilizando, numa primeira fase, nomes colocados nos próprios campos;
 numa 2.ªfase, usar ficheiros com nomes e apelidos de pessoas e combiná-los
 de forma aleatória (respeitando o género), gerando assim nomes a colocar no campo nome do vector de pessoas;
 a data de nascimento, gerando anos, meses e dias, de forma aleatória, mas respeitando valores para datas válidas
 a altura, usando uma lógica, atendendo á idade
 o peso, idem à condição anterior;
 as habilitações literárias (utilizando um conjunto de habilitações, guardadas num vector),
 do qual é depois seleccionada, aleatoriamente, uma;
 o vencimento, gerado aleatoriamente, entre 770 e 5000;
 a data de actualização, colocando a data do sistema, sempre que haja uma alteração a qualquer dos dados de uma pessoa.
 
 - o 1.º parâmetro é o vector onde serão colocados os dados; o 2.º param. é o tamanho do vector;
 - o 3.º parâmetro indica o limite sup. do intervalo de geração dos números [0-limsup];
 */

void gerarDadosP(PESSOA *vectP, int tam, int limSup)
{
    int i;
    int numb; //nLinhas;
    int idade;
    //VECTPESSOA nom;
    //HABIL habilitLit[20];
    //HABIL *P=habilitLit;
    
    
    // gerar o codigo das pessoas
    for (i = 0; i < tam; i++)
    {
        // gerando valores aleatórios entre zero e 1000
        numb=rand() % 1000;
        (vectP+i)->num=numb;
    }
    
    // Gerar o género
    for (i = 0; i < tam; i++)
    {
        /* gerando valores aleatórios entre 0 e 1 */
        numb=(rand() % 2);
        if(numb==0)
            (vectP+i)->genero = 'M';
        else
            (vectP+i)->genero = 'F';
    }
    
     // Gerar nomes (1.ª solução): usar nomes e registá-los, apenas
     strcpy(vectP[0].nome,"Antonio Ferreira");
     strcpy(vectP[1].nome,"Manuel Maria Coelho");
     strcpy(vectP[2].nome,"Jose Manuel Silva");
     strcpy(vectP[3].nome,"Zeferino Ferreira");
     strcpy(vectP[4].nome,"Joao Fialho Gabriel");
     strcpy(vectP[5].nome,"Luis Antonio Ferreira");
     strcpy(vectP[6].nome,"Ana Maria Ferreira Loureiro");
     strcpy(vectP[7].nome,"Joana Alexandra Melo y Olazabal");
     strcpy(vectP[8].nome,"Carolina Loureiro");
     strcpy(vectP[9].nome,"Jorge Alexandre Ferreira");
     strcpy(vectP[10].nome,"Carlos Manuel Gama Simões");
     strcpy(vectP[11].nome,"Andre Domingues dso Santos Ferreira");
     strcpy(vectP[12].nome,"João Gabriel Santos de Almeida");
     strcpy(vectP[13].nome,"Manuel Renato da Silva Coelho");
     strcpy(vectP[14].nome,"Rui Filipe de Amaral Ferreira");
     strcpy(vectP[15].nome,"Luis Rafael da Gama Pereira");
     strcpy(vectP[16].nome,"Joaquim manuel da Silva Loureiro");
     strcpy(vectP[17].nome,"Maria Madalena da Costa Vieira");
     strcpy(vectP[18].nome,"Luisa Maria da Conceição Dantas");
     strcpy(vectP[19].nome,"Cesar Augusto da Silva Marado");
     strcpy(vectP[20].nome,"Jorge Manuel Alexandre Pontes Martins");
     strcpy(vectP[21].nome,"Manuel Alexandre Silva Pereira");
     strcpy(vectP[22].nome,"Joao Manuel da Silva Baltazar");
     strcpy(vectP[23].nome,"Fausto Miguel Alexandre de Albuquerque");
     strcpy(vectP[24].nome,"Jose Baptista Ferreira de Carvalho");
     strcpy(vectP[25].nome,"Ana Filipa de Oliveira Santos");
    
    // Gerar datas de nascimento
    for (i = 0; i < tam; i++)
    {
        /* gerando valores aleatórios entre  1 e 105 para somar a 1910 e gerar ano de nascimento */
        numb=rand() % 105;
        (vectP+i)->nascimento.ano=1910+numb;
        /* gerando valores aleatórios entre 1 e 12 para ser o mês */
        numb=(rand() % 11) + 1;
        (vectP+i)->nascimento.mes=numb;
        if (numb == 1 || numb == 3 || numb == 5 || numb == 7 || numb == 8 || numb == 10 || numb == 12)
        {
            /* gerando valores aleatórios entre 1 e 31 para ser o dia */
            numb=(rand() % 30) + 1;
            (vectP+i)->nascimento.dia=numb;
        }
        else if (numb == 4 || numb == 6 || numb == 9 || numb == 11)
        {
            /* gerando valores aleatórios entre 1 e 30 para ser o dia */
            numb=(rand() % 29) + 1;
            (vectP+i)->nascimento.dia=numb;
        }
        else if (numb == 2)
        {
            int ano=(vectP+i)->nascimento.ano;
            if (((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0))
            {
                // gerar valores aleatórios entre 1 e 29 para ser o dia de ano bissexto
                numb=(rand() % 28) + 1;
                (vectP+i)->nascimento.dia=numb;
            }
            else
            {
                // gerar valores aleatórios entre 1 e 28 para ser o dia de ano comum
                numb=(rand() % 27) + 1;
                (vectP+i)->nascimento.dia=numb;
            }
        }
        else
        {
            printf("Mês numb %d inválido!!", numb);
            getchar();
            printf("digite <Enter> para continuar...");
            getchar();
        }
    }
    
    // gerar altura entre 50 cm e 220 cm
    for (i = 0; i < tam; i++)
    {
        idade=2018 - (vectP+i)->nascimento.ano;
        //printf("Idade 1: %d\n", idade);
        if (idade>1 && idade < 5)
        {
            /* gerando valores aleatórios entre 86 e 100 */
            numb=rand() % 14;
            (vectP+i)->altura=(float)(numb+86)/100;
        }
        else if (idade>4 && idade < 8)
        {
            /* gerando valores aleatórios entre 101 e 120 */
            numb=rand() % 19;
            (vectP+i)->altura=(float)(numb+101)/100;
        }
        else if (idade>7 && idade < 12)
        {
            /* gerando valores aleatórios entre 121 e 140 */
            numb=rand() % 19;
            (vectP+i)->altura=(float)(numb+121)/100;
            if((vectP+i)->genero == 'F')
                (vectP+i)->altura-=0.05;
        }
        else if (idade>11 && idade < 15)
        {
            /* gerando valores aleatórios entre 141 e 165 */
            numb=rand() % 24;
            (vectP+i)->altura=(float)(numb+135)/100;
            if((vectP+i)->genero == 'F')
                (vectP+i)->altura-=0.07;
        }
        else if (idade>14 && idade < 17)
        {
            /* gerando valores aleatórios entre 166 e 190 */
            numb=rand() % 24;
            (vectP+i)->altura=(float)(numb+166)/100;
            if((vectP+i)->genero == 'F')
                (vectP+i)->altura-=0.1;
        }
        else if (idade>18 && idade < 22)
        {
            /* gerando valores aleatórios entre 191 e 220 */
            numb=rand() % 29;
            (vectP+i)->altura=(float)(numb+191)/100;
            if((vectP+i)->genero == 'F')
                (vectP+i)->altura-=0.15;
        }
        else if (idade>21 && idade < 110)
        {
            /* gerando valores aleatórios entre 170 e 200 */
            numb=rand() % 30;
            (vectP+i)->altura=(float)(numb+170)/100;
            if((vectP+i)->genero == 'F')
                (vectP+i)->altura-=0.1;
        }
    }
    
    // gerar peso entre 2 Kg e 220 Kg
    // melhorar para gerar pesos com lógica (atendendo à idade, e usando intervalos)
    for (i = 0; i < tam; i++)
    {
        /* gerando valores aleatórios entre 2 e 220 */
        idade=2018 - (vectP+i)->nascimento.ano;
        //printf("Idade 2: %d\n", idade);
        if (idade>1 && idade < 5)
        {
            numb=rand() % 20;
            (vectP+i)->peso=(numb+2);
        }
        else if (idade>4 && idade < 8)
        {
            numb=rand() % 10;
            (vectP+i)->peso=(numb+10);
        }
        else if (idade>7 && idade < 12)
        {
            numb=rand() % 15;
            (vectP+i)->peso=(numb+20);
        }
        else if (idade>11 && idade < 15)
        {
            numb=rand() % 20;
            (vectP+i)->peso=(numb+30);
        }
        else if (idade>14 && idade < 17)
        {
            numb=rand() % 30;
            (vectP+i)->peso=(numb+40);
        }
        else if (idade>18 && idade < 22)
        {
            numb=rand() % 50;
            (vectP+i)->peso=(numb+60);
        }
        else if (idade>21 && idade < 110)
        {
            numb=rand() % 60;
            (vectP+i)->peso=(numb+60);
        }
    }
    
    // gerar habilitações literárias
    for (i = 0; i < tam; i++)
    {
        idade=2018 - (vectP+i)->nascimento.ano;
        //printf("Idade 3: %d\n", idade);
        if (idade>1 && idade < 6)
        {
            strcpy((vectP+i)->habilitacoes, "Pré-Primária");
        }
        else if (idade>5 && idade < 10)
        {
            strcpy((vectP+i)->habilitacoes, "1.º ciclo");
        }
        else if (idade>9 && idade < 12)
        {
            numb=rand() % 10;
            if(numb < 2)
                strcpy((vectP+i)->habilitacoes, "1.º ciclo");
            else
                strcpy((vectP+i)->habilitacoes, "2.º ciclo");
        }
        else if (idade>11 && idade < 16)
        {
            numb=rand() % 30;
            if(numb < 2)
                strcpy((vectP+i)->habilitacoes, "1.º ciclo");
            else if (numb> 2 && numb < 3)
                strcpy((vectP+i)->habilitacoes, "2.º ciclo");
            else if (numb> 3 && numb < 8)
                strcpy((vectP+i)->habilitacoes, "Curso Prof. Eq. 3.º Ciclo");
            else
                strcpy((vectP+i)->habilitacoes, "3.º ciclo");
        }
        else if (idade>15 && idade < 17)
        {
            numb=rand() % 30;
            if(numb < 2)
                strcpy((vectP+i)->habilitacoes, "1.º ciclo");
            else if (numb> 2 && numb < 4)
                strcpy((vectP+i)->habilitacoes, "2.º ciclo");
            else if (numb> 3 && numb < 7)
                strcpy((vectP+i)->habilitacoes, "Curso Prof. Eq. 3.º Ciclo");
            else if (numb> 6 && numb < 10)
                strcpy((vectP+i)->habilitacoes, "3.º ciclo");
            else if (numb> 9 && numb < 15)
                strcpy((vectP+i)->habilitacoes, "Curso Prof. Eq. 3.º Ciclo");
            else
                strcpy((vectP+i)->habilitacoes, "Secundário");
        }
        else if (idade>18 && idade < 22)
        {
            numb=rand() % 30;
            if(numb < 2)
                strcpy((vectP+i)->habilitacoes, "1.º ciclo");
            else if (numb> 2 && numb < 5)
                strcpy((vectP+i)->habilitacoes, "2.º ciclo");
            else if (numb> 4 && numb < 8)
                strcpy((vectP+i)->habilitacoes, "3.º ciclo");
            else if (numb> 7 && numb < 15)
                strcpy((vectP+i)->habilitacoes, "Curso Profissional Eq. Secundário");
            else if (numb> 14 && numb < 20)
                strcpy((vectP+i)->habilitacoes, "Secundário");
            else if (numb> 16 && numb < 22)
                strcpy((vectP+i)->habilitacoes, "Licenciatura");
            else
                strcpy((vectP+i)->habilitacoes, "Pós-Graduação");
        }
        else if (idade>21 && idade < 30)
        {
            numb=rand() % 40;
            if(numb < 2)
                strcpy((vectP+i)->habilitacoes, "1.º ciclo");
            else if (numb> 2 && numb < 5)
                strcpy((vectP+i)->habilitacoes, "2.º ciclo");
            else if (numb> 4 && numb < 11)
                strcpy((vectP+i)->habilitacoes, "3.º ciclo");
            else if (numb> 10 && numb < 16)
                strcpy((vectP+i)->habilitacoes, "Curso Prof. Eq. 3.º Ciclo");
            else if (numb> 15 && numb < 21)
                strcpy((vectP+i)->habilitacoes, "Curso Profissional Eq. Secundário");
            else if (numb> 20 && numb < 32)
                strcpy((vectP+i)->habilitacoes, "Secundário");
            else if (numb> 31 && numb < 35)
                strcpy((vectP+i)->habilitacoes, "Pós-Graduação");
            else if (numb> 34 && numb < 38)
                strcpy((vectP+i)->habilitacoes, "Mestrado");
            else if (numb > 38 && numb < 40)
                strcpy((vectP+i)->habilitacoes, "Doutoramento");
            else
                strcpy((vectP+i)->habilitacoes, "Pós-Doutoramento");
        }
        else
        {
            numb=rand() % 40;
            if(numb < 3)
                strcpy((vectP+i)->habilitacoes, "1.º ciclo");
            else if (numb> 2 && numb < 6)
                strcpy((vectP+i)->habilitacoes, "2.º ciclo");
            else if (numb> 5 && numb < 14)
                strcpy((vectP+i)->habilitacoes, "3.º ciclo");
            else if (numb> 13 && numb < 17)
                strcpy((vectP+i)->habilitacoes, "Curso Prof. Eq. 3.º Ciclo");
            else if (numb> 16 && numb < 22)
                strcpy((vectP+i)->habilitacoes, "Curso Profissional Eq. Secundário");
            else if (numb> 21 && numb < 23)
                strcpy((vectP+i)->habilitacoes, "Novas Oportunidades Eq. Secundário");
            else if (numb> 20 && numb < 29)
                strcpy((vectP+i)->habilitacoes, "Secundário");
            else if (numb> 30 && numb < 35)
                strcpy((vectP+i)->habilitacoes, "Pós-Graduação");
            else if (numb> 34 && numb < 36)
                strcpy((vectP+i)->habilitacoes, "Mestrado");
            else if (numb > 37 && numb < 40)
                strcpy((vectP+i)->habilitacoes, "Doutoramento");
            else
                strcpy((vectP+i)->habilitacoes, "Pós-Doutoramento");
        }
    }
    
    
    // Gerar o valor do vencimento entre 700 e 4000, atendendo a escalões de habilitações literárias
    // Falta tratar os escalões
    for (i = 0; i < tam; i++)
    {
        /* gerando valores aleatórios entre 700 e 5000 */
        numb=(rand() % 4300) + 700;
        //printf("%d ", numb);
        
        (vectP+i)->salario = (float) numb;
    }
    // Gerar a data de actualização
    for (i = 0; i < tam; i++)
    {
        (vectP+i)->dtActualizacao.ano=2018;
        (vectP+i)->dtActualizacao.mes=12;
        (vectP+i)->dtActualizacao.dia=18;
    }
    PESSOA umaPessoa;
    printf("Vector gerado...\n");
    for (i=0; i<tam; i++)
    {
        umaPessoa=vectP[i];
        printf("Pessoa: %d\n", i+1);
        mostrarP(umaPessoa);
    }
    printf("\nDigite <enter> para continuar...");
    getchar();
}

void mostrarP(PESSOA x)
{
        printf("\nCódigo         : %d",       x.num);
        printf("\nNome	       : %s",       x.nome);
        printf("\nData nascimento: %d-%d-%d", x.nascimento.ano, x.nascimento.mes, x.nascimento.dia);
        printf("\nGénero         : %c", x.genero);
        printf("\nAltura         : %.2f",       x.altura);
        printf("\nPeso           : %.2f",       x.peso);
        printf("\nHabilitacoes   : %s",       x.habilitacoes);
        printf("\nSalario        : %.2f\n", x.salario);
        printf("\nData actualização dos dados: %d-%d-%d\n", x.dtActualizacao.ano, x.dtActualizacao.mes, x.dtActualizacao.dia);
        printf("---------------------------------------------------------\n");
}

void lerP(PESSOA *ptr)
{	printf("\nEscreva os dados correspondentes aos  itens seguintes\n");
    printf("\nNome: "); gets((*ptr).nome);
    printf("\nData nascimento (a m d): "); scanf("%d %d %d", &(*ptr).nascimento.ano, &(*ptr).nascimento.mes, &(*ptr).nascimento.dia);
    do {
        printf("Qual o género <M/F>: ");
        scanf("%c", &(*ptr).genero);
    } while (ptr->genero=='M' || ptr->genero=='F');
    
    do {
        printf("\nAltura: "); scanf("%f", &(*ptr).altura);
    } while (ptr->altura>=0.6 && ptr->altura<=2.2);
    
    printf("\nPeso: "); scanf("%f", &(*ptr).peso);
    printf("\nData nascimento (a m d): "); scanf("%d %d %d", &(*ptr).nascimento.ano, &(*ptr).nascimento.mes, &(*ptr).nascimento.dia);
    fflush(stdin);
    printf("\nHabilitacoes: "); gets(ptr->habilitacoes); // ptr-> é equivalente a *(ptr)
    printf("\nSalario: "); scanf("%f", &(*ptr).salario);
}


void trocaElemVectorP(PESSOA *vectP, int index1, int index2)
{
    PESSOA aux;
    aux = vectP[index1];
    vectP[index1] = vectP[index2];
    vectP[index2] = aux;
}

// método para ordenar um vector pelo método da selecção directa
void sortSelecaoDirectaP(PESSOA *vectP, int tam)
{
    int i, j, posMax;
    // vai ordenar o vector
    for (i = tam - 1; i > 0; i--)
    {
        posMax = i;
        for (j = 0; j <= i - 1; j++)
        {
            if (vectP[j].num > vectP[posMax].num)
                posMax = j;
        }
        trocaElemVectorP(vectP, i, posMax);
    }
}

// método para ordenar um vector pelo método da selecção directa (por nome, ascendente)
void sortSelecaoDirectaPNome(PESSOA *vectP, int tam)
{
    int i, j, posMax;
    // vai ordenar o vector
    for (i = tam - 1; i > 0; i--)
    {
        posMax = i;
        for (j = 0; j <= i - 1; j++)
        {
            if (strcmp(vectP[j].nome, vectP[posMax].nome)>0)
                posMax = j;
        }
        trocaElemVectorP(vectP, i, posMax);
    }
}

// método para ordenar um vector pelo método da selecção directa (por nome, descendente)
void sortSelecaoDirectaPNomeDesc(PESSOA *vectP, int tam)
{
    int i, j, posMax;
    // vai ordenar o vector
    for (i = tam - 1; i > 0; i--)
    {
        posMax = i;
        for (j = 0; j <= i - 1; j++)
        {
            if (strcmp(vectP[j].nome, vectP[posMax].nome)<0)
                posMax = j;
        }
        trocaElemVectorP(vectP, i, posMax);
    }
}

// método para ordenar um vector pelo método da inserção directa por código
void sortInsercaoDirectaP(PESSOA *vectP, int tam)
{
    // vai ordenar o vector
    PESSOA tmp;
    int i, j;
    for (i = 1; i < tam; i++)
    {
        tmp = vectP[i];
        j = i;
        while (j > 0 && vectP[j - 1].num > tmp.num)
        {
            vectP[j] = vectP[j - 1];
            j--;
        }
        vectP[j] = tmp;
    }
}

// método para ordenar um vector pelo método da inserção directa por nome ascendente
void sortInsercaoDirectaPNome(PESSOA *vectP, int tam)
{
    // vai ordenar o vector
    PESSOA tmp;
    int i, j;
    for (i = 1; i < tam; i++)
    {
        tmp = vectP[i];
        j = i;
        while (j > 0 && strcmp(vectP[j - 1].nome, tmp.nome)>0)
        {
            vectP[j] = vectP[j - 1];
            j--;
        }
        vectP[j] = tmp;
    }
}

// método para ordenar um vector pelo método da inserção directa por nome descendente
void sortInsercaoDirectaPNomeDesc(PESSOA *vectP, int tam)
{
    // vai ordenar o vector
    PESSOA tmp;
    int i, j;
    for (i = 1; i < tam; i++)
    {
        tmp = vectP[i];
        j = i;
        while (j > 0 && strcmp(vectP[j - 1].nome, tmp.nome)<0)
        {
            vectP[j] = vectP[j - 1];
            j--;
        }
        vectP[j] = tmp;
    }
}

// método para ordenar por código um vector pelo método BubbleSort por código ascendente
void bubbleSortP(PESSOA *vectP, int tam)
{
    int i, j;
    // vai ordenar o vector de saída
    for (i = 0; i < tam - 1; i++)
    {
        for (j = 0; j < tam - 1; j++)
            
        {
            // compara elementos adjacentes para ver se estão fora de ordem
            if (vectP[j].num > vectP[j + 1].num)
                trocaElemVectorP(vectP, j, j + 1);
        }
    }
}


// método para ordenar um vector pelo método FastBubbleSort por código ascendente
void fastBubbleSortP(PESSOA *vectP, int tam)
{
    int houveTroca = 1;
    while (houveTroca)
    {
        houveTroca = 0;
        for (int j = 0; j < tam - 1; j++)
        {
            // compara elementos adjacentes para ver se estão fora de ordem
            if (vectP[j].num > vectP[j + 1].num)
            {
                trocaElemVectorP(vectP, j, j + 1);
                houveTroca = 1;
            }
        }
    }
}

// método para ordenar um vector por código pelo método ShakerSort por código ascendente
void shakerSortP(PESSOA *vectP, int tam)
{
    // vai ordenar o vector de saída
    {
        int inf = 0, sup = tam - 1, ultimaTroca = 0, i;
        do
        {
            for (int i = inf; i < sup; i++)     // percorre para a direita
            {
                if (vectP[i].num > vectP[i + 1].num)
                {
                    trocaElemVectorP(vectP, i, i + 1); // troca elementos
                    ultimaTroca = i;
                }
            }
            sup = ultimaTroca;
            for (i = sup; i > inf; i--)     // percorre para a esquerda
            {
                if (vectP[i].num < vectP[i - 1].num)
                {
                    trocaElemVectorP(vectP, i, i - 1); // troca elementos
                    ultimaTroca = i;
                }
            }
            inf = ultimaTroca;
        }
        while (inf < sup);
    }
}


// método para ordenar um vector pelo método ShellSort
/*
 *  Shellsort is a simple extension of insertion sort which gains speed
 * by allowing exchanges of elements that are far apart. The idea is
 * to rearrange the array to give it the property that every hth
 * element (starting anywhere) yields a sorted array. Such an array
 * is said to be h-sorted.
 *
 * By h-sorting for some large values of h, we can move elements in
 * the array long distances and thus make it easier to h-sort for
 * smaller values of h. Using such a procedure for any sequence of
 * values h which ends in 1 will produce a sorted array.
 *
 */

// Por código, ascendente

void ShellSortV1P(PESSOA *vectP, int tam)
{
    int inner;
    PESSOA temp;
    int h = 1;
    // find the largest h value possible
    while (h <= tam / 3)
        h = h * 3 + 1;
    while (h > 0)
    {
        for (int outer = h; outer <= tam - 1; outer++)
        {
            temp = vectP[outer];
            inner = outer;
            while ((inner > h - 1) && vectP[inner - h].num >= temp.num)
            {
                vectP[inner] = vectP[inner - h];
                inner -= h;
            }
            vectP[inner] = temp;
        }
        h = (h - 1) / 3;
    }
}


// método para ordenar um vector por nome pelo método ShellSort Versão 1 por nome
void ShellSortV1PNome(PESSOA *vectP, int tam)
{
    int inner;
    PESSOA temp;
    int h = 1;
    // find the largest h value possible
    while (h <= tam / 3)
        h = h * 3 + 1;
    while (h > 0)
    {
        for (int outer = h; outer <= tam - 1; outer++)
        {
            temp = vectP[outer];
            inner = outer;
            // while ((inner > h - 1) && vectP[inner - h].num >= temp.num)
            while ((inner > h - 1) && strcmp(vectP[inner - h].nome, temp.nome)>0)
            {
                vectP[inner] = vectP[inner - h];
                inner -= h;
            }
            vectP[inner] = temp;
        }
        h = (h - 1) / 3;
    }
}


// método para ordenar um vector por nome pelo método ShellSort Versão 2 por nome

void ShellSortV2P(PESSOA *vectP, int tamVect)
{
    PESSOA tmp1, tmp2;
    int intervalo;
    int houveTroca;
    intervalo=tamVect/2;
    do
    {
        do
        {
            houveTroca = 0;
            for (int i = 0; i < tamVect - intervalo; i++)
            {
                tmp1=vectP[i];
                tmp2=vectP[i + intervalo];
                
                if ((strcmp(vectP[i].nome, vectP[i + intervalo].nome) > 0))
                {
                    trocaElemVectorP(vectP, i, i + intervalo);
                    houveTroca = 1;
                }
            }
        }
        while (houveTroca);
        intervalo /= 2;
    }
    while (intervalo > 0);
}

// método para ordenar um vector por nome pelo método ShellSort Versão 3

void ShellSortV3P(PESSOA *vectP, int tamVect)
{
    int i, j, increment;
    increment = 3;
    PESSOA temp;
    while (increment > 0)
    {
        for (i=0; i < tamVect; i++)
        {
            j = i;
            temp = vectP[i];
            while ((j >= increment) && (vectP[j-increment].nome > temp.nome))
            {
                vectP[j]=vectP[j - increment];
                j = j - increment;
            }
            vectP[j]=temp;
        }
        if (increment/2 != 0)
            increment = increment/2;
        else if (increment == 1)
            increment = 0;
        else
            increment = 1;
    }
}

int partition(PESSOA *vectP, int tam, int first, int last)
{
    PESSOA pivotVal = vectP[first];
    int theFirst = first;
    int okSide;
    first++;
    do
    {
        okSide = 1;
        while (okSide)
        {
            if (vectP[first].num > pivotVal.num)
                okSide = 0;
            else
            {
                first++;
                okSide = (first <= last);
            }
        }
        okSide = (first <= last);
        while (okSide)
        {
            if (vectP[last].num <= pivotVal.num)
                okSide = 0;
            else
            {
                last--;
                okSide = (first <= last);
            }
        }
        if (first < last)
        {
            trocaElemVectorP(vectP, first, last); // troca elementos
            first++;
            last--;
        }
    } while (first <= last);
    trocaElemVectorP(vectP,theFirst, last);
    return last;
}

// método para ordenar um vector pelo método QuickSort por código da pessoa
// versão que mostra a utilização do algoritmo de partição
void QuickSortV1P(PESSOA *vectP, int tam, int first, int last)
{
    PESSOA pivot; int part;
    if ((last - first) <= 0)
        return;
    else
    {
        pivot.num = vectP[last].num;
        part = partition(vectP, tam, first, last);
        QuickSortV1P(vectP, tam, first, part - 1);
        QuickSortV1P(vectP, tam, part + 1, last);
    }
}

// método para pesquisar um vector sequencialmente (linear) por código
int seqSearchP(PESSOA *vectP, int tamVect, int chave)
{
    int indice = 0;
    while (indice < tamVect && vectP[indice].num != chave)
    {
        indice++;
    }
    if (indice < tamVect)
        return indice; // encontrou a chave
    else
        return -1; // não encontrou a chave
}

// método para pesquisar um vector sequencialmente (linear) por nome
int seqSearchPNome(PESSOA *vectP, int tamVect, char *chave)
{
    int indice = 0;
    printf("A chave para a pesquisa linear por nome: %s\n\n", chave);
    while (indice < tamVect && strcmp(vectP[indice].nome, chave)!=0)
    {
        indice++;
    }
    if (indice < tamVect)
        return indice; // encontrou a chave
    else
        return -1; // não encontrou a chave
}

// método para pesquisar um vector de forma binária iterativa por código
int PesquisaBinariaP(PESSOA *vectP, int tamVect, int chave)
{
    int indInf = 0, indMeio, indSup = tamVect - 1;
    while (indSup>=indInf)
    {
        indMeio = (indInf + indSup) / 2;
        if (vectP[indMeio].num == chave)
            return indMeio;
        else
        {
            if (vectP[indMeio].num < chave)
                indInf = indMeio + 1;
            else
                indSup = indMeio -1;
        }
    }
    return -1;
}

// método para pesquisar um vector de forma binária iterativa por nome
int PesquisaBinariaPNome(PESSOA *vectP, int tamVect, char *chave)
{
    int indInf = 0, indMeio, indSup = tamVect - 1;
    while (indSup>=indInf)
    {
        indMeio = (indInf + indSup) / 2;
        if (strcmp(vectP[indMeio].nome, chave)==0)
            return indMeio;
        else
        {
            if (strcmp(vectP[indMeio].nome, chave) <0)
                indInf = indMeio + 1;
            else
                indSup = indMeio -1;
        }
    }
    return -1;
}

// método para pesquisar um vector de forma binária recursiva por codigo
int PesquisaBinariaRecP(PESSOA *vectP, int tamVect, int indInf, int indSup, int chave)
{
    if (indInf > indSup)
        return -1;
    else
    {
        int indMeio;
        indMeio = (int)(indInf + indSup) / 2;
        if (chave < vectP[indMeio].num)
            return PesquisaBinariaRecP(vectP, tamVect, indInf, indMeio - 1, chave);
        else if (vectP[indMeio].num == chave)
            return indMeio;
        else
            return PesquisaBinariaRecP(vectP, tamVect, indMeio + 1, indSup, chave);
    }
}

// método para pesquisar um vector de forma binária recursiva por nome
int PesquisaBinariaRecPNome(PESSOA *vectP, int tamVect, int indInf, int indSup, char *chave)
{
    if (indInf > indSup)
        return -1;
    else
    {
        int indMeio;
        indMeio = (int)(indInf + indSup) / 2;
        if (strcmp(chave, vectP[indMeio].nome)<0)
            return PesquisaBinariaRecPNome(vectP, tamVect, indInf, indMeio - 1, chave);
        else if (strcmp(vectP[indMeio].nome, chave)==0)
            return indMeio;
        else
            return PesquisaBinariaRecPNome(vectP, tamVect, indMeio + 1, indSup, chave);
    }
}
