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
    int valor;
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
NO tabela2[MAX], REGISTRO* r, int* prox)
{
    if(!arq) return false;

    int end = buscarEndereco1(tabela1,r->NroUSP);

    if (end != -1) return false;

    end = *prox;

    fseek(arq,sizeof(REGISTRO)*end,SEEK_SET);
    fwrite(&r,sizeof(REGISTRO),1,arq);

    bool um = inserirIndice1(tabela1,r->NroUSP,end);
    bool dois = inserirIndice2(tabela2,r->NroUSP,end);

    if(!um ||!dois) return false;

    return true;
}