public class Funcionario {
    private String cpf;
    private String nome;
    private float salario;
    private float teto;

    public Funcionario(String cpf, String nome, float salario) {
        this.cpf = cpf;
        this.nome = nome;
        this.salario = salario;
        this.teto = 40000;
    }

    public float getTeto() {
        return teto;
    }

    private void setTeto(float teto) {
        this.teto = teto;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public float getSalario() {
        return salario;
    }

    public void setSalario(float salario) {
        this.salario = salario;
    }

    public boolean atribuiNovoTeto(float teto) {
        if(teto <= 0)
            throw new ErroAtribuicao("\nValor inválido de teto. Tente novamente.");
        else {
           setTeto(teto);
            return true;
        }
    }

    public void aumentaSalario(float porc) {
        if(porc < 0) {
            throw new ErroAtribuicao("\nValor inválido de salário. Tente novamente");
        } else if(porc*getSalario() > getTeto()) {
            throw new ErroAtribuicao("\nValor ultrapassa o teto. Tente novamente.");
        } else {
            setSalario(getSalario()*porc);
        }
    }

    public String toString() {
        return "\nNome: " + getNome() + "\nSalário: " + getSalario() + "\nTeto: " + getTeto() + "\nCPF: " + getCpf() + "\n______________________\n";
    }
}