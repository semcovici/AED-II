#include <stdio.h>

typedef struct
{
    int NroUSP; // chave primaria
    int curso;
    int estado;
    int idade;
    bool valido; // para exclusao logica
} REGISTRO;

REGISTRO achaNroUSP(FILE *arq)
{

    REGISTRO reg;

    if (!arq)
        return reg;

    int nroUSP;
    scanf("%i", &nroUSP);

    while (1 == fread(&reg, sizeof(REGISTRO), 1, arq))
    {

        if (reg.NroUSP == nroUSP && reg.valido == true)
        {
            return reg;
        }
    }

    return reg;
}