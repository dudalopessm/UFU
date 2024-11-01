public class Funcionario {
    /*
- Uma empresa tem quatro tipos de funcionários: chefes, vendedores, operários e horistas.
- Cada um desses funcionários ganha seus salários conforme regras distintas, apresentadas a seguir:
- Chefe: salário fixo e predefinido; Vendedor: valor fixo + comissão X vendas; Operario: valor por produção X quantidade produzida;
Horista: valor por hora X total de horas trabalhadas.
- Crie as classes correspondentes, adicionando atributos e métodos que achar necessário. A classe Funcionario deve incluir
os campos privados nome, dataNascimento e salario. Além disso, crie uma classe Empresa, que conterá o método main().
A empresa tem vários funcionários, logo crie um vetor (array) de funcionários. Adicione a ele ao menos um tipo de
cada funcionário definido anteriormente. Criar também uma classe {FolhaPagamento}, que lê dados referentes ao conjunto
de empregados de uma empresa e mostra a folha de pagamento da empresa.
- Criar o vetor utilizando variáveis do tipo Funcionário, mas instancie os objetos com elementos das subclasses de
Funcionario (polimorfismo)
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

    public void pagamento() {
    }

    //mostra dados
    @Override
    public String toString() {
        return "\nNome completo: " + nome  +
                "\nData de nascimento: " + dataNascimento +
                "\nSalário: " + salario;
    }
}