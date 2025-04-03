/******************************************************************************
Fac¸a um programa que realize a leitura dos seguintes dados relativos a um conjunto de
 alunos: Matricula, Nome, C´ odigo da Disciplina, Nota1 e Nota2. Considere uma turma de
 at´ e 10 alunos. Ap´ os ler todos os dados digitados, e depois de armazen´ a-los em um vetor
 de estrutura, exibir na tela a listagem final dos alunos com as suas respectivas m´ edias
 finais (use uma m´ edia ponderada: Nota1 com peso=1.0 e Nota2 com peso=2.0).
*******************************************************************************/
#include <stdio.h>

typedef struct {
    int matricula;
    char nome[50];
    int disciplina;
    float nota1;
    float nota2;
    float media;
} Aluno;

int main(){
    
    Aluno alunos[10];
    int i;
    
    for(i=0; i<10; i++){
        printf("Aluno %d\n", i+1);
        printf("Nome: ");
        scanf(" %49[^\n]", alunos[i].nome);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Disciplina: ");
        scanf("%d", &alunos[i].disciplina);
        printf("Primeira nota: ");
        scanf("%f", &alunos[i].nota1);
        printf("Segunda nota: ");
        scanf("%f", &alunos[i].nota2);
        alunos[i].media=(alunos[i].nota1*1 + alunos[i].nota2*2)/3;
        printf("\n");
    }
    
    for(i=0; i<10; i++){
        printf("Nome: %s\tMedia= %.2f\n", alunos[i].nome, alunos[i].media);
    }

	return 0;
}