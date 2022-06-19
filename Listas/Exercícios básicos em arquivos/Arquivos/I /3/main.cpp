#include <stdio.h>

typedef struct{
    int NroUSP;//chave primaria
    int curso;
    int estado;
    int idade;
    bool valido;//para exclusao logica
}REGISTRO;

REGISTRO achaNroUSP(FILE** arq,REGISTRO reg){

    if(!arq) return reg;

    int nroUSP;
    printf("Digite o nroUSP:    ");
    scanf("%i",&nroUSP);
    printf("\nSeu nroUSP é:   %i\n", nroUSP);

    while(1==fread(&reg, sizeof(REGISTRO),1, *arq)){

        if(reg.NroUSP == nroUSP){
            return reg;
        }
    } 

    return reg;
}

int main(){

    FILE* arq = fopen("arq1.bin","rb");
    REGISTRO reg;

    reg = achaNroUSP(&arq, reg);

    fclose(arq);
}