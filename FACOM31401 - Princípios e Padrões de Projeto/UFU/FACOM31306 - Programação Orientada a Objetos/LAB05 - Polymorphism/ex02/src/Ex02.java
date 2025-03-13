public class Ex02 {
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
    public static void main(String[]args) {
        Forma[] formas = new Forma[7];
        formas[0] = new Circulo(2.0);
        formas[1] = new Cubo(5.0);
        formas[2] = new Esfera(7.0);
        formas[3] = new Quadrado(3.45);
        formas[4] = new Tetraedro(8.3, 9.0);
        formas[5] = new Triangulo(6.5, 4.333);
        formas[6] = new Esfera(8.7556);
        for(Forma unidade : formas) {
            System.out.println(unidade.descricao());
            if(unidade instanceof FormaBidimensional) {
                System.out.println("\n* Área: " + (((FormaBidimensional) unidade).obterArea()));
            } else if(unidade instanceof  FormaTridimensional) {
                System.out.println("\n* Área: " + ((FormaTridimensional) unidade).obterArea());
                System.out.println("* Volume: " + ((FormaTridimensional) unidade).obterVolume());
            }
        }
    }
}
