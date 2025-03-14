/**

27. Fac¸a um programa que, dada uma string, diga se ela e um palındromo ou nao. Lem- ˜
brando que um pal´ındromo e uma palavra que tenha a propriedade de poder ser lida ´
tanto da direita para a esquerda como da esquerda para a direita. Exemplo:
ovo
arara
Socorram-me, subi no ^onibus em Marrocos.
Anotaram a data da maratona
 
 
**/

#include <stdio.h>

int main()
{
	char string[10000];
	int i=0, j=0, tam=0, nao_eh_palindromo = 0;
	
	
	printf("Frase: ");
	scanf ("%10000[^\n]", string);
	
	while(string[i] != '\0'){
	    if(string[i] >= 65 && string[i]<=90){
	        string[i] = string[i]+32;
	    }
	    tam++;
	    i++;
	}
	
	i=0;

	while(string[i] != '\0'){
	    if(string[i] == ' '){
	        for (j=i; j<tam; j++){
	            string[j] = string[j+1];
	        }
	        tam--;
	    }
	    i++;
	}
	
	
	i=0;
	
	while(tam > 0){
	    
	    if(string[i] != string[tam-1]){
	        nao_eh_palindromo = 1;
	    }
	    i++;
	    tam--;
	}
	
	
	if(nao_eh_palindromo){
	    printf("\nNao e palindromo");
	}
	else {
	    printf("\nE palindromo");
	}
	
	
	
	return 0;
}