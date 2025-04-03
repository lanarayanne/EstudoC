/******************************************************************************
. Utilizando uma estrutura, fac ¸a um programa que permita a entrada de nome, enderec ¸o e
 telefone de 5 pessoas e os imprima em ordem alfab´ etica
 
*******************************************************************************/
#include <stdio.h>

typedef struct {
    char rua[100];
    int num;
    int cep;
}Endereco;

typedef struct {
    char nome[100];
    Endereco endereco;
    char telefone[12];
} Pessoa;

int main(){
    
    Pessoa pessoa[5];
    int i;
    
    for(i=0; i<5; i++){
        printf("Pessoa %d\n", i+1);
        printf("Nome:");
        scanf(" %100[^\n]", pessoa[i].nome);
        printf("Endereco\n");
        printf("Rua:");
        scanf(" %100[^\n]", pessoa[i].endereco.rua);
        printf("Numero:");
        scanf("%d", &pessoa[i].endereco.num);
        printf("CEP:");
        scanf("%d", &pessoa[i].endereco.cep);
        printf("Telefone:");
        scanf(" %11[^\n]", pessoa[i].telefone);
        printf("\n");
   }

    
    int j=0;
    
    for(j=0; j<5; j++){
        for(i=0; i<4; i++){
            if(pessoa[i].nome[0] > pessoa[i+1].nome[0]){
                Pessoa copia = pessoa[i];
                pessoa[i] = pessoa[i+1];
                pessoa[i+1] = copia;
            }
        }
    }
    
    
    
    for(i=0; i<5; i++){
        printf("%d) ", i+1);
        printf("%s\n", pessoa[i].nome);
        printf("Rua %s n %d\n", pessoa[i].endereco.rua, pessoa[i].endereco.num);
        printf("Telefone: %s\n", pessoa[i].telefone);
    }
    
	return 0;
}