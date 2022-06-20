// Passo 1: Grafo
// Passo 2: escrita
// Passo 3: binario
// Passo 4:

#include <stdio.h>
#include <stdlib.h>

#define V 5

typedef struct s
{
    int peso;
    int v; // vertice
    struct s *prox;
} NO;

typedef struct z
{
    NO *inicio;
} VERTICE;

typedef struct f
{
    NO *inicio;
    NO *fim;
} FILA;

bool escrita(FILE* arq, VERTICE* g)
{
    int t = sizeof(int);

    fwrite(&V, t, 1, arq);
    int i;
    for (i = 1; i <= V; i++)
    {
        NO *p = g[i].inicio;
        while (p)
        {
            int origem = i;
            int destino = p->v;
            int peso = p->peso;

            fwrite(&origem, t, 1, arq);
            fwrite(&destino, t, 1, arq);
            fwrite(&peso, t, 1, arq);

            p = p->prox;
        }
    }
}

