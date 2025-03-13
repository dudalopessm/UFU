public class Eleicao {
    private String nomeMunicipio;
    private String estadoMunicipio;
    private int codigoMunicipio;
    private int numeroVotantes;
    private int numeroCandidatos;
    private Candidato[] candidatos;

    public Eleicao(String nomemun, String emun, int codmun, int numvot, int numcan, Candidato[] listaCan) {
        this.nomeMunicipio = nomemun;
        this.estadoMunicipio = emun;
        this.codigoMunicipio = codmun;
        this.numeroVotantes = numvot;
        this.numeroCandidatos = numcan;
        this.candidatos = listaCan;
    }

    public String getNomeMunicipio() {
        return this.nomeMunicipio;
    }
    public String getEstadoMunicipio() {
        return this.estadoMunicipio;
    }
    public int getCodigoMunicipio() {
        return this.codigoMunicipio;
    }
    public int getNumeroVotantes() {
        return this.numeroVotantes;
    }
    public int getNumeroCandidatos() {
        return this.numeroCandidatos;
    }
    public void mostrarEleicao() {
        System.out.println("~~~~~~~~~ Informações da eleição de " + getNomeMunicipio() + " ~~~~~~~~~");
        System.out.println("Município: " + getNomeMunicipio() + " - " + getEstadoMunicipio());
        System.out.println("Código do Município: " + getCodigoMunicipio());
        System.out.println("Número de Votantes: " + getNumeroVotantes());
        System.out.println("Número de Candidatos: " + getNumeroCandidatos());
        System.out.println("~~~~~~~~~ Candidatos ~~~~~~~~~");
        for (Candidato candidato : candidatos) {
            candidato.mostrar();
        }
    }
}