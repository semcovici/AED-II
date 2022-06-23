// 1. Escreva  uma  função  para  inserir  um  novo  registro  r  no  arquivo,  tomando  cuidado  para  evitar 
// chaves duplicadas (use o índice).

#include <stdio.h>
#define MAX 5

typedef struct{
    int NroUSP;//chave primaria
    int curso;
    int estado;
    int idade;
    bool valido;//para exclusao logica
}REGISTRO;

bool inserirIndice(REGISTRO tabela[MAX], int nroUSP, int end); //inserção em tabela ordenada, retornando true/false 
int buscarEndereco(REGISTRO tabela[MAX], int nroUSP); // retorna -1 se end não existe 
int excluirIndice(REGISTRO tabela[MAX], int nroUSP); // retorna o endereço exluído, ou -1 se não encontrar

int prox = 0; //quem é o proximo na tabela

bool insere(FILE* arq, REGISTRO r, REGISTRO tabela[MAX]){

    if(buscarEndereco(tabela,r.NroUSP) != -1) return false;

    //insere no arquivo
    fseek(arq,sizeof(REGISTRO)* prox, SEEK_SET);
    fwrite(&r, sizeof(REGISTRO), 1, arq);

    //insere na tabela
    if(inserirIndice(tabela, r.NroUSP, prox)){
        prox ++;
        return true;
    }

    return false;
}