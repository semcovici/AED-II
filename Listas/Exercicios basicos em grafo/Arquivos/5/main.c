#include <stdio.h>
#include <stdlib.h>

#define V 5

typedef int bool;
#define true 1
#define false 0

typedef struct s{
    int v;
	struct s* prox;
}NO;

typedef struct z{
    NO* inicio;    
} VERTICE;

/*busca a aresta que conecta i e j*/
NO* buscaArestaGLL(VERTICE* g, int i, int j, NO* ant){
    ant = NULL;
    NO* p = g[i].inicio;

    while(p){
        if(p->v == j) return p;
        ant = p;
        p=p->prox;
    }

    return NULL;
}

bool inserirArestaGLL(VERTICE* g, int i, int j){
    NO* ant;
    NO* atual = buscaArestaGLL(g,i,j,&ant);

    if(atual) return false;

    atual = (NO*)malloc(sizeof(NO));
    atual -> v = j;
		
    atual->prox = g[i].inicio;
    g[i].inicio = atual;

	return true;
}

void imprimeGLL(VERTICE* g){

    int i;
    for(i=0; i<V; i++){

        NO* p = g[i].inicio;
        printf("VERTICE %i\n", i);
        while(p){

            printf("%i\n", p->v);
            p = p->prox;
        }
    }
}

void inicializarGLL(VERTICE* g){
    
    int i;
    for(i=0; i<V; i++){
        g[i].inicio = NULL;
    }
}

void imprimeGMatriz(int g[V][V]){
    int i,j;

    for(i=0; i<V; i++)
        for(j=0;j<V; j++)
                printf ("\nElemento[%d][%d] = %d\n", i, j, g[i][j]);
}

void inicializarGMatriz(int g[V][V]){
    int i,j;
    for(i=0; i<V; i++)
        for(j=0; j<V; j++)
            g[i][j] = 0;
}

void inserirArestaGM(int g[V][V], int i, int j){
    g[i][j] = 1;
}

void grafoCompletasso(int g[V][V]){
    int i,j;
    for(i=0; i<V; i++)
        for(j=0; j<V; j++)
            g[i][j] = 1;
}

void transformaGMemLL(int m[V][V], VERTICE* g){

    int i, j;
    for(i=0; i<V; i++){
        for(j=0; j<V; j++){
            if(m[i][j] != 0){
                inserirArestaGLL(g,i,j);
            }
        }
    }
}

int main(){

    int m[V][V];
    inicializarGMatriz(m);
    
    VERTICE* g = (VERTICE*) malloc(sizeof(VERTICE)*V);
    inicializarGLL(g);

    grafoCompletasso(m);
    
    transformaGMemLL(m, g);

    imprimeGLL(g);

    return 0;
}