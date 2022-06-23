// 7. Implemente  o  procedimento  de  ordenação  KeySort,  que  dado  um  arquivo  arq1  cria  uma  tabela 
// temporária de chaves em memória (idêntica a uma tabela de índices primários) e então reescreve o 
// arquivo  em  um  novo  arquivo  de  saída  arq2,  na  ordem  correta  de  chaves  (exercício  completo  e 
// altamente recomendável).

#include <stdio.h>

#define MAX 40

typedef struct
{
    int NroUSP; // chave primaria
    int curso;
    int estado;
    int idade;
    bool valido; // para exclusao logica
} REGISTRO;

bool insereConformeChave(FILE* arq1, FILE* arq2, int chave[MAX], int i){

    REGISTRO r;
    while(1==fread(&r, sizeof(REGISTRO),1,arq1)){

        if(r.NroUSP == chave[i]) break;
    }

    fseek(arq2,sizeof(REGISTRO)*i,SEEK_SET);
    fwrite(&r, sizeof(REGISTRO),1,arq2);
}

bool keySort(FILE *arq1, FILE *arq2)
{

    if (!arq1 || !arq2)
        return false;

    int chave[MAX];

    REGISTRO aux;

    int cont = MAX;

    // coloca as chaves validas no vetor
    while (1 == fread(&aux, sizeof(REGISTRO), 1, arq1))
    {

        if (aux.valido == true)
        {
            chave[MAX - cont] = aux.NroUSP;
            cont--;
        }
    }

    bubblesort(chave); // ordena as chaves

    rewind(arq1);

    for (int i = 0; i < MAX; i++)
    {
        insereConformeChave(arq1,arq2,chave,i);
    }

    return true;
}