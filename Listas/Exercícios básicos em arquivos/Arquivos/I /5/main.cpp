//5. Escreva uma função para excluir todos os registros do curso X.
#include <stdio.h>

typedef struct{
    int NroUSP;//chave primaria
    int curso;
    int estado;
    int idade;
    bool valido;//para exclusao logica
}REGISTRO;

bool excluiRegistroCursoX(FILE* arq,int X){
    
    if(!arq) return false;

    REGISTRO aux;

    while(1==fread(&aux,sizeof(REGISTRO),1,arq)){

        if(aux.curso == X && aux.valido == true){
            aux.valido = false; //exclusão lógica

            fseek(arq, -sizeof(REGISTRO),SEEK_CUR);
            fwrite(&aux, sizeof(REGISTRO),1,arq);
        }
    }

    return true;
}