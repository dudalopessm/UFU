#include <stdio.h>
float media (float n1,float n2,float n3) {
    float m;
    m = ((n1 + n2 + n3)/3);
    return m;
}
int main () {
    printf("######## Calculadora de media academica ########");
    float n1, n2, n3, media1, notaf;
    printf("\n\nDigite a primeira nota: ");
    setbuf (stdin, NULL);
    scanf("%f", &n1);
    printf("Agora, digite a segunda nota: ");
    setbuf (stdin, NULL);
    scanf("%f", &n2);
    printf("Por fim, digite a terceira nota: ");
    setbuf (stdin, NULL);
    scanf("%f", &n3);
    media1 = media(n1, n2, n3);
    printf("\n\nCalculando sua media...");
    if (media1 <= 3) {
        printf("\n\nSua media corresponde a %.2f pontos e voce foi REPROVADO.", media1);
    } else if (media1 > 3 && media1 <= 7) {
        notaf = 12 - media1;
        printf("\n\nSua media corresponde a %.2f pontos e voce esta de EXAME FINAL.", media1);
        printf("\nA nota que deve ser tirada na prova final equivale a %.2f.", notaf);
    } else {
        printf("\n\nSua media corresponde a %.2f pontos e voce foi APROVADO.", media1);
    }
   printf("\n\n######## Obrigada por usar o software! ########");
   printf("\n");
   return 0;
}