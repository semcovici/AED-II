// 6. Escreva uma função para alterar o curso de um registro de nroUSP X para o curso Y (verifique quais 
// índices precisam ser atualizados). 
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
int excluirIndice2(NO tabela[MAX], int nroUSP);    

NO* chavesCurso(int curso);
NO* chavesEstado(int estado);

bool inserirRegistro(FILE *arq, REGISTRO tabela1[MAX], 
NO tabela2[MAX], int X, int Y, int* prox)
{
    if(!arq) return false;

    int end = buscarEndereco1(tabela1,X);

    if(end == -1) return false;

    REGISTRO aux;

    fseek(arq,sizeof(REGISTRO)*end,SEEK_SET);
    fread(&aux,sizeof(REGISTRO),1,arq);

    if(aux.valido == false) return false;

    aux.curso = Y;

    fseek(arq,-sizeof(REGISTRO),SEEK_CUR);
    fwrite(&aux,sizeof(REGISTRO),1,arq);

    int a = excluirIndice2(tabela2,X);
    int b = inserirIndice2(tabela2,X,end);

    if(!a||!b) return false;

    return true;
}