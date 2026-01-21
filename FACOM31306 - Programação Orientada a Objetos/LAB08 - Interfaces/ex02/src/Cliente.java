public class Cliente implements Classificavel {
    private String nome;

    public Cliente(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int eMenorQue(Classificavel obj) {
        Cliente compara = (Cliente) obj;
        if(this.nome.compareTo(compara.getNome()) < 1)
            return -1;
        else if(this.nome.compareTo(compara.getNome()) > 1)
            return 1;
        else
            return 0;
    }

    public String toString() {
        return "Cliente: " + getNome();
    }
}