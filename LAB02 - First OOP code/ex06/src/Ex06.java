import java.util.Scanner;
public class Ex06 {
    public static void main(String[]args) {
        //TESTES COM INFORMAÇÕES JÁ SETADAS
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

        //TESTE COM INFORMAÇÕES FORNECIDAS PELO USUÁRIO
        Scanner sc = new Scanner(System.in);
        int N;
        System.out.print("Digite a quantidade de cidades para serem cadastradas: ");
        N = sc.nextInt();
        sc.nextLine();
        Eleicao[] listaEleicao = new Eleicao[N];
        String nomeC, dataN, genero, cargo, nomeM, estadoM;
        int codmun, numeroP, numeroV, numC;
        double bensC;
        boolean reelege;
        for (int i = 0; i < listaEleicao.length; i++) {
            System.out.print("Digite o nome da cidade: ");
            nomeM = sc.nextLine();
            System.out.print("Digite o estado da cidade: ");
            estadoM = sc.nextLine();
            System.out.print("Digite o código do município: ");
            codmun = sc.nextInt();
            sc.nextLine();
            System.out.print("Digite o numero de votantes do município: ");
            numeroV = sc.nextInt();
            sc.nextLine();
            System.out.print("Digite a quantidade de candidatos da cidade para serem cadastrados: ");
            numC = sc.nextInt();
            sc.nextLine();
            Candidato[] listaCandidatos = new Candidato[numC];
            for (int j = 0; j < listaCandidatos.length; j++) {
                System.out.println("---- Candidato " + (j+1) + " ----");
                System.out.print("Digite o nome do candidato: ");
                nomeC = sc.nextLine();
                System.out.print("Digite a data de nascimento: ");
                dataN = sc.nextLine();
                System.out.print("Digite o genero: ");
                genero = sc.nextLine();
                System.out.print("Digite true ou false para candidato a reeleicao: ");
                reelege = sc.nextBoolean();
                sc.nextLine();
                System.out.print("Digite a quantidade de bens em reais do candidato: ");
                String bensCStr = sc.nextLine().replace(",", ".");  // Substituir vírgula por ponto
                bensC = Double.parseDouble(bensCStr);  // Converte a string para double
                System.out.print("Digite o cargo pretendido: ");
                cargo = sc.nextLine();
                System.out.print("Digite o número do partido: ");
                numeroP = sc.nextInt();
                sc.nextLine();
                listaCandidatos[j] = new Candidato(nomeC, dataN, genero, bensC, reelege, numeroP, cargo, codmun, nomeM);
            }
            listaEleicao[i] = new Eleicao(nomeM, estadoM, codmun, numeroV, listaCandidatos.length, listaCandidatos);
        }
        System.out.println("-------------------- Eleicoes --------------------");
        for (Eleicao unidade : listaEleicao) {
            unidade.mostrarEleicao();
        }
        sc.close();git add
    }
}