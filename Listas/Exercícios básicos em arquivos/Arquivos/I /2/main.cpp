// 2. Faça uma cópia invertida de arq1 em um novo arquivo arq2, ou seja: copie o último registro (n) de 
// arq1 para o início de arq2, depois copie o registro n-1 para a segunda posição etc.

#include <stdio.h>

typedef struct{
    int NroUSP;//chave primaria
    int curso;
    int estado;
    int idade;
    bool valido;//para exclusao logica
}REGISTRO;

bool inverte(FILE* arq1, FILE* arq2, REGISTRO reg){

    if(!arq1 || !arq2) return false; 

    int i = 1;
    while(true){
        fseek(arq1, - sizeof(REGISTRO)* i, SEEK_END);

        if(0==fread(&reg,sizeof(REGISTRO),1,arq1)) break;

        fwrite(&reg, sizeof(REGISTRO),1,arq2);
        i++;
    }

    return true;
    
}