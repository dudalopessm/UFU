import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;

public abstract class Estudante extends Dados_Pessoa{
    private double CRA;
    private ArrayList<Turma> turmasMatriculadas = new ArrayList<Turma>();
    
    //Construtor
    public Estudante(String login, String nome, String data, String CPF, double CRA){
        super(login, nome, data, CPF);
        setCRA(CRA);
    }

    public Estudante(String login, String nome, String data, String CPF, double CRA, ArrayList<Turma> turmasMatriculadas) {
        super(login, nome, data, CPF);
        setCRA(CRA);
        matriculaEstudanteEmDisciplinas(turmasMatriculadas);
    }

    //Getters e setters
    public double getCRA() {
        return this.CRA;
    }

    private void setCRA(double cra) {
        Scanner sc = new Scanner(System.in);
        boolean veri = false;
        double input = cra;
        while(!veri) {
            try {
                verificaCRA(cra);
                this.CRA = cra;
                veri = true;
            } catch(CRAInvalidoException e) {
                System.out.println(e.getMessage());
                System.out.println("Digite o CRA novamente, de 0 a 100: ");
                try {
                    cra = sc.nextDouble();
                } catch(InputMismatchException ee) {
                    System.out.println("Digite um número válido.");
                    sc.nextLine();
                }
            }
        }
    }

    public ArrayList<Turma> getTurmasMatriculadas() {
        return turmasMatriculadas;
    }

    private void setTurmasMatriculadas(ArrayList<Turma> turmasMatriculadas) {
        this.turmasMatriculadas = turmasMatriculadas;
    }

    @Override
    public String toString(){
        return super.toString() + "\nCRA: " + this.CRA;
    }

     //Verifica se CRA é número entre 0 e 100
     public boolean verificaCRA(double cra) throws CRAInvalidoException {
        if(cra < 0 || cra > 100) {
            throw new CRAInvalidoException("CRA deve estar entre 0 e 100.");
        }
        return true;
    }

    //Mudanças cadastrais
    public boolean mudaCRA(double cra) {
        if(verificaCRA(cra)) {
            setCRA(cra);
            return true;
        }
        return false;
    }

    //Matrícula e desmatricula
    public boolean matriculaEstudanteEmDisciplinas(ArrayList<Turma> disc) {
        if(this.getTurmasMatriculadas().isEmpty()) {
            for(int i = 0; i < disc.size(); i++)
                disc.get(i).matriculaUmAluno(this);
            this.getTurmasMatriculadas().addAll(disc);
            return true;
        } else {
            for(int i = 0; i < disc.size(); i++) {
                if(!this.getTurmasMatriculadas().contains(disc.get(i))) {
                    disc.get(i).matriculaUmAluno(this);
                    this.getTurmasMatriculadas().add(disc.get(i));
                }
            }
        }
        if(this.getTurmasMatriculadas().isEmpty())
            return false;
        else
            return true;
    }

    public boolean matriculaEstudanteEmUmaDisciplina(Turma disc) {
        if(this.getTurmasMatriculadas().isEmpty()) {
            disc.matriculaUmAluno(this);
            this.getTurmasMatriculadas().add(disc);
            return true;
        } else {
            if(this.getTurmasMatriculadas().contains(disc))
                return false;
            else {
                disc.matriculaUmAluno(this);
                this.getTurmasMatriculadas().add(disc);
                return true;
            }
        }
    }

    public boolean desmatriculaEstudanteEmDisciplina(Turma disc) {
        if(this.getTurmasMatriculadas().contains(disc)) {
            disc.desmatriculaAluno(this);
            this.getTurmasMatriculadas().remove(disc);
            return true;
        } else {
            return false;
        }
    }
}