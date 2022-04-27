#include <stdio.h>
#include <stdlib.h>

#define V 5

typedef int bool;
#define true 1
#define false 0

#define vazio 0

typedef struct s{
    int p;//peso
    int v;//vertice
	struct s* prox;
}NO;

typedef struct z{
    NO* inicio;    
} VERTICE;

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

void inicializarGM(int g[V][V]){
    int i,j;
    for(i=0; i<V; i++)
        for(j=0; j<V; j++)
            g[i][j] = vazio;
}

void inicializarGLL(VERTICE* g){
    
    int i;
    for(i=0; i<V; i++){
        g[i].inicio = NULL;
    }
}

bool inserirArestaGLL(VERTICE* g, int i, int j, int peso){
    NO* ant;
    NO* atual = buscaArestaGLL(g,i,j,&ant);

    if(atual) return false;

    atual = (NO*)malloc(sizeof(NO));
    atual -> v = j;
    atual -> p = peso;
		
    atual->prox = g[i].inicio;
    g[i].inicio = atual;

	return true;
}

void transformaGMemLL(int m[V][V], VERTICE* g){

    int i, j;
    for(i=0; i<V; i++){
        for(j=0; j<V; j++){
            if(m[i][j] != vazio){
                inserirArestaGLL(g,i,j, m[i][j]);
            }
        }
    }
}


//Arestas de g1 estao em g2?
bool subGrafo(VERTICE* g1, VERTICE* g2){
    int n1;
    for(n1 = 1; n1 <= V; n1 ++){
        NO* p1 = g1[n1].inicio;

        while(p1){
            int i = n1; 
            int j = p1->v;
            NO* ant;
            NO* aux = buscaAresta(g2,i,j,&ant);
            if(!aux || aux -> p != p1 -> p) return false;

            p1 = p1->prox;
        }
    }
    return true;
}




int main(){

    VERTICE* g = (VERTICE*) malloc(sizeof(VERTICE)*V);
    inicializarGLL(g);

    int m[V][V];
    inicializarGM(m);

    VERTICE* mLL = (VERTICE*)malloc(sizeof(VERTICE)*V);
    transformaGMemLL(m, mLL);


    if(subGrafo(g, mLL)){
        puts("Eh subgrafo");
    }
    else puts("Nao eh subgrafo");
    
}