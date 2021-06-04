#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 

#define MAX_STRING 10

//Precisa struct?
typedef struct{
    float entrada;
    float saida;
} Valor; 


void LerLinhas(char linha[], FILE *arquivo);
Valor lerValores(char linha[]);

int main(){

    FILE *arquivo;
    arquivo = fopen("valores.csv","r");

    FILE *saida;
    saida = fopen("tabela.csv", "w");

    if(arquivo == NULL || saida == NULL){ //ou
        printf("Algo deu errado!\n");
        exit(EXIT_FAILURE);
    }

    char linha[MAX_STRING];

    while(!feof(arquivo)){
        LerLinhas(linha,arquivo);
        Valor x = lerValores(linha);
        if (x.entrada>=1.0){
            x.saida = log(x.entrada);
        } else {
            x.saida = 4;
        }
        fprintf(saida, "Entrada: %.2f \t Saida: %f\n", x.entrada, x.saida);
        
    }

    //Fecha o arquivo
    fclose(arquivo);
    fclose(saida);
    return 0;


}



void LerLinhas(char linha[], FILE *arquivo) {
    fgets(linha, MAX_STRING, arquivo);
    if (linha[strlen(linha)-1] == '\n')
            linha[strlen(linha)-1] = '\0';
}


Valor lerValores(char linha[]){
    Valor valor;
    char *token = strtok(linha, ";");
    valor.entrada = atof(token);
    //valor.entrada = atof(linha);
    return valor; 
}