public class Produto implements Classificavel {
    private int codigo;

    public Produto(int codigo) {
        this.codigo = codigo;
    }

    public int getCodigo() {
        return codigo;
    }

    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    public int eMenorQue(Classificavel obj) {
        Produto compara = (Produto) obj;
        if(this.codigo < compara.getCodigo())
            return -1;
        else if (this.codigo > compara.getCodigo())
            return 1;
        else
            return 0;
    }

    public String toString() {
        return "Produto: " + this.codigo;
    }
}