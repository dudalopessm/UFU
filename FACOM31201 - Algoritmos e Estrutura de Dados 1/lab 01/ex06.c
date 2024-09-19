#include <stdio.h>
#include <string.h>
#include <math.h>
double area (double base, double altura) {
    double result; 
    result = 0;
    result = ((base*altura)/2);
    return result;
}
double areaeq (int n, double *lados) {
    double result;
    result = 0;
    result = (((lados[1])*(lados[1]))*1.732)/4;
    return result;
}
double areaisos (int n, double *lados) {
    double result, h;
    result = 0;
    h = sqrt(((lados[0]*lados[0])-((lados[1]*lados[1])/4)));
    result = (lados[0]*h)/2;
    return result;
}
double areaesc (int n, double *lados) {
    double result, h, s;
    s = (lados[0]+lados[1]+lados[2])/2;
    result = 0;
    h = ((2/lados[0])*sqrt((s*(s-lados[0])*(s-lados[1])*(s-lados[2]))));
    result = (lados[0]*h)/2;
    return result;
}
int main () {
    printf("\n\n######## Calculadora de area de triangulo ########");
    printf("\n\nVoce conhece a altura do triangulo? ");
    char pergunta[4];
    fgets(pergunta, 4, stdin);
    double b, h, r;
    double l[3];
    if (strcmp(pergunta,"S") == 0 || strcmp(pergunta,"s") == 0 || strcmp(pergunta,"sim") == 0 || strcmp(pergunta,"Sim") == 0 || strcmp(pergunta,"SIM") == 0|| strcmp(pergunta,"SIm") == 0 || strcmp(pergunta,"SiM") == 0) {
        printf("\n\nDigite a medida da base: ");
        setbuf (stdin, NULL);
        scanf("%lf", &b);
        printf("\n\nDigite a medida da altura: ");
        setbuf (stdin, NULL);
        scanf("%lf", &h);
        while (b <=0 || h<= 0) {
            printf("\n\nDados invalidos, portanto, encerrando programa...");
            printf("\n");
            return 0;
        }
        printf("\n\nCalculando...");
        r = area(b, h);
        printf("\n\nA area do triangulo possui %.2lf u.c.", r);
    } else {
        printf("\n\nDigite a medida dos lados abaixo, sendo o primeiro o maior lado.");
        for (int i = 0; i < 3; i++) {
            setbuf (stdin, NULL);
            printf("\n\nDigite a medida do %d lado: ", i + 1);
            scanf("%lf", &l[i]);
        }
        while (l[0] <= 0 || l[1] <= 0 || l[2] <= 0) {
            printf("\n\nDados invalidos, portanto, encerrando programa...");
            printf("\n");
            return 0;
        }
        if (l[0] == l[1] && l[1] == l[2]) {
            r = areaeq(3, l);
            printf("\n\nCalculando...");
            printf("\n\nA area do triangulo possui %.2lf u.c.", r);
        } else if (l[1] == l[2] && l[0] != l[1]) {
            r = areaisos(3, l);
            printf("\n\nCalculando...");
            printf("\n\nA area do triangulo possui %.2lf u.c.", r);
        } else {
            r = areaesc(3, l);                    
            printf("\n\nCalculando...");
            printf("\n\nA area do triangulo possui %.2lf u.c.", r);
        }
    }
    printf("\n\n######## Obrigada por usar! ########");
    printf("\n");
    return 0;
    }
