#include <stdio.h>
#include <stdlib.h>

#define V 5

typedef int bool;
#define true 1
#define false 0

typedef struct s{
    int v;//vertice
	struct s* prox;
}NO;

typedef struct z{
    int flag;
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
        printf("VERTICE %i->flag:%i\n", i, g[i].flag);
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


void inicializaFlag(VERTICE* g){

    int i;
    for(i=0; i<V; i++){
        g[i].flag = 0;
    }
}

int existeCaminho(VERTICE* g, int a, int b, int cont){

    g[a].flag = 1;
    
    if(a>=V || b>=V) return cont;

    if(a == b) return cont;//existe = true

    NO* p = g[a].inicio;

    while(p){

        cont ++;

        if(g[p->v].flag == 0){

            existeCaminho(g, p->v, b, cont);
        }

        p = p->prox;
    }
    g[a].flag = 2;

    return cont;
}

int main(){

    VERTICE* g = (VERTICE*) malloc(sizeof(VERTICE)*V);
    inicializarGLL(g);
    inicializaFlag(g);    

    inserirArestaGLL(g,0,1);
    inserirArestaGLL(g,1,0);

    inserirArestaGLL(g,2,3);
    inserirArestaGLL(g,3,2);

    inserirArestaGLL(g,3,4);
    inserirArestaGLL(g,4,3);

    inserirArestaGLL(g,4,2);
    inserirArestaGLL(g,2,4);

    imprimeGLL(g);

    int cont = 0;

    cont = existeCaminho(g, 4, 4, cont);

    printf("askljfblakdsfb: %i\n", cont);

    return 0;
}