/*16.Variação: ao invés de contar os grupos, 
retornar uma lista ligada contendo os vértices do 
maior grupo identificado. Se dois ou mais grupos possuem 
a mesma quantidade de vértices, retornar a lista de 
vértices dequalquer um.*/

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

NO* prof(VERTICE* g, int i,int* tamanho){

    NO* caminho =(NO*)malloc(sizeof(NO)*V);

    g[i].flag = 1;//descoberto//*

    NO* p = g[i].inicio;
    while(p){

        if(g[p->v].flag == 0){
            printf("teste");
            
            caminho[i] = *g[i].inicio;
            printf("tetesetszgsr    %i\n", caminho[i].v);
            prof(g,p->v, &tamanho);//percurso

            return caminho;
        }
        p = p->prox;//proximo adjacente
    }

    g[i].flag = 2;
    tamanho ++;
}

NO* criaNOMaiorGrupo(VERTICE* g){
    
    NO* maiorGrupo = (NO*) malloc(sizeof(NO)* V);
    NO* aux = (NO*) malloc(sizeof(NO)*V);

    int tamanhoMaior = 0; 
    int tamanhoAux;
    int i;
    for(i=0;i<V;i++){

        tamanhoAux = 0;

        if(g[i].flag == 0){

            aux = prof(g,i,&tamanhoAux);
            
            if(tamanhoAux > tamanhoMaior){
                maiorGrupo = aux;
                tamanhoMaior = tamanhoAux;
            }
        }
    }

    return maiorGrupo;
}


int main(){

    VERTICE* g = (VERTICE*) malloc(sizeof(VERTICE)*V);
    inicializarGLL(g);
    inicializaFlag(g);

    NO* maiorGrupo = (NO*)malloc(sizeof(NO));
    

    inserirArestaGLL(g,0,1);
    inserirArestaGLL(g,1,0);

    inserirArestaGLL(g,2,3);
    inserirArestaGLL(g,3,4);
    inserirArestaGLL(g,2,4);

    imprimeGLL(g);

    NO* resposta = criaNOMaiorGrupo(g);

    puts("\n\n\n");
    int i;
    for(i=0;i<V;i++){
        printf("%i->", resposta[i].v);
    }

    return 0;
}