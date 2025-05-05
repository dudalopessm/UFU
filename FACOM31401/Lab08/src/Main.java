public class Main {
    public static void main(String[] args) {
        ExpressaoAritmetica exp1 = new Numero(0);
        System.out.println("a) Expressão: " + exp1);
        System.out.println("   Resultado: " + exp1.getResultado());

        ExpressaoAritmetica exp2 = new Operacao(new Numero(1), new Numero(2), '+');
        System.out.println("b) Expressão: " + exp2);
        System.out.println("   Resultado: " + exp2.getResultado());

        ExpressaoAritmetica exp3 = new Operacao(
                new Numero(1),
                new Operacao(new Numero(2), new Numero(3), '+'),
                '*');
        System.out.println("c) Expressão: " + exp3);
        System.out.println("   Resultado: " + exp3.getResultado());

        ExpressaoAritmetica exp4 = new Operacao(
                new Operacao(new Numero(2), new Numero(3), '*'),
                new Operacao(
                        new Numero(4),
                        new Operacao(new Numero(5), new Numero(3), '-'),
                        '/'
                ),
                '+'
        );
        System.out.println("d) Expressão: " + exp4);
        System.out.println("   Resultado: " + exp4.getResultado());
    }
}