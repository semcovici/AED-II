#include <stdio.h>



typedef struct{
    int NroUSP;//chave primaria
    int curso;
    int estado;
    int idade;
    bool valido;//para exclusao logica
}REGISTRO;

bool reescreve(FILE** arq1, FILE** arq2, REGISTRO* reg){

    if(!arq1 || ! arq2) return false;

    while(1==fread(reg, sizeof(REGISTRO),1, *arq1)){

        if(reg->valido == true){
            fwrite(reg,sizeof(REGISTRO),1, *arq2);
        }
    }
    
    return true;
}

int main(){

    FILE* arq1 = fopen("arq1.bin","rb");
    FILE* arq2 = fopen("arq2.bin","wb");
    REGISTRO reg;

    if(reescreve(&arq1, &arq2, &reg)) printf("certinho");

    fclose(arq1);
    fclose(arq2);
}