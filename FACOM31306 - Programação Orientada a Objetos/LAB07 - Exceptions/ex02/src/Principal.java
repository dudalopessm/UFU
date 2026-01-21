public class Principal {
    public static void main(String[]args) {
        System.out.println("------------------------------- Divisão por zero? -------------------------------");
        Operacao op = new Operacao();
        float saida;
        try {
            saida = op.iniciarOperacao(6870,231);
            System.out.println("Operação realizada com sucesso. Resultado: " + saida);
        } catch (DivisaoPorZeroException e) {
            System.out.println(e.getMessage());
        }
        try {
            saida = op.iniciarOperacao(167,0);
            System.out.println("Operação realizada com sucesso. Resultado: " + saida);
        } catch (DivisaoPorZeroException e) {
            System.out.println(e.getMessage());
        }
    }
}