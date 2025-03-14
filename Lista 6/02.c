/******************************************************************************

implemente um programa que leia o nome, a idade e o enderec¸o de uma pessoa e
 armazene os dados em uma estrutura.

*******************************************************************************/
#include <stdio.h>

typedef struct {
	char logradouro[50];
	char rua[200];
	char numero[10];
	char complemento[50];
	int cep;
	char bairro[100];
	char cidade[100];
	char estado[50];
	
} Endereco;


typedef  struct {
	char nome[50];
	int idade;
	Endereco endereco;
} Pessoa;


int main()

{
	Pessoa pessoa;
	
	printf("Nome: ");
	scanf("%50[^\n]", pessoa.nome);
	printf("Idade: ");
	scanf("%d", &pessoa.idade);
	printf("Endereco\nLogradouro: ");
	scanf(" %50[^\n]", pessoa.endereco.logradouro);
	printf("Nome: ");
	scanf(" %200[^\n]", pessoa.endereco.rua);
	printf("Numero: ");
	scanf(" %20[^\n]", pessoa.endereco.numero);
	printf("Bairro: ");
	scanf(" %100[^\n]", pessoa.endereco.bairro);
	printf("Cidade: ");
	scanf(" %100[^\n]", pessoa.endereco.cidade);
	printf("Estado: ");
	scanf(" %50[^\n]", pessoa.endereco.estado);
	printf("CEP: ");
	scanf("%d", &pessoa.endereco.cep);
	
	
	
	printf("Nome: %s\n", pessoa.nome);
	printf("Idade: %d\n", pessoa.idade);
	printf("Endereco: %s %s, numero %s, %s, %s, %s %d", pessoa.endereco.logradouro, pessoa.endereco.rua, pessoa.endereco.numero, pessoa.endereco.bairro, pessoa.endereco.cidade, pessoa.endereco.estado, pessoa.endereco.cep);
	
	return 0;
}