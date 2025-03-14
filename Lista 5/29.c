/**

 Implemente um programa que leia duas strings, str1 e str2, e um valor inteiro positivo
 N. Concatene nao mais que N caracteres da string str2 ` a string str1 e termine str1 com
 NULL
 
**/

#include <stdio.h>

int main()
{
	char string1[10000];
	char string2[10000];
	char nada;
	
	int i=0, j=0, k=0, tam1=0, tam2=0, cont=0, quant;
	
	
	printf("Frase 1: ");
	scanf ("%10000[^\n]", string1);
	
	scanf("%c", &nada);
	
	printf("Frase 2: ");
	scanf ("%10000[^\n]", string2);
	
	printf("Quantidade de caracteres a serem concatenados: ");
	scanf("%d", &quant);
	
	
	while(string1[i] != '\0'){
	    tam1++;
	    i++;
	}
	
	i=0;
	
	while(string2[i] != '\0'){
	    tam2++;
	    i++;
	}
	
	j=0;
	k=0;
	
	for(i=tam1; i<=(tam1+quant); i++){
	    if(i==tam1){
	        string1[i] = ' ';
	    }
	    else {
	        string1[i] = string2[j];
	        j++;
	    }
	}
	
	i=0;
	
	printf("\nFrase concatenada: ");
	while (string1[i] != '\0'){
	    printf("%c", string1[i]);
	    i++;
	}
	
	
	
	return 0;
}