public class Operacao extends ExpressaoAritmetica {
    private ExpressaoAritmetica op1;
    private ExpressaoAritmetica op2;
    private char operador;

    public Operacao(ExpressaoAritmetica op1, ExpressaoAritmetica op2, char operador) {
        this.op1 = op1;
        this.op2 = op2;
        this.operador = operador;
    }

    @Override
    public int getResultado() {
        switch(operador) {
            case '+': return op1.getResultado() + op2.getResultado();
            case '-': return op1.getResultado() - op2.getResultado();
            case '*': return op1.getResultado() * op2.getResultado();
            case '/':
                int divisor = op2.getResultado();
                if(divisor == 0) {
                    throw new ArithmeticException("Divisão por zero não permitida.");
                } return op1.getResultado() / op2.getResultado();
            default:
                throw new UnsupportedOperationException("Operador " + operador + " não suportado.");
        }
    }

    @Override
    public String toString() {
        return "(" + op1.toString() + " " + operador + " " + op2.toString() + ")";
    }
}