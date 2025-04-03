/******************************************************************************
Fac¸a um programa que fac ¸a operac ¸˜ oes simples de n´umeros complexos:
 Crie e leia dois n´umeros complexos z e w, compostos por parte real e parte ima
gin´ aria.
 Apresente a soma, subtrac¸˜ ao e produto entre z e w, nessa ordem, bem como o
 m´ odulo de ambos
*******************************************************************************/
#include <stdio.h>
#include<math.h>


typedef struct {
    float a;
    float b;
} Complexo;

int main(){
    
    Complexo complexo1, complexo2;
    
    printf("Primeiro numero:\n");
    printf("a:");
    scanf("%f", &complexo1.a);
    printf("b: ");
    scanf("%f", &complexo1.b);
    
    printf("Segundo numero:\n");
    printf("a:");
    scanf("%f", &complexo2.a);
    printf("b: ");
    scanf("%f", &complexo2.b);
    
    float modulo1 = sqrt(pow(complexo1.a, 2) + pow(complexo1.b, 2));
    float modulo2 = sqrt(pow(complexo2.a, 2) + pow(complexo2.b, 2));
    
    printf("\nSoma = (%.2f)+(%.2f)i", complexo1.a+complexo2.a, complexo1.b+complexo2.b);
    printf("\nSubtracao = (%.2f)-(%.2f)i", complexo1.a-complexo2.a, complexo1.b-complexo2.b);
    printf("\nMultiplicacao = (%.2f)*(%.2f)i", complexo1.a*complexo2.a, complexo1.b*complexo2.b);
    printf("\nModulo do primeiro numero= %.2f", modulo1);
    printf("\nModulo do segundo numero= %.2f", modulo2);
    
    

	return 0;
}


