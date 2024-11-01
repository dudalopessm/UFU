public class Ex03 {
    public static void main(String[]args) {
        /*
- Modifique a classe Candidato, transformando os atributos protected para private
- Entenda o erro que ocorre em toString() das subclasses com essa modificação
- Modifique o método toString() para ser possível vizualizar os atributos privados de Candidato. Para isso use super.toString()
- Crie um novo construtor para Vereador, que terá como parâmetro um candidato (não sabemos ainda a que cargo) e os atributos adicionais de vereador.
Esse construtor permitirá criar um novo objeto de Vereador a partir de um objeto já existente de Candidato (ou seja, um candidato a vereador a partir
de um candidato que já foi criado - fazer tudo via cópia de valores, não por referência).
- Faça um programa principal que cria e mostre os dados das classes envolvidas
         */
        CandidatoPrefeito prefeito = new CandidatoPrefeito("Luís Eduardo Falcão Ferreira", "16/03/1984", "Masculino", 963218.45, true, "30", "Sandra Gomes", "30");
        CandidatoVereador vereador = new CandidatoVereador("Guilherme Fonseca Marques", "19/07/1971", "Masculino", 520070.00, false, "30888", "Caiçaras");
        Candidato c = new Candidato("Brenda Évellyn Santos", "14/06/2000", "Feminino", 10644, false, "30333");
        CandidatoVereador vereadora = new CandidatoVereador(c, "Copacabana");
        System.out.println("------------------------------------ Vereadores e prefeitos ------------------------------------");
        System.out.println(prefeito.toString());
        System.out.println(vereador.toString());
        System.out.println(vereadora.toString());
    }
}
