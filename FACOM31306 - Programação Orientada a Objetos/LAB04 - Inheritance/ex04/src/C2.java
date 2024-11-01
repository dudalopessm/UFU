public class C2 extends C1 {
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
    public String aniversario;
    protected String RG;
    private String renda;

    //construtores
    public C2() {
        System.out.println("Classe C2: chamada do construtor padrão, sem parâmetros");
    }
    public C2(String aniversario, String rg, String renda) {
        this.aniversario = aniversario;
        this.RG = rg;
        this.renda = renda;
        System.out.println("Classe C2: chamada do construtor com parâmetros de C2 e nenhum de C1");
    }
    public C2(String nome, String cpf, String genero, String aniversario, String rg, String renda) {
        super(nome, genero, cpf);
        this.aniversario = aniversario;
        this.RG = rg;
        this.renda = renda;
        System.out.println("Classe C2: chamada do construtor completo com parâmetros");
    }

    //get
    public String getRenda() {
        return renda;
    }

    //mostrar dados
    public void mostrar_atributos() {
        System.out.println("Nome: " + nome);
        System.out.println("Gênero: " + genero);
        System.out.println("CPF: " + getCPF());
        System.out.println("Aniversário: " + aniversario);
        System.out.println("RG: " + RG);
        System.out.println("Renda: " + renda);
    }
    public void mostrar_atributos_super() {
        super.mostrar_atributos_super();
        System.out.println("Aniversário: " + aniversario);
        System.out.println("RG: " + RG);
        System.out.println("Renda: " + renda);
    }
}
