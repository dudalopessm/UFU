public abstract class ContaCorrente {
    private float saldo;
    private int estado; // 1 = conta ativa, 2 = conta inativa
    private int numConta;
    private int senha;

    public ContaCorrente(float val, int num, int pwd) {
        this.numConta = num;
        this.senha = pwd;
        this.saldo = val;
        this.estado = 1;
    }

    public boolean debitaValor(float val, int pwd) {
        if (pwd != senha)
            return false;
        if (estado != 1)
            return false;
        if (val <= 0)
            return false;
        if (val > saldo)
            return false;
        saldo -= val;
        if (saldo == 0) // conta zerada não pode receber mais lançamentos e nem ser reativada
            estado = 2;
        return true;
    }

    public void debitaValor(float val) {
        saldo -= val;
    }

    public float getSaldo(int pwd) {
        if (senha == pwd)
            return saldo;
        else
            return -1; // problema na senha
    }

    public void creditaValor(int pwd, float val) {
        if (senha == pwd)
            saldo += val;
    }

    protected int getEstado(int pwd) {
        if (senha == pwd)
            return estado;
        else
            return -1;
    }

    protected void setEstado(int pwd, int e) {
        if (senha == pwd) {
            estado = e;
        }
    }

    public int getNumConta() {
        return numConta;
    }

    public void setNumConta(int numConta) {
        this.numConta = numConta;
    }

    protected boolean isSenha(int pwd) {
        if (senha == pwd)
            return true;
        else
            return false;
    }
}