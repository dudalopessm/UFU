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

    public boolean eMenorQue(Classificavel obj) {
        Cliente compara = (Cliente) obj;
        if(this.nome.compareTo(compara.getNome()) < 1) {
            return true;
        }
        else
            return false;
    }

    public String toString() {
        return "Cliente: " + getNome();
    }
}