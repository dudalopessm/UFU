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

    public boolean eMenorQue(Classificavel obj) {
        Produto compara = (Produto) obj;
        if(this.codigo < compara.codigo)
            return true;
        else
            return false;
    }

    public String toString() {
        return "Produto: " + this.codigo;
    }
}