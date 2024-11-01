public class Ex01 {
    /*
- não utilizar herança no ex01
Relembre o exercício de uma prática anterior. Nele indicamos que os candidatos possuem seguintes informações: Nome Completo, Data de Nascimento, Gênero,
Total de Bens (em Reais), Candidato a reeleição (sim/não), número do partido, Cargo pretendido
- Assim, modifique o exercício de forma que sejam criadas duas classes. Uma chamada CandidatoPrefeito e outra CandidatoVereador. Essas classes devem
possuir todos os atributos antes listados (exceto Cargo Pretendido) e mais alguns, específicos de cada uma. Para prefeito, o nome e partido do
candidato a vice-prefeito. Para o vereador, o número de três dígitos (use string ao invés de tipos numéricos) e o bairro em que mora.
- Crie construtores que inicializam todos os atributos das classes. Crie também um método toString() para mostrar os dados dos candidatos.
- Faça um programa principal que cria um candidato a prefeito e um a vereador, e mostre os dados criados.
 */
    public static void main(String[]args) {
        System.out.println("------------------------------------ Vereadores e prefeitos ------------------------------------");
        CandidatoVereador vereador = new CandidatoVereador("Guilherme Fonseca Marques", "19/07/1971", "Masculino", 520070.00, false, "30888", "Caiçaras");
        System.out.println("\n"+vereador.toString());
        CandidatoPrefeito prefeito = new CandidatoPrefeito("Luís Eduardo Falcão Ferreira", "16/03/1984", "Masculino", 963218.45, true, 30, "Sandra Gomes", "30");
        System.out.println(prefeito.toString());
    }
}
