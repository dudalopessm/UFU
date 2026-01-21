import java.io.Serializable;
import java.util.ArrayList;
import java.time.LocalDate;
import java.util.InputMismatchException;

public class Turma implements Serializable {
    //Atributos
    public int semestre;
    public int ano;
    private ArrayList<Estudante> membros = new ArrayList<Estudante>();
    private Professor profTitular;

    //Construtor
    public Turma(int semestre, int ano, Professor titular, ArrayList<Estudante> alunos) {
        setSemestre(semestre);
        verificaAno(ano);
        setProfTitular(titular);
        matriculaListaDeAlunos(alunos);
    }

    //Getters e setters
    public int getSemestre() {
        return semestre;
    }

    private void setSemestre(int semestre) {
        try {
            if(verificaSemestre(semestre)) {
                this.semestre = semestre;
            }
        } catch (SemestreInvalidoException e) {
            System.out.println("Erro: " + e.getMessage());
            this.semestre = 0;
        }
    }

    public int getAno() {
        return ano;
    }

    private void setAno(int ano) {
        try {
            if(verificaAno(ano)) {
                this.ano = ano;
            }
        } catch (DataInvalidaException e) {
            System.out.println("Erro: " + e.getMessage());
            this.ano = 0;
        }
    }

    public ArrayList<Estudante> getMembros() {
        return membros;
    }

    private void setMembros(ArrayList<Estudante> membros) {
        this.membros = membros;
    }
	

    public Professor getProfTitular() {
        return profTitular;
    }

    private void setProfTitular(Professor profTitular) {
        if(this.profTitular != null){
            this.profTitular.removeMinistada(this);
        }
        profTitular.setMinstradas(this);
        this.profTitular = profTitular;
    }

    //Impressão
    public String toString() {
        return "\nSemestre: "+ semestre + "\nAno: "+ ano + "\nProfessor: " + profTitular.getNome();
    }

    public void alunosDaTurma() {
        for(int i = 0; i < this.membros.size(); i++) {
            System.out.println( "----------------------------------------" + "\nNome do aluno: " + this.membros.get(i).getNome());
        }
    }

    //Verificação do semestre
    public boolean verificaSemestre(int sem) throws SemestreInvalidoException {
        if(sem != 1 && sem != 2)
            throw new SemestreInvalidoException("O semestre deve ser 1 ou 2.");
        return true;
    }

    public boolean isSemestreValido() {
        try {
            return verificaSemestre(this.semestre);
        } catch (SemestreInvalidoException e) {
            return false;
        }
    }

    public String getSemestreErrorMessage() {
        try {
            verificaSemestre(this.semestre);
            return null;
        } catch(SemestreInvalidoException e) {
            return e.getMessage();
        }
    }

    //Verifica se o ano é válido
    private boolean verificaAno(int ano) throws DataInvalidaException {
        int anoAtual = LocalDate.now().getYear();
        if (ano > anoAtual + 1) {
            throw new DataInvalidaException("O ano não pode ser maior que o próximo ano");
        }
        return true;
    }

    public boolean isAnoValido() {
        try {
            return verificaAno(this.ano);
        } catch (DataInvalidaException e) {
            return false;
        }
    }

    public String getAnoErrorMessage() {
        try {
            verificaAno(this.ano);
            return null;
        } catch(DataInvalidaException e) {
            return e.getMessage();
        }
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
            for(Estudante aux: membros) {
                aux.matriculaEstudanteEmUmaDisciplina(this);
            }
            return true;
    }

    protected boolean desmatriculaAluno(Estudante al) {
        if(this.getMembros().contains(al)) {
            al.desmatriculaEstudanteEmTurma(this);
            this.getMembros().remove(al);
            return true;
        } else {
            return false;
        }
    }
}