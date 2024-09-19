#include <stdio.h>
#include <stdlib.h>
struct cliente {
    int cpf, filhos;
    char civil[20], nomesf[50];
};
void opcoes () {
    printf("\n\nEscolha sua opcao:");
    printf("\n\n1- Inserir cliente.");
    printf("\n\n2- Remover cliente.");
    printf("\n\n3- Mostrar todos os cpfs inseridos.");
    printf("\n\n4- Sair.");
    printf("\n");
}
int main () {
    printf("\n\n######## Informacoes dos clientes ########");
    printf("\n\nInsira a quantidade de clientes que ira consultar: ");
    int n, op, i, r, n2;
    op = 0;
    setbuf(stdin, NULL);
    scanf("%d", &n);
    struct cliente c[n];
    if (c == NULL) return 0;  
    opcoes();
    while (op != 4) {
    printf("\nA opcao desejada corresponde ao numero: ");
    setbuf(stdin, NULL);
    scanf("%d", &op);
        if (op == 1) {
            printf("\n\nQuantos clientes deseja inserir: ");
            setbuf(stdin, NULL);
            scanf("%d", &n2);
            for (i = 0; i < n2; i++) {
                printf("\n\nDigite o cpf do cliente a ser inserido: ");
                setbuf(stdin, NULL);
                scanf("%d", &c[i].cpf);
                printf("\nDigite o estado civil do cliente a ser inserido: ");
                setbuf(stdin, NULL);
                fgets(c[i].civil, 20, stdin);
                printf("\nO cliente a ser inserido tem filhos? Se sim digite o numero, se nao digite 0: ");
                setbuf(stdin, NULL);
                scanf("%d", &c[i].filhos);
                if (c[i].filhos > 0) {
                    printf("\nInsira o nome dos filhos, separados por virgulas: ");
                    setbuf(stdin, NULL);
                    fgets(c[i].nomesf, 50, stdin);
                    
                }
            }
            printf("\n\nVoltando...");
            printf("\n");
        } else if (op == 2) {
            printf("\n\nDigite a posicao no sistema do cliente deseja remover: ");
                setbuf(stdin, NULL);
                scanf("%d", &r);
                for (i = r; i < n - 1; i++) {
                    c[i].cpf = c[i+1].cpf;
                }
            n--;
            printf("\n\nVoltando...");
            printf("\n");
        } else if (op == 3) {
            printf("\n\nClientes: ");
            printf("\n");
            for (i = 0; i < n; i++) {
                if (c[i].filhos > 0) {
                    printf("\n - %d que possui parentesco com: %s", c[i].cpf, c[i].nomesf);
                } else {
                    printf("\n - %d", c[i].cpf);
                }
            }
            printf("\n\nVoltando...");
            printf("\n");
        } else if (op == 4) {
        printf("\n\nEncerrando o software...");
        printf("\n\n######## Obrigada por usar! ########");
        printf("\n");
            break;
        }
    }
    return 0;
}