import java.util.ArrayList;
public class Disciplinas implements ConvertString{
    //Atributos
    private String codigo;
    private String nome;
    private String cargaHoraria;
    private ArrayList<Turma> turmas = new ArrayList<>();

    //Construtor
    public Disciplinas(String nome, String codigo, String cargaHoraria) {
        this.nome = nome;
        this.codigo = codigo;
        this.cargaHoraria = cargaHoraria;
    }

    //Getters e setters
    public String getCodigo() {
        return codigo;
    }
    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }
    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public String getCargaHoraria() {
        return cargaHoraria;
    }
    public void setCargaHoraria(String cargaHoraria) {
        this.cargaHoraria = cargaHoraria;
    }

    public String toString() {
        String disSTR = "Codigo: "+ this.getCodigo()+"\nNome: "+ this.getNome()+"\nCarga Horaria: "+ this.getCargaHoraria();
        for(Turma aux: turmas){
            disSTR += aux.toString();
        }
        return disSTR;
    }

    //Mudanças cadastrais
    public boolean criaTurma(String semestre, int ano){
        Turma nova = new Turma(semestre, ano);
        return turmas.add(nova);
    }

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