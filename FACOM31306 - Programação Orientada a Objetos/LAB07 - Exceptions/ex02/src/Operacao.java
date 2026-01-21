public class Operacao {
    public float iniciarOperacao(int numerador, int denominador) throws DivisaoPorZeroException {
        return calcular(numerador, denominador);
    }
    private float calcular(int numerador, int denominador) throws DivisaoPorZeroException {
        return dividir(numerador, denominador);
    }
    private float dividir(int numerador, int denominador) throws DivisaoPorZeroException {
        if(denominador == 0) {
            throw new DivisaoPorZeroException("\nNão se pode dividir por zero.");
        } else {
            return numerador/denominador;
        }
    }
}