public class Ex01 {
    public static void main(String[] args) {
        Candidato c1 = new Candidato("Alexandre Holanda Sabino", "13/05/1973", "Masculino", 132000.00, false, 12, "Prefeito", 2305233, "Horizonte - CE");
        Candidato c2 = new Candidato("Manoel Gomes de Faria Neto", "18/08/1959", "Masculino", 1919410.00, true, 40, "Prefeito", 2305233, "Horizonte - CE");
        Candidato c3 = new Candidato("Rhenan Cavalcante Assunção", "12/02/1989", "Masculino", 278000.00, false, 25, "Prefeito", 2305233, "Horizonte - CE");
        System.out.println("~~~~~~~~~~~~ Sistema de informações de candidatos a eleição de 2024 ~~~~~~~~~~~~");
        c1.mostrar();
        c2.mostrar();
        c3.mostrar();
    }
}