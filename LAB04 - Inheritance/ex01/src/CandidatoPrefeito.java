import java.util.Date;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;


public class CandidatoPrefeito {
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
    private String nomePrefeito;
    private LocalDate dataNascimentoPrefeito;
    private String generoPrefeito;
    private double bensPrefeito;
    private boolean reeleicaoPrefeito;
    private int numeroPartidoPrefeito;
    private String nomeVice;
    private String partidoVice;

    //construtor
    public CandidatoPrefeito(String nome, String nasc, String gen, double bem, boolean ree, int numP, String nomev, String partv) {
        this.nomePrefeito = nome;
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        LocalDate dataUsuario = LocalDate.parse(nasc, formatter);
        this.dataNascimentoPrefeito = dataUsuario;
        this.generoPrefeito = gen;
        this.bensPrefeito = bem;
        this.reeleicaoPrefeito = ree;
        this.numeroPartidoPrefeito = numP;
        this.nomeVice = nomev;
        this.partidoVice = partv;

    }

    //getters
    public String getNomePrefeito() {
        return nomePrefeito;
    }
    public LocalDate getDataNascimentoPrefeito() {
        return dataNascimentoPrefeito;
    }
    public String getGeneroPrefeito() {
        return generoPrefeito;
    }
    public double getBensPrefeito() {
        return bensPrefeito;
    }
    public boolean isReeleicaoPrefeito() {
        return reeleicaoPrefeito;
    }
    public int getNumeroPartidoPrefeito() {
        return numeroPartidoPrefeito;
    }
    public String getNomeVice() {
        return nomeVice;
    }
    public String getPartidoVice() {
        return partidoVice;
    }

    //mostra dados
    @Override
    public String toString() {
        return "Candidato " +
                "'" + nomePrefeito + '\'' +
                ", nascido em " + dataNascimentoPrefeito +
                ", com genero identificado como " + generoPrefeito + '\'' +
                ", de bens " + bensPrefeito + "reais" +
                ", com candidatura a reeleicao " + reeleicaoPrefeito +
                ", representado pelo partido de número " + numeroPartidoPrefeito +
                ", de vice de nome " + nomeVice + '\'' +
                ", representado pelo partido " + partidoVice + '\'';
    }
}