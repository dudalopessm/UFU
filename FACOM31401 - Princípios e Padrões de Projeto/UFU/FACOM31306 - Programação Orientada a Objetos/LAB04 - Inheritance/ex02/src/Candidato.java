public class Candidato {
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
    protected String nomeCandidato;
    protected  String dataNascimento;
    protected String genero;
    protected double bens;
    protected boolean reeleicao;
    protected String numeroPartido;

    //construtor
    public Candidato(String nomeCandidato, String dataNascimento, String genero, double bem, boolean ree, String numeroPartido) {
        this.nomeCandidato = nomeCandidato;
        this.dataNascimento = dataNascimento;
        this.genero = genero;
        this.bens = bem;
        this.reeleicao = ree;
        this.numeroPartido = numeroPartido;
    }

    //gets
    public String getNomeCandidato() {
        return nomeCandidato;
    }
    public String getDataNascimento() {
        return dataNascimento;
    }
    public String getGenero() {
        return genero;
    }
    public double getBens() {
        return bens;
    }
    public boolean isReeleicao() {
        return reeleicao;
    }
    public String getNumeroPartido() {
        return numeroPartido;
    }

    //mostrar dados
    @Override
    public String toString() {
        return "************ Candidato  ************" +
                "\nNome: " + nomeCandidato +
                "\nNascimento: " + dataNascimento +
                "\nGênero: " + genero +
                "\nBens declarados: " + bens + " reais" +
                "\nCandidato a reeleicao: " + reeleicao +
                "\nNúmero do partido: " + numeroPartido;
    }
}
