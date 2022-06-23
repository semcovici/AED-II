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

bool inserirIndice(REGISTRO tabela[MAX], int nroUSP, int end); // inserção em tabela ordenada, retornando true/false
int buscarEndereco(REGISTRO tabela[MAX], int nroUSP);          // retorna -1 se end não existe
int excluirIndice(REGISTRO tabela[MAX], int nroUSP);           // retorna o endereço exluído, ou -1 se não encontrar

REGISTRO achaRegistro(FILE *arq, int X, REGISTRO tabela[MAX])
{

    int end = buscarEndereco(tabela, X);
    if (end != -1)
    {
        REGISTRO r;

        fseek(arq, sizeof(REGISTRO) * end, SEEK_SET);
        fread(&r, sizeof(REGISTRO), 1, arq);

        return r;
    }
}