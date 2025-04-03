/******************************************************************************
 Fac¸a um programa que armazene em um registro de dados (estrutura composta) os da
dos de um funcion´ ario de uma empresa, compostos de: Nome, Idade, Sexo (M/F), CPF,
 Data de Nascimento, C´ odigo do Setor onde trabalha (0-99), Cargo que ocupa (string de
 at´ e 30 caracteres) e Sal´ ario. Os dados devem ser digitados pelo usu´ ario, armazenados
 na estrutura e exibidos na tela.
*******************************************************************************/
#include <stdio.h>
#include<math.h>


typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[100];
    int idade;
    char sexo;
    int cpf;
    Data nascimento;
    int setor;
    char cargo[30];
    float salario;
} Funcionario;

int main(){
    
    Funcionario funcionario;
    
    printf("Nome:");
    scanf("%99[^\n]", funcionario.nome);
    printf("Idade: ");
    scanf("%d", &funcionario.idade);
    printf("Sexo: ");
    scanf(" %c", &funcionario.sexo);
    printf("CPF: ");
    scanf("%d", &funcionario.cpf);
    printf("Data nascimento dd mm aaaa: ");
    scanf("%d %d %d", &funcionario.nascimento.dia, &funcionario.nascimento.mes,  &funcionario.nascimento.ano);
    printf("Código do setor: ");
    scanf("%d", &funcionario.setor);
    printf("Cargo: ");
    scanf(" %29[^\n]", funcionario.cargo);
    printf("Salario: ");
    scanf("%f", &funcionario.salario);
    
    printf("\nNome: %s", funcionario.nome);
    printf("\nIdade: %d", funcionario.idade);
    printf("\nSexo: %c", funcionario.sexo);
    printf("\nCPF: %d ", funcionario.cpf);
    printf("\nData nascimento: %d/%d/%d", funcionario.nascimento.dia, funcionario.nascimento.mes, funcionario.nascimento.ano);
    printf("\nCodigo do setor: %d", funcionario.setor);
    printf("\nCargo: %s", funcionario.cargo);
    printf("\nSalario: %.2f", funcionario.salario);

	return 0;
}