public class Principal {
    public static void main(String[]args) {
        System.out.println("\n-------------------------------- Tetos de salários --------------------------------");

        Funcionario[] vet = new Funcionario[3];
        vet[0] = new Funcionario("456.986.038-23", "Bruno Travençolo", 30897.45F);
        vet[1] = new Funcionario("232.345.432-92", "Lucas Matos", 23456.56F);
        vet[2] = new Funcionario("792-499-213-56", "Eduarda Lopes", 26754.69F);

        System.out.println("Antes das modificações:");

        for(Funcionario un : vet) {
            System.out.println(un.toString());
        }

        /* teste para teto negativo - não deve alterar */
        try {
            vet[0].atribuiNovoTeto(-1);
            System.out.println("Novo teto atribuído com sucesso.");
        } catch (ErroAtribuicao e) {
            System.out.println(e.getMessage());
        } finally {
            System.out.println("Teto atual: " + vet[0].getTeto());
        }

        /* teste para teto - deve alterar */
        try {
            vet[1].atribuiNovoTeto(30000);
            System.out.println("Novo teto atribuído com sucesso.");
        } catch (ErroAtribuicao e) {
            System.out.println(e.getMessage());
        } finally {
            System.out.println("Teto atual: " + vet[1].getTeto());
        }

        /* teste para aumentar salário - não deve alterar */
        try {
            vet[0].aumentaSalario(-0.8F);
            System.out.println("Novo salário atribuído com sucesso.");
        } catch (ErroAtribuicao e) {
            System.out.println(e.getMessage());
        } finally {
            System.out.println("Salário atual: " + vet[0].getSalario());
        }

        /* teste para aumentar salário - não deve alterar */
        try {
            vet[2].aumentaSalario(400);
            System.out.println("Novo salário atribuído com sucesso.");
        } catch (ErroAtribuicao e) {
            System.out.println(e.getMessage());
        } finally {
            System.out.println("Salário atual: " + vet[2].getSalario());
        }

        /* teste para aumentar salário - deve alterar */
        try {
            vet[1].aumentaSalario(0.8F);
            System.out.println("Novo salário atribuído com sucesso.");
        } catch (ErroAtribuicao e) {
            System.out.println(e.getMessage());
        } finally {
            System.out.println("Salário atual: " + vet[1].getSalario());
        }

        System.out.println("Depois das modificações:");

        for(Funcionario un : vet) {
            System.out.println(un.toString());
        }

    }
}