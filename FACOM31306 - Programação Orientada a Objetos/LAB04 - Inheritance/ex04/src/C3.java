public class C3 extends C2 {
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
    public String etnia;
    protected String ocupacao;
    private boolean irmaos;

    //construtores
    public C3() {
        System.out.println("Classe C3: chamada do construtor padrão, sem parâmetros");
    }
    public C3(String etnia, String ocupacao, boolean irmaos) {
        this.etnia = etnia;
        this.ocupacao = ocupacao;
        this.irmaos = irmaos;
        System.out.println("Classe C3: chamada do construtor de C3 com parâmetros, C2 padrão e C1 padrão");
    }
    public C3(String aniversario, String rg, String renda, String etnia, String ocupacao, boolean irmaos) {
        super(aniversario, rg, renda);
        this.etnia = etnia;
        this.ocupacao = ocupacao;
        this.irmaos = irmaos;
        System.out.println("Classe C3: chamada do construtor de C2 com parâmetros e C3 com parâmetros");
    }
    public C3(String nome, String cpf, String genero, String aniversario, String rg, String renda, String etnia, String ocupacao, boolean irmaos) {
        super(nome, genero, cpf, aniversario, rg, renda);
        this.etnia = etnia;
        this.ocupacao = ocupacao;
        this.irmaos = irmaos;
        System.out.println("Classe C3: chamada do construtor de C2 com parâmetros, C1 com parâmetros e C3 com parâmetros - completo");
    }

    //mostrar dados
    public void mostrar_atributos() {
        System.out.println("Nome: " + nome);
        System.out.println("Gênero: " + genero);
        System.out.println("CPF: " + getCPF());
        System.out.println("Aniversário: " + aniversario);
        System.out.println("RG: " + RG);
        System.out.println("Renda: " + getRenda());
        System.out.println("Etnia: " + etnia);
        System.out.println("Ocupação: " + ocupacao);
        System.out.println("Possui irmãos?: " + irmaos);
    }
    public void mostrar_atributos_super() {
        super.mostrar_atributos_super();
        System.out.println("Etnia: " + etnia);
        System.out.println("Ocupação: " + ocupacao);
        System.out.println("Possui irmãos?: " + irmaos);
    }
}
