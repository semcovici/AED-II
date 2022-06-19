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

int chaveEnd(FILE *arq, int end)
{

    REGISTRO aux;

    fseek(arq, sizeof(REGISTRO) * end, SEEK_SET);
    fread(&aux, sizeof(REGISTRO), 1, arq);

    return aux.NroUSP;
}

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

int main()
{

    FILE *arq1 = fopen("arq.bin", "rb");
    FILE *arq2 = fopen("arq.bin", "wb");

    keySort(arq1, arq2);

    fclose(arq1);
    fclose(arq2);
}