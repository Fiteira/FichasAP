#include<stdio.h>



/*int stren(char *p){
    int cont;
    cont=0;
    while (p[cont]!='\0')
    {
       cont++;
    }
    return cont;
}*/

void strCncat(char *p,char *p1){
    int cont,cont2,i;
    cont2=strlen(p1);
    while (p[cont]!='\0')
    {
        cont++;
    }
        for(i=0;i<cont2;i++){
            p[cont]=p1[i];
            cont++;
        }

}

main(){

    char p[40] ,p1[20];
    printf("Introduza uma string: ");
    fflush(stdin);
    gets(p);
    printf("Introduza uma string 2: ");
    fflush(stdin);
    gets(p1);
    //printf("\n%d",stren(p));
    strCncat(p,p1);
    printf("\n%s",p);


}