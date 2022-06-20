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

bool excluiCursoX(FILE *arq, int X, REGISTRO tabela[MAX])
{
    if(!arq) return false;

    REGISTRO r;
    while (1 == fread(&r, sizeof(REGISTRO), 1, arq))
    {

        if (r.curso == X && r.valido == true)
        {

            r.valido == false;

            fseek(arq, -sizeof(REGISTRO), SEEK_CUR);
            fwrite(&r, sizeof(REGISTRO), 1, arq);

            excluirIndice(tabela, r.NroUSP);
        }
    }
    return true;
}