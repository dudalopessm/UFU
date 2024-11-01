public class Main {
    public void mostraOrdenados(Classificavel vet[]) {
        for(Classificavel un : vet) {
            System.out.println(vet.toString());
        }
    }
    public static void main(String[]args) {
        //---------------------------------------- COMEÇO DA MAIN ----------------------------------------
        System.out.println("---------------------------- Ordenação usando Interface ----------------------------");

        //---------------------------------------- DEFINIÇÃO DE VETORES PARA TESTE ----------------------------------------
        /* vetor de produtos */
        Produto[] prods = new Produto[3];
        prods[0] = new Produto(3);
        prods[1] = new Produto(1);
        prods[2] = new Produto(2);

        /* vetor de clientes */
        Cliente[] clis = new Cliente[3];
        clis[0] = new Cliente("Duda");
        clis[1] = new Cliente("Lucas");
        clis[2] = new Cliente("Bruno");

        /* vetor de servicos */
        Servico[] serv = new Servico[3];
        serv[0] = new Servico(1345.45F);
        serv[1] = new Servico(1039.67F);
        serv[2] = new Servico(1484.34F);

        /* classificador */
        Classificador ord = new Classificador();

        //---------------------------------------- MOSTRA ANTES DE ORDENAR ----------------------------------------
        System.out.println("\n********************* Produtos *********************");
        for(Produto un : prods) {
            System.out.println(un.toString());
        }

        System.out.println("\n********************* Clientes *********************");
        for(Cliente un : clis) {
            System.out.println(un.toString());
        }

        System.out.println("\n********************* Serviços *********************");
        for(Servico un : serv) {
            System.out.println(un.toString());
        }

        //---------------------------------------- ORDENAÇÕES ----------------------------------------
        System.out.println("\nOrdenando produtos...");
        ord.ordena(prods);
        System.out.println("\nOrdenando clientes...");
        ord.ordena(clis);
        System.out.println("\nOrdenando serviços...");
        ord.ordena(serv);

        //---------------------------------------- MOSTRA DADOS ORDENADOS ----------------------------------------
        System.out.println("\n********************* Produtos *********************");
        for(Produto un : prods) {
            System.out.println(un.toString());
        }

        System.out.println("\n********************* Clientes *********************");
        for(Cliente un : clis) {
            System.out.println(un.toString());
        }

        System.out.println("\n********************* Serviços *********************");
        for(Servico un : serv) {
            System.out.println(un.toString());
        }

    }
}
