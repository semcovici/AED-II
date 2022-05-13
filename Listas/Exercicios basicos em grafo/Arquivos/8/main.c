/*8. Sejam dois grafos g1e g2contendo exatamente os mesmos vértices. 
Verifique se g2é um subgrafo de g1, retornando true/false conforme o caso. 
Para tornar o problema mais interessante, 
considere que um grafo é representado em listas e outro em matriz.*/
#include <stdio.h>
#include <stdlib.h>

#define V 5
#define vazio 0

typedef int bool;
#define true 1
#define false 0

typedef struct s{
    int p;//peso
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

void imprimeGLL(VERTICE* g){

    int i;
    for(i=0; i<V; i++){

        NO* p = g[i].inicio;
        printf("VERTICE %i\n", i);
        while(p){
            printf("%i-peso: %i\n", p->v, p->p);
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

void imprimeGM(int g[V][V]){
    int i,j;

    for(i=0; i<V; i++)
        for(j=0;j<V; j++)
                printf ("\nElemento[%d][%d] = %d\n", i, j, g[i][j]);
}

void inicializarGM(int g[V][V]){
    int i,j;
    for(i=0; i<V; i++)
        for(j=0; j<V; j++)
            g[i][j] = 0;
}

void inserirArestaGM(int g[V][V], int i, int j, int peso){
    g[i][j] = peso;
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
            if(m[i][j] != vazio){
                inserirArestaGLL(g,i,j, m[i][j]);
            }
        }
    }
}

//Arestas de g1 estao em g2?
bool subGrafo(VERTICE* g1, VERTICE* g2){
    
    int n1;
    for(n1 = 0; n1 < V; n1 ++){
        NO* p1 = g1[n1].inicio;

        while(p1){
            int i = n1; 
            int j = p1->v;
            NO* ant;
            NO* aux = buscaArestaGLL(g2,i,j,&ant);
            if(!aux || aux -> p != p1 -> p) return false;

            p1 = p1->prox;
        }
    }
    return true;
}

int main(){

    VERTICE* g1 = (VERTICE*)malloc(sizeof(VERTICE)*V);
    inicializarGLL(g1);

    inserirArestaGLL(g1, 1, 1, 10);
    inserirArestaGLL(g1, 2, 1, 22);
    inserirArestaGLL(g1, 3, 1, 33);

    puts("G111111111111111111111111111111111111111111111111111\n");
    imprimeGLL(g1);

    int m[V][V];
    inicializarGM(m);

    inserirArestaGM(m, 1, 1, 10);
    inserirArestaGM(m, 2, 1, 22);
    inserirArestaGM(m, 3, 1, 33);

    //imprimeGM(m);

    VERTICE* g2 = (VERTICE*)malloc(sizeof(VERTICE)*V);
    inicializarGLL(g2);

    transformaGMemLL(m, g2);

    puts("G2222222222222222222222222222222222222222222222222222\n");
    imprimeGLL(g2);

    
    bool eh = subGrafo(g1, g2);
    if(subGrafo(g1, g2)){
         puts("Eh subgrafo");
    }
    else puts("Nao eh subgrafo");
    
    return 0;
}