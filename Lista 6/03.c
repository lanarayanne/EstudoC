/******************************************************************************

 Construa uma estrutura aluno com nome, n´umero de matr´ ıcula e curso. Leia do usu´ ario
 a informac¸˜ ao de 5 alunos, armazene em vetor dessa estrutura e imprima os dados na
 tela.

*******************************************************************************/
#include <stdio.h>

typedef struct {
	char nome[100];
	int matricula;
	char curso[100];
	
} Aluno;

int main()

{
	Aluno alunos[5];
	int i;
	
	for(i=0; i<5; i++){
	    printf("\nAluno %d\n", i+1);
	    printf("Nome: ");
	    scanf(" %100[^\n]", alunos[i].nome);
	    printf("Matricula: ");
	    scanf("%d", &alunos[i].matricula);
	    printf("Curso: ");
	    scanf(" %100[^\n]", alunos[i].curso);
	    
	}
	
	for(i=0; i<5; i++){
	    printf("\nAluno %d\n", i+1);
	    printf("Nome: %s\n", alunos[i].nome);
	    printf("Matricula: %d\n", alunos[i].matricula);
	    printf("Curso:%s\n\n", alunos[i].curso);
	}
	
	return 0;
}