// 4. Escreva  uma  função  para  inserir  um  novo  registro  r  no  arquivo,  tomando  cuidado  para  evitar 
// chaves duplicadas. 

#include <stdio.h>

typedef struct{
    int NroUSP;//chave primaria
    int curso;
    int estado;
    int idade;
    bool valido;//para exclusao logica
}REGISTRO;

bool insereRegistro(FILE* arq, REGISTRO r){
    
    if(!arq) return false;

    REGISTRO aux;

    while(1==fread(&aux,sizeof(REGISTRO),1,arq)){

        if(r.NroUSP == aux.NroUSP && r.valido==true) return false;
    }

    fwrite(&r, sizeof(REGISTRO),1,arq);
    return true;
}