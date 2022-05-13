/*1. Escreva um algoritmo para contar 
a quantidade de laços em um grafo.*/
#include <stdio.h>

#define V 5

void inicializarGrafo(int g[V][V]){
    int i,j;
    for(i=0; i<V; i++)
        for(j=0; j<V; j++)
            g[i][j] = 0;
}

int contaLaco(int g[V][V]){
    int i;
    int qtd = 0;

    for(i=0; i<V; i++){
        if(g[i][i] == 1){
             qtd++;
        }
    }

    return qtd;
}

void imprimeGrafo(int g[V][V]){
    int i,j;

    for(i=0; i<V; i++)
        for(j=0;j<V; j++)
            printf("%d\n", g[i][j]);
}

void inserirAresta(int i, int j, int g[V][V]){
    g[i][j] = 1;
}

int main(){
    int g[V][V];
    int qtdLaco;

    inicializarGrafo(g);

    inserirAresta(1,1,g);//Laco
    inserirAresta(2,2,g);//Laco
    inserirAresta(1,3,g);//nao Laco

    qtdLaco = contaLaco(g);

    printf("Quantidade de Lacos = %i", qtdLaco);

    return 0;
}