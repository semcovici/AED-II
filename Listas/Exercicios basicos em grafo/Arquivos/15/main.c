/*15. Seja um grafo gnão-conexo  e não-dirigido. 
Escreva uma função para contar a quantidade de grupos 
disjuntos de vértices mutuamente alcançáveis em g*/
#include <stdio.h>
#include <stdlib.h>

#define V 5
#define vazio 0

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

void prof(VERTICE* g, int i){

    g[i].flag = 1;//descoberto//*

    NO* p = g[i].inicio;
    while(p){

        if(g[p->v].flag == 0){

            prof(g,p->v);//percurso
        }
        p = p->prox;//proximo adjacente
    }
    g[i].flag = 2;//*
}

void inicializaFlag(VERTICE* g){

    int i;
    for(i=0; i<V; i++){
        g[i].flag = 0;
    }
}

int contaGruposDesconexos(VERTICE* g){

    int i;
    int grupos = 0;
    for(i=0; i<V; i++){

        if(g[i].flag == 0){
            
            prof(g, i);//marca as flags
            grupos ++;
        }
    }
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

    int grupos = contaGruposDesconexos(g);

    printf("grupos: %i\n", grupos);

    return 0;
}