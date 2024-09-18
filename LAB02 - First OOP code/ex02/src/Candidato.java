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

    public void setNome(String nome) {
        this.nomeCompleto = nome;
    }
    public String getNome() {
        return this.nomeCompleto;
    }
    public int alteraNome(String nome) {
        if(!nome.equals(getNome())) {
            setNome(nome);
            return 0;
        } else {
            return 1;
        }
    }

    public void setDataNascimento(String nas) {
        if(nas.charAt(2) == '/' && nas.charAt(5) == '/') {
            this.dataNascimento = nas;
        } else {
            System.out.println("Formato de data de nascimento inválido. Tente novamente.");
        }
    }
    public String getDataNascimento() {
        return this.dataNascimento;
    }
    public int alteraData(String data) {
        if(data != getDataNascimento()) {
            setDataNascimento(data);
            return 0;
        } else {
            return 1;
        }
    }

    public void setGenero(String gen) {
        if (gen.equalsIgnoreCase("masculino") || gen.equalsIgnoreCase("feminino") || gen.equalsIgnoreCase("não binário") || gen.equalsIgnoreCase("não informado")) {
            this.genero = gen;
        } else {
            System.out.println("Gênero não reconhecido. Tente novamente.");
        }
    }
    public String getGenero() {
        return this.genero;
    }
    public int alteraGenero(String gen) {
        if(gen != getGenero()) {
            setGenero(gen);
            return 0;
        } else {
            return 1;
        }
    }

    public void setBens(double bem) {
        this.bens = bem;
    }
    public double getBens() {
        return this.bens;
    }
    public int alteraBens(double bens) {
        if(bens != getBens()) {
            setBens(bens);
            return 0;
        } else {
            return 1;
        }
    }

    public void setReeleicao(boolean re) {
        this.reeleicao = re;
    }
    public boolean getReeleicao() {
        return this.reeleicao;
    }
    public int alteraReeleicao(boolean ree) {
        if(ree != getReeleicao()) {
            setReeleicao(ree);
            return 0;
        } else {
            return 1;
        }
    }

    public void setNumeroPartido(int num) {
        this.numeroPartido = num;
    }
    public int getNumeroPartido() {
        return this.numeroPartido;
    }
    public int alteraNumeroPart(int nump) {
        if(nump != getNumeroPartido()) {
            setNumeroPartido(nump);
            return 0;
        } else {
            return 1;
        }
    }

    public void setCargo(String cargo) {
        this.cargoPretendido = cargo;
    }
    public String getCargo() {
        return this.cargoPretendido;
    }
    public int alteraCargo(String c) {
        if(c != getCargo()) {
            setCargo(c);
            return 0;
        } else {
            return 1;
        }
    }

    public void setCodigoMun(int cod) {
        this.codigoMunicipio = cod;
    }
    public int getCodigoMun() {
        return this.codigoMunicipio;
    }

    public void setMunicipio(String mun) {
        this.municipio = mun;
    }
    public String getMunicipio() {
        return this.municipio;
    }
    public int alteraMunicipio(String mun, int codmun) {
        if(mun != getMunicipio() && codmun != getCodigoMun()) {
            setMunicipio(mun);
            setCodigoMun(codmun);
            return 0;
        } else {
            return 1;
        }
    }

    public void mostrar() {
        System.out.println("**********************");
        System.out.println("Município: " + getMunicipio());
        System.out.println("Código do município: " + getCodigoMun());
        System.out.println("Nome: " + getNome());
        System.out.println("Data de nascimento: " + getDataNascimento());
        System.out.println("Gênero: "+ getGenero());
        System.out.println("Bens totais declarados: " + getBens());
        System.out.println("Candidato a reeleição?: " + getReeleicao());
        System.out.println("Número do partido: " + getNumeroPartido());
        System.out.println("Cargo pretendido: " + getCargo());
    }
}
