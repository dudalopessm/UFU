public class Funcionario {
        /*
- Uma empresa tem quatro tipos de funcionários: chefes, vendedores, operários e horistas. Cada um desses funcionários ganha seus salários
conforme regras distintas, apresentadas a seguir:
- Chefe: salário fixo e predefinido; Vendedor: valor fixo + comissão * vendas; Operario: valor por produção * quantidade produzida;
Horista: valor por hora * total de horas trabalhadas.
- Crie as classes correspondentes, adicionando atributos e métodos que achar necessários. A classe Funcionario deve incluir os campos privados nome,
dataNascimento e salario. Além disso, crie uma classe Empresa, que conterá o método main(). A empresa tem vários funcionários,
logo crie um vetor (array) para cada tipo de funcionário, instancie no mínimo 2 exemplos de cada tipo de funcionário.
- Mostre uma chamada para cálculo do salário
     */
    private String nome;
    private String dataNascimento;
    private double salario;

    //construtor
    public Funcionario(String nome, String dataNascimento) {
        this.nome = nome;
        this.dataNascimento = dataNascimento;
    }

    //gets e sets
    public String getNome() {
        return nome;
    }
    public String getDataNascimento() {
        return dataNascimento;
    }
    public double getSalario() {
        return salario;
    }
    protected void setSalario(double salario) {
        this.salario = salario;
    }

    //mostra dados
    @Override
    public String toString() {
        return "\nNome completo: " + nome  +
                "\nData de nascimento: " + dataNascimento +
                "\nSalário: " + salario;
    }
}