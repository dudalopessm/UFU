import java.util.ArrayList;
import java.time.LocalDate;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Turma {
    //Atributos
    public int semestre;
    public int ano;
    private ArrayList<Estudante> membros = new ArrayList<Estudante>();
    private Disciplinas disciplina = new Disciplinas();
    private Professor profTitular;

    //Construtor
    public Turma(int semestre, int ano, Disciplinas disc, Professor titular, ArrayList<Estudante> alunos) {
        verificaSemestre(semestre);
        verificaAno(ano);
        setDisciplina(disc);
        setProfTitular(titular);
        matriculaListaDeAlunos(alunos);
    }

    public Turma(Disciplinas disciplina) {
        this.disciplina = disciplina;
    }

    //Getters e setters
    public int getSemestre() {
        return semestre;
    }

    private void setSemestre(int semestre) {
        verificaSemestre(semestre);
    }

    public int getAno() {
        return ano;
    }

    private void setAno(int ano) {
        verificaAno(ano);
    }

    public ArrayList<Estudante> getMembros() {
        return membros;
    }

    private void setMembros(ArrayList<Estudante> membros) {
        this.membros = membros;
    }

    public Disciplinas getDisciplina() {
        return disciplina;
    }

    private void setDisciplina(Disciplinas disciplina) {
        this.disciplina = disciplina;
    }

    public Professor getProfTitular() {
        return profTitular;
    }

    private void setProfTitular(Professor profTitular) {
        this.profTitular = profTitular;
    }

    //Impressão
    public String toString() {
        return "\nDisciplina: " + disciplina.getNome() + "\nSemestre: "+ semestre + "\nAno: "+ ano + "\nProfessor: " + profTitular.getNome();
    }

    public void alunosDaTurma() {
        for(int i = 0; i < this.membros.size(); i++) {
            System.out.println( "----------------------------------------" + "\nNome do aluno: " + this.membros.get(i).getNome() + "\nMatrícula: " + this.membros.get(i).getLogin());
        }
    }

    //Verificação do semestre
    public void verificaSemestre(int sem) {
        Scanner sc = new Scanner(System.in);
        boolean veri = false;
        int input = sem;
        while(!veri) {
            try {
                if(input != 1 || input != 2)
                    throw new SemestreInvalidoException("O semestre deve ser 1 ou 2");

                this.semestre = input;
                veri = true;
            } catch(SemestreInvalidoException e) {
                System.out.println(e.getMessage());
                System.out.println("Digite um novo semestre (1 ou 2): ");
                try {
                    input = sc.nextInt();
                    sc.nextLine();
                } catch(InputMismatchException ee) {
                    System.out.println("Erro: digite apenas números.");
                    sc.nextLine();
                    veri = false;
                }
            }

        }
        sc.close();
    }

    //Verifica se o ano é válido
    private void verificaAno(int ano) {
        boolean veri = false;
        Scanner sc = new Scanner(System.in);
        int input = ano;
        while(!veri) {
            try {
                int anoAtual = LocalDate.now().getYear();

                if (input > anoAtual + 1) {
                    throw new DataInvalidaException("O ano não pode ser maior que o próximo ano");
                }

                this.ano = input;
                veri = true;
            } catch(DataInvalidaException e) {
                System.out.println(e.getMessage());
                System.out.println("Digite um ano novamente: ");
                try {
                    input = sc.nextInt();
                    sc.nextLine();
                } catch(InputMismatchException ee) {
                    System.out.println("Digite apenas números.");
                    sc.nextLine();
                }
            }
        }
        sc.close();
    }

    //Matrículas e desmatrículas de estudantes - só vou usar elas manipulando estudantes
    protected boolean matriculaUmAluno(Estudante al) {
        if(this.getMembros().isEmpty()) {
            this.getMembros().add(al);
            return true;
        } else {
            if(this.getMembros().contains(al)) {
                return false;
            } else {
                this.getMembros().add(al);
                return true;
            }
        }
    }

    protected boolean matriculaListaDeAlunos(ArrayList<Estudante> lista) {
        if(this.getMembros().isEmpty()) {
            this.getMembros().addAll(lista);
            return true;
        } else {
            for(int i = 0; i < lista.size(); i++) {
                if(!this.getMembros().contains(lista.get(i))) {
                    this.getMembros().add(lista.get(i));
                }
            }
        }
        if(this.getMembros().isEmpty())
            return false;
        else
            return true;
    }

    protected boolean desmatriculaAluno(Estudante al) {
        if(this.getMembros().contains(al)) {
            this.getMembros().remove(al);
            return true;
        } else {
            return false;
        }
    }

    //Mudanças cadastrais
    //Cadastro professor

}