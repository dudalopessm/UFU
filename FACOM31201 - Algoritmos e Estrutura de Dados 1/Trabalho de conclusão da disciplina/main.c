#include "Clientes.h"
#include "Pratos.h"
#include "Pedidos.h"
#include "Restaurantes.h"
#include "Avaliacoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Inicio() { //funcao para mostrar o inicio
    printf("\n\n-------- Bem vindo(a) --------");
    printf("\n");
    printf("\n\nEu sou a Eva, sua gerenciadora de pedidos inteligente ( o.o )");
    printf("\nOpcoes disponiveis:");
    printf("\n");
    printf("\n0. Sair do aplicativo");
    printf("\n1. Menu para clientes");
    printf("\n2. Menu para prestadores de servico");
    printf("\n");
}

void Fim() { //funcao para mostrar tela de fim
    printf("\n\nEncerrando...");
    printf("\nSalvando...");
    printf("\nAte a proxima!");
}

void Opcao() { //sempre que for pedir opcao
    printf("\nDigite a opcao desejada: ");
}

void Restaurantes(char *auxcat) { //funcao para retornar a categoria do restaurante por meio de strcpy
    int op;
    do {
        printf("\n1. Comida japonesa");
        printf("\n2. Comida brasileira");
        printf("\n3. Pizzas");
        printf("\n4. Hamburgueres");
        printf("\n5. Vegetarianos");
        printf("\n6. Comida arabe");
        printf("\n7. Doces e bolos");
        printf("\n8. Comida italiana");
        printf("\n9. Padaria");
        printf("\n10. Nenhuma listada");
        Opcao();
        scanf("%d", &op);
        switch (op) {
            case 1:
                strcpy(auxcat, "Comida japonesa");
                break;
            case 2:
                strcpy(auxcat, "Comida brasileira");
                break;
            case 3:
                strcpy(auxcat, "Pizzas");
                break;
            case 4:
                strcpy(auxcat, "Hamburgueres");
                break;
            case 5:
                strcpy(auxcat, "Vegetarianos");
                break;
            case 6:
                strcpy(auxcat, "Comida arabe");
                break;
            case 7:
                strcpy(auxcat, "Doces e bolos");
                break;
            case 8:
                strcpy(auxcat, "Comida italiana");
                break;
            case 9:
                strcpy(auxcat, "Padaria");
                break;
            case 10:
                strcpy(auxcat, "Nenhuma listada");
                break;
            default:
                printf("\nOpcao invalida! Digite alguma valida.");
        }
    } while(op < 1 && op > 10);
}

int ConfirmaSenha(char *s) { //funcao que verifica se a senha tem exatamente 8 caracteres e contem pelo menos um numero
    int i = 0, num = 0, tam = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '1' && s[i] <= '9') {
            num++;
        }
        tam++;
    }
    if (num && tam >= 8) return 0;
    return 1;
}

int ConfirmaEmail(char *email) { //funcao que verifica se o email tem @ e .
    int auxarroba = 0, auxponto = 0, i;
    for (i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            auxarroba++;
        } else if (email[i] == '.' && auxarroba == 1) {
            auxponto++;
        }
    }
    if (auxarroba != 1) return 2;
    if (auxponto != 1) return 3;
    return 0;
}

int ConfirmaCPF(char *cpf) { //verifica se o CPF digitado está na formatação certa (XXX.XXX.XXX-XX)
    int i, tam = 0;
    for (i = 0; cpf[i] != '\0'; i++) {
        tam++;
    }
    if (cpf[11] != '-') return 1;
    if (cpf[3] != '.' || cpf[7] != '.') return 1;
    if(tam<14) return 1;
    return 0;
}

int ConfirmaCNPJ(char *cnpj) { //verifica se o CNPJ digitado está na formatação certa (XX.XXX.XXX/YYYY-ZZ)
    int i, tam = 0;
    for (i = 0; cnpj[i] != '\0'; i++) {
        tam++;
    }
    if (tam!= 17) return 1;
    if (cnpj[2] != '.' || cnpj[6] != '.') return 1;
    if (cnpj[10] != '/') return 1;
    if (cnpj[15] != '-') return 1;
    return 0;
}

int ConfirmaEstrelas(char *est) { //verifica se a classificacao é um numero entre 0 e 5 e se foi realizada
    int i, tam = 0, num = 0;
    for (i = 0; est[i] != '\0'; i++) {
        if (est[i] >= '0' && est[i] <= '5') num++; 
        tam++;
    }
    if ((num == 1) && (tam == 1)) return 0; 
    return 1;
}

int main () {
    int menuprincp, menucli1, menucli2, menurest1, menurest2;
    int controle, opcli, cod, ret, quantidade, opc, op, auxx;
    char auxcat[30], auxsenha[10], auxfeed[300], auxestr[2];
    ListaC *lCli;
    ListaR *lRest;
    ListaP *lPr;
    ListaF *lFeed;
    lCli = criarCliente();
    lRest = criarRest();
    lPr = criarP();
    lFeed = criarF();
    Cliente c1;
    Cliente c2 = {"123.123.123-12", "Administrador", "admin@email.com", "admin123"}; //usuario para teste em produção
    controle = inserirCliente(lCli, c2); //usuario para teste em produção
    Restaurante r1;
    Restaurante r2 = {"Japaroll", "Comida japonesa", "12.345.678/0003-00", "admin@email.com", "admin123", 11, NULL, NULL}; //usuario para teste em produção
    controle = inserirRest(lRest, r2); //usuario para teste em produção
    Restaurante r3 = {"Duda Bolos", "Doces e bolos", "12.345.678/0003-01", "duda@email.com", "laura222", 1, NULL, NULL}; //usuario para teste em produção
    controle = inserirRest(lRest, r3);
    Pratos p1;
    Feedback feed1;
    do
    {
        //inicio do programa
        Inicio();
        Opcao();
        scanf("%d", &menuprincp);
        system("cls");
        switch (menuprincp)
        {
            case 0: //caso usuario queira sair
                system("cls");
                Fim();
                break;
            //LOGIN CLIENTE
            case 1: 
                do {
                    printf("\n\n-------- Area do cliente --------");
                    printf("\n0. Retornar");
                    printf("\n1. Login");
                    printf("\n2. Cadastre-se");
                    Opcao();
                    scanf("%d", &menucli1);
                    setbuf(stdin, NULL);
                    system("cls");
                    switch (menucli1) {
                        case 0: //saida do menu do cliente
                            break;
                        case 1: //tela de login do cliente
                            do {
                                setbuf(stdin, NULL);
                                printf("\nInsira seu email: ");
                                setbuf(stdin, NULL);
                                fgets(c1.email, 50, stdin);
                                c1.email[strcspn(c1.email, "\n")] = '\0';
                                setbuf(stdin, NULL);
                                controle = ConfirmaEmail(c1.email);
                                if (controle) {
                                    printf("\nEmail invalido, digite novamente.");
                                } else if (buscaEmailCliente(lCli, c1.email) != 0) {
                                    controle = 1;
                                    printf("\nEmail nao cadastrado, digite novamente.");
                                }
                            } while(controle);
                            buscaCliente(lCli, c1.email, &c1); //verifica se email está cadastrado
                            do {
                                setbuf(stdin, NULL);
                                printf("\nSenha: ");
                                setbuf(stdin, NULL);
                                fgets(auxsenha, 9, stdin);
                                auxsenha[strcspn(auxsenha, "\n")] = '\0';
                                setbuf(stdin, NULL);
                                controle = ConfirmaSenha(auxsenha);
                                if(controle){
                                    printf("\nSenha invalida. Tente novamente.");
                                } else if (strcmp(auxsenha, c1.senha)) {
                                    printf("\nSenha incorreta, digite novamente.");
                                    controle = 1;
                                }
                            }while(controle);
                            //CLIENTE LOGADO
                            do {
                                system("cls");
                                printf("\n\n-------- %s, bem vindo(a) --------", c1.nome);
                                printf("\n0. Retornar");
                                printf("\n1. Faca seu pedido!");
                                printf("\n2. Pagamento e finalizacao de pedidos");
                                printf("\n3. Confirmacao de pedidos");
                                printf("\n4. Feedbacks");
                                printf("\n5. Excluir conta");
                                Opcao();
                                scanf("%d", &menucli2);
                                system("cls");
                                switch (menucli2) {
                                    case 0: //saida
                                        break;
                                    case 1: //para fazer pedidos
                                        do {
                                            printf("\n-------- Nossos servicos --------");
                                            Restaurantes(auxcat); //define qual categoria o usuario quer olhar
                                            system("cls");
                                            printf("\n-------- Restaurantes disponiveis --------");
                                            mostrarR(lRest, auxcat); //mostra restaurantes disponiveis
                                            printf("\nDeseja olhar o cardapio de algum restaurante?");
                                            printf("\n0. Nao, desejo retornar ");
                                            printf("\n1. Sim, quero olhar");
                                            Opcao();
                                            scanf("%d", &opcli);
                                            switch (opcli) {
                                                case 0:
                                                    break;
                                                case 1: //fazer pedido
                                                    printf("\nDigite o numero da identificacao do restaurante: ");
                                                    scanf("%d", &opcli);
                                                    ret = achaRest(lRest, opcli, &r1); //verifica se restaurante existe
                                                    if (ret) {
                                                        printf("\nCodigo incorreto. Tente novamente.");
                                                        opcli = 1;
                                                        break;
                                                    } else {
                                                        do {
                                                            printf("\n-------- Menu --------");
                                                            mostrarPratos(r1.cardapio); //mostra cardapio do restaurante
                                                            printf("\n");
                                                            printf("\nDeseja fazer um pedido?");
                                                            printf("\n0. Nao, desejo retornar.");
                                                            printf("\n1. Sim, desejo pedir.");
                                                            printf("\nDigite sua opcao: ");
                                                            scanf("%d", &opcli);
                                                            setbuf(stdin, NULL);
                                                            switch (opcli) {
                                                                case 0:
                                                                    break;
                                                                case 1:
                                                                    printf("\nDigite o codigo do prato: ");
                                                                    scanf("%d", &opcli);
                                                                    fflush(stdin);
                                                                    printf("\nQuantidade: ");
                                                                    scanf("%d", &quantidade);
                                                                    fflush(stdin);
                                                                    acharPrato(lRest, opcli, &r1); //conecta o prato ao restaurante 
                                                                    controle = buscaPrato(r1.cardapio, opcli, &p1); //busca se o prato esta no cardapio e retorna ele em um item
                                                                    system("cls");
                                                                    if (controle) {
                                                                        printf("\nErro na realizacao do pedido.");
                                                                        opcli = 1;
                                                                        break;
                                                                    } else {
                                                                        p1.quantidade = quantidade; //define a quantidade do pedido
                                                                        p1.restauranteorigem = r1.identificacao; //define a origem do pedido
                                                                        ret = inserirPrato(c1.carrinho, p1); //insere o prato no carrinho do cliente
                                                                        if (ret) {
                                                                            printf("\nErro ao realizar pedido.");
                                                                        } else {
                                                                            printf("\nPedido realizado.");
                                                                        }
                                                                    }
                                                            }
                                                            printf("\n");
                                                            printf("\nPedir de novo?");
                                                            printf("\n0. Nao, desejo retornar.");
                                                            printf("\n1. Sim, desejo olhar os pratos novamente.");
                                                            Opcao();
                                                            scanf("%d", &opcli);
                                                            system("cls");
                                                        } while (opcli);
                                                    }
                                            }
                                            printf("\nOlhar outros restaurantes?");
                                            printf("\n0. Nao, desejo retornar.");
                                            printf("\n1. Sim, desejo olhar os restaurantes novamente.");
                                            Opcao();
                                            scanf("%d", &opcli);
                                            system("cls");
                                        } while(opcli);
                                        break;
                                    case 2: //carrinho e pagamento
                                        printf("\n-------- Pagamento R$ --------");
                                        mostrarPCliente(c1.carrinho); //mostra pedidos no carrinho ainda nao finalizados
                                        float pag = carrinho(c1.carrinho); //retorna total a ser pago
                                        printf("\nTotal: %.2f reais", pag);
                                        printf("\n-------------------------");
                                        printf("\n");
                                        opc = 1;
                                        while (opc && (listaVaziaP(c1.carrinho) == 1)) {
                                            printf("\nCancelar algum item?");
                                            printf("\n0. Nao");
                                            printf("\n1. Sim");
                                            Opcao();
                                            scanf("%d", &opc);
                                            fflush(stdin);
                                            switch (opc) {
                                                case 0:
                                                    break;
                                                case 1:
                                                    printf("\nNumero do item que deseja cancelar: ");
                                                    scanf("%d", &opc);
                                                    fflush(stdin);
                                                    controle = buscaPrato(c1.carrinho, opc, &p1); //busca se o item a ser cancelado existe
                                                    if (controle == 0) {
                                                        controle = removerPrato(c1.carrinho, p1); //cancela item do carrinho
                                                        if (controle == 0) {
                                                            opc = 0;
                                                            system("cls");
                                                            printf("\nPedido cancelado.");
                                                        } else {
                                                            opc = 1;
                                                            system("cls");
                                                            printf("\nErro ao cancelar pedido.");
                                                        }
                                                    } else {
                                                        system("cls");
                                                        printf("\nOpcao invalida. Tente novamente.");
                                                    }
                                                    break;
                                                default:
                                                    system("cls");
                                                    printf("\nOpcao invalida. Tente novamente.");
                                            }
                                        }
                                        opc = 1;
                                        while(opc && (listaVaziaP(c1.carrinho)) != 0) {
                                            printf("\nEfetuar pagamento e finalizar compra?");
                                            printf("\n0. Nao");
                                            printf("\n1. Sim");
                                            Opcao();
                                            scanf("%d", &opc);
                                            fflush(stdin);
                                            switch(opc) {
                                                case 0:
                                                    break;
                                                case 1:
                                                    while(listaVaziaP(c1.carrinho) == 1) { //condição para o loop iniciar é existir algum pedido no carinho - retorno 1 da função quer dizer que não está vazia
                                                        retornarPrato(c1.carrinho, &p1); //retorna o prato da lista em um item a ser inserido nos pedidos confirmados
                                                        achaRest(lRest, p1.restauranteorigem, &r1); //verifica se o restaurante origem está na lista de restaurantes e retorna ele em um item
                                                        inserirPedido(r1.pedidos, c1, p1); //insere pedido na fila do restaurante 
                                                        inserirPrato(c1.pedidos, p1); //insere o prato na lista de pedidos confirmados do cliente
                                                        ret = removerPrato(c1.carrinho, p1); //remove o prato da lista de pedidos a pagar do cliente 
                                                    }
                                                    if (ret == 0) {
                                                        opc = 0;
                                                        system("cls");
                                                        printf("\nPedido saindo para entrega.");
                                                    } else {
                                                        system("cls");
                                                        printf("\nErro ao realizar pedido.");
                                                    }
                                                    break;
                                                default:
                                                    system("cls");
                                                    printf("\nOpcao invalida. Tente novamente.");
                                            }
                                        }
                                        pag = 0;
                                        printf("\nPressione qualquer tecla para voltar.");
                                        fflush(stdin);
                                        getc(stdin);
                                        fflush(stdin);
                                        system("cls");
                                        break;
                                    case 3: //confirmacao de pedidos
                                        auxx = 1;
                                        printf("\n-------- Pedidos a serem confirmados --------");
                                        mostrarPCliente(c1.pedidos); //mostra pedidos a serem entregues
                                        printf("\n-------- Pedidos entregues  --------");
                                        mostrarPCliente(c1.entregues); //mostra pedidos que ja foram entregues
                                        auxx = listaVaziaP(c1.pedidos);
                                        while (auxx != 0) { //enquanto houver pedidos a serem confirmados o loop acontecerá
                                            printf("\nHouve algum pedido recebido?");
                                            printf("\n0. Nao");
                                            printf("\n1. Sim");
                                            Opcao();
                                            scanf("%d", &opc);
                                            fflush(stdin);
                                            switch(opc) {
                                                case 0:
                                                    printf("\nPressione qualquer tecla para retornar.");
                                                    fflush(stdin);
                                                    getc(stdin);
                                                    fflush(stdin);
                                                    system("cls");
                                                    auxx = 0;
                                                    break;
                                                case 1:
                                                    printf("\nNumero do pedido recebido: ");
                                                    scanf("%d", &op);
                                                    fflush(stdin);
                                                    controle = buscaPrato(c1.pedidos, op, &p1); //verifica se o prato está nos pedidos a serem entregues e retorna ele em um item
                                                    if (controle == 0) {
                                                        controle = removerPrato(c1.pedidos, p1); //remove o prato da lista de pedidos a serem entregues
                                                        controle = inserirPrato(c1.entregues, p1); //insere o prato na lista de pedidos já entregues
                                                        if (controle == 0) {
                                                            opc = 0;
                                                            system("cls");
                                                            printf("\nPedido dado como entregue. Obrigada por pedir!");
                                                            auxx = 1;
                                                        } else {
                                                            opc = 0;
                                                            auxx = 1;
                                                            system("cls");
                                                            printf("\nErro ao realizar confirmacao.");
                                                        }
                                                    } else {
                                                        opc = 1;
                                                        auxx = 1;
                                                        system("cls");
                                                        printf("\nCodigo do pedido incorreto. Tente novamente.");
                                                    }
                                                    break;
                                                default:
                                                    opc = 1;
                                                    auxx = 1;
                                                    system("cls");
                                                    printf("\nOpcao invalida. Tente novamente.");
                                            }
                                        }
                                        while (auxx == 0) {
                                            printf("\n-------- Pedidos entregues  --------");
                                            mostrarPCliente(c1.entregues); //mostra pedidos que ja foram entregues
                                            printf("\nPressione qualquer tecla para retornar.");
                                            fflush(stdin);
                                            getc(stdin);
                                            fflush(stdin);
                                            system("cls");
                                            break;
                                        }
                                        system("cls");
                                        break;
                                    case 4: //feedbacks
                                        do {
                                            printf("\n-------- Pagina de Feedbacks --------");
                                            printf("\nDeseja avaliar (opcao 1) ou olhar feedbacks ja existentes (opcao 2)?");
                                            printf("\n0. Retornar ao menu inicial");
                                            printf("\n1. Desejo avaliar um pedido");
                                            printf("\n2. Olhar feedbacks ja existentes");
                                            Opcao();
                                            scanf("%d", &opc);
                                            switch (opc) {
                                                case 0:
                                                    break;
                                                case 1: //fazer feedback
                                                    printf("\n-------- Meus pedidos  --------");
                                                    mostrarPCliente(c1.entregues); //mostra pedidos que ja foram entregues que estao disponiveis a serem avaliados
                                                    printf("\nQual pedido deseja avaliar? Digite o codigo do pedido. ");
                                                    fflush(stdin);
                                                    scanf("%d", &cod);
                                                    controle = buscaItemPrato(c1.entregues, cod); //verifica se o prato existe na lista de pedidos entregues
                                                    if (controle == 0) {
                                                        system("cls");
                                                        printf("\n-------- Avaliacao do pedido de codigo %d --------", cod);
                                                        do {
                                                            printf("\nDigite quantas estrelas deseja dar ao pedido (0 a 5), em decimais: ");
                                                            fflush(stdin);
                                                            fgets(auxestr, 2, stdin);
                                                            auxestr[strcspn(auxestr, "\n")] = '\0';
                                                            ret = ConfirmaEstrelas(auxestr);
                                                            if (ret == 0) {
                                                                strcpy(feed1.estrelas, auxestr);
                                                                printf("\nClassificacao registrada. Prosseguindo...");
                                                            } else {
                                                                printf("\nClassificacao incorreta. Tente novamente.");
                                                                ret = 1;
                                                            }
                                                        } while(ret);
                                                        printf("\nDigite uma avaliacao para o pedido, com maximo de 300 caracteres: ");
                                                        fflush(stdin);
                                                        fgets(auxfeed, 300, stdin);
                                                        auxfeed[strcspn(auxfeed, "\n")] = '\0';
                                                        strcpy(feed1.avaliacao, auxfeed);
                                                        feed1.pedentregues = c1.entregues; 
                                                        ret = inserirFeed(lFeed, c1, r1, feed1); //insere feedback do pedido
                                                        if (ret) {
                                                            system("cls");
                                                            printf("\nErro ao registrar feedback.");
                                                        } else {
                                                            opc = 0;
                                                            controle = 1;
                                                            system("cls");
                                                            printf("\nFeedback registrado.");
                                                        }
                                                    } else {
                                                        system("cls");
                                                        printf("\nPedido inexistente ou nao entregue ainda. Tente novamente.");
                                                        opc = 1;
                                                    }
                                                    break;
                                                case 2: //consulta de feedbacks de restaurantes
                                                    printf("\n-------- Feedbacks  --------");
                                                    printf("\nO que deseja olhar?");
                                                    printf("\n0. Retornar");
                                                    printf("\n1. Meus feedbacks");
                                                    printf("\n2. Olhar feedbacks de algum restaurante");
                                                    Opcao();
                                                    scanf("%d", &op);
                                                    system("cls");
                                                    switch(op) {
                                                        case 0:
                                                            break;
                                                        case 1:
                                                            printf("\n-------- Meus feedbacks registrados --------");
                                                            mostrarFeedCli(lFeed, c1.email); //mostra feedbacks registrados pelo usuario
                                                            printf("\nPressione qualquer tecla para retornar.");
                                                            fflush(stdin);
                                                            getc(stdin);
                                                            system("cls");
                                                            break;
                                                        case 2:
                                                            printf("\n-------- Feedbacks --------");
                                                            printf("\nDe qual estabelecimento deseja olhar os feedbacks?");
                                                            Restaurantes(auxcat); //mostra categorias de restaurantes e obtem a de interesse do usuario
                                                            system("cls");
                                                            printf("\n-------- Restaurantes disponiveis --------");
                                                            mostrarR(lRest, auxcat); //mostra restaurantes disponiveis
                                                            printf("\nDeseja ver os feedbacks de algum restaurante?");
                                                            printf("\n0. Nao, desejo retornar ");
                                                            printf("\n1. Sim, quero olhar");
                                                            Opcao();
                                                            scanf("%d", &opcli);
                                                            switch (opcli) {
                                                                case 0:
                                                                    break;
                                                                case 1:
                                                                    printf("\nDigite o numero da identificacao do restaurante: ");
                                                                    Opcao();
                                                                    scanf("%d", &opcli);
                                                                    ret = achaRest(lRest, opcli, &r1); //verifica se o restaurante existe na lista e retorna ele em um item
                                                                    if (ret) {
                                                                        printf("\nCodigo incorreto. Tente novamente.");
                                                                        opcli = 1;
                                                                        break;
                                                                    } else {
                                                                        printf("\n-------- Feedbacks --------");
                                                                        mostrarFeedRest(lFeed, r1.identificacao); //mostra os feedbacks do estabelecimento escolhido
                                                                        printf("\n");
                                                                        printf("\nPressione qualquer tecla para retornar.");
                                                                        fflush(stdin);
                                                                        getc(stdin);
                                                                        system("cls");
                                                                        break;
                                                                    }
                                                                    break;
                                                                default:
                                                                    printf("\nOpcao invalida. Tente novamente.");
                                                                    break;
                                                            }
                                                    }
                                                    break;
                                                default:
                                                    printf("\nOpcao invalida. Tente novamente.");
                                                    break;
                                            }
                                        } while(opc);
                                        break;
                                    case 5: //excluir conta
                                        printf("\n-------- Exclusao da conta --------");
                                        printf("\n %s, deseja excluir sua conta?", c1.nome);
                                        printf("\n0. Nao");
                                        printf("\n1. Sim");
                                        Opcao();
                                        scanf("%d", &opcli);
                                        fflush(stdin);
                                        while (opcli) {
                                            printf("\nSenha necessaria para delecao de conta, digite-a: ");
                                            fgets(auxsenha, 9, stdin);
                                            auxsenha[strcspn(auxsenha, "\n")] = '\0';
                                            fflush(stdin);
                                            if (strcmp(auxsenha, c1.senha) == 0) {
                                                ret = removerCliente(lCli, c1); //se a senha estiver correta, a conta é excluida
                                                if (ret) {
                                                    system("cls");
                                                    printf("\nErro na exclusao da conta.");
                                                } else {
                                                    opcli = 0;
                                                    menucli2 = 0;
                                                    system("cls");
                                                    printf("\nConta excluida.");
                                                }
                                            } else {
                                                system("cls");
                                                printf("\nSenha incorreta. Tente novamente.");
                                            }
                                        }
                                        break;
                                    default:
                                        printf("\nOpcao invalida. Tente novamente.");
                                }
                            } while(menucli2);
                            break;
                            //CLIENTE DESLOGADO
                            //registro do cliente
                        case 2:
                            system("cls");
                            printf("-------- Dados --------\n");
                            printf("\nInsira seu nome: ");
                            setbuf(stdin, NULL);
                            fgets(c1.nome, 50, stdin);
                            c1.nome[strcspn(c1.nome, "\n")] = '\0';
                            setbuf(stdin, NULL);
                            do {
                                printf("\nFormato do CPF: XXX.XXX.XXX-XX");
                                printf("\nDigite seu CPF: ");
                                fflush(stdin);
                                fgets(c1.cpf, 15, stdin);
                                c1.cpf[strcspn(c1.cpf, "\n")] = '\0';
                                setbuf(stdin, NULL);
                                controle = ConfirmaCPF(c1.cpf);
                                if (controle) {
                                    printf("\nCPF invalido, tente novamente.");
                                } else if (procuraCliente(lCli, c1.cpf) == 0) {
                                    printf("\nCPF existente em alguma conta, tente novamente.");
                                    controle = 1;
                                }
                            } while(controle);
                            do {
                                setbuf(stdin, NULL);
                                printf("\nInsira seu email: ");
                                fflush(stdin);
                                fgets(c1.email, 50, stdin);
                                controle = ConfirmaEmail(c1.email);
                                setbuf(stdin, NULL);
                                c1.email[strcspn(c1.email, "\n")] = '\0';
                                setbuf(stdin, NULL);
                                if (controle) {
                                    printf("\nEmail invalido, tente novamente.");
                                } else if(buscaEmailCliente(lCli, c1.email) == 0) {
                                    controle = 1;
                                    printf("\nEmail ja cadastrado, tente novamente.");
                                }
                            } while(controle);
                            do {
                                printf("\nCrie uma senha com numeros e letras de 8 caracteres: ");
                                setbuf(stdin, NULL);
                                fgets(c1.senha, 9, stdin);
                                setbuf(stdin, NULL);
                                c1.senha[strcspn(c1.senha, "\n")] = '\0';
                                controle = ConfirmaSenha(c1.senha);
                                if (controle) {
                                    printf("\nSenha invalida. Tente novamente.");
                                }
                            } while(controle);
                            controle = inserirCliente(lCli, c1);
                            system("cls");
                            if (controle == 0) {
                                printf("\n\nCadastro efetuado.");
                            } else {
                                printf("Erro ao cadastrar");
                            }
                            break;
                        default:
                            printf("\n\nOpcao invalida, digite novamente.");
                    }
                } while (menucli1);
                break;
                //RESTAURANTE
            case 2:
                do {
                    printf("\n\n-------- Area do prestador de servico --------");
                    printf("\n1. Login");
                    printf("\n2. Cadastre-se");
                    printf("\n0. Retornar");
                    Opcao();
                    scanf("%d", &menurest1);
                    setbuf(stdin, NULL);
                    system("cls");
                    switch (menurest1) {
                        case 0: //saida do menu do restaurante
                            break;
                        case 1: //login restaurante
                            do {
                                printf("\nInsira o email: ");
                                setbuf(stdin, NULL);
                                fgets(r1.email, 30, stdin);
                                setbuf(stdin, NULL);
                                r1.email[strcspn(r1.email, "\n")] = '\0';
                                controle = ConfirmaEmail(r1.email);
                                if (controle) {
                                    printf("\nEmail incorreto. Digite novamente.");
                                } else if (buscaEmailRest(lRest, r1.email) != 0) {
                                    controle = 1;
                                    printf("\nEmail nao cadastrado. Digite novamente.");
                                }
                            } while(controle);
                            buscaRest(lRest, r1.email, &r1);
                            do {
                                printf("\nInsira a senha: ");
                                setbuf(stdin, NULL);
                                fgets(auxsenha, 9, stdin);
                                setbuf(stdin, NULL);
                                auxsenha[strcspn(auxsenha, "\n")] = '\0';
                                controle = ConfirmaSenha(auxsenha);
                                if (controle) {
                                    printf("\nSenha invalida. Tente novamente.");
                                } else if (strcmp(auxsenha, r1.senha) != 0) {
                                    printf("\nSenha incorreta. Tente novamente.");
                                    controle = 1;
                                }
                            } while(controle);
                            system("cls");
                            //RESTAURANTE LOGADO
                            do { //menu de funcionalidades
                                printf("\n\n-------- %s, bem vindo(a) --------", r1.nomeRest);
                                printf("\n0. Retornar");
                                printf("\n1. Ver meu cardapio");
                                printf("\n2. Pedidos em minha loja");
                                printf("\n3. Cadastrar prato");
                                printf("\n4. Alteracao de prato");
                                printf("\n5. Excluir prato");
                                printf("\n6. Feedbacks da minha loja");
                                printf("\n7. Excluir conta");
                                Opcao();
                                scanf("%d", &menurest2);
                                setbuf(stdin, NULL);
                                system("cls");
                                switch (menurest2) {
                                    case 0: //retornar a tela principal
                                        break;
                                    case 1: //mostra cardapio
                                        printf("\n-------- Meu cardapio --------");
                                        mostrarPratos(r1.cardapio); //mostra cardapio do restaurante logado
                                        printf("\nVolte ao pressionar qualquer tecla.");
                                        fflush(stdin);
                                        fgetc(stdin);
                                        setbuf(stdin, NULL);
                                        system("cls");
                                        break;
                                    case 2: //mostra meus pedidos
                                        printf("-------- Pedidos da loja --------");
                                        mostrarPedidos(r1.pedidos); //mostra pedidos ja realizados na loja
                                        printf("\nPressione qualquer tecla para sair.");
                                        fflush(stdin);
                                        getc(stdin);
                                        setbuf(stdin, NULL);
                                        system("cls");
                                        break;
                                    case 3: //cadastrar prato
                                        printf("\n-------- Cadastro de prato --------");
                                        printf("\nNome do prato: ");
                                        setbuf(stdin, NULL);
                                        fgets(p1.nome, 30, stdin);
                                        p1.nome[strcspn(p1.nome, "\n")] = '\0';
                                        setbuf(stdin, NULL);
                                        printf("\nPreco do prato: ");
                                        scanf("%f", &p1.preco);
                                        setbuf(stdin, NULL);
                                        printf("\nIngredientes do prato: ");
                                        setbuf(stdin, NULL);
                                        fgets(p1.ingredientes, 300, stdin);
                                        p1.ingredientes[strcspn(p1.ingredientes, "\n")] = '\0';
                                        setbuf(stdin, NULL);
                                        p1.codigo = geracaoCod(lRest); //gera codigo de prato 
                                        p1.restauranteorigem = r1.identificacao;
                                        controle = inserirPrato(r1.cardapio, p1); //insere prato no cardapio do restaurante
                                        if (controle) {
                                            system("cls");
                                            printf("\nErro na insercao do prato.");
                                        } else {
                                            system("cls");
                                            printf("\nPrato inserido.");
                                        }
                                        break;
                                    case 4: //alterar prato
                                        printf("\n-------- Alteracao de prato --------");
                                        printf("\nDigite o codigo do prato: ");
                                        scanf("%d", &cod);
                                        setbuf(stdin, NULL);
                                        controle = buscaPrato(lPr, cod, &p1);
                                        if (controle) {
                                            printf("\nCodigo incorreto, digite novamente.");
                                            break;
                                        }
                                        do {
                                            printf("\nNome: %s", p1.nome);
                                            printf("\nAlterar nome?");
                                            printf("\n0. Nao");
                                            printf("\n1. Sim");
                                            Opcao();
                                            scanf("%d", &opcli);
                                            setbuf(stdin, NULL);
                                            switch (opcli) {
                                                case 0:
                                                    break;
                                                case 1:
                                                    printf("\nNovo nome: ");
                                                    setbuf(stdin, NULL);
                                                    fgets(p1.nome, 30, stdin);
                                                    p1.nome[strcspn(p1.nome, "\n")] = '\0';
                                                    setbuf(stdin, NULL);
                                                    break;
                                                default:
                                                    printf("\nOpcao invalida. Tente novamente.");
                                            }
                                        } while(opcli != 1 && opcli != 0);
                                        do {
                                            printf("\nPreco: %2.f", p1.preco);
                                            printf("\nAlterar preco?");
                                            printf("\n0. Nao");
                                            printf("\n1. Sim");
                                            Opcao();
                                            scanf("%d", &opcli);
                                            setbuf(stdin, NULL);
                                            switch (opcli) {
                                                case 0:
                                                    break;
                                                case 1:
                                                    printf("\nNovo preco: ");
                                                    scanf("%f", &p1.preco);
                                                    setbuf(stdin, NULL);
                                                    break;
                                                default:
                                                    printf("\nOpcao invalida. Tente novamente.");
                                            }
                                        } while(opcli != 1 && opcli != 0);
                                        do {
                                            printf("\nIngredientes: %s", p1.ingredientes);
                                            printf("\nAlterar ingredientes?");
                                            printf("\n0. Nao");
                                            printf("\n1. Sim");
                                            Opcao();
                                            scanf("%d", &opcli);
                                            setbuf(stdin, NULL);
                                            switch (opcli) {
                                                case 0:
                                                    break;
                                                case 1:
                                                    printf("\nNovos ingredientes: ");
                                                    setbuf(stdin, NULL);
                                                    fgets(p1.ingredientes, 300, stdin);
                                                    p1.nome[strcspn(p1.nome, "\n")] = '\0';
                                                    setbuf(stdin, NULL);
                                                    break;
                                                default:
                                                    printf("\nOpcao invalida. Tente novamente.");
                                            }
                                        } while(opcli != 1 && opcli != 0);
                                        controle = removerPrato(r1.cardapio,p1);  //remove prato antigo
                                        if (controle) {
                                            system("cls");
                                            printf("\nErro na modificacao do prato.");
                                        } else {
                                            controle = inserirPrato(r1.cardapio, p1); //insere prato com dados novos
                                            if (controle) {
                                                system("cls");
                                                printf("\nErro na modificacao do prato.");
                                            } else {
                                                system("cls");
                                                printf("\nPrato alterado.");
                                            }
                                        }
                                        break;
                                    case 5: //exclusao de prato
                                        printf("\n-------- Exclusao de pratos --------");
                                        printf("\nDigite o codigo do prato: ");
                                        scanf("%d", &cod);
                                        setbuf(stdin, NULL);
                                        controle = buscaPrato(r1.cardapio, cod, &p1); 
                                        if (controle) {
                                            printf("\nPrato nao encontrado. Codigo invalido.");
                                            break;
                                        }
                                        printf("\nDeseja excluir o prato %s?", p1.nome);
                                        printf("\n0. Nao");
                                        printf("\n1. Sim");
                                        Opcao();
                                        scanf("%d", &opcli);
                                        setbuf(stdin, NULL);
                                        while (opcli) {
                                            controle = removerPrato(r1.cardapio, p1); //remove prato
                                            if (controle) {
                                                system("cls");
                                                printf("\nErro ao remover prato.");
                                            } else {
                                                opcli = 0;
                                                system("cls");
                                                printf("\nPrato excluido.");
                                            }
                                        }
                                        break;
                                    case 6: //feedbacks
                                        printf("\n-------- Meus feedbacks registrados --------");
                                        mostrarFeedRest(lFeed, r1.identificacao); //mostra feedbacks do estabelecimento
                                        printf("\n");
                                        printf("\nPressione qualquer tecla para retornar.");
                                        fflush(stdin);
                                        getc(stdin);
                                        fflush(stdin);
                                        break;
                                    case 7: //excluir conta
                                        printf("\n-------- Exclusao de conta de prestador de servico --------");
                                        printf("\nDeseja excluir sua conta, %s?", r1.nomeRest);
                                        printf("\n0. Nao");
                                        printf("\n1. Sim");
                                        Opcao();
                                        scanf("%d", &opcli);
                                        setbuf(stdin, NULL);
                                        while (opcli) {
                                            printf("\nSenha necessaria para exclusao. Digite-a: ");
                                            setbuf(stdin, NULL);
                                            fgets(auxsenha, 9, stdin);
                                            auxsenha[strcspn(auxsenha, "\n")] = '\0';
                                            setbuf(stdin, NULL);
                                            if (strcmp(auxsenha, r1.senha) == 0) {
                                                controle = removerRest(lRest, r1);
                                                if (controle) {
                                                    system("cls");
                                                    printf("\nErro na delecao da conta.");
                                                } else {
                                                    opcli = 0;
                                                    menurest2 = 0;
                                                    system("cls");
                                                    printf("\nConta excluida.");
                                                }
                                            } else {
                                                system("cls");
                                                printf("\nSenha incorreta. Digite novamente.");
                                            }
                                        }
                                        break;
                                    default:
                                        printf("\nOpcao invalida. Digite novamente.");
                                }
                            } while(menurest2);
                            break;
                            //RESTAURANTE DESLOGADO
                        case 2: //registro restaurante
                            printf("\n-------- Registro de restaurante --------");
                            printf("\nNome do restaurante: ");
                            setbuf(stdin, NULL);
                            fgets(r1.nomeRest, 29, stdin);
                            setbuf(stdin, NULL);
                            r1.nomeRest[strcspn(r1.nomeRest, "\n")] = '\0';
                            do{
                                printf("\nFormato de digitacao do CNPJ: XX.XXX.XXX/XXXX-XX");
                                printf("\nCNPJ do restaurante: ");
                                setbuf(stdin, NULL);
                                fgets(r1.CNPJ, 18, stdin);
                                setbuf(stdin, NULL);
                                r1.CNPJ[strcspn(r1.CNPJ, "\n")] = '\0';
                                setbuf(stdin, NULL);
                                controle = ConfirmaCNPJ(r1.CNPJ);
                                if (controle) {
                                    printf("\nCNPJ no formato invalido. Tente novamente.");
                                } else if (buscaItemRest(lRest, r1.CNPJ) == 0) {
                                    controle = 1;
                                    printf("\nCNPJ ja existente. Tente novamente.");
                                }
                            } while(controle);
                            do {
                                setbuf(stdin, NULL);
                                printf("\nEmail: ");
                                fflush(stdin);
                                fgets(r1.email, 30, stdin);
                                setbuf(stdin, NULL);
                                controle = ConfirmaEmail(r1.email);
                                r1.email[strcspn(r1.email, "\n")] = '\0';
                                if (controle) {
                                    printf("\nEmail invalido. Tente novamente.");
                                } else if (buscaEmailRest(lRest, r1.email) == 0) {
                                    controle = 1;
                                    printf("\nEmail ja existente. Tente novamente.");
                                }
                            } while(controle);
                            do {
                                printf("\nCrie uma senha com letras e numeros de 8 caracteres: ");
                                setbuf(stdin, NULL);
                                fgets(r1.senha, 9, stdin);
                                setbuf(stdin, NULL);
                                controle = ConfirmaSenha(r1.senha);
                                if (controle) {
                                    printf("\nSenha invalida. Tente novamente.");
                                }
                            } while(controle);
                            printf("\nEscolha qual categoria se enquadra no seu restaurante: ");
                            Restaurantes(auxcat);
                            strcpy(r1.categoria, auxcat);
                            controle = inserirRest(lRest, r1);
                            system("cls");
                            if (controle == 0) {
                                printf("\nRestaurante cadastrado.");
                            } else {
                                printf("\nErro ao inserir restaurante.");
                            }
                            break;
                        default:
                            printf("\nOpcao invalida. Tente novamente.");
                    }
                } while(menurest1);
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.");
        }
    } while (menuprincp);
    //fim do programa
    printf("\n");
    system("pause");
    return 0;
}