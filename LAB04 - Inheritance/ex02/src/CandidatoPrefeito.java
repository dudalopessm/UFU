public class CandidatoPrefeito extends Candidato {
    /*
O conceito de herança (inheritance) em POO é muito utilizado para reaproveitamento de código.
- Identifique no exercício anterior quais atributos em comum possuem os dois tipos de candidatos e crie uma classe chamada Candidato, transformando
os atributos private para protected. Lembre de incluir na classe o método toString()
- Modifique as classes de Prefeito/Vereador, eliminando todos os atributos e métodos reduntantes de Candidato. Obtenha os valores desses atributos
por herança utilizando a palavra chave extends, isto é: "public class CandidatoVereador extends Candidato {".
- Note que a herança irá trazer os atributos e os métodos para as classes de Prefeito/Vereador.
- Note que o método toString() deve continuar nas classes de Prefeito/Vereador, pois ele é diferente do método toString() da classe Candidato
O construtor deve ser modificado, de forma a inicializar somente os atributos das classes de Prefeito/Vereador. Os atributos que são originais
de classe Candidato (chamada de superclasse ou classe mãe/pai) deverão ser inicializados por meio da chamada do construtor original de Figurinha.
Isso é feito usando a palavra reservada super
- Faça um programa principal que cria um candidato a prefeito e um a vereador, e mostre os dados criados.
*/
    private String nomeVice;
    private String partidoVice;

    //construtor
    public CandidatoPrefeito(String nomeCandidato, String dataNascimento, String genero, double bem, boolean ree, String numeroPartido, String nomeVice, String partidoVice) {
        super(nomeCandidato, dataNascimento, genero, bem, ree, numeroPartido);
        this.nomeVice = nomeVice;
        this.partidoVice = partidoVice;
    }

    //gets
    public String getNomeVice() {
        return nomeVice;
    }
    public String getPartidoVice() {
        return partidoVice;
    }

    //mostra dados
    @Override
    public String toString() {
        return super.toString() +
                "\nNome do vice: "+ nomeVice +
                "\nPartido do vice: " + partidoVice;
    }
}
