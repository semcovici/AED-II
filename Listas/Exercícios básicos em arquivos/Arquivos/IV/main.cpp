// IV-Serialização de EDs - faça você mesmo.

// Passo 1: Escolha uma estrutura de dados dentre lista sequencial (i.e., vetor), lista ligada dinâmica
// (simples ou dupla), árvore de busca binária, grafo em listas de adjacências ou grafo em matriz de
// adjacências.

// Passo 2: Escolha a operação de leitura (do arquivo para a memória) ou escrita (da ED em arquivo).
// Tipicamente a leitura é mais trabalhosa, pois envolve recriar a ED usando malloc() etc.
// Passo 3: Escolha o tipo de arquivo: texto com delimitadores (use fprintf/fscanf) ou binário (use
// fwrite/fread).

// Passo 4: Implemente o algoritmo correspondente à configuração escolhida (ED, operação, tipo de
// arquivo)  e, em caso de dúvidas, teste no próprio compilador.

// Passo 1: Grafo
// Passo 2: escrita
// Passo 3: binario
// Passo 4:

#include <stdio.h>
#include <stdlib.h>

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

bool escrita(FILE *arq, VERTICE *g, int V)
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

bool leitura(FILE *arq, VERTICE *g, int V) // vertice ja alocado e inicializado
{
    fread(&V, sizeof(int), 1, arq);

    int origem, destino, peso;
    while (1 == fread(&origem, sizeof(int), 1, arq))
    {
        fread(&destino, sizeof(int), 1, arq);
        fread(&peso, sizeof(int), 1, arq);
        inserirAresta(g, origem, destino, peso);
    }
}

void inserirAresta(VERTICE *g, int origem, int destino, int peso)
{

    NO *novo = (NO *)malloc(sizeof(NO));
    novo->peso = destino;
    novo->peso = peso;
    novo->prox = g[origem].inicio;
    g[origem].inicio = novo;
}
