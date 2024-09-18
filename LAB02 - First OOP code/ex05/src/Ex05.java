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
        Eleicao eleicaoHorizonte = new Eleicao("Horizonte", "Ceará", 2305233, 74755, 11, listaCandidatos);

        System.out.println("~~~~~~~~~~~~ Sistema de informações de candidatos a eleição de 2024 ~~~~~~~~~~~~");
        eleicaoHorizonte.mostrarEleicao();
    }
}