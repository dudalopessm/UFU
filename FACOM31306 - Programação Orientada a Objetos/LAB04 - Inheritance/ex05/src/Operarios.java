public class Operarios extends  Funcionario{
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
    private double valorProd;
    private int quantidadeProd;

    //construtor -> não possui salário fixo, então construtor com Funcionário sem a passagem do salário
    public Operarios(String nome, String dataNascimento, double valorProd, int quantidadeProd) {
        super(nome, dataNascimento);
        this.valorProd = valorProd;
        this.quantidadeProd = quantidadeProd;
    }

    //salário específico
    public void pagamento() {
        setSalario((valorProd)*(quantidadeProd));
    }

    //mostrar dados
    @Override
    public String toString() {
        return "\n************ Operário  ************" +
                "\nValor da produção: " + valorProd +
                "\nQuantidade produzida: " + quantidadeProd +
                super.toString();
    }
}