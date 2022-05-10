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
    int dist;
    int via;
    int flag;
    NO* inicio;    
} VERTICE;

typedef struct f{
    NO* inicio;
    NO* fim;
}FILA;

void inicializarFila(FILA* f){
    f->inicio = NULL;
    f->fim = NULL;
}

/* Inserção no fim da fila */
bool inserirNaFila(FILA* f, int v) {
  
  NO* novo = (NO*) malloc(sizeof(NO));
  
  novo->v = v;
  novo->prox = NULL;

  //insere no inicio da fila, caso não haja ngm
  if (f->inicio==NULL){
     f->inicio = novo;
  }else{
     f->fim->prox = novo;//insere no fim
  }

  f->fim = novo;
  return true;
} /* inserir */

/* Excluir  */
bool excluirDaFila(FILA* f) {
  if (f->inicio==NULL){
    return false;                     
  }
  //*v = f->inicio->v;
  NO* apagar = f->inicio;
  f->inicio = f->inicio->prox;
  free(apagar);
  if (f->inicio == NULL){
    f->fim = NULL;
  }
  return true;
} /* excluirDaFila */


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

void inicializarFlags(VERTICE* g){

    int i;
    for(i=0; i<V; i++){
        g[i].flag = 0;
    }
}

void inicializarVia(VERTICE* g){

    int i;
    for(i=0;i<V;i++){
        g[i].via = -1;
    }
}

void exibirAmigos(VERTICE* g, int i){

    FILA f;
    inicializarFila(&f);

    inicializarFlags(g);
    inicializarVia(g);
    inicializarDist(g);

    inserirNaFila(&f, i);
    g[i].flag = 1;
    g[i].dist = 0;

    while(f.inicio){

        i = f.inicio->v;
        excluirDaFila(&f);

        NO* p = g[i].inicio;
        while(p){

            if(g[p->v].flag == 0){

                g[p->v].flag = 1;
        
                g[p->v].via = i;

                g[p->v].dist = 1 + g[i].dist;

                inserirNaFila(&f, p->v);
            }

            p=p->prox;
        }
        g[i].flag = 2;
    }
}

void imprimeFlags(VERTICE* g){

    puts("FLAGS FLAGS");
    int i;
    for(i=0; i<V; i++){

        printf("flag[%i] -> %i\n",i, g[i].flag);
    }
}
void imprimeVia(VERTICE* g){

    puts("VIA VIA VIA");
    int i;
    for(i=0;i<V;i++){

        printf("via[%i] -> %i\n", i, g[i].via);
    }
}

void imprimeDist(VERTICE* g){

    puts("DIST DIST DIST");
    int i;
    for(i=0;i<V;i++){

        printf("dist[%i] -> %i\n", i, g[i].dist);
    }
}

void inicializarDist(VERTICE* g){

    int i;
    for(i=0; i<V; i++){
        g[i].dist = -1;
    }
}

int main(){

    VERTICE* g = (VERTICE*) malloc(sizeof(VERTICE)*V);
    inicializarGLL(g);

    inserirArestaGLL(g,0,1);
    inserirArestaGLL(g,1,2);
    inserirArestaGLL(g,2,3);
    inserirArestaGLL(g,3,4);

    imprimeGLL(g);

    exibirAmigos(g, 0);

    imprimeFlags(g);
    imprimeVia(g);
    imprimeDist(g);

    return 0;
}