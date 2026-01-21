public class Candidato {
    public String nomeCompleto;
    public String dataNascimento;
    public String genero;
    public double bens;
    public boolean reeleicao;
    public int numeroPartido;
    public String cargoPretendido;
    public int codigoMunicipio;
    public String municipio;

    public Candidato(String nome, String nasc, String genero, double bem, boolean reelege, int numpart, String cargo, int codmun, String municipio) {
        this.nomeCompleto = nome;
        this.dataNascimento = nasc;
        this.genero = genero;
        this.bens = bem;
        this.reeleicao = reelege;
        this.numeroPartido = numpart;
        this.cargoPretendido = cargo;
        this.codigoMunicipio = codmun;
        this.municipio = municipio;
    }
    public void mostrar() {
        System.out.println("---------------------------------------------------------");
        System.out.println("Município: " + municipio);
        System.out.println("Código do município: " + codigoMunicipio);
        System.out.println("Nome: " + nomeCompleto);
        System.out.println("Data de nascimento: " + dataNascimento);
        System.out.println("Gênero: "+ genero);
        System.out.println("Bens totais declarados: " + bens);
        System.out.println("Candidato a reeleição?: " + reeleicao);
        System.out.println("Número do partido: " + numeroPartido);
        System.out.println("Cargo pretendido: " + cargoPretendido);
    }
}
