/******************************************************************************

Escreva um trecho de codigo para fazer a criacao dos novos tipos de dados conforme  L
solicitado abaixo:
b" Horario: composto de hora, minutos e segundos.  L
b" Data: composto de dia, mes e ano. 
b" Compromisso: composto de uma data, horario e texto que descreve o compromisso.  L

*******************************************************************************/
#include <stdio.h>

typedef struct {
	int hr;
	int min;
	int seg;
} Horario;


typedef  struct {
	int dia;
	int mes;
	int ano;
} Data;

typedef struct {
	Horario horario;
	Data data;
	char compromisso[500];
} Compromisso;

int main()

{

	Compromisso compromisso1;
	
	printf("Informe o nome do compromisso: ");
	scanf("%500[^\n]", compromisso1.compromisso);
	printf("Informe a data do compromisso (dd mm aaaa): ");
	scanf("%d%d%d", &compromisso1.data.dia, &compromisso1.data.mes, &compromisso1.data.ano);
	printf("Informe o horario do compromisso (hr min seg): ");
	scanf("%d%d%d", &compromisso1.horario.hr, &compromisso1.horario.min, &compromisso1.horario.seg);
	
	
	printf("Compromisso: %s\n", compromisso1.compromisso);
	printf("Data: %d/%d/%d\n", compromisso1.data.dia, compromisso1.data.mes, compromisso1.data.ano);
	printf("Horario: %d:%d:%d", compromisso1.horario.hr, compromisso1.horario.min, compromisso1.horario.seg);
	
	return 0;
}