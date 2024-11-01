public class Ex04 {
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
    public static void main(String[]args) {
        System.out.println("------------------------------------ Classes descontextualizadas para explorar herança ------------------------------------");
        C1 ob1 = new C1("Duda", "983.938.374-98", "Feminino");
        C1 ob2 = new C1();
        C2 ob3 = new C2();
        C2 ob4 = new C2("22/08/2000", "MG-34.054.067", "67 mil reais/mês");
        C2 ob5 = new C2("Duda", "983.938.374-98", "Feminino", "22/01/2004", "MG-21.070.087", "0 reais/mês");
        C3 ob6 = new C3();
        C3 ob7 = new C3("Branco", "Estudante", false);
        C3 ob8 = new C3("22/07/1999", "MG-09.098.987", "5 mil reais/mês","Branco", "Estudante", false);
        C3 ob9 = new C3("Duda", "983.938.374-98", "Feminino", "22/01/2004", "MG-21.070.087", "30 mil reais/mês", "Branco", "Estudante", true);
        System.out.println("******************************");
        ob1.mostrar_atributos();
        System.out.println("******************************");
        ob2.mostrar_atributos_super();
        System.out.println("******************************");
        ob3.mostrar_atributos();
        System.out.println("******************************");
        ob4.mostrar_atributos();
        System.out.println("******************************");
        ob5.mostrar_atributos_super();
        System.out.println("******************************");
        ob5.mostrar_atributos();
        System.out.println("******************************");
        ob6.mostrar_atributos();
        System.out.println("******************************");
        ob7.mostrar_atributos_super();
        System.out.println("******************************");
        ob8.mostrar_atributos();
        System.out.println("******************************");
        ob9.mostrar_atributos();
        System.out.println("******************************");
        ob9.mostrar_atributos_super();
    }
}
