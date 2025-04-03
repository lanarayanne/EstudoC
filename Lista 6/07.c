/******************************************************************************
 7. Fac¸a um programa que converta coordenadas polares para cartesianas:
 Crie e leia um ponto em coordenada polar, composto por raio (r) e argumento (a)
 em radianos.
 1
Crie outro ponto, agora em coordenada cartesiana, composto por x e y, sabendo
 que x =r cos a e y =r sina.
 No programa principal, leia um ponto em coordenada polar e mostre as coordenadas do
 ponto gerado no plano cartesiano.
*******************************************************************************/
#include <stdio.h>
#include<math.h>

typedef struct {
    float raio;
    float argumento;
} Polar;

typedef struct {
    float x;
    float y;
} Cartesiana;

int main(){
    
    Polar polar;
    Cartesiana cartesiana;
    
    printf("Informe uma coordenada polar:\nRaio:");
    scanf("%f", &polar.raio);
    printf("Argumento: ");
    scanf("%f", &polar.argumento);
    
    cartesiana.x= polar.raio * cos(polar.argumento);
    cartesiana.y= polar.raio * sin(polar.argumento);
    
    printf("\nCartesianas:\nx=%.2f\ny=%.2f", cartesiana.x, cartesiana.y);

	return 0;
}