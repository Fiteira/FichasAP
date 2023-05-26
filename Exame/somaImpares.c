#include <stdio.h>

void somaImpares(int m){
    int i,qtosNumeros=0,menorImpar=0,somaImpares=0,impar=0;

    for(i=1;i<m;i++)
        qtosNumeros+=i;

    menorImpar=(qtosNumeros*2)+1;
    impar=menorImpar;

    for(i=0;i<m;i++){
        //printf("%d+",impar);
        somaImpares+=impar;
        impar+=2;
    }
    printf("= %d",somaImpares);

}
main(){
    int m=5;
    printf("%d ao cubo: ",m);
    somaImpares(m);
    printf("\n\n");
}