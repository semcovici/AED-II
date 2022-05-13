/*9.Dados dois grafos g1 e g2, escreva um algoritmo que 
retorne um grafo g3 cujas arestas estejam presentes em g1 mas não em g2.*/
#include <stdio.h>
#include <stdlib.h>

#define V 5
#define vazio 0

typedef int bool;
#define true 1
#define false 0

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

void taEmAMasNaoEmB(int g1[V][V], int g2[V][V], int g3[V][V]){

    int i, j;
    for(i=0; i<V; i++){
        for(j=0; j<V; j++){
            if(g1[i][j] != vazio && g1[i][j] != g2[i][j]){
                g3[i][j] = g1[i][j];
            }
        }
    }   
}

void imprimeArestasExistentes(int g[V][V]){
    int i,j;

    for(i=0; i<V; i++)
        for(j=0;j<V; j++)
                if(g[i][j] != vazio){
                     printf ("\nElemento[%d][%d] = %d\n", i, j, g[i][j]);
                }              
}

int main(){
    int g1[V][V];
    inicializarGM(g1);

    inserirArestaGM(g1, 1, 1, 10);
    inserirArestaGM(g1, 1, 2, 10);
    inserirArestaGM(g1, 1, 3, 10);


    int g2[V][V];
    inicializarGM(g2);

    inserirArestaGM(g2, 1, 1, 10);
    inserirArestaGM(g2, 1, 2, 10);
    inserirArestaGM(g2, 2, 3, 10);

    int g3[V][V];
    inicializarGM(g3);

    taEmAMasNaoEmB(g1, g2, g3);

    imprimeArestasExistentes(g3);

    return 0;
}