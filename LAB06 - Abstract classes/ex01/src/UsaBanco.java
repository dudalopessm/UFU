import java.util.Scanner;
public class UsaBanco {
    public static void main(String[]args) {
        Scanner sc = new Scanner(System.in);
        ContaEspecial contasEsp[] = new ContaEspecial[4];
        ContaComum contasCom[] = new ContaComum[2];
        contasEsp[0] = new ContaEspecial(10000, 1, 1122, 30);
        contasEsp[1] = new ContaEspecial(100, 2, 1322, 0);
        contasEsp[2] = new ContaEspecial(1111, 3, 1124, -1);
        contasEsp[3] = new ContaEspecial(2000, 4, 1144, 10000);
        contasCom[0] = new ContaComum(20, 5, 1444, 45);
        contasCom[1] = new ContaComum(255, 6, 4444, 44);
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
            if (unidade != null) {
                System.out.println("Conta de número " + unidade.getNumConta() + " criada com sucesso!");
            }
        }
        for(ContaComum unidade : contasCom) {
            if (unidade != null) {
                System.out.println("Conta de número " + unidade.getNumConta() + " criada com sucesso!");
            }
        }
        sc.close();
    }
}
