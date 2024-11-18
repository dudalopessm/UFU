import java.io.Serializable;
import java.util.ArrayList;
public class Disciplinas implements Serializable {
    //Atributos
    private String codigo;
    private String nome;
    private String cargaHoraria;
    private ArrayList<Turma> turma = new ArrayList<>();

    //Construtor
    public Disciplinas(String nome, String codigo, String cargaHoraria) {
        this.nome = nome;
        this.codigo = codigo;
        this.cargaHoraria = cargaHoraria;
    }

    //Getters e setters
    public void setTurma(ArrayList<Turma> turma) {
        for(Turma tur: turma){
            Turma aux = new Turma(tur.getSemestre(), tur.getAno(), tur.getProfTitular(),tur.getMembros());
            this.turma.add(aux);
            aux = null;
        }
    }
    public void setTurma(Turma turma) {
        Turma aux = new Turma(turma.getSemestre(), turma.getAno(), turma.getProfTitular(),turma.getMembros());
            this.turma.add(aux);
    }

    public void setTurma(int semestre, int ano, Professor titular, ArrayList<Estudante> alunos){
        Turma aux = new Turma(semestre, ano, titular, alunos);
        this.turma.add(aux);
    }

    public ArrayList<Turma> getTurmas(){
        return this.turma;
    }
    public String getCodigo() {
        return codigo;
    }

    private void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    public String getNome() {
        return nome;
    }

    private void setNome(String nome) {
        this.nome = nome;
    }

    public String getCargaHoraria() {
        return cargaHoraria;
    }

    private void setCargaHoraria(String cargaHoraria) {
        this.cargaHoraria = cargaHoraria;
    }

    //Mudanças cadastrais
    public boolean mudaNome(String novo) {
        if(this.nome.equalsIgnoreCase(novo)) {
            System.out.println("Nome anterior idêntico ao novo. Tente novamente.");
            return false;
        } else {
            setNome(novo);
            return true;
        }
    }
    public boolean mudaCodigo(String novo) {
        if(this.codigo.equalsIgnoreCase(novo)) {
            System.out.println("Código anterior idêntico ao novo. Tente novamente.");
            return false;
        } else {
            setCodigo(novo);
            return true;
        }
    }
    public boolean mudaCargaHoraria(String novo) {
        if(this.cargaHoraria.equalsIgnoreCase(novo)) {
            System.out.println("Carga horária anterior idêntico ao novo. Tente novamente.");
            return false;
        } else {
            setCargaHoraria(novo);
            return true;
        }
    }
}