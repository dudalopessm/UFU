public class Empresa {
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
    public String nome;
    public int quantidadeFuncionarios;
    public Funcionario[] empregados;
    //construtor
    public Empresa(Funcionario[] func, int quantidadeFuncionarios, String nome) {
        this.quantidadeFuncionarios = quantidadeFuncionarios;
        this.nome = nome;
        this.empregados = new Funcionario[quantidadeFuncionarios];
        for(int i = 0; i < quantidadeFuncionarios; i++) {
            this.empregados[i] = new Funcionario(func[i].getNome(), func[i].getDataNascimento());
        }
    }
    //mostra funcionários sem cargos
    public void mostra() {
        System.out.println("\n------------------------------------ Quadro de funcionários da empresa " + nome + " ------------------------------------");
        for(Funcionario func : empregados) {
            System.out.println(func.toString());
        }
    }
    public static void main(String[]args) {
        Funcionario[] testeF = new Funcionario[8];
        testeF[0] = new Vendedor("Yasmin Ribeiro", "21/09/2001", 02, 2);
        testeF[1] = new Vendedor("Marcos Natan", "12/07/2004", 03, 3);
        testeF[2] = new Chefe("Bruno Mota", "21/08/1991", "Logística");
        testeF[3] = new Chefe("Taynara Estaniecki", "10/02/1988", "Marketing");
        testeF[4] = new Horistas("Sebastião Da Cruz", "30/06/1976", 34.5, 405.5);
        testeF[5] = new Horistas("Viviane Batista", "04/03/2000", 67.8, 200.8);
        testeF[6] = new Operarios("Cristiano Araújo", "31/07/1987", 4.5, 2000);
        testeF[7] = new Operarios("Maxswell Zonhyas", "03/03/1993", 3.5, 2345);
        Empresa teste = new Empresa(testeF, testeF.length, "Apollinário Soluções");
        FolhaPagamento folhaTeste = new FolhaPagamento(testeF, testeF.length);
        folhaTeste.retornaFolha(testeF);
    }
}