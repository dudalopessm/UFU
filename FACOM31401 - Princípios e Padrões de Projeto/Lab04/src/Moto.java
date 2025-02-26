public class Moto extends Veiculo {
    public Moto(String modelo, String marca, int ano) {
        super(modelo, marca, ano);
    }

    public void ligar() {
        System.out.println("Ligando a moto " + modelo);
    }
}
