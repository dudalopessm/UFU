public class Ex02 {
    public static void main(String[]args) {
        Candidato c1 = new Candidato();
        //sets para c1
        c1.setNome("Alexandre Holanda Sabino");
        c1.setDataNascimento("13/05/1973");
        c1.setGenero("Masculino");
        c1.setBens(132000.00);
        c1.setReeleicao(false);
        c1.setNumeroPartido(12);
        c1.setCargo("Prefeito");
        c1.setCodigoMun(2305233);
        c1.setMunicipio("Horizonte - CE");

        Candidato c2 = new Candidato();
        //sets para c2
        c2.setNome("Manoel Gomes de Faria Neto");
        c2.setDataNascimento("18/08/1959");
        c2.setGenero("Masculino");
        c2.setBens(1919410.00);
        c2.setReeleicao(true);
        c2.setNumeroPartido(40);
        c2.setCargo("Prefeito");
        c2.setCodigoMun(2305233);
        c2.setMunicipio("Horizonte - CE");

        Candidato c3 = new Candidato();
        //sets para c3
        c3.setNome("Rhenan Cavalcante Assunção");
        c3.setDataNascimento("12/02/1989");
        c3.setGenero("Masculino");
        c3.setBens(278000.00);
        c3.setReeleicao(false);
        c3.setNumeroPartido(25);
        c3.setCargo("Prefeito");
        c3.setCodigoMun(2305233);
        c3.setMunicipio("Horizonte - CE");

        System.out.println("~~~~~~~~~~~~ Sistema de informações de candidatos a eleição de 2024 ~~~~~~~~~~~~");
        c1.mostrar();
        c2.mostrar();
        c3.mostrar();
        int controle;
        System.out.println("\n----------------------------- Alterações -----------------------------");
        System.out.println("\nAlterando nome do candidato " + c1.getNome());
        controle = c1.alteraNome("Alexandre de Morais");
        System.out.println("Novo nome: " + c1.getNome());
        System.out.println("\nAlterando a data de nascimento do candidato " + c2.getNome());
        controle = c2.alteraData("01/01/2023");
        System.out.println("Nova data de nascimento: " + c2.getDataNascimento());
        System.out.println("\nAlterando o gênero do candidato " + c3.getNome());
        controle = c3.alteraGenero("Feminino");
        System.out.println("Novo gênero: " + c3.getGenero());
        System.out.println("\nAlterando bens do candidato " + c1.getNome());
        controle = c1.alteraBens(2);
        System.out.println("Nova quantia de bens: " + c1.getBens());
        System.out.println("\nAlterando reeleição do candidato " + c2.getNome());
        controle = c2.alteraReeleicao(false);
        System.out.println("Nova possibilidade de reeleição: " + c2.getReeleicao());
        System.out.println("\nAlterando número de partido do candidato " + c3.getNome());
        controle = c3.alteraNumeroPart(13);
        System.out.println("Novo número: " + c3.getNumeroPartido());
        System.out.println("\nAlterando cargo do candidato " + c1.getNome());
        controle = c1.alteraCargo("Palhaço");
        System.out.println("Novo cargo: " + c1.getCargo());
        System.out.println("\nAlterando município do candidato " + c2.getNome());
        controle = c2.alteraMunicipio("Patos de Minas", 3148004);
        System.out.println("Novo município: " + c2.getMunicipio());
        System.out.println("\n----------------------------- Mostrando candidatos alterados -----------------------------");
        c1.mostrar();
        c2.mostrar();
        c3.mostrar();
    }
}
