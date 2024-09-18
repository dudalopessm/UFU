public class Ex06 {
    public static void main(String[]args) {
        //informações para o município de Fortaleza - CE: 3/9 prefeitos, 3/9 vice-prefeitos e 2/771 vereadores
        Candidato[] listaCandidatos2 = new Candidato[5];
        listaCandidatos2[0] = new Candidato("Wagner Sousa Gomes", "21/01/1979", "Masculino", 1014323.79, false, 44, "Prefeito", 2304400, "Fortaleza - CE");
        listaCandidatos2[1] = new Candidato("George Lima de Araújo", "04/10/1971", "Masculino", 567776.00, false, 77, "Prefeito", 2304400, "Fortaleza - CE");
        listaCandidatos2[2] = new Candidato("Alcyvania Maria Cavalcante de Brito Pinheiro", "29/12/1965", "Feminino", 304320.00, false, 22, "Vice-Prefeito", 2304400, "Fortaleza - CE");
        listaCandidatos2[3] = new Candidato("Jose Elcio Batista", "16/01/1974", "Masculino", 971177.62, true, 12, "Vice-Prefeito", 2304400, "Fortaleza - CE");
        listaCandidatos2[4] = new Candidato("Adriana Gerônimo Vieira Silva", "02/02/1990", "Feminino", 0.00, true, 50777, "Vereador", 2304400, "Fortaleza - CE");
        Eleicao eleicaoFortaleza = new Eleicao("Fortaleza", "Ceará", 2304400, 2428708, listaCandidatos2.length, listaCandidatos2);
        System.out.println("~~~~~~~~~~~~ Sistema de informações de candidatos a eleição de 2024 ~~~~~~~~~~~~");
        System.out.println("Candidato mais rico: " + eleicaoFortaleza.buscaCandidatoRico(listaCandidatos2).getNome());
        System.out.println("Percentual de bens que possui em relação a todos os outros candidatos que estão concorrendo na eleição " + eleicaoFortaleza.bensDoRico(listaCandidatos2, eleicaoFortaleza.buscaCandidatoRico(listaCandidatos2)));
        System.out.println("Informações sobre o candidato: ");
        eleicaoFortaleza.buscaCandidatoRico(listaCandidatos2).mostrar();
    }
}