#include <stdio.h>

// Dados três valores, A, B e C, verificar se eles podem ser valores dos lados de um triângulo e, se forem,  qual é o tipo do triângulo (equilátero, isósceles ou escaleno).
// a < b + c | b < a + c | c < a + b -> regra existência triângulo

int main () {
    float A, B, C;

    printf("Digite tres valores dos lados de um triangulo:\t");
    scanf("%f %f %f", &A, &B, &C);

    if(A < B + C && B < A + C && C < A + B && A != B && A != C && B != C){
        printf("O triangulo ABC eh escaleno.\n");
    } else if ((A < B + C && B < A + C && C < A + B) && ((B != C && (A == B || A == C)) || (B == C && A != B && A != C))) {
        printf("O triangulo ABC eh isosceles.\n");
    } else if (A < B + C && B < A + C && C < A + B && A == B && B == C && A == C) {
        printf("O triangulo ABC eh equilatero.\n");
    } else {
        printf ("Nao existe triangulo com os valores de ABC digitados acima.\n");
    }

    return 0;

}
