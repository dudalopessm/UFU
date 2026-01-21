public class FolhaPagamento {
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
    public double salarios[];
    public int quantidadeFuncionarios;
    public FolhaPagamento(Funcionario[] lista, int quantidadeFuncionarios) {
        this.quantidadeFuncionarios = quantidadeFuncionarios;
        this.salarios = new double[quantidadeFuncionarios];
        for(int i = 0; i < lista.length; i++) {
            lista[i].pagamento();
            salarios[i] = lista[i].getSalario();
        }
    }

    public void retornaFolha(Funcionario[] func) {
        for(int i = 0; i < this.salarios.length; i++) {
            System.out.println("O salário do(a) funcionário(a) " + func[i].getNome() + " é de R$" + salarios[i] + ".");
        }
    }
}
