import java.util.Scanner;
public class Principal {
    public static void main(String[]args) {
        int N;
        Scanner sc = new Scanner(System.in);
        System.out.println("--------------------------- Vista prova 1 ---------------------------");
        System.out.println("Informe a quantidade de times: ");
        N = sc.nextInt();
        sc.nextLine();
        Time[] listaTimes = new Time[N];
        String nomeJ, nomeT;
        double pesoJ, alturaJ, mediaId;
        int idJ;
        int quantR;
        for(int i = 0; i < listaTimes.length; i++) {
            System.out.println("*********** Time " + (i+1) + " ***********");
            System.out.print("Digite o nome do time: ");
            nomeT = sc.nextLine();
            System.out.print("Digite 1 se houver um reserva e digite 0 caso não haja: ");
            quantR = sc.nextInt();
            sc.nextLine();
            Jogador[] aux = new Jogador[2]; //vetor de titulares
            if(quantR == 0) {
                for(int j = 0; j < aux.length; j++) {
                    System.out.println("@@@@@@ Jogador " + (j+1) + " @@@@@@");
                    System.out.print("Digite o nome do jogador: ");
                    nomeJ = sc.nextLine();
                    System.out.print("Digite a idade do jogador: ");
                    idJ = sc.nextInt();
                    sc.nextLine();
                    System.out.print("Digite o peso do jogador: ");
                    String PesoStr = sc.nextLine().replace(",", ".");
                    pesoJ = Double.parseDouble(PesoStr);
                    System.out.print("Digite a altura do jogador: ");
                    String AltStr = sc.nextLine().replace(",", ".");
                    alturaJ = Double.parseDouble(AltStr);
                    aux[j] = new Jogador(nomeJ, idJ, pesoJ, alturaJ);
                }
                listaTimes[i] = new Time(nomeT, aux);
            } else if(quantR == 1) {
                for(int j = 0; j < aux.length; j++) {
                    System.out.println("@@@@@@ Jogador " + (j+1) + " @@@@@@");
                    System.out.print("Digite o nome do jogador: ");
                    nomeJ = sc.nextLine();
                    System.out.print("Digite a idade do jogador: ");
                    idJ = sc.nextInt();
                    sc.nextLine();
                    System.out.print("Digite o peso do jogador: ");
                    String PesoStr = sc.nextLine().replace(",", ".");
                    pesoJ = Double.parseDouble(PesoStr);
                    System.out.print("Digite a altura do jogador: ");
                    String AltStr = sc.nextLine().replace(",", ".");
                    alturaJ = Double.parseDouble(AltStr);
                    aux[j] = new Jogador(nomeJ, idJ, pesoJ, alturaJ);
                }
                System.out.println("@@@@@@ Jogador reserva @@@@@@");
                System.out.print("Digite o nome do jogador: ");
                nomeJ = sc.nextLine();
                System.out.print("Digite a idade do jogador: ");
                idJ = sc.nextInt();
                sc.nextLine();
                System.out.print("Digite o peso do jogador: ");
                String PesoStr = sc.nextLine().replace(",", ".");
                pesoJ = Double.parseDouble(PesoStr);
                System.out.print("Digite a altura do jogador: ");
                String AltStr = sc.nextLine().replace(",", ".");
                alturaJ = Double.parseDouble(AltStr);
                Jogador r = new Jogador(nomeJ, idJ, pesoJ, alturaJ);
                listaTimes[i] = new Time(nomeT, aux, r);
            } else {
                System.out.println("Numero de reservas inválido! Erro na geração do time!");
                listaTimes[i] = new Time();
            }
        }
        System.out.println("\n");
        System.out.println("####################### Mostra de times #######################");
        for(Time unidade : listaTimes) {
            if(unidade.getReserva() != null) {
                System.out.println(unidade.toString());
            } else {
                unidade.mostraSemReserva();
            }
        }
        System.out.println("####################### Média de idades #######################");
        for(Time unidade : listaTimes) {
            mediaId = unidade.calculoIdadeMedia();
            System.out.println("A média de idade do time " + unidade.getNomeTime() + " é de " + mediaId + " anos.");
        }
        System.out.println("####################### Destruição de times #######################");
        for(Time unidade : listaTimes) {
            unidade.destroiTime();
            if(unidade.getReserva() != null) {
                System.out.println(unidade.toString());
            } else {
                unidade.mostraSemReserva();
            }
        }
        sc.close();
    }
}