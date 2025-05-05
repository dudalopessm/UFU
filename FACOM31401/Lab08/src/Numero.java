public class Numero extends ExpressaoAritmetica {
    private int valor;

    public Numero(int valor) {
        this.valor = valor;
    }

    @Override
    public int getResultado() {
        return valor;
    }

    @Override
    public String toString() {
        return Integer.toString(valor);
    }
}