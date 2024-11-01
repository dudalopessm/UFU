public class Ex02 {
    /*
    O conceito de herança (inheritance) em POO é muito utilizado para reaproveitamento de código.
- Identifique no exercício anterior quais atributos em comum possuem os dois tipos de candidatos e crie uma classe chamada Candidato, transformando
os atributos private para protected. Lembre de incluir na classe o método toString()
- Modifique as classes de Prefeito/Vereador, eliminando todos os atributos e métodos reduntantes de Candidato. Obtenha os valores desses atributos
 por herança utilizando a palavra chave extends, isto é: "public class CandidatoVereador extends Candidato {".
- Note que a herança irá trazer os atributos e os métodos para as classes de Prefeito/Vereador.
- Note que o método toString() deve continuar nas classes de Prefeito/Vereador, pois ele é diferente do método toString() da classe Candidato
O construtor deve ser modificado, de forma a inicializar somente os atributos das classes de Prefeito/Vereador. Os atributos que são originais
de classe Candidato (chamada de superclasse ou classe mãe/pai) deverão ser inicializados por meio da chamada do construtor original de Prefeito/Vereador.
Isso é feito usando a palavra reservada super
- Faça um programa principal que cria um candidato a prefeito e um a vereador, e mostre os dados criados.
     */
    public static void main(String[]args) {
        CandidatoPrefeito prefeito = new CandidatoPrefeito("Luís Eduardo Falcão Ferreira", "16/03/1984", "Masculino", 963218.45, true, "30", "Sandra Gomes", "30");
        CandidatoVereador vereador = new CandidatoVereador("Guilherme Fonseca Marques", "19/07/1971", "Masculino", 520070.00, false, "30888", "Caiçaras");
        System.out.println("------------------------------------ Vereadores e prefeitos ------------------------------------");
        System.out.println(prefeito.toString());
        System.out.println(vereador.toString());
    }
}
