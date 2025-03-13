public class CandidatoVereador extends Candidato {
    /*
- Modifique a classe Candidato, transformando os atributos protected para private
- Entenda o erro que ocorre em toString() das subclasses com essa modificação
- Modifique o método toString() para ser possível vizualizar os atributos privados de Candidato. Para isso use super.toString()
- Crie um novo construtor para Vereador, que terá como parâmetro um candidato (não sabemos ainda a que cargo) e os atributos adicionais de vereador.
Esse construtor permitirá criar um novo objeto de Vereador a partir de um objeto já existente de Candidato (ou seja, um candidato a vereador a partir
de um candidato que já foi criado - fazer tudo via cópia de valores, não por referência).
- Faça um programa principal que cria e mostre os dados das classes envolvidas
     */
    private String bairro;

    //construtores
    public CandidatoVereador(String nomeCandidato, String dataNascimento, String genero, double bem, boolean ree, String numeroPartido, String bairro) {
        super(nomeCandidato, dataNascimento, genero, bem, ree, numeroPartido);
        this.bairro = bairro;
    }
    public CandidatoVereador(Candidato c, String bairro) {
        super(c.getNomeCandidato(), c.getDataNascimento(), c.getGenero(), c.getBens(), c.isReeleicao(), c.getNumeroPartido());
        this.bairro = bairro;
    }

    //gets
    public String getBairro() {
        return bairro;
    }

    //mostra dados
    @Override
    public String toString() {
        return super.toString() +
                "\nBairro em que mora: " + bairro;
    }
}