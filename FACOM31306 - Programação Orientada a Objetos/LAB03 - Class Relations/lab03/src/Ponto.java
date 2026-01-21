public class Ponto {
    private double x, y;

    //construtor
    public Ponto(double X, double Y) {
        setX(X);
        setY(Y);
    }

    //getters e setters
    public double getX() {
        return x;
    }
    public void setX(double x) {
        this.x = x;
    }
    public double getY() {
        return y;
    }
    public void setY(double y) {
        this.y = y;
    }

    //mostra pontos
    public String toString() {
        return "x = " + String.format("%.4f", getX()) + ", y = " + String.format("%.4f", getY());
    }
}
