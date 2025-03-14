/**

      O codigo de Cesar e uma das mais simples e conhecidas tecnicas de criptografia. E um
 tipo de substituicao na qual cada letra do texto ´ e substituida por outra, que se apresenta
 no alfabeto abaixo dela um n´umero fixo de vezes. Por exemplo, com uma troca de trˆ es
 posic ¸˜ oes, ‘A’ seria substitu´ ıdo por ‘D’, ‘B’ se tornaria ‘E’, e assim por diante. Implemente
 umprograma que fac¸a uso desse C´ odigo de C´ esar (3 posic¸˜ oes), entre com uma string e
 retorne a string codificada. Exemplo:
 String: a ligeira raposa marrom saltou sobre o cachorro cansado
 Nova string: D OLJHLUD UDSRVD PDUURP VDOWRX VREUH R FDFKRUUR FDQVDGR
 
 
**/

#include <stdio.h>

int main()
{
	char string[10000];
	int i=0, quant = 3;
	
	
	printf("Frase a ser criptografada: ");
	scanf ("%10000[^\n]", string);

	while(string[i] != '\0'){
	    if (string[i] != ' '){
	        printf("%c", string[i]+3);
	    }
	    else {
	        printf("%c", string[i]);
	    }
	    i++;
	}
	
	
	return 0;
}