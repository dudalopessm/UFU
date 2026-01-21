public class Circulo {
    private double raio;
    private Ponto centro;

    //construtor
    public Circulo(double r, Ponto c) {
        setRaio(r);
        setCentro(c);
    }

    //getters e setters
    public double getRaio() {
        return raio;
    }
    public void setRaio(double raio) {
        this.raio = raio;
    }
    public Ponto getCentro() {
        return centro;
    }
    public void setCentro(Ponto p) {
        this.centro = new Ponto(p.getX(), p.getY());
    }

    //mostra círculos
    public String toString() {
        return "****************** Círculo ******************" + "\nRaio: " + String.format("%.4f", getRaio()) + ",\nCentro: " + getCentro().toString();
    }
}