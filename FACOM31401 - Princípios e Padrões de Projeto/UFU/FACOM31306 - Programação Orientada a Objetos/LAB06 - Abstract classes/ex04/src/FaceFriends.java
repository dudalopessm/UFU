import java.util.ArrayList;
import java.util.Scanner;
// vou me aventurar com arrayList para praticar quando for o trabalho
public class FaceFriends {
    //---------------------------------------------------------------------------- SCANNER ----------------------------------------------------------------------------
    static Scanner sc = new Scanner(System.in);

    //---------------------------------------------------------------------------- FUNÇÕES ----------------------------------------------------------------------------
    /* menu inicial que aparecerá sempre quando o usuário retornar */
    public static int userTypeMenuInicial() {
        System.out.println("\n----------------------------- Face Friends -----------------------------");
        System.out.println("0. Sair");
        System.out.println("1. Inserir um contato, especificando o subtipo e então requerendo os seus campos");
        System.out.println("2. Imprimir todos os contatos");
        System.out.println("3. Imprimir somente os familiares");
        System.out.println("4. Imprimir somente os amigos");
        System.out.println("5. Imprimir somente os colegas de trabalho");
        System.out.println("6. Imprimir os MELHORES amigos, os IRMÃOS e os COLEGAS de trabalho");
        System.out.println("7. Imprimir os dados de um ÚNICO contato escolhido pelo índice");
        System.out.println("\nDigite sua opção: ");
        int op = sc.nextInt();
        sc.nextLine();
        return op;
    }

    /* menu para cadastro */
    public static ArrayList<Contato> userTypeDados(int controle, ArrayList<Contato> users) {
        String nome, apelido, email, aniversario;
        System.out.println("Nome e sobrenome: ");
        nome = sc.nextLine();
        System.out.println("Apelido: ");
        apelido = sc.nextLine();
        System.out.println("Email: ");
        email = sc.nextLine();
        while (!Contato.verificaEmail(users, email)) {
            System.out.println("Email já cadastrado! Digite outro email: ");
            email = sc.nextLine();
        }
        System.out.println("Data de aniversário: ");
        aniversario = sc.nextLine();
        if(controle == 1) {
            int grau;
            System.out.println("Grau de amizade: ");
            grau = sc.nextInt();
            sc.nextLine();
            while(grau < 1 || grau > 3) {
                System.out.println("Grau de amizade inválido! O número deve ser de 1 a 3. Tente novamente: ");
                grau = sc.nextInt();
            }
            Amigos amigo = new Amigos(nome, apelido, email, aniversario, grau, users);
            if(amigo != null) {
                users.add(amigo);
                System.out.println("Usuário criado com sucesso!");
            } else
                System.out.println("Erro ao criar o usuário.");
        } else if(controle == 2) {
            String relacao;
            System.out.println("Tipo de relação profissional: ");
            relacao = sc.nextLine();
            Trabalho colega = new Trabalho(nome, apelido, email, aniversario, relacao, users);
            if(colega != null) {
                users.add(colega);
                System.out.println("Usuário criado com sucesso!");
            } else
                System.out.println("Erro ao criar o usuário.");
        } else if(controle == 3) {
            String parentesco;
            System.out.println("Parentesco: ");
            parentesco = sc.nextLine();
            Familia fam = new Familia(nome, apelido, email, aniversario, parentesco, users);
            if(fam != null) {
                users.add(fam);
                System.out.println("Usuário criado com sucesso!");
            } else
                System.out.println("Erro ao criar o usuário.");
        }
        return users;
    }

    //---------------------------------------------------------------------------- INICIO ----------------------------------------------------------------------------
    public static void main(String[]args) {
        //---------------------------------------------------------------------------- ARRAY PARA TESTES ----------------------------------------------------------------------------
        ArrayList<Contato> lista = new ArrayList<Contato>();

        /* amigos */
        lista.add(new Amigos("Ana Silva", "Aninha", "ana.silva@example.com", "12/03/1995", 1, lista));
        lista.add(new Amigos("Carlos Souza", "Cacá", "carlos.souza@example.com", "25/06/1988", 1, lista));
        lista.add(new Amigos("Bruno Costa", "Bruninho", "bruno.costa@example.com", "07/11/1990", 1, lista));
        lista.add(new Amigos("Daniela Mendes", "Dani", "daniela.mendes@example.com", "02/01/1993", 2, lista));
        lista.add(new Amigos("Eduardo Lima", "Dudu", "eduardo.lima@example.com", "13/08/1985", 3, lista));

        /* família */
        lista.add(new Familia("Fernanda Ribeiro", "Nanda", "fernanda.ribeiro@example.com", "21/12/1992", "Mãe", lista));
        lista.add(new Familia("Gabriel Oliveira", "Biel", "gabriel.oliveira@example.com", "04/05/1994", "Irmão", lista));
        lista.add(new Familia("Helena Martins", "Lena", "helena.martins@example.com", "16/07/1987", "Prima", lista));
        lista.add(new Familia("Pedro Henrique", "PH", "pedro.henrique@example.com", "30/04/1992", "Pai", lista));
        lista.add(new Familia("Felipe Nunes", "Lipe", "felipe.nunes@example.com", "19/03/1995", "Irmão", lista));

        /* trabalho */
        lista.add(new Trabalho("Lucas Almeida", "Lu", "lucas.almeida@example.com", "05/02/1990", "Colega", lista));
        lista.add(new Trabalho("Mariana Santos", "Mari", "mariana.santos@example.com", "18/09/1989", "Chefe", lista));
        lista.add(new Trabalho("Aline Oliveira", "Ali", "aline.oliveira@example.com", "22/07/1993", "Colega", lista));
        lista.add(new Trabalho("Larissa Rocha", "Lari", "larissa.rocha@example.com", "12/10/1987", "Colega", lista));
        lista.add(new Trabalho("Patrícia Carvalho", "Pati", "patricia.carvalho@example.com", "01/12/1986", "Colega", lista));

        //---------------------------------------------------------------------------- MENU ----------------------------------------------------------------------------
        int menu;
        do {
            menu = FaceFriends.userTypeMenuInicial();
            switch (menu) {
                /* sair */
                case 0:
                    System.out.println("Saindo...");
                    break;

                /* inserção */
                case 1:
                    System.out.println("*********** Inserir um contato ***********");
                    String tipo;
                    int tipoNum = 0;
                    do {
                        System.out.println("Qual tipo deseja inserir? ");
                        System.out.println("Disponíveis: Amigos, Trabalho, Familia");
                        tipo = sc.nextLine();
                        if (tipo.equalsIgnoreCase("Amigos")) {
                            tipoNum = 1;
                        } else if (tipo.equalsIgnoreCase("Trabalho")) {
                            tipoNum = 2;
                        } else if (tipo.equalsIgnoreCase("Familia")) {
                            tipoNum = 3;
                        } else {
                            System.out.println("Tipo inválido. Digite um dos tipos disponíveis.");
                        }
                    }while(tipoNum == 0);
                    lista = FaceFriends.userTypeDados(tipoNum, lista);
                    break;

                /* imprime todos */
                case 2:
                    System.out.println("*********** Imprimir todos os contatos ***********");
                    for(int i = 0; i < lista.size(); i++) {
                        System.out.println(lista.get(i).imprimirBasico());
                        System.out.println("___________________________");
                    }
                    System.out.println("\nPressione Enter para continuar...");
                    sc.nextLine();
                    sc.nextLine();
                    break;

                /* imprime só familia */
                case 3:
                    System.out.println("*********** Imprimir somente os familiares ***********");
                    for(int i = 0; i < lista.size(); i++) {
                        if(lista.get(i) instanceof Familia) {
                            System.out.println(lista.get(i).imprimirBasico() + lista.get(i).imprimirContato());
                            System.out.println("___________________________");
                        }
                    }
                    System.out.println("\nPressione Enter para continuar...");
                    sc.nextLine();
                    sc.nextLine();
                    break;

                /* imprime só amigos */
                case 4:
                    System.out.println("*********** Imprimir somente os amigos ***********");
                    for(int i = 0; i < lista.size(); i++) {
                        if(lista.get(i) instanceof Amigos) {
                            System.out.println(lista.get(i).imprimirBasico() + lista.get(i).imprimirContato());
                            System.out.println("___________________________");
                        }
                    }
                    System.out.println("\nPressione Enter para continuar...");
                    sc.nextLine();
                    sc.nextLine();
                    break;

                /* imprime só trabalho */
                case 5:
                    System.out.println("*********** Imprimir somente os colegas de trabalho ***********");
                    for(int i = 0; i < lista.size(); i++) {
                        if(lista.get(i) instanceof Trabalho) {
                            System.out.println(lista.get(i).imprimirBasico() + lista.get(i).imprimirContato());
                            System.out.println("___________________________");
                        }
                    }
                    System.out.println("\nPressione Enter para continuar...");
                    sc.nextLine();
                    sc.nextLine();
                    break;

                /* imprime melhores amigos, irmãos e colegas */
                case 6:
                    System.out.println("*********** Imprimir os MELHORES amigos, os IRMÃOS e os COLEGAS de trabalho ***********");
                    System.out.println("Melhores amigos: ");
                    for(int i = 0; i < lista.size(); i++) {
                        if(lista.get(i) instanceof Amigos && ((Amigos) lista.get(i)).getGrau() == 1) {
                            System.out.println(lista.get(i).imprimirBasico() + lista.get(i).imprimirContato());
                            System.out.println("___________________________");
                        }
                    }
                    System.out.println("\nPressione Enter para continuar...");
                    sc.nextLine();
                    sc.nextLine();
                    System.out.println("Irmãos: ");
                    for(int i = 0; i < lista.size(); i++) {
                        if(lista.get(i) instanceof Familia && ((Familia) lista.get(i)).getParentesco().compareToIgnoreCase("Irmão") == 0) {
                            System.out.println(lista.get(i).imprimirBasico() + lista.get(i).imprimirContato());
                            System.out.println("___________________________");
                        }
                    }
                    System.out.println("\nPressione Enter para continuar...");
                    sc.nextLine();
                    sc.nextLine();
                    for(int i = 0; i < lista.size(); i++) {
                        if(lista.get(i) instanceof Trabalho && ((Trabalho) lista.get(i)).getTipo().compareToIgnoreCase("Colega") == 0) {
                            System.out.println(lista.get(i).imprimirBasico() + lista.get(i).imprimirContato());
                            System.out.println("___________________________");
                        }
                    }
                    System.out.println("\nPressione Enter para continuar...");
                    sc.nextLine();
                    sc.nextLine();
                    break;

                /* imprime pelo índice */
                case 7:
                    System.out.println("*********** Imprimir os dados de um ÚNICO contato escolhido pelo índice ***********");
                    int indice;
                    System.out.println("Digite o índice do contato desejado: ");
                    indice = sc.nextInt();
                    sc.nextLine();
                    while(indice < 0 || indice > lista.size()) {
                        System.out.println("Índice inválido! Tente novamente: ");
                        indice = sc.nextInt();
                        sc.nextLine();
                    }
                    System.out.println("Dados do contato desejado: ");
                    System.out.println("___________________________");
                    System.out.println(lista.get(indice).imprimirBasico() + lista.get(indice).imprimirContato());
                    System.out.println("___________________________");
                    System.out.println("\nPressione Enter para continuar...");
                    sc.nextLine();
                    sc.nextLine();
                    break;

            }
        }while(menu != 0);
        //---------------------------------------------------------------------------- FIM ----------------------------------------------------------------------------

        sc.close();
    }
}