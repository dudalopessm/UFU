public class Ex03 {
    public static void main(String[]args) {
        Candidato candidatos[] = new Candidato[3];
        for (int i = 0; i < candidatos.length; i++) {
            candidatos[i] = new Candidato();
        }

        //sets para c1
        candidatos[0].setNome("Alexandre Holanda Sabino");
        candidatos[0].setDataNascimento("13/05/1973");
        candidatos[0].setGenero("Masculino");
        candidatos[0].setBens(132000.00);
        candidatos[0].setReeleicao(false);
        candidatos[0].setNumeroPartido(12);
        candidatos[0].setCargo("Prefeito");
        candidatos[0].setCodigoMun(2305233);
        candidatos[0].setMunicipio("Horizonte - CE");


        //sets para c2
        candidatos[1].setNome("Manoel Gomes de Faria Neto");
        candidatos[1].setDataNascimento("18/08/1959");
        candidatos[1].setGenero("Masculino");
        candidatos[1].setBens(1919410.00);
        candidatos[1].setReeleicao(true);
        candidatos[1].setNumeroPartido(40);
        candidatos[1].setCargo("Prefeito");
        candidatos[1].setCodigoMun(2305233);
        candidatos[1].setMunicipio("Horizonte - CE");


        //sets para c3
        candidatos[2].setNome("Rhenan Cavalcante Assunção");
        candidatos[2].setDataNascimento("12/02/1989");
        candidatos[2].setGenero("Masculino");
        candidatos[2].setBens(278000.00);
        candidatos[2].setReeleicao(false);
        candidatos[2].setNumeroPartido(25);
        candidatos[2].setCargo("Prefeito");
        candidatos[2].setCodigoMun(2305233);
        candidatos[2].setMunicipio("Horizonte - CE");

        System.out.println("~~~~~~~~~~~~ Sistema de informações de candidatos a eleição de 2024 ~~~~~~~~~~~~");
        for(Candidato candidato : candidatos) {
            candidato.mostrar();
        }
    }
}