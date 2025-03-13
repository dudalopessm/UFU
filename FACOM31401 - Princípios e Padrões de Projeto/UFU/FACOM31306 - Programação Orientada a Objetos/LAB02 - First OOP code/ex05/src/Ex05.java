public class Ex05 {
    public static void main(String[]args) {
        //informações para o município de Horizonte - CE: 3 prefeitos, 3 vice-prefeitos e para efeito de teste, pegarei apenas 5 dos 133 candidatos a vereadores
        Candidato[] listaCandidatos = new Candidato[11];
        listaCandidatos[0] = new Candidato("Alexandre Holanda Sabino", "13/05/1973", "Masculino", 132000.00, false, 12, "Prefeito", 2305233, "Horizonte - CE");
        listaCandidatos[1] = new Candidato("Manoel Gomes de Faria Neto", "18/08/1959", "Masculino", 1919410.00, true, 40, "Prefeito", 2305233, "Horizonte - CE");
        listaCandidatos[2] = new Candidato("Rhenan Cavalcante Assunção", "12/02/1989", "Masculino", 278000.00, false, 25, "Prefeito", 2305233, "Horizonte - CE");
        listaCandidatos[3] = new Candidato("Antônio Jairo do Nascimento Freitas", "30/09/1991", "Masculino", 0.00, false, 12, "Vice-prefeito", 2305233, "Horizonte - CE");
        listaCandidatos[4] = new Candidato("Rafael Ribeiro dos Santos", "01/06/1982", "Masculino", 1200000.00, true, 40, "Vice-prefeito", 2305233, "Horizonte - CE");
        listaCandidatos[5] = new Candidato("Regino Pereira Matos", "08/10/1980", "Masculino", 225000.00, false, 25, "Vice-prefeito", 2305233, "Horizonte - CE");
        listaCandidatos[6] = new Candidato("Aderson Cavalcante da Silva", "12/05/1980", "Masculino", 0.00, false, 27000, "Vereador", 2305233, "Horizonte - CE");
        listaCandidatos[7] = new Candidato("Liduina Sousa da Silva Nascimento", "25/03/1987", "Feminino", 15000.00, false, 27190, "Vereador", 2305233, "Horizonte - CE");
        listaCandidatos[8] = new Candidato("Valdiglecia Silva dos Santos", "11/05/1983", "Feminino", 0.00, false, 55444, "Vereador", 2305233, "Horizonte - CE");
        listaCandidatos[9] = new Candidato("Érica Serpa Viana Assunção", "16/08/1989", "Feminino", 0.00, false, 25456, "Vereador", 2305233, "Horizonte - CE");
        listaCandidatos[10] = new Candidato("Erbson Dyonnes de Sousa Brito", "15/08/1992", "Masculino", 0.00, false, 13123, "Vereador", 2305233, "Horizonte - CE");
        Eleicao eleicaoHorizonte = new Eleicao("Horizonte", "Ceará", 2305233, 74755, listaCandidatos.length, listaCandidatos);


        //informações para o município de Fortaleza - CE: 3/9 prefeitos, 3/9 vice-prefeitos e 2/771 vereadores
        Candidato[] listaCandidatos2 = new Candidato[8];
        listaCandidatos2[0] = new Candidato("Wagner Sousa Gomes", "21/01/1979", "Masculino", 1014323.79, false, 44, "Prefeito", 2304400, "Fortaleza - CE");
        listaCandidatos2[1] = new Candidato("George Lima de Araújo", "04/10/1971", "Masculino", 567776.00, false, 77, "Prefeito", 2304400, "Fortaleza - CE");
        listaCandidatos2[2] = new Candidato("Andre Fernandes de Moura", "10/12/1997", "Masculino", 377707.00, false, 22, "Prefeito", 2304400, "Fortaleza - CE");
        listaCandidatos2[3] = new Candidato("Alcyvania Maria Cavalcante de Brito Pinheiro", "29/12/1965", "Feminino", 304320.00, false, 22, "Vice-Prefeito", 2304400, "Fortaleza - CE");
        listaCandidatos2[4] = new Candidato("Jose Elcio Batista", "16/01/1974", "Masculino", 971177.62, true, 12, "Vice-Prefeito", 2304400, "Fortaleza - CE");
        listaCandidatos2[5] = new Candidato("Rachel Girão Silva", "10/05/1979", "Feminino", 85000.00, false, 77, "Vice-Prefeito", 2304400, "Fortaleza - CE");
        listaCandidatos2[6] = new Candidato("Adriana Gerônimo Vieira Silva", "02/02/1990", "Feminino", 0.00, true, 50777, "Vereador", 2304400, "Fortaleza - CE");
        listaCandidatos2[7] = new Candidato("Francisco Eudes Ferreira Bringel", "04/05/1972", "Masculino", 270622.72, true, 55000, "Vereador", 2304400, "Fortaleza - CE");
        Eleicao eleicaoFortaleza = new Eleicao("Fortaleza", "Ceará", 2304400, 2428708, listaCandidatos2.length, listaCandidatos2);

        System.out.println("~~~~~~~~~~~~ Sistema de informações de candidatos a eleição de 2024 ~~~~~~~~~~~~");
        eleicaoHorizonte.mostrarEleicao();
        System.out.println("\n\n");
        eleicaoFortaleza.mostrarEleicao();
    }
}