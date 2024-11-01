public class Quadrado extends FormaBidimensional {
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

    public Quadrado(double lado) {
        this.lado = lado;
    }

    public double getLado() {
        return lado;
    }

    public void setLado(double lado) {
        this.lado = lado;
    }

    public double obterArea() {
        return this.lado*this.lado;
    }

    public String descricao() {
        return "\n------------------------ QUADRADO ------------------------" + "\nQuadrado de lado " +getLado()+ ".";
    }
}
