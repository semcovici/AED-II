/*20. Um grafo não dirigido é completo se 
todos seus vértices são adjacentes, ouseja, 
existe uma aresta conectando cada par de vértices 
de um grafo. Escrevaum algoritmo que, dado um 
grafo simples g, verifique se gé completo, 
retornando true/false conforme o caso.*/

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

int main(){

    VERTICE* g = (VERTICE*) malloc(sizeof(VERTICE)*V);
    inicializarGLL(g);
    inicializaFlag(g);    

    GCompletoLL(g);

    //excluirAresta(g,4,2);

    bool eh = ehCompleto(g);

    imprimeGLL(g);

    if (eh) printf("eh completo");
    else printf("nao eh completo");

    return 0;
}