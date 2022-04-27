#include <stdio.h>
#include <stdlib.h>

#define V 5

typedef int bool;
#define true 1
#define false 0

#define vazio 0

#define c 5

void imprimeArestasExistentes(int g[V][V]){
    int i,j;

    for(i=0; i<V; i++)
        for(j=0;j<V; j++)
                if(g[i][j] != vazio){
                     printf ("\nElemento[%d][%d] = %d\n", i, j, g[i][j]);
                }              
}

void inicializarGM(int g[V][V]){
    int i,j;
    for(i=0; i<V; i++)
        for(j=0; j<V; j++)
            g[i][j] = vazio;
} 

void inserirArestaGMPond(int g[V][V],int i, int j, int peso){
    g[i][j] = peso;
}

void verificaPesoMaiorQueC(int g[V][V], int copia[V][V]){
    
    int i, j;
    for(i=0; i<V; i++)
        for(j=0; j<V; j++)
            if(g[i][j] > c)
                copia[i][j] = g[i][j];
}

int main(){

    int g[V][V];
    inicializarGM(g);

    inserirArestaGMPond(g,1,1,10);
    inserirArestaGMPond(g,2,1,1);
    inserirArestaGMPond(g,3,1,2);
    inserirArestaGMPond(g,3,3,21);
    inserirArestaGMPond(g,2,4,4);
    inserirArestaGMPond(g,2,3,32);

    int copia[V][V];
    inicializarGM(copia);

    verificaPesoMaiorQueC(g, copia);

    puts("todos");
    imprimeArestasExistentes(g);

    puts("maiores que c");
    imprimeArestasExistentes(copia);

}