/*11. Considere um grafo dirigido em lista de adjacências 
representando uma rede de chamadas telefônicas entre diversas 
unidades de uma empresa, onde cada vértice representa uma unidade, 
e cada aresta representa uma chamada efetuada. As unidades podem 
estar em diferentes países, identificados por um campo int país 
definido no respectivo vértice. Problema: a conta de telefone global 
da empresa está muito alta. Escreva um algoritmo que identifique a unidade 
que efetua chamadas para o maior número de países. Havendo empate, retorne 
qualquer resposta possível.*/

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
    int contChamadasInt;
    int pais;
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

bool inserirArestaGLL(VERTICE* g, int i, int j, int pais){
    NO* ant;
    NO* atual = buscaArestaGLL(g,i,j,&ant);

    if(atual) return false;

    atual = (NO*)malloc(sizeof(NO));
    atual -> v = j;
		
    atual->prox = g[i].inicio;
    g[i].inicio = atual;
    g[i].pais = pais;

	return true;
}

void imprimeGLL(VERTICE* g){

    int i;
    for(i=0; i<V; i++){

        NO* p = g[i].inicio;
        printf("VERTICE %i->pais:%i\n", i, g[i].pais);
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

int contaMaisChamadasInternacionais(VERTICE* g){

    int i;
    for(i=0; i<V; i++){
        NO* p = g[i].inicio;
        while(p){
            if(g[p->v].pais != g[i].pais){
                g[i].contChamadasInt ++;
            }
            p = p -> prox;
        }
    }
    
    int j;
    int maior = g[0].contChamadasInt;
    for(j=0; j<V; j++){

        int atual = g[j].contChamadasInt;   
        if(j > 0){
            if(atual > maior){
                maior = atual;
            } 
        }
    }
    return maior;
}

void inicializaContaChamInt(VERTICE* g){

    int i;
    for(i=0; i<V; i++){
        g[i].contChamadasInt = 0;
    }
}

void inicializaPais(VERTICE* g){
    
    int i;
    for(i=0; i<V; i++){
        g[i].pais = 0;
    }
}

int main(){

    VERTICE* g = (VERTICE*) malloc(sizeof(VERTICE)*V);
    inicializarGLL(g);
    inicializaContaChamInt(g);
    inicializaPais(g);

    printf("%i\n", g[0].pais);
    printf("%i\n", g[1].pais);
    printf("%i\n", g[2].pais);
    printf("%i\n", g[3].pais);
    printf("%i\n", g[4].pais);

    
    inserirArestaGLL(g,1,3,1);
    inserirArestaGLL(g,2,3,2);
    inserirArestaGLL(g,2,4,2);
    inserirArestaGLL(g,3,1,3);
    inserirArestaGLL(g,3,2,3);
    inserirArestaGLL(g,3,4,3);




    imprimeGLL(g);


    int maior = contaMaisChamadasInternacionais(g);
    puts("maior");
    printf("%i", maior);

    return 0;
}