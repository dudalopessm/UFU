import java.util.Scanner;
public class UsaBanco {
    public static void main(String[]args) {
        // ------------------------------------------------- INICIO DA MAIN -------------------------------------------------
        // declarando Scanner
        Scanner sc = new Scanner(System.in);
        System.out.println("-------------------------------- Sistema de Banco --------------------------------");

        // ------------------------------------------------- DECLARAÇÃO DE OBJETOS -------------------------------------------------
        //System.out.println("\n");
        System.out.println("\n******************** Criação de contas ********************");
        ContaEspecial contasEsp[] = new ContaEspecial[4];
        ContaComum contasCom[] = new ContaComum[2];
        contasEsp[0] = new ContaEspecial(10000, 1, 1122, 0);
        contasEsp[1] = new ContaEspecial(100, 2, 1322, 100);
        contasEsp[2] = new ContaEspecial(1111, 3, 1124, -3);
        contasEsp[3] = new ContaEspecial(2000, 4, 1144, 10000);
        contasCom[0] = new ContaComum(20, 5, 1444, 45);
        contasCom[1] = new ContaComum(255, 6, 4444, 44);

        // ------------------------------------------------- DETERMINA SE O LIMITE É VÁLIDO -------------------------------------------------
        for(ContaEspecial unidade : contasEsp) {
            if (unidade.getLimite() < 0) {
                System.out.println("Erro na definição do limite da conta de número: " + unidade.getNumConta());
                System.out.println("Digite o limite novamente. O valor deve ser maior ou igual a 0: ");
                int aux = sc.nextInt();
                while(aux < 0) {
                    System.out.println("Digite o limite novamente. O valor deve ser maior ou igual a 0: ");
                    aux = sc.nextInt();
                }
            }
            if (unidade != null && unidade instanceof ContaEspecial) {
                System.out.println("Conta de número " + unidade.getNumConta() + " criada com sucesso!");
            }
        }
        for(ContaComum unidade : contasCom) {
            if (unidade != null) {
                System.out.println("Conta de número " + unidade.getNumConta() + " criada com sucesso!");
            }
        }

        // ------------------------------------------------- SAQUE COM SENHA INCORRETA -------------------------------------------------
        //System.out.println("\n");
        System.out.println("\n******************** Teste de saque ********************");
        if (contasEsp[0].debitaValor(1000, 1125)) { // senha aqui é 1122
            System.out.println("Débito efetuado. Novo saldo: " + contasEsp[0].getSaldo(1125));
        } else {
            System.out.println("\nDébito não efetuado. Digite o valor e a senha novamente.");
            System.out.println("Valor: ");
            float valor; int senha;
            valor = sc.nextFloat();
            System.out.println("Senha: ");
            senha = sc.nextInt();
            while (!contasEsp[0].isSenha(senha)) {
                System.out.println("Senha incorreta! Tente novamente: ");
                senha = sc.nextInt();
            }
            while(valor > contasEsp[0].getSaldo(senha)) {
                System.out.println("\nValor a ser debitado maior do que o saldo da conta. Digite o valor novamente: ");
                valor = sc.nextFloat();
            }
            contasEsp[0].debitaValor(valor, senha);
            System.out.println("\nDébito efetuado com sucesso. Novo saldo: " + contasEsp[0].getSaldo(senha));
        }

        // ------------------------------------------------- SAQUE COM VALOR INCORRETO -------------------------------------------------
        //System.out.println("\n");
        System.out.println("\n******************** Teste de saque ********************");
        if(contasEsp[1].debitaValor(10000, 1322)) { // valor aqui é 100
            System.out.println("\nDébito efetuado. Novo saldo: " + contasEsp[1].getSaldo(1322));
        } else {
            System.out.println("\nDébito não efetuado. Digite o valor e a senha novamente.");
            System.out.println("Valor: ");
            float valor; int senha;
            valor = sc.nextFloat();
            System.out.println("Senha: ");
            senha = sc.nextInt();
            while (!contasEsp[1].isSenha(senha)) {
                System.out.println("Senha incorreta! Tente novamente: ");
                senha = sc.nextInt();
            }
            while(valor > contasEsp[1].getSaldo(senha)) {
                System.out.println("\nValor a ser debitado maior do que o saldo da conta. Digite o valor novamente: ");
                valor = sc.nextFloat();
            }
            contasEsp[1].debitaValor(valor, senha);
            System.out.println("\nDébito efetuado com sucesso. Novo saldo: " + contasEsp[1].getSaldo(senha));
        }

        // ------------------------------------------------- SAQUE BEM SUCEDIDO -------------------------------------------------
        //System.out.println("\n");
        System.out.println("\n******************** Teste de saque ********************");
        if (contasEsp[2].debitaValor(100, 1124)) {
            System.out.println("\nDébito efetuado. Novo saldo: " + contasEsp[2].getSaldo(1124));
        } else {
            System.out.println("\nDébito não efetuado. Digite o valor e a senha novamente.");
            System.out.println("Valor: ");
            float valor; int senha;
            valor = sc.nextFloat();
            System.out.println("Senha: ");
            senha = sc.nextInt();
            while (!contasEsp[2].isSenha(senha)) {
                System.out.println("Senha incorreta! Tente novamente: ");
                senha = sc.nextInt();
            }
            while(valor > contasEsp[2].getSaldo(senha)) {
                System.out.println("\nValor a ser debitado maior do que o saldo da conta. Digite o valor novamente: ");
                valor = sc.nextFloat();
            }
            contasEsp[2].debitaValor(valor, senha);
            System.out.println("\nDébito efetuado com sucesso. Novo saldo: " + contasEsp[2].getSaldo(senha));
        }

        // ------------------------------------------------- SAQUE QUE ZERA SALDO DE CONTA COMUM -------------------------------------------------
        //System.out.println("\n");
        System.out.println("\n******************** Teste de saque ********************");
        if (contasCom[0].debitaValor(20, 1444)) {
            int estado = contasCom[0].getEstado(1444);
            if(estado == 1) {
                System.out.println("\nDébito efetuado. Novo saldo: " + contasCom[0].getSaldo(1444));
            } else if (estado == 2) {
                System.out.println("\nDébito efetuado e conta desativada devido ao saldo ter sido zerado. Essa conta não poderá mais ser acessada.");
                contasCom[0] = null;
            }
        } else {
            System.out.println("\nDébito não efetuado. Digite o valor e a senha novamente.");
            System.out.println("Valor: ");
            float valor; int senha;
            valor = sc.nextFloat();
            System.out.println("Senha: ");
            senha = sc.nextInt();
            while (!contasCom[0].isSenha(senha)) {
                System.out.println("Senha incorreta! Tente novamente: ");
                senha = sc.nextInt();
            }
            while(valor > contasCom[0].getSaldo(senha)) {
                System.out.println("\nValor a ser debitado maior do que o saldo da conta. Digite o valor novamente: ");
                valor = sc.nextFloat();
            }
            contasCom[0].debitaValor(valor, senha);
            System.out.println("\nDébito efetuado com sucesso. Novo saldo: " + contasCom[0].getSaldo(senha));
        }

        // ------------------------------------------------- SAQUE BEM SUCEDIDO CONTA COMUM -------------------------------------------------
        //System.out.println("\n");
        System.out.println("\n******************** Teste de saque ********************");
        if (contasCom[1].debitaValor(200, 4444)) {
            int estado = contasCom[1].getEstado(4444);
            if(estado == 1) {
                System.out.println("\nDébito efetuado. Novo saldo: " + contasCom[1].getSaldo(4444));
            } else if (estado == 2) {
                System.out.println("\nDébito efetuado e conta desativada devido ao saldo ter sido zerado. Essa conta não poderá mais ser acessada.");
                contasCom[1] = null;
            }
        } else {
            System.out.println("\nDébito não efetuado. Digite o valor e a senha novamente.");
            System.out.println("Valor: ");
            float valor; int senha;
            valor = sc.nextFloat();
            System.out.println("Senha: ");
            senha = sc.nextInt();
            while (!contasCom[1].isSenha(senha)) {
                System.out.println("Senha incorreta! Tente novamente: ");
                senha = sc.nextInt();
            }
            while(valor > contasCom[1].getSaldo(senha)) {
                System.out.println("\nValor a ser debitado maior do que o saldo da conta. Digite o valor novamente: ");
                valor = sc.nextFloat();
            }
            contasCom[1].debitaValor(valor, senha);
            System.out.println("\nDébito efetuado com sucesso. Novo saldo: " + contasCom[1].getSaldo(senha));
        }

        // ------------------------------------------------- MOSTRA CONTAS ATIVAS -------------------------------------------------
        int contasAtivas[] = new int[6];
        contasAtivas[0] = contasEsp[0].getEstado(1122);
        contasAtivas[1] = contasEsp[1].getEstado(1322);
        contasAtivas[2] = contasEsp[2].getEstado(1124);
        contasAtivas[3] = contasEsp[3].getEstado(1144);
        try {
            contasAtivas[4] = contasCom[0].getEstado(1444);
        } catch (NullPointerException e) {
            //System.out.println("Erro: A conta não pode ser mais acessada, pois está inativa devido ao seu saldo zerado.");
            contasAtivas[4] = 2;
        }
        contasAtivas[5] = contasCom[1].getEstado(4444);
        //System.out.println("\n");
        System.out.println("\n******************** Contas ativas ********************");
        for(int i = 0; i < contasAtivas.length; i++) {
            if (contasAtivas[i] == 1) {
                System.out.println("A conta de número " + (i+1) + " está ativa.");
            } else if (contasAtivas[i] == 2) {
                System.out.println("A conta de número " + (i+1) + " está inativa.");
            }
        }

        // ------------------------------------------------- FIM DA MAIN -------------------------------------------------
        // fechando scanner
        sc.close();
    }
}