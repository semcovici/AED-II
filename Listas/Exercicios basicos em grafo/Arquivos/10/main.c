#include <stdio.h>
#include <stdlib.h>

#define V 5
#define vazio 0
#define spam 1001

typedef int bool;
#define true 1
#define false 0

typedef struct s{
    int id;
    int v;//vertice
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

bool inserirArestaGLL(VERTICE* g, int i, int j, int id){
    NO* ant;
    NO* atual = buscaArestaGLL(g,i,j,&ant);

    if(atual) return false;

    atual = (NO*)malloc(sizeof(NO));
    atual -> v = j;
    atual -> id = id;
		
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
            printf("%i-id: %i\n", p->v, p->id);
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

/*k eh o que estamos verificando se eh suspeito*/
bool verificaSuspeito(VERTICE* g, int k){

    bool sus = false;

    int i;
    for(i=0; i<V; i++){

        NO* p = g[i].inicio;
            
            while(p){
                if(i != k){
                    if(p->v == k){
                        if(p-> id == spam){
                            return sus;
                        }
                    }
                }
                p= p->prox;
            }
    }
    sus = true;
    return sus;
}

void imprimeSuspeitos(VERTICE* g){

    int i;
    for(i=0; i<V; i++){
        if(verificaSuspeito(g, i)){
            printf("O user %i eh suspeito\n", i);
        }else{
            printf("O user %i nao eh suspeito\n", i);
        }
    }
}

int main(){

    VERTICE* g = (VERTICE*) malloc(sizeof(VERTICE)*V);
    inicializarGLL(g);

    inserirArestaGLL(g,2,3,spam);
    inserirArestaGLL(g,3,4,spam);
    inserirArestaGLL(g,3,1,spam);
    inserirArestaGLL(g,4,3,spam);
    inserirArestaGLL(g,4,1,spam);

    imprimeGLL(g);

    imprimeSuspeitos(g);

    
    return 0;
}