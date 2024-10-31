public class Familia extends Contato {
    private String parentesco;
    public Familia(String nome, String apelido, String email, String aniversario, String parentesco) {
        super(nome, apelido, email, aniversario);
        this.parentesco = parentesco;
    }

    public String getParentesco() {
        return parentesco;
    }

    public void setParentesco(String parentesco) {
        this.parentesco = parentesco;
    }

    public String imprimirContato() {
        return "\nGrau de parentesco: " + getParentesco();
    }
}