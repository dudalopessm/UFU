public class Triangulo extends FormaBidimensional {
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
    public double base;
    public double altura;

    public Triangulo(double base, double altura) {
        this.base = base;
        this.altura = altura;
    }

    public double getBase() {
        return base;
    }

    public void setBase(double base) {
        this.base = base;
    }

    public double getAltura() {
        return altura;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }

    public double obterArea() {
        return this.base*this.altura;
    }

    public String descricao() {
        return "\n------------------------ TRIÂNGULO ------------------------" + "\nTriângulo de base " + getBase() + " e altura " + getAltura() + ".";
    }
}