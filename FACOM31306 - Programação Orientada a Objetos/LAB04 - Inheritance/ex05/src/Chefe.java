public class Chefe extends Funcionario {
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
    private String tipoSetor;
    private double salario = 10000;

    //construtor -> every chefe recebe 10 mil, então o salário não é passado no construtor
    public Chefe(String nome, String dataNascimento, String tipoSetor) {
        super(nome, dataNascimento);
        this.tipoSetor = tipoSetor;
    }

    //salário específico
    public void pagamento() {
        setSalario(salario);
    }

    //mostra dados
    @Override
    public String toString() {
        return "\n************ Chefe do setor " + tipoSetor + " ************" +
                super.toString();
    }
}