/**

33. Faca um programa para ler uma tabela contendo os nomes dos alunos de uma turma de
5 alunos. O programa deve solicitar ao usuario os nomes do aluno, sempre perguntando B4
se ele deseja inserir mais um nome na lista. Uma vez lidos todos os alunos, o usuario B4
ira indicar um nome que ele deseja verificar se esta presente na lista, onde o programa B4
deve procurar pelo nome (ou parte deste nome) e se encontrar deve exibir na tela o nome
completo e o indice do vetor onde esta guardado este nome.

**/

#include <stdio.h>

int main()
{


	char alunos[5][100];
	char busca[100];

	int opcao;
	char nada;
	int i=0;



		printf("Deseja adicionar um novo aluno?\n(1)Sim (2)Nao ");
		scanf("%d", &opcao);
		scanf("%c", &nada);

		while (opcao != 2 || i>5) {
			printf("Nome: ");
			scanf("%100[^\n]", alunos[i]);
			i++;
			printf("\nDeseja adicionar um novo aluno?\n(1)Sim (2)Nao ");
			scanf("%d", &opcao);
			scanf("%c", &nada);
		}

		printf("\nDigite o nome para buscar: ");
		scanf("%100[^\n]", busca);



/*
	char alunos[5][100] = {"Alana", "Julia", "Agata", "Maria"};
	char busca[100] = {""};
	
	*/

	i=0;
	int j=0;
	int k=0;
	int l=0;
	int igual = 0;
	int quant = 0;
	int localizador=-1;

	while(busca[i]!= '\0') {
		i++;
	}

	quant=i;
	i=0;

	while(alunos[i][j] != '\0') {
		while(alunos[i][j] != '\0') {
			k=0;
			l=j;
			if(alunos[i][j] != '\0' && alunos[i][j] == busca[k]) {
				while(alunos[i][l] != '\0' && alunos[i][l] == busca[k]) {
					igual++;
					l++;
					k++;
				}
			}
			j++;
			
		}
		if(igual==quant) {
			localizador=i;
			break;
		}
		else {
			igual=0;
		}
		j=0;
		i++;

	}
	
	j=0;


	if(localizador>-1) {
	    
	    printf("Indice = %d \nAluno = ", localizador);
	    while (alunos[localizador][j] != '\0'){
	        printf("%c", alunos[localizador][j]);
	        j++;
	    }
	    
		
	}
	
	else{
	    printf("Aluno não encontrado");
	}

	return 0;
}