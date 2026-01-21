public class CandidatoPrefeito extends Candidato {
    /*
- Modifique a classe Candidato, transformando os atributos protected para private
- Entenda o erro que ocorre em toString() das subclasses com essa modificação
- Modifique o método toString() para ser possível vizualizar os atributos privados de Candidato. Para isso use super.toString()
- Crie um novo construtor para Vereador, que terá como parâmetro um candidato (não sabemos ainda a que cargo) e os atributos adicionais de vereador.
Esse construtor permitirá criar um novo objeto de Vereador a partir de um objeto já existente de Candidato (ou seja, um candidato a vereador a partir
de um candidato que já foi criado - fazer tudo via cópia de valores, não por referência).
- Faça um programa principal que cria e mostre os dados das classes envolvidas
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

    //mostra dados -> o erro é que os atributos de Candidato são privados, ou seja, não estão visíveis no pacote/na subclasse. Assim, o único jeito
    //de acessar é via super.toString()
    @Override
    public String toString() {
        return super.toString() +
                "\nNome do vice: "+ nomeVice +
                "\nPartido do vice: " + partidoVice;
    }
}
