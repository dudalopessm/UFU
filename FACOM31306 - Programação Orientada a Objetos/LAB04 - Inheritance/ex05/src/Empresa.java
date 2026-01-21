public class Empresa {
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
    public static void main(String[]args) {
        Vendedor vendedores[] = new Vendedor[2];
        Chefe chefes[] = new Chefe[2];
        Operarios operarios[] = new Operarios[2];
        Horistas horistas[] = new Horistas[2];
        System.out.println("\n------------------------------------ Quadro de funcionários da empresa Coca-Cola  ------------------------------------");
        vendedores[0] = new Vendedor("Yasmin Ribeiro", "21/09/2001", 02, 2);
        vendedores[1] = new Vendedor("Marcos Natan", "12/07/2004", 03, 3);
        chefes[0] = new Chefe("Bruno Mota", "21/08/1991", "Logística");
        chefes[1] = new Chefe("Taynara Estaniecki", "10/02/1988", "Marketing");
        horistas[0] = new Horistas("Sebastião Da Cruz", "30/06/1976", 34.5, 405.5);
        horistas[1] = new Horistas("Viviane Batista", "04/03/2000", 67.8, 200.8);
        operarios[0] = new Operarios("Cristiano Araújo", "31/07/1987", 4.5, 2000);
        operarios[1] = new Operarios("Maxswell Zonhyas", "03/03/1993", 3.5, 2345);
        for(Vendedor un : vendedores) {
            un.pagamento();
            System.out.println(un.toString());
        }
        for(Chefe un : chefes) {
            un.pagamento();
            System.out.println(un.toString());
        }
        for(Operarios un : operarios) {
            un.pagamento();
            System.out.println(un.toString());
        }
        for(Horistas un : horistas) {
            un.pagamento();
            System.out.println(un.toString());
        }
    }
}
