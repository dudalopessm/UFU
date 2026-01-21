public class C1 {
        /*
- Teste de chamada de herança Faça um programa que contenha três classes: C1; C2; C/3
- A classe C1 é base da Classe C2, que por sua vez é base da Classe C3
- Para cada classe, inclua um atributo público, protegido e privado (pode ser de qualquer tipo)
- Para cada classe, construa um construtor padrão sem parâmetros e um construtor com parâmetros
- Nos construtores de cada classe, inclua um comando que imprime uma mensagem indicando a passagem pelo contrutor. Por exemplo,
para C1: "Classe C1: chamada do construtor padrao, sem parametros" "Classe C3: chamada do construtor com parametros"
- Na classe C3 inclua um construtor que use o "super" para chamar o construtor da classe C2 com parâmetro
- Em todas as classes, inclua um método que chama mostar_atributos, que mostra os valores de todos os atributos de um objeto (não utilizar super)
- Lembre que as classes herdam os atributos, inclusive os privados - e esses também devem ser mostrados
- Em todas as classes, inclua um método que chama mostar_atributos_super, que mostra os valores de todos os atributos de um objeto e que utilize super
     */
    public String nome;
    protected String genero;
    private String CPF;

    //construtores
    public C1() {
        System.out.println("Classe C1: chamada do construtor padrão, sem parâmetros");
    }
    public C1(String nome, String cpf, String genero) {
        this.nome = nome;
        this.CPF = cpf;
        this.genero = genero;
        System.out.println("Classe C1: chamada do construtor com parâmetros");
    }

    //get
    public String getCPF() {
        return CPF;
    }

    //mostrar dados
    public void mostrar_atributos() {
        System.out.println("Nome: " + nome);
        System.out.println("Gênero: " + genero);
        System.out.println("CPF: " + CPF);
    }
    public void mostrar_atributos_super() {
        System.out.println("Nome: " + nome);
        System.out.println("Gênero: " + genero);
        System.out.println("CPF: " + CPF);
    }
}
