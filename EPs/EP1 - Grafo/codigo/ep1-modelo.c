#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

// ######### ESCREVA O NRO DO SEU GRUPO AQUI CONFORME CADASTRADO EM
// https://docs.google.com/spreadsheets/d/1_wy0Uko3vX8GE07G1WP4X6X6-yRdu6eCpLdmmRvU7EM/edit?usp=sharing

int grupo() {
  return 0;
}

// ######### ESCREVA O NROUSP AQUI
int nroUSP1() {
    return 0;
}

int nroUSP2() {
    return 0;
}

//-------------------------------------------

// nos das listas de adjacencias
// usados no grafo, e para uso tambem na lista de resposta
typedef struct adj {
	int v;
	struct adj* prox;
} NO;

// vertices
typedef struct {
	NO* inicio;
} VERTICE;


// funcao principal (assinatura exigida por alguns compiladores)
NO* EncontrarCaminho(VERTICE* g, int V, int v1, int t);

//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------
NO* EncontrarCaminho(VERTICE* g, int V, int v1, int t)
{
	// seu codigo AQUI
}



//---------------------------------------------------------
// use main() para fazer chamadas de teste ao seu programa
// mas nao entregue o codido de main() nem inclua nada
// abaixo deste ponto
//---------------------------------------------------------
int main()
{
	if nroUSP1()==0 printf("\n\nNro USP do primeiro integrante nao informado!!!\n\n");
	if grupo()==0 printf("\n\nNro do grupo nao informado!!!\n\n");

	// crie um grafo de teste aqui
	// chame a funcao implementada e armazena a lista em uma variavel NO*
	// verifique se a lista retornada está correta
}

