/**

32. Leia uma cadeia de caracteres no formato DD/MM/AAAAb e copie o dia, mes e ano para
 3 variaveis inteiras. Antes disso, verifique se as barras estao no lugar certo, e se DD, MM
 e AAAA sao numericos

**/

#include <stdio.h>

int main()
{
	char data[10];

	printf("Informe uma data DD/MM/AAAA: ");
	scanf("%10[^\n]", data);

	//Verficacoes

	for (int i=0; i<10; i++) {
		if (i != 2 && i != 5) {
			if (data[i] <48 || data[i]>57) {
				printf("Data invalida - dias devem ser numeros\n");
			}
		}
		else {
			if (data[i] != 47) {
				printf("Data invalida\n");
			}
		}
	}

	int dia = ((data[0]-48)*10) + (data[1] - 48);
	int mes = ((data[3]-48)*10) + (data[4] - 48);
	int ano = ((data[6]-48)*1000) + ((data[7]-48)*100) + ((data[8]-48)*10) + (data[9]-48);


	if (mes < 0 || mes >12) {
		printf("Mes invalido\n");
	}

	if (mes==2) {
		if(ano%4 == 0) {
			if (dia > 29) {
				printf("Dia Invalido\n");
			}
		}
		else {
			if (dia > 28) {
				printf("Dia Invalido\n");
			}
		}
	}
	else if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
		if (dia < 0 || dia >31) {
			printf("Dia invalido\n");
		}
	}
	else {
		if (dia < 0 || dia >30) {
			printf("Dia invalido\n");
		}

	}

	printf("Dia = %d\n", dia);
	printf("Mes = %d\n", mes);
	printf("Ano = %d\n", ano);


	return 0;
}