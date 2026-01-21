public class Candidato {
    /*
- Modifique a classe Candidato, transformando os atributos protected para private
- Entenda o erro que ocorre em toString() das subclasses com essa modificação
- Modifique o método toString() para ser possível vizualizar os atributos privados de Candidato. Para isso use super.toString()
- Crie um novo construtor para Vereador, que terá como parâmetro um candidato (não sabemos ainda a que cargo) e os atributos adicionais de vereador.
Esse construtor permitirá criar um novo objeto de Vereador a partir de um objeto já existente de Candidato (ou seja, um candidato a vereador a partir
de um candidato que já foi criado - fazer tudo via cópia de valores, não por referência).
- Faça um programa principal que cria e mostre os dados das classes envolvidas
     */
    private String nomeCandidato;
    private   String dataNascimento;
    private String genero;
    private double bens;
    private boolean reeleicao;
    private String numeroPartido;

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

    //mostra dados -> o erro é que os atributos de Candidato são privados, ou seja, não estão visíveis no pacote/na subclasse. Assim, o único jeito
    //de acessar é via super.toString()
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
