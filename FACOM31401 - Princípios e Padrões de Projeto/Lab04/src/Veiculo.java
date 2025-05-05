public abstract class Veiculo {
    protected String modelo;
    protected String marca;
    protected int ano;

    public Veiculo(String modelo, String marca, int ano) {
        this.modelo = modelo;
        this.marca = marca;
        this.ano = ano;
    }

    public abstract void ligar();
}