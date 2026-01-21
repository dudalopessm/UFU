public class Tetraedro extends FormaTridimensional {
    /*
        Implemente uma hierarquia de formas geométricas,
de acordo com a Figura do próximo slide
• Cada forma bidimensional deve conter o método
obterArea(), e cada forma tridimensional deve conter o
método obterArea() e obterVolume()
• Crie um programa que utilize um vetor de formas para
objetos dessa hierarquia
• Crie métodos para mostrar uma descrição textual do
objeto ao qual cada elemento se refere
• O programa também deve percorrer o vetor e, se for
uma forma bidimensional, mostrar sua área, e se for
uma forma tridimensional, mostrar seu volume
     */
    public double lado;
    public double altura;

    public Tetraedro(double lado, double altura) {
        this.lado = lado;
        this.altura = altura;
    }

    public double getLado() {
        return lado;
    }

    public void setLado(double lado) {
        this.lado = lado;
    }

    public double getAltura() {
        return altura;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }

    public double obterArea() {
        return this.lado*this.lado*Math.sqrt(3.0);
    }

    public double obterVolume() {
        return (1.0/3.0)*(this.lado*this.lado*Math.sqrt(3.0))*this.altura;
    }

    public String descricao() {
        return "\n------------------------ TETRAEDRO ------------------------" + "\nTetraedro de lado " + getLado() + " e altura " + getAltura() + ".";
    }
}
