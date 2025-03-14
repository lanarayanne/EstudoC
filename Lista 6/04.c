/******************************************************************************
Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve
 conter a matr´ ıcula do aluno, nome, nota da primeira prova, nota da segunda prova e nota
 da terceira prova.
 (a) Permita ao usu´ ario entrar com os dados de 5 alunos.
 (b) Encontre o aluno com maior nota da primeira prova.
 (c) Encontre o aluno com maior m´ edia geral.
 (d) Encontre o aluno com menor m´ edia geral
 (e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para
 aprovac ¸˜ ao.
*******************************************************************************/
#include <stdio.h>

typedef struct {
	char nome[100];
	int matricula;
	float nota1;
	float nota2;
	float nota3;
	float media;
} Aluno;

int main()

{
	Aluno alunos[5];
	int i;
	float maior_nota = 0;
	float maior_media = 0;
	int localizador_nota;
	int localizador_media;
	
	for(i=0; i<5; i++){
	    printf("\nAluno %d\n", i+1);
	    printf("Nome: ");
	    scanf(" %100[^\n]", alunos[i].nome);
	    printf("Matricula: ");
	    scanf("%d", &alunos[i].matricula);
	    printf("Nota 1: ");
	    scanf("%f", &alunos[i].nota1);
	    printf("Nota 2: ");
	    scanf("%f", &alunos[i].nota2);
	    printf("Nota 3: ");
	    scanf("%f", &alunos[i].nota3);
	    
	    alunos[i].media= (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3)/3;
	    
	    if (alunos[i].media >= 6){
	        printf("Aprovado\n");
	    }
	    else{
	        printf("Reprovado\n");
	    }
	    
	    if(alunos[i].nota1>=maior_nota){
	        maior_nota=alunos[i].nota1;
	        localizador_nota = i;
	    }
	    
	    if(alunos[i].media>=maior_media){
	        maior_media=alunos[i].media;
	        localizador_media = i;
	    }
	    
	}
	
	printf("\nMaior primeira nota\nAluno:%s\nNota:%.2f", alunos[localizador_nota].nome, maior_nota);
	printf("\nMaior Media\nAluno:%s\nNota:%.2f", alunos[localizador_media].nome, maior_media);
	
	return 0;
}