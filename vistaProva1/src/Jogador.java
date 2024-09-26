public class Jogador {
    private String nomeJogador;
    private int idadeJogador;
    private double alturaJogador;
    private double pesoJogador;

    //construtores
    public Jogador() {
    }
    public Jogador(String nome, int idade, double altura, double peso) {
        this.nomeJogador = nome;
        this.idadeJogador = idade;
        this.alturaJogador = altura;
        this.pesoJogador = peso;
    }

    //getters e setters
    public String getNomeJogador() {
        return nomeJogador;
    }
    public void setNomeJogador(String nomeJogador) {
        this.nomeJogador = nomeJogador;
    }
    public int getIdadeJogador() {
        return idadeJogador;
    }
    public void setIdadeJogador(int idadeJogador) {
        this.idadeJogador = idadeJogador;
    }
    public double getAlturaJogador() {
        return alturaJogador;
    }
    public void setAlturaJogador(double alturaJogador) {
        this.alturaJogador = alturaJogador;
    }
    public double getPesoJogador() {
        return pesoJogador;
    }
    public void setPesoJogador(double pesoJogador) {
        this.pesoJogador = pesoJogador;
    }

    //método para mostrar
    public String toString() {
        return "Nome jogador: " + getNomeJogador() + " | Idade jogador: " + getIdadeJogador() + " | Peso jogador: " + getPesoJogador() + " | Altura jogador: " + getAlturaJogador();
    }

    //remoção
    void removeJogador() {
        setAlturaJogador(0);
        setIdadeJogador(0);
        setPesoJogador(0);
        setNomeJogador(null);
    }
}
