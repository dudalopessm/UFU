import java.util.Scanner;
import java.util.Random;
/*
----------------------- Relacionamento entre classes -----------------------
Entre objetos de diferentes classes: associação (usa), agregação (é parte de) e composição (é parte essencial de).
COMPOSIÇÃO: O objeto ponto é independente do objeto círculo, mas não vale a recíproca. Ou seja, o objeto círculo usa um objeto ponto para construir seu centro.
Isso caracteriza a composição de ponto em relação à círculo.
AGREGAÇÃO: o objeto círculo é formado por pontos (no caso, os centros), mas os pontos existem independentemente do círculo existir.
Isso é uma relação de agregação entre pontos e círculos.
ASSOCIAÇÃO: o objeto círculo usa o objeto ponto chamando seu método de mostrar para exibir na tela a informação do centro do círculo.
Isso marca a associação entre círculo e ponto.
Assim, neste programa com a interação entre Ponto e Circulo, estão respondidos os exercícios de 1 a 3 do laboratório.
 */
public class Principal {
    public static void main(String[]args) {
        Scanner sc = new Scanner(System.in);
        int N;
        System.out.print("Digite quantos pontos deseja: ");
        N = sc.nextInt();
        Ponto[] listaPontos = new Ponto[N];
        //seta pontos randômicos para o usuário não precisar digitar nos testes
        Random random = new Random();
        double min = 10.0;
        double max = 20.0;
        for(int i = 0; i < listaPontos.length; i++) {
           listaPontos[i] = new Ponto((min+(max-min)* random.nextDouble()), (min+(max-min)* random.nextDouble()));
        }
        System.out.println("\nPontos gerados randomicamente: ");
        for(Ponto unidade : listaPontos) {
            System.out.println("\n" + unidade);
        }
        System.out.print("\nDigite quantos círculos deseja: ");
        int n;
        n = sc.nextInt();
        Circulo[] listaCirculos = new Circulo[n];
        int aux = 0, cont = 0;
        //seta circulos usando pontos randômicos do vetor anterior e raios randômicos
        for(int i = 0; i < listaCirculos.length; i++) {
            int indicePonto = i % listaPontos.length;
            listaCirculos[i] = new Circulo((min + (max - min) * random.nextDouble()), listaPontos[indicePonto]);
        }
        System.out.println("\nCírculos gerados randomicamente: ");
        for(Circulo unidade : listaCirculos) {
            System.out.println("\n" + unidade);
        }
        sc.close();
    }
}