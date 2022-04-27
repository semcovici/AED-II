#include <stdio.h>

#define V 5

void inicializarGrafo(int g[V][V]){
    int i,j;
    for(i=0; i<V; i++)
        for(j=0; j<V; j++)
            g[i][j] = 0;
}

void grafoCompletasso(int g[V][V]){
    int i,j;
    for(i=0; i<V; i++)
        for(j=0; j<V; j++)
            g[i][j] = 1;
}

void imprimeGrafo(int g[V][V]){
    int i,j;

    for(i=0; i<V; i++)
        for(j=0;j<V; j++)
                printf ("\nElemento[%d][%d] = %d\n", i, j, g[i][j]);
}

void inserirAresta(int i, int j, int g[V][V]){
    g[i][j] = 1;
}

void destruirArestas(int g[V][V]){
    int i,j;
    for(i=0; i<V; i++)
        for(j=0; j<V; j++)
            g[i][j] = 0;
}


int main(){
    int g[V][V];

    inicializarGrafo(g);
    grafoCompletasso(g);
    imprimeGrafo(g);

    destruirArestas(g);

    imprimeGrafo(g);

    return 0;
}