public class Candidato {
    private String nomeCompleto;
    private String dataNascimento;
    private String genero;
    private double bens;
    private boolean reeleicao;
    private int numeroPartido;
    private String cargoPretendido;
    private int codigoMunicipio;
    private String municipio;

    public Candidato(String nome, String nasc, String gen, double bem, boolean reelege, int numpart, String cargo, int codmun, String mun) {
        this.nomeCompleto = nome;
        this.dataNascimento = nasc;
        this.genero = gen;
        this.bens = bem;
        this.reeleicao = reelege;
        this.numeroPartido = numpart;
        this.cargoPretendido = cargo;
        this.codigoMunicipio = codmun;
        this.municipio = mun;
    }

    public String getNome() {
        return this.nomeCompleto;
    }
    public int alteraNome(String nome) {
        if(!nome.equals(getNome())) {
            this.nomeCompleto = nome;
            return 0;
        } else {
            return 1;
        }
    }

    public String getDataNascimento() {
        return this.dataNascimento;
    }
    public int alteraData(String data) {
        if(data != getDataNascimento()) {
            this.dataNascimento =  data;
            return 0;
        } else {
            return 1;
        }
    }

    public String getGenero() {
        return this.genero;
    }
    public int alteraGenero(String gen) {
        if(gen != getGenero()) {
            this.genero = gen;
            return 0;
        } else {
            return 1;
        }
    }

    public double getBens() {
        return this.bens;
    }
    public int alteraBens(double bem) {
        if(bem != getBens()) {
            this.bens = bem;
            return 0;
        } else {
            return 1;
        }
    }

    public boolean getReeleicao() {
        return this.reeleicao;
    }
    public int alteraReeleicao(boolean ree) {
        if(ree != getReeleicao()) {
            this.reeleicao = ree;
            return 0;
        } else {
            return 1;
        }
    }

    public int getNumeroPartido() {
        return this.numeroPartido;
    }
    public int alteraNumeroPart(int nump) {
        if(nump != getNumeroPartido()) {
            this.numeroPartido = nump;
            return 0;
        } else {
            return 1;
        }
    }

    public String getCargo() {
        return this.cargoPretendido;
    }
    public int alteraCargo(String c) {
        if(c != getCargo()) {
            this.cargoPretendido = c;
            return 0;
        } else {
            return 1;
        }
    }

    public int getCodigoMun() {
        return this.codigoMunicipio;
    }

    public String getMunicipio() {
        return this.municipio;
    }
    public int alteraMunicipio(String mun, int codmun) {
        if(mun != getMunicipio() && codmun != getCodigoMun()) {
            this.municipio = mun;
            this.codigoMunicipio = codmun;
            return 0;
        } else {
            return 1;
        }
    }

    public void mostrar() {
        System.out.println("**********************");
        System.out.println("Nome: " + getNome());
        System.out.println("Data de nascimento: " + getDataNascimento());
        System.out.println("Gênero: "+ getGenero());
        System.out.println("Bens totais declarados: " + getBens());
        System.out.println("Candidato a reeleição?: " + getReeleicao());
        System.out.println("Número do partido: " + getNumeroPartido());
        System.out.println("Cargo pretendido: " + getCargo());
    }
}