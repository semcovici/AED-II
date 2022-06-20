#include <stdio.h>
#define MAX 5

typedef struct
{
    int NroUSP; // chave primaria
    int curso;
    int estado;
    int idade;
    bool valido; // para exclusao logica
} REGISTRO;

typedef struct
{
    int NroUSP;
    NO* prox;
} NO;

bool inserirIndice1(REGISTRO tabela[MAX], int nroUSP, int end); // inserção em tabela ordenada, retornando true/false
int buscarEndereco1(REGISTRO tabela[MAX], int nroUSP);          // retorna -1 se end não existe
int excluirIndice1(REGISTRO tabela[MAX], int nroUSP);           // retorna o endereço exluído, ou -1 se não encontrar

bool inserirIndice2(NO tabela[MAX], int nroUSP, int end);
int excluirIndice2(REGISTRO tabela[MAX], int nroUSP);    

NO* chavesCurso(int curso);
NO* chavesEstado(int estado);

bool inserirRegistro(FILE *arq, REGISTRO tabela1[MAX], 
NO tabela2[MAX], int X, int* prox)
{
    if(!arq) return false;

    NO* chaves = chavesCurso(X);
    REGISTRO aux;

    while(chaves){

        int end = buscarEndereco1(tabela1,chaves->NroUSP);

        fseek(arq,sizeof(REGISTRO)*end,SEEK_SET);
        fread(&aux,sizeof(REGISTRO), 1, arq);

        printf("\n end: %i|NroUSP:  %i|curso: %i|estado: %i|idade: %i|valido: %i"
                ,aux.NroUSP, aux.curso,aux.estado,aux.idade,aux.valido);

        chaves = chaves->prox;
    }

    return true;
}