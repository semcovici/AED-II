// 5. Escreva uma função para alterar o registro de nroUSP X para o nroUSP Y se possível (use o índice).
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

bool trocaNroUSP(FILE *arq, int X, int Y, REGISTRO tabela[MAX])
{
    if (!arq)
        return false;

    REGISTRO r;

    int end = buscarEndereco(tabela, X);

    if (end == -1)
        return false;

    fseek(arq, sizeof(REGISTRO) * end, SEEK_SET);
    fread(&r, sizeof(REGISTRO), 1, arq);

    r.NroUSP = Y;

    fseek(arq, -sizeof(REGISTRO), SEEK_CUR);
    fwrite(&r, sizeof(REGISTRO), 1, arq);

    excluirIndice(tabela, X);
    inserirIndice(tabela, Y, end);

    return true;
}