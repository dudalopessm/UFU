public class ContaEspecial extends ContaCorrente {
    private float limite;

    public ContaEspecial(float val, int num, int pwd, float limite) {
        super(val, num, pwd);
        setLimite(limite, pwd);
    }

    public float getLimite() {
        return limite;
    }

    public ContaCorrente setLimite(float limite, int pwd) {
        if(limite < 0) {
            this.limite = -1; // verificação na main
            return this;
        } else if (limite == 0) {
            return new ContaComum(this.getSaldo(pwd), this.getNumConta(), pwd, limite);
        } else {
            this.limite = limite;
            return this;
        }
    }

    public boolean debitaValor(float val, int pwd) {
        if (isSenha(pwd) == false)
            return false;
        if (getEstado(pwd) != 1)
            return false;
        if (val <= 0)
            return false;
        if (val > getSaldo(pwd))
            return false;
        debitaValor(val);
        if (getSaldo(pwd) == 0) {
            if(getLimite() <= 0) {
                setEstado(pwd, 2);
            }
        }
        return true;
    }
}