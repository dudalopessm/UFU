import java.io.Serializable;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.ArrayList;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.util.Scanner;
//Jansi: https://github.com/fusesource/jansi
import org.fusesource.jansi.Ansi;
import static org.fusesource.jansi.Ansi.ansi;

    public class Universidade implements Serializable {
        public String nome;
        public String dataFundacao;
        public ArrayList<Disciplinas> disciplinas = new ArrayList<Disciplinas>();
        public ArrayList<Professor> professores = new ArrayList<Professor>();
        public ArrayList<Estudante> estudantes = new ArrayList<Estudante>();

        public Universidade(String nome, String dataFundacao) {
            this.nome = nome;
            this.dataFundacao = dataFundacao;
        }

        public String getDataFundacao() {
            return this.dataFundacao;
        }

        public void setDataFundacao(String data) {
            try {
                if(ValidacaoDataNasc.dataValida(data)) {
                    DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
                    LocalDate.parse(data, formatter);
                    this.dataFundacao = data;
                } else {
                    throw new IllegalArgumentException("Data de fundação deve estar no formato dd/mm/aaaa");
                }
            } catch(DateTimeParseException e) {
                throw new IllegalArgumentException("Data de fundação inválida.");
            }
        }

        public String getNome() {
            return nome;
        }

        public void setNome(String nome) {
            this.nome = nome;
        }

        //Try with resources: https://pt.stackoverflow.com/questions/172909/como-funciona-o-try-with-resources, https://www.baeldung.com/java-try-with-resources
        public void escreverUniversidade(String nomeArq){
            try (FileOutputStream arq = new FileOutputStream(nomeArq); ObjectOutputStream os = new ObjectOutputStream(arq)) {
                os.writeObject(this);
                System.out.println("Dados salvos com sucesso no arquivo: " + nomeArq);

            } catch (IOException e) {
                System.err.println("Erro ao escrever no arquivo: " + nomeArq);
                e.printStackTrace();
            }
        }

        public static void popularUni(Universidade uni) {
        Professor aux = new Professor("Carlos Sergio", "12/11/1975", "700.179.826-69", "Facom", "15/12/2018", uni);
        uni.professores.add(aux);
        aux = new Professor("Maria da Silva", "05/03/1982", "876.543.210-06", "Fafich", "20/01/2021", uni);
        uni.professores.add(aux);
        aux = new Professor("João Paulo", "28/07/1968", "123.456.789-09", "Farmácia", "10/06/2018", uni);
        uni.professores.add(aux);
        aux = new Professor("Ana Beatriz", "18/10/1990", "987.654.321-00", "Medicina", "01/09/2023", uni);
        uni.professores.add(aux);
        aux = new Professor("Pedro Henrique", "02/04/1979", "456.789.012-02", "Engenharia", "18/03/2019", uni);
        uni.professores.add(aux);
        aux = new Professor("Laura Santos", "25/12/1985", "789.012.345-02", "Direito", "05/07/2022", uni);
        uni.professores.add(aux);
        aux = new Professor("Ricardo Almeida", "11/06/1995", "321.654.987-08", "Ciências", "28/11/2020", uni);
        uni.professores.add(aux);
        aux = new Professor("Juliana Oliveira", "09/09/1972", "654.321.987-04", "Educação Física", "15/04/2017", uni);
        uni.professores.add(aux);
        aux = new Professor("Rafael Costa", "17/08/1988", "147.258.369-60", "Música", "30/05/2023", uni);
        uni.professores.add(aux);
        aux = new Professor("Camila Ferreira", "22/05/1992", "581.364.792-70", "Letras", "20/10/2016", uni);
        uni.professores.add(aux);
        Estudante est = new Estudante_Graduacao("Lucas Matos", "05/04/2006", "540.544.334-33", 86.3, "QTI");
        uni.estudantes.add(est);
        est = new Estudante_Graduacao("Maria Silva", "12/11/2005", "123.456.789-09", 78.9, "fisk");
        uni.estudantes.add(est);
        est = new Estudante_Graduacao("João Souza", "28/07/2004", "987.654.321-00", 92.5, "Drumind edificios");
        uni.estudantes.add(est);
        est = new Estudante_Graduacao("Ana Santos", "15/03/2007", "456.789.012-02", 81.2, "UBS");
        uni.estudantes.add(est);
        est = new Estudante_Graduacao("Pedro Oliveira", "02/09/2006", "789.012.345-02", 75.0, "VTR");
        uni.estudantes.add(est);
        est = new Estudante_Graduacao("Laura Almeida", "21/06/2005", "321.654.987-08", 95.8, "Sankha");
        uni.estudantes.add(est);
        est = new Estudante_Graduacao("Ricardo Costa", "18/10/2007", "654.321.987-04", 88.1, "Drogasil");
        uni.estudantes.add(est);
        est = new Estudante_Graduacao("Juliana Ferreira", "05/05/2004", "147.258.369-60", 72.7, "Lar Doce");
        uni.estudantes.add(est);
        est = new Estudante_Graduacao("Rafael Santos", "11/12/2006", "581.364.792-70", 90.0, "NTT Data");
        uni.estudantes.add(est);
        est = new Estudante_Graduacao("Camila Costa", "29/08/2005", "258.369.147-81", 84.6, "Lumini");
        uni.estudantes.add(est);
        Estudante_PosGraduacao grad = new Estudante_PosGraduacao("Maria Luiza", "15/06/2002", "658.658.453-53", 59.3, "Arodinamica das vacas");
        uni.estudantes.add(grad);
        grad = new Estudante_PosGraduacao("João Pedro", "20/03/1998", "123.456.789-09", 82.1, "Desenvolvimento de algoritmos de aprendizado de máquina para diagnóstico médico");
        uni.estudantes.add(grad);
        grad = new Estudante_PosGraduacao("Ana Clara", "01/11/2000", "987.654.321-00", 75.5, "O papel da biodiversidade na mitigação das mudanças climáticas");
        uni.estudantes.add(grad);
        grad = new Estudante_PosGraduacao("Pedro Henrique", "10/07/1999", "456.789.012-02", 90.8, "Análise da eficiência energética em edifícios sustentáveis");
        uni.estudantes.add(grad);
        grad = new Estudante_PosGraduacao("Laura Beatriz", "25/12/2001", "789.012.345-02", 68.2, "Estudos sobre a influência da mídia social no comportamento do consumidor");
        uni.estudantes.add(grad);
        grad = new Estudante_PosGraduacao("Ricardo Silva", "18/05/1997", "321.654.987-08", 85.9, "Investigação sobre novas terapias para doenças neurodegenerativas");
        uni.estudantes.add(grad);
        grad = new Estudante_PosGraduacao("Juliana Oliveira", "08/09/1996", "654.321.987-04", 78.0, "Modelagem matemática de sistemas ecológicos");
        uni.estudantes.add(grad);
        grad = new Estudante_PosGraduacao("Rafael Santos", "15/04/2001", "147.258.369-60", 92.3, "O impacto da globalização na economia brasileira");
        uni.estudantes.add(grad);
        grad = new Estudante_PosGraduacao("Camila Souza", "22/10/2000", "581.364.792-70", 71.6, "Desenvolvimento de novos materiais para aplicações em energia renovável");
        uni.estudantes.add(grad);
        grad = new Estudante_PosGraduacao("Daniel Ferreira", "03/02/1999", "258.369.147-81", 88.7, "Estudos sobre a diversidade genética de espécies ameaçadas de extinção");
        uni.estudantes.add(grad);
    }

        //Fonte: https://cursos.alura.com.br/forum/topico-como-limpar-o-console-no-java-162798
        public final static void clearConsole() {
            try
            {
                final String os = System.getProperty("os.name");

                if (os.contains("Windows"))
                {
                    Runtime.getRuntime().exec("cls");
                }
                else
                {
                    Runtime.getRuntime().exec("clear");
                }
            }
            catch (final Exception e)
            {
                //  Handle any exceptions.
            }
        }

        public static void esperarTecla(Scanner scanner) {
            System.out.println("Pressione qualquer tecla para continuar...");
            scanner.nextLine();
        }

        public static int inicio(Scanner scanner, Universidade uni) {
            System.out.println(ansi().fgRgb(255, 180, 231).a("===================================== Gestão da Universidade " + uni.getNome() + " =====================================").reset());
            System.out.println(ansi().fgRgb(255, 180, 235).a("Opções disponíveis: ").reset());
            System.out.println(ansi().fgRgb(255, 234, 247).a("0. Sair").reset());
            System.out.println(ansi().fgRgb(255, 234, 247).a("1. Consultar um aluno, professor, disciplina ou turma").reset());
            System.out.println(ansi().fgRgb(255, 234, 247).a("2. Cadastro de aluno, professor, disciplina ou turma").reset());
            System.out.println(ansi().fgRgb(255, 234, 247).a("3. Mudança cadastral nos dados de um aluno ou professor").reset());
            System.out.println(ansi().fgRgb(255, 234, 247).a("Digite a opção desejada: ").reset());
            int op = scanner.nextInt();
            scanner.nextLine();
            while(op < 0 || op > 3) {
                System.out.println(ansi().fgRgb(255, 234, 247).a("A opção deve estar 0 e 3. Digite novamente: ").reset());
                op = scanner.nextInt();
                scanner.nextLine();
            }
            return op;
        }

        public static int menuConsulta(Scanner scanner, Universidade uni) {
            int op;
            System.out.println(ansi().fgRgb(255, 234, 247).a("_*_*_*_*_*_*_*_*_*_*_* Menu de Consulta _*_*_*_*_*_*_*_*_*_*_*").reset());
            System.out.println(ansi().fgRgb(255, 180, 235).a("Opções disponíveis: ").reset());
            System.out.println(ansi().fgRgb(255, 234, 247).a("0. Sair").reset());
            System.out.println(ansi().fgRgb(255, 234, 247).a("1. Consultar um aluno").reset());
            System.out.println(ansi().fgRgb(255, 234, 247).a("2. Consultar um professor").reset());
            System.out.println(ansi().fgRgb(255, 234, 247).a("3. Consultar uma disciplina").reset());
            System.out.println(ansi().fgRgb(255, 234, 247).a("4. Consultar uma turma").reset());
            op = scanner.nextInt();
            scanner.nextLine();
            while(op < 0 || op > 4) {
                System.out.println(ansi().fgRgb(255, 234, 247).a("A opção deve estar 0 e 4. Digite novamente: ").reset());
                op = scanner.nextInt();
                scanner.nextLine();
            }
            return op;
        }

        public static int consultarAlunos(Scanner scanner, Universidade uni) {
            System.out.println(ansi().fgRgb(255, 234, 247).a("============ Consulta de alunos ============").reset());
            System.out.println(ansi().fgRgb(255, 234, 247).a("Opções: ").reset());
            System.out.println(ansi().fgRgb(255, 234, 247).a("0. Retornar ao menu de consulta").reset());
            System.out.println(ansi().fgRgb(255, 234, 247).a("1. Consultar todos os alunos da universidade").reset());
            System.out.println(ansi().fgRgb(255, 234, 247).a("2. Consultar todos os alunos de uma turma").reset());
            System.out.println(ansi().fgRgb(255, 234, 247).a("3. Consultar um aluno específico").reset());
            int op;
            op = scanner.nextInt();
            scanner.nextLine();
            while(op < 0 || op > 3) {
                System.out.println(ansi().fgRgb(255, 234, 247).a("A opção deve estar 0 e 3. Digite novamente: ").reset());
                op = scanner.nextInt();
                scanner.nextLine();
            }
            return op;
        }

        public static int menuCadastro(Scanner scanner, Universidade uni) {
            int op;
            System.out.println(ansi().fgRgb(255, 234, 247).a("_*_*_*_*_*_*_*_*_*_*_* Menu de Cadastro _*_*_*_*_*_*_*_*_*_*_*").reset());
            System.out.println(ansi().fgRgb(255, 180, 235).a("Opções disponíveis: ").reset());
            System.out.println(ansi().fgRgb(255, 234, 247).a("0. Sair").reset());
            System.out.println(ansi().fgRgb(255, 234, 247).a("1. Cadastrar um aluno").reset());
            System.out.println(ansi().fgRgb(255, 234, 247).a("2. Cadastrar um professor").reset());
            System.out.println(ansi().fgRgb(255, 234, 247).a("3. Cadastrar uma disciplina").reset());
            System.out.println(ansi().fgRgb(255, 234, 247).a("4. Cadastrar uma turma").reset());
            op = scanner.nextInt();
            scanner.nextLine();
            while(op < 0 || op > 4) {
                System.out.println(ansi().fgRgb(255, 234, 247).a("A opção deve estar 0 e 4. Digite novamente: ").reset());
                op = scanner.nextInt();
                scanner.nextLine();
            }
            return op;
        }

        public static int menuMudanca(Scanner scanner, Universidade uni) {
            int op;
            System.out.println(ansi().fgRgb(255, 234, 247).a("_*_*_*_*_*_*_*_*_*_*_* Mudança Cadastral _*_*_*_*_*_*_*_*_*_*_*").reset());
            System.out.println(ansi().fgRgb(255, 180, 235).a("Opções disponíveis: ").reset());
            System.out.println(ansi().fgRgb(255, 234, 247).a("0. Sair").reset());
            System.out.println(ansi().fgRgb(255, 234, 247).a("1. Mudar informações de um aluno").reset());
            System.out.println(ansi().fgRgb(255, 234, 247).a("2. Mudar informações de um professor").reset());
            op = scanner.nextInt();
            scanner.nextLine();
            while(op < 0 || op > 2) {
                System.out.println(ansi().fgRgb(255, 234, 247).a("A opção deve estar 0 e 2. Digite novamente: ").reset());
                op = scanner.nextInt();
                scanner.nextLine();
            }
            return op;
        }

    public static void main(String args[]) {
        Universidade ufu = new Universidade("UFU", "01/11/2015");
        Universidade.popularUni(ufu);
        //ufu.escreverUniversidade("baseDedados");
        Scanner sc = new Scanner(System.in);
        int controle;
        int op;
        do {
            Universidade.clearConsole();
            controle = Universidade.inicio(sc, ufu);
            switch(controle) {
                default:
                    break;
                case 0:
                    System.out.println(ansi().fgRgb(255, 234, 247).a("Saindo...").reset());
                    break;
                case 1:
                    do {
                        op = menuConsulta(sc, ufu);
                        switch (op) {
                            default:
                                break;
                            case 0:
                                System.out.println(ansi().fgRgb(255, 234, 247).a("Saindo da consulta...").reset());
                                break;
                            case 1:
                                do {
                                    controle = Universidade.consultarAlunos(sc, ufu);
                                    switch(controle) {
                                        default:
                                            break;
                                        case 0:
                                            System.out.println(ansi().fgRgb(255, 234, 247).a("Retornando...").reset());
                                            break;
                                        case 1:
                                            System.out.println(ansi().fgRgb(255, 234, 247).a("---------------------------- Todos os alunos da universidade " + ufu.getNome() + " ----------------------------").reset());
                                            //mostra alunos
                                            Universidade.esperarTecla(sc);
                                            break;
                                        case 2:
                                            System.out.println(ansi().fgRgb(255, 234, 247).a("Digite o nome da disciplina que deseja consultar: ").reset());
                                            String nomeDisc = sc.nextLine();
                                            //faz a busca aqui
                                            System.out.println(ansi().fgRgb(255, 234, 247).a("---------------------------- Alunos da turma " + ufu.getNome() + " ----------------------------").reset());
                                            //mostra aqui
                                            Universidade.esperarTecla(sc);
                                            break;
                                        case 3:
                                            System.out.println(ansi().fgRgb(255, 234, 247).a("Digite o nome do aluno que deseja consultar: ").reset());
                                            String nomeAlun = sc.nextLine();
                                            //busca aqui
                                            System.out.println(ansi().fgRgb(255, 234, 247).a("---------------------------- Aluno " + ufu.getNome() + " ----------------------------").reset());
                                            //mostra aqui
                                            Universidade.esperarTecla(sc);
                                            break;
                                    }
                                }while(controle != 0);
                                break;
                            case 2:
                                break;
                            case 3:
                                break;
                            case 4:
                                break;

                        }
                        Universidade.esperarTecla(sc);
                    } while(op != 0);
                    break;
                case 2:
                    op = Universidade.menuCadastro(sc, ufu);
                    switch (op) {
                        default:
                            break;
                        case 0:
                            System.out.println(ansi().fgRgb(255, 234, 247).a("Saindo do menu de cadastro...").reset());
                            break;
                        case 1:
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        case 4:
                            break;

                    }
                    Universidade.esperarTecla(sc);
                    break;
                case 3:
                    op = Universidade.menuMudanca(sc, ufu);
                    switch (op) {
                        default:
                            break;
                        case 0:
                            System.out.println(ansi().fgRgb(255, 234, 247).a("Saindo do menu de mudanças cadastrais...").reset());
                            break;
                        case 1:
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        case 4:
                            break;

                    }
                    Universidade.esperarTecla(sc);
                    break;
            }

        }while(controle != 0);
        sc.close();
    }
}