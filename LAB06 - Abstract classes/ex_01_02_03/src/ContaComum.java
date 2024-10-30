public class ContaComum extends ContaCorrente {
    private float limite;

    public ContaComum(float val, int num, int pwd, float limite) {
        super(val, num, pwd);
        setLimite(limite);
    }

    public float getLimite() {
        return limite;
    }

    public void setLimite(float limite) {
        this.limite = 0;
    }
}