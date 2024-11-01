import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class CandidatoVereador {
        /*
- não utilizar herança no ex01
Relembre o exercício de uma prática anterior. Nele indicamos que os candidatos possuem seguintes informações: Nome Completo, Data de Nascimento, Gênero,
Total de Bens (em Reais), Candidato a reeleição (sim/não), número do partido, Cargo pretendido
- Assim, modifique o exercício de forma que sejam criadas duas classes. Uma chamada CandidatoPrefeito e outra CandidatoVereador. Essas classes devem
possuir todos os atributos antes listados (exceto Cargo Pretendido) e mais alguns, específicos de cada uma. Para prefeito, o nome e partido do
candidato a vice-prefeito. Para o vereador, o número de três dígitos (use string ao invés de tipos numéricos) e o bairro em que mora.
- Crie construtores que inicializam todos os atributos das classes. Crie também um método toString() para mostrar os dados dos candidatos.
- Faça um programa principal que cria um candidato a prefeito e um a vereador, e mostre os dados criados.
     */
    private String nomeVereador;
    private LocalDate dataNascimentoVereador;
    private String generoVereador;
    private double bensVereador;
    private boolean reeleicaoVereador;
    private String numeroPartidoVereador;
    private String bairroVereador;

    //construtor
    public CandidatoVereador(String nomeVereador, String nasc, String gen, double bem, boolean ree, String numP, String bairro) {
        this.nomeVereador = nomeVereador;
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        LocalDate dataUsuario = LocalDate.parse(nasc, formatter);
        this.dataNascimentoVereador = dataUsuario;
        this.generoVereador = gen;
        this.bensVereador = bem;
        this.reeleicaoVereador = ree;
        this.numeroPartidoVereador = numP;
        this.bairroVereador = bairro;
    }

    //gets
    public String getNomeVereador() {
        return nomeVereador;
    }
    public LocalDate getDataNascimentoVereador() {
        return dataNascimentoVereador;
    }
    public String getGeneroVereador() {
        return generoVereador;
    }
    public double getBensVereador() {
        return bensVereador;
    }
    public boolean isReeleicaoVereador() {
        return reeleicaoVereador;
    }
    public String getNumeroPartidoVereador() {
        return numeroPartidoVereador;
    }
    public String getBairroVereador() {
        return bairroVereador;
    }

    //mostra dados
    @Override
    public String toString() {
        return "************ Candidato  ************" +
                "\nNome: " + nomeVereador +
                "\nNascimento: " + dataNascimentoVereador +
                "\nGênero: " + generoVereador +
                "\nBens declarados: " + bensVereador + " reais" +
                "\nCandidato a reeleicao: " + reeleicaoVereador +
                "\nNúmero do partido: " + numeroPartidoVereador +
                "\nBairro em que mora: " + bairroVereador;
    }
}