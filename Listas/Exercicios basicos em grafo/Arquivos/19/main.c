/*19.Variação 2: retornar a lista dos vértices que
 compõe ocaminho de a até b.
*/
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

// NO* existeCaminho(VERTICE* g, int a, int b, int* caminho){

//     g[a].flag = 1;
    
//     //if(a>=V || b>=V) return cont;

//     if(a == b){
//         int x;
//         for(x=0; x<V; x++){
//             if(caminho[x] == -1){
//                 caminho[x] = a;
//                 break;
//             }
//         }
//         return caminho;
//     } 
    

//     NO* p = g[a].inicio;

//     while(p){

//         int i;
//         for(i=0; i<V; i++){

//             if(caminho[i] == -1){
//                 caminho[i] = a;
//                 break;
//             }
                
//         }

//         if(g[p->v].flag == 0){

//             existeCaminho(g, p->v, b, &caminho);
//         }

//         p = p->prox;
//     }
//     g[a].flag = 2;
    
// }

NO* listaLigadaCaminho(VERTICE* g, int a, int b){

    FILA f;
    inicializarFila(&f);
    inicializaFlag(g);

    NO* caminho = (NO*)malloc(sizeof(NO)*V);

    inserirNaFila(&f, a);
    g[a].flag = 1;

    while(f.inicio){

        a = f.inicio->v;
        excluirDaFila(&f);

        if(a==b){
            while(f.inicio) excluirDaFila(&f);
            return caminho;
        }

        NO* p = g[a].inicio;
        while(p){

            if(g[a].flag == 0){

                g[a].flag = 1;
                inserirNaFila(&f, a);
                
            }

            p=p->prox;
        }
        g[a].flag = 2;
    }

    return NULL;
}

int main(){

    VERTICE* g = (VERTICE*) malloc(sizeof(VERTICE)*V);
    inicializarGLL(g);
    inicializaFlag(g);    

    inserirArestaGLL(g,0,1);
    inserirArestaGLL(g,1,2);
    inserirArestaGLL(g,2,3);
    inserirArestaGLL(g,3,4);

    imprimeGLL(g);

    NO* caminho = listaLigadaCaminho(g,0,4);

    int i;
    for(i=0;i<V;i++)
        printf("%i->", caminho[i]);


    imprimeGLL(g);



    return 0;
}