public class Main {
    /*
- Copie o exemplo Estudante disponível na pasta 'samples/polimorfismo'. Crie uma classe Universidade,
que tem como propriedade o nome da Universidade e a data de Fundação. A universidade possui no máximo 100 alunos,
que podem ser de graduação e pós-graduação.
- (a) Crie um método que mostra quantos estudantes de graduação, mestrado e doutorado a Universidade possui (para facilitar,
é permitido instanciar os alunos no próprio código)
- (b) Mostre as informações do nome de todos os alunos e, no caso de aluno de doutorado, mostrar adicionalmente o título da tese a linha de pesquisa
- (c) Crie um novo vetor e copie para ele todos os alunos de pós-graduação (somente a cópia da referência do objeto - não há necessidade
de duplicar o objeto na memória). Percorra o vetor e mostre as informações completas dos alunos.
- (d) Faça, para as classes de estudante de graduação, estudante de mestrado e estudante de doutorado, uma sobrecarga do método print(),
fazendo receber como parâmetro um valor booleano que indica se o print será na mesma linha ou em várias linhas. No caso da mesma linha,
são mostrados todos os atributos da classe separados por ponto e vírgula. No caso de várias linhas, cada atributo é exibido em uma linha diferente.
- (e) Referente ao exercício anterior, é possível utilizar o recém criado método print(boolean) em um polimorfismo tendo como base
um vetor da classe Estudante? Justifique. Caso não seja possível, altere somente o código da classe Estudante para que passe a ser possível.
O que ocorre neste caso com a classe Estudante de Pós-graduação?
RESPOSTA: Não é possível. No jeito que fiz, o método print(boolean linha) só estava presente nas classes filhas de EstudantePosGrad e Estudante, mas não nas superclasses
e isso faria com que o método não funcionasse. Então, devo declará-lo na superclasse Estudante e na classe EstudantePosGrad, e assim devo sobrescrevê-lo para
incluir o comportamento específico da pós-graduação.
     */
    public static void main(String[] args) {
        Estudante listateste[] = new Estudante[10];
        listateste[0] = new EstudanteGraduacao("Carlos","Rua 1o de Abril", "Assembly is hard");
        listateste[1] = new EstudanteGraduacao("Maria", "Rua Maio", "Java is funny");
        listateste[2] = new EstudantePosGrad("Ailton","Rua 31 de fevereiro","Engenharia","Banco de Dados");
        listateste[3] = new EstudanteMestrado("Carla","Rua Primavera","Medicina","Vacinas de RNA", "Anticorpos","academico");
        listateste[4] = new EstudanteDoutorado("Bruno","Rua Inverno","Tecnologia","Processamento de Imagens","Carros Inteligentes");
        listateste[5] = new EstudanteGraduacao("Joana", "Rua Estrela", "I love C++");
        listateste[6] = new EstudantePosGrad("Paulo", "Rua Sol", "Matemática", "Teoria dos Números");
        listateste[7] = new EstudanteMestrado("Fernanda", "Rua Neve", "Biologia", "Clonagem", "DNA", "laboratorial");
        listateste[8] = new EstudanteDoutorado("Gustavo", "Rua Lua", "Física", "Astrofísica", "Buracos Negros");
        listateste[9] = new EstudanteDoutorado("Ana", "Rua Vento", "Química", "Reações Orgânicas", "Síntese de Fármacos");
        Universidade ufu = new Universidade("Universidade Federal de Ubatuba", "09/09/1989", 10, listateste);
        System.out.println("\n/////////////////////////////////////////////////////////////////////////////");
        System.out.println("\n****************** QUANTIDADE DE ALUNOS NA UNIVERSIDADE ******************");
        ufu.contaAlunos(listateste);
        System.out.println("\n/////////////////////////////////////////////////////////////////////////////");
        ufu.mostraAlunos();
        System.out.println("/////////////////////////////////////////////////////////////////////////////");
        int contador = 0;
        for(Estudante elemento : listateste) {
            if (elemento instanceof EstudantePosGrad)
                contador++;
        }
        Estudante listaPosgrad[] = new Estudante[contador];
        int j = 0;
        for(int i = 0; i < listateste.length; i++) {
            if(listateste[i] instanceof EstudantePosGrad) {
                listaPosgrad[j] = listateste[i];
                j++;
            }
        }
        System.out.println("\n************************ ESTUDANTES DA PÓS ************************");
        System.out.println("\n/////////////////////////////////////////////////////////////////////////////");
        for(Estudante elemento : listaPosgrad) {
            if(elemento != null) {
                elemento.print();
                elemento.print(true); //quando o boolean é true mostra todos em uma linha só
                System.out.println("\n/////////////////////////////////////////////////////////////////////////////");
            }
        }
    }
}