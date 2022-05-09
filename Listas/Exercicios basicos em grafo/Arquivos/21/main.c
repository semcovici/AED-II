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
    NO* inicio;    
} VERTICE;

/*busca a aresta que conecta i e j*/
NO* buscaArestaGLL(VERTICE* g, int i, int j, NO** ant){
    *ant = NULL;
    NO* p = g[i].inicio;

    while(p){
        if(p->v == j) return p;
        *ant = p;
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

bool excluirAresta(VERTICE* g, int i, int j){
    
    NO* ant;
    NO* atual = buscaArestaGLL(g,i,j,&ant);

    if(!atual) return false; //não existe essa aresta, logo não pode excluir-la
		
    if(ant == NULL) {
        ant->prox = atual->prox;
    }else {
        g[i].inicio = atual -> prox;
    }

    free(atual);

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

bool ehCompleto(VERTICE* g){

    int cont;
    int i;
    for(i=0; i<V; i++){
        
        cont = 0;
        NO* p = g[i].inicio;
        while(p){
            cont ++;
            p=p->prox;
        }  

        if(cont != V - 1) return false;
    }
    
    return true;
}

void GCompletoLL(VERTICE* g){

    int i, j;
    for(i=0; i<V; i++){
        for(j=0; j<V; j++){
            if(i==j) continue;
            inserirArestaGLL(g,i,j);
        }
    }

} 

VERTICE* geraComplemento(VERTICE* g, VERTICE* complemento){

    int i, j, existe;
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){

            NO* p = g[i].inicio;
            existe = -1;

            while(p){
                
                if(p->v==j) existe = 1;

                p=p->prox;
            }

            if(existe==-1){
                inserirArestaGLL(complemento,i,j);
            }
        }
    }

    return complemento;
}

int main(){

    VERTICE* g = (VERTICE*) malloc(sizeof(VERTICE)*V);
    inicializarGLL(g);

    inserirArestaGLL(g,1,2);
    inserirArestaGLL(g,2,2);
    inserirArestaGLL(g,3,2);
    inserirArestaGLL(g,4,2);
    inserirArestaGLL(g,3,4);
    inserirArestaGLL(g,0,2);
    inserirArestaGLL(g,0,1);

    puts("------GRAFO G-----");
    imprimeGLL(g);

    
    VERTICE* complemento = (VERTICE*)malloc(sizeof(VERTICE)*V);
    inicializarGLL(complemento);

    complemento = geraComplemento(g, complemento);

    puts("-----COMPLEMENTO DE G------");
    imprimeGLL(complemento);

    return 0;
}