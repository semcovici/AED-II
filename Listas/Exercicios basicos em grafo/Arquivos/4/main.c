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

void copiaTransposta(int g[V][V], int c[V][V]){

    int i,j, temp;
    for(i=0; i<V; i++)
        for(j=0; j<V; j++)
            c[i][j] = g[j][i];
}

void imprimeArestasExistentes(int g[V][V]){
    int i,j;

    for(i=0; i<V; i++)
        for(j=0;j<V; j++)
                if(g[i][j] != 0){
                     printf ("\nElemento[%d][%d] = %d\n", i, j, g[i][j]);
                }              
}


int main(){
    int g[V][V];
    int c[V][V];

    inicializarGrafo(g);
    inicializarGrafo(c);

    inserirAresta(0,3,g);
    inserirAresta(3,4,g);
    inserirAresta(4,2,g);
    inserirAresta(2,3,g);

    copiaTransposta(g,c);

    puts("grafo");
    imprimeArestasExistentes(g);
    puts("grafo transposto");
    imprimeArestasExistentes(c);

    return 0;
}