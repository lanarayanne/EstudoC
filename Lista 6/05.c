/******************************************************************************
Considerando a estrutura

struct Vetor{
 float x;
 float y;
 float z;
 };
 para representar um vetor no R3, implemente um programa que calcule a soma de dois
 vetores.
 
*******************************************************************************/
#include <stdio.h>

typedef struct {
	float x;
	float y;
	float z;
} Vetor;

int main()

{
    Vetor vetor1;
    Vetor vetor2;
    Vetor vetor_soma;
    
	printf("Vetor 1:\n");
	printf("x:");
	scanf("%f", &vetor1.x);
	printf("y:");
	scanf("%f", &vetor1.y);
	printf("z:");
	scanf("%f", &vetor1.z);
	
	printf("\nVetor 2:\n");
	printf("x:");
	scanf("%f", &vetor2.x);
	printf("y:");
	scanf("%f", &vetor2.y);
	printf("z:");
	scanf("%f", &vetor2.z);
	
	vetor_soma.x = vetor1.x + vetor2.x;
	vetor_soma.y = vetor1.y + vetor2.y;
	vetor_soma.z = vetor1.z + vetor2.z;
	
	printf("Soma de Vetores");
	printf("\nx = %.2f", vetor_soma.x);
	printf("\ny = %.2f", vetor_soma.y);
	printf("\nz = %.2f", vetor_soma.z);
	
	return 0;
}