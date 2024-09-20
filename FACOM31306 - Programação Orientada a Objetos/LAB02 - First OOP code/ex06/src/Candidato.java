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

    //construtores
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
    public Candidato() {
        //construtor padrão para auxiliar a busca do candidato rico, quero um objeto que inicie com tudo NULL ou 0
    }

    //setters e getters
    public void setNomeCompleto(String nomeCompleto) {
        this.nomeCompleto = nomeCompleto;
    }
    public void setDataNascimento(String dataNascimento) {
        this.dataNascimento = dataNascimento;
    }
    public void setGenero(String genero) {
        this.genero = genero;
    }
    public void setBens(double bens) {
        this.bens = bens;
    }
    public void setReeleicao(boolean reeleicao) {
        this.reeleicao = reeleicao;
    }
    public void setNumeroPartido(int numeroPartido) {
        this.numeroPartido = numeroPartido;
    }
    public void setCargoPretendido(String cargoPretendido) {
        this.cargoPretendido = cargoPretendido;
    }
    public void setCodigoMunicipio(int codigoMunicipio) {
        this.codigoMunicipio = codigoMunicipio;
    }
    public void setMunicipio(String municipio) {
        this.municipio = municipio;
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

    //mostra informações
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

    //destroi objeto para reutilização no vetor
    public void destroiCandidato() {
        setBens(0);
        setCargoPretendido(null);
        setCodigoMunicipio(0);
        setDataNascimento(null);
        setGenero(null);
        setMunicipio(null);
        setNomeCompleto(null);
        setNumeroPartido(0);
        setReeleicao(false);
    }
}