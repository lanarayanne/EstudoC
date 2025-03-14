/**

 31.

**/

#include <stdio.h>

int main()
{
	char string1[20];
	char string2[20];
	char limpar[200];
	char opcao;
	char caractere, caractere2;

	int i=0, j=0, k=0, tam1=0, tam2=0, cont=0, contc=0, index1, index2, diferente=0, fechar=0, esta_contida=0, primeiroc=0;

	printf("(a) Ler uma String\n");
	printf("(b) Tamanho da String\n");
	printf("(c) Comparar String com outra\n");
	printf("(d) Concatenar String com outra\n");
	printf("(e) Imprimir reverso\n");
	printf("(f) Contar quantas vezes caractere aparece\n");
	printf("(g) Substituir primeira ocorrencia de um caractere por outro\n");
	printf("(h) Verificar se e substring\n");
	printf("(i) Retornar substring\n");
	printf("(j) Sair\n");


	while (!fechar) {

		printf("\nEscolha uma opcao: ");
		scanf(" %c", &opcao);

		if(opcao >= 65 && opcao<=90) {
			opcao=opcao+32;
		}

		switch(opcao) {
		case 'a': //Ler uma string
			scanf("%100[^\n]", limpar);
			printf("\nFrase (max: 20 caracteres): ");
			scanf (" %20[^\n]", string1);
			printf("\n--------------------------------------------------\n");
			scanf("%100[^\n]", limpar);
			break;

		case 'b': //Tamanho da string
			i=0;
			while(string1[i] != '\0') {
				i++;
			}
			tam1 = i;
			printf("\nTamanho: %d", tam1);
			printf("\n--------------------------------------------------\n");
			break;

		case 'c': //Comparar string com outra
			scanf("%200[^\n]", limpar);
			printf("Frase 2 (max: 20 caracteres): ");
			scanf (" %20[^\n]", string2);

			for (i=0; i<tam1; i++) {
				if (string1[i]!=string2[i]) {
					diferente=1;
				}
			}

			if(diferente) {
				printf("\nAs frases sao diferentes");
			}
			else {
				printf("\nAs frases sao iguais");
			}
			printf("\n--------------------------------------------------\n");
			scanf("%100[^\n]", limpar);
			break;

		case 'd': // Concatenar Strings
			scanf("%100[^\n]", limpar);
			printf("Frase 2: ");
			scanf (" %20[^\n]", string2);
			printf("%s %s", string1, string2);
			printf("\n--------------------------------------------------\n");
			scanf("%100[^\n]", limpar);
			break;

		case 'e': //Imprimir reverso
			printf("\n");

			i=0;
			while(string1[i] != '\0') {
				i++;
			}

			while(i>=0) {
				printf("%c", string1[i]);
				i--;
			}

			printf("\n--------------------------------------------------\n");
			break;

		case 'f': //Contar quantas vezes aparece caractere
			scanf("%100[^\n]", limpar);
			printf("\nInforme o caractere: ");
			scanf(" %c", &caractere);

			i=0;
			while(string1[i] != '\0') {
				if(string1[i] == caractere) {
					contc++;
				}
				i++;
			}

			printf("\n'%c' aparece %d vezes", caractere, contc);
			printf("\n--------------------------------------------------\n");
			scanf("%100[^\n]", limpar);
			break;

		case 'g': //Substituir primeira ocorrencia de caractere

			scanf("%100[^\n]", limpar);
			printf("\nInforme o caractere a ser substituido: ");
			scanf(" %c", &caractere);
			printf("Informe o caractere que ira substituir: ");
			scanf(" %c", &caractere2);
			i=0;


			while(string1[i] != '\0' && primeiroc !=1) {
				if(string1[i] == caractere ) {
					string1[i] = caractere2;
					primeiroc=1;
				}
				i++;
			}

			i=0;
			printf("\nSubstituicao do primeiro '%c' por '%c': ", caractere, caractere2);
			while(string1[i] != '\0') {
				printf("%c", string1[i]);
				i++;
			}

			printf("\n--------------------------------------------------\n");
			scanf("%100[^\n]", limpar);
			break;

		case 'h': // Verificar se e substring
			scanf("%200[^\n]", limpar);

			printf("Informe a substring: ");
			scanf (" %20[^\n]", string2);

			j= 0;
			i=0;
			while(string1[i] != '\0') {
				i++;
			}
			tam1 = i;

			for(i=0; i<tam1; i++) {
				if(string1[i] == string2[j]) {
					k=i;
					for(j=0; j<tam2; j++) {
						if (string1[k] == string2[j]) {
							cont++;
							k++;
						}
					}
					if(cont==tam2) {
						esta_contida=1;
					}
				}
				j=0;
			}

			if(esta_contida) {
				printf("\nA substring esta contida na frase");
			}
			else {
				printf("\nA substring NAO esta contida na frase");
			}

			printf("\n--------------------------------------------------\n");
			scanf("%100[^\n]", limpar);
			break;

		case 'i': // Retornar substring
		
            printf("\n");
			do{
				printf("Informe a primeira posicao (Entre 0 a 20): ");
				scanf("%d", &index1);
			}while (index1 > 20 || index1<=0);

			do {
				printf("Informe a ultima posicao (Entre 0 a 20): ");
				scanf("%d", &index2);
				if (index2 > index1){
				    printf("Posicao final menor que inicial");
				}
			} while (index2 >20 || index2<=0 || index2<index1);

			printf("Substring de %d a %d: ", index1, index2);

			for (i=index1-1; i<=index2-1; i++) {
				printf("%c", string1[i]);
			}
			printf("\n--------------------------------------------------\n");
			scanf("%100[^\n]", limpar);
			break;

		case 'j':
			fechar=1;
			break;

		default:
			printf("Opcao invalida: ");
			scanf("%100[^\n]", limpar);
			break;

		}
	}


	return 0;
}