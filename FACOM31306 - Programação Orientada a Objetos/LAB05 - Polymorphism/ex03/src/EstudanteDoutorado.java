public class EstudanteDoutorado extends EstudantePosGrad {
    String tituloTese;

    public EstudanteDoutorado(String nome, String endereco, String formacao,
                              String linhadDePesquisa, String tituloTese) {
        super(nome, endereco, formacao, linhadDePesquisa);
        this.tituloTese = tituloTese;
    }

    public void print() {
        super.print();
        System.out.println("Estudante de Doutorado" + "\nTítulo da tese: " + getTituloTese());
    }

    public void print(boolean linha) {
        if(!linha)
            print();
        else {
            System.out.println(getNome()+"; "+ getEndereco() + "; " + getTituloTese() + "; " + getFormacao() + "; " + getLinhaDePesquisa() + ".");
        }
    }

    public String getTituloTese() {
        return tituloTese;
    }

    public void setTituloTese(String tituloTese) {
        this.tituloTese = tituloTese;
    }
}
