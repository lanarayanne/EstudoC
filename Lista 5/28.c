/**

28. Construa um programa que leia duas strings fornecidas pelo usuario e verifique se a se- ´
gunda string lida esta contida no final da primeira, retornando o resultado da verificac¸ao.
 
**/

#include <stdio.h>

int main()
{
	char string1[10000];
	char string2[10000];
	char nada;
	
	int i=0, j=0, k=0, tam1=0, tam2=0, cont=0, esta_contida = 0;
	
	
	printf("Frase 1: ");
	scanf ("%10000[^\n]", string1);
	
	scanf("%c", &nada);
	
	printf("Frase 2: ");
	scanf ("%10000[^\n]", string2);
	
	
	while(string1[i] != '\0'){
	    if(string1[i] >= 65 && string1[i]<=90){
	        string1[i] = string1[i]+32;
	    }
	    tam1++;
	    i++;
	}
	
	i=0;
	
	while(string2[i] != '\0'){
	    if(string2[i] >= 65 && string2[i]<=90){
	        string2[i] = string2[i]+32;
	    }
	    tam2++;
	    i++;
	}
	
	j=0;
	k=0;
	
	for(i=0; i<tam1; i++){
	    if(string1[i] == string2[j]){
	        k=i;
	        for(j=0; j<tam2; j++){
	            if (string1[k] == string2[j]){
	                cont++;
	                k++;
	            }
	        }
	        if(cont==tam2 && i==(tam1-tam2)){
	            esta_contida=1;
	        }
	    }
	    j=0;
	}
	
	
	if(esta_contida){
	    printf("\nA frase 2 esta contida no final da frase 1");
	}
	else {
	    printf("\nA frase 2 NAO esta contida no final da frase 1");
	}
	
	
	
	return 0;
}