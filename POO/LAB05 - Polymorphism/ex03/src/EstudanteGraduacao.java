public class EstudanteGraduacao extends Estudante {
    private String tituloTCC;

    public EstudanteGraduacao(String nome, String endereco, String tituloTCC) {
        super(nome, endereco);
        this.tituloTCC = tituloTCC;
    }

    public void print() {
        super.print();
        System.out.println("Estudante de graduação - Título do TCC: " + tituloTCC + ".");
    }

    public void print(boolean linha) {
        if(!linha)
            print();
        else {
            System.out.println(getNome()+"; "+ getEndereco() + "; " + getTituloTCC() + ".");
        }
    }

    public String getTituloTCC() {
        return tituloTCC;
    }

    public void setTituloTCC(String tituloTCC) {
        this.tituloTCC = tituloTCC;
    }
}
