#include <stdio.h>

typedef struct{
    int NroUSP;//chave primaria
    int curso;
    int estado;
    int idade;
    bool valido;//para exclusao logica
}REGISTRO;

bool inverte(FILE** arq1, FILE** arq2, REGISTRO* reg){

    if(!arq1 || !arq2) return false;

    int i = 1;
    while(true){
        fseek(*arq1, - sizeof(REGISTRO)* i, SEEK_END);

        if(0==fread(reg,sizeof(REGISTRO),1,*arq1)) break;

        fwrite(reg, sizeof(REGISTRO),1,*arq2);
        i++;
    }

    return true;
    
}

int main(){

    FILE* arq1 = fopen("arq1.bin","rb");
    FILE* arq2 = fopen("arq2.bin","wb");
    REGISTRO reg;

    if(inverte(&arq1, &arq2, &reg)) printf("certinho");

    fclose(arq1);
    fclose(arq2);
}