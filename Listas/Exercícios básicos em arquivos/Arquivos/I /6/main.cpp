#include <stdio.h>

typedef struct{
    int NroUSP;//chave primaria
    int curso;
    int estado;
    int idade;
    bool valido;//para exclusao logica
}REGISTRO;

bool trocaCurso(FILE* arq,int X,int Y){
    
    if(!arq) return false;

    REGISTRO aux;

    while(1==fread(&aux,sizeof(REGISTRO),1,arq)){

        if(aux.NroUSP == X && aux.valido == true){

            aux.curso = Y;

            fseek(arq, -sizeof(REGISTRO),SEEK_CUR);
            fwrite(&aux, sizeof(REGISTRO),1,arq);
            return true;
        }
    }

    return false;
}