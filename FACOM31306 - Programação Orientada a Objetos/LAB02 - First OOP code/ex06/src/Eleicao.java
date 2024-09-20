public class Eleicao {
    private String nomeMunicipio;
    private String estadoMunicipio;
    private int codigoMunicipio;
    private int numeroVotantes;
    private int numeroCandidatos;
    private Candidato[] candidatos;

    //construtores
    public Eleicao(String nomemun, String emun, int codmun, int numvot, int numcan, Candidato[] listaCan) {
        this.nomeMunicipio = nomemun;
        this.estadoMunicipio = emun;
        this.codigoMunicipio = codmun;
        this.numeroVotantes = numvot;
        this.numeroCandidatos = numcan;
        this.candidatos = new Candidato[getNumeroVotantes()];
    }

    //getters
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

    //mostra informações
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

    //busca o candidato mais rico e o retorna
    public Candidato buscaCandidatoRico(Candidato[] lista) {
        double aux = lista[0].getBens();
        Candidato auxiliar = lista[0];
        for(int i = 0; i < lista.length; i++) {
            if (lista[i].getBens() >= aux) {
                aux = lista[i].getBens();
                auxiliar = lista[i];
            }
        }
        return auxiliar;
    }
    //retorna a porcentagem de bens do rico em relação a toda lista
    public double bensDoRico(Candidato[] lista, Candidato rico) {
        double somaBens = 0;
        for(int i = 0; i < lista.length; i++) {
            somaBens = somaBens + lista[i].getBens();
        }
        return (rico.getBens()/somaBens)*100;
    }
}