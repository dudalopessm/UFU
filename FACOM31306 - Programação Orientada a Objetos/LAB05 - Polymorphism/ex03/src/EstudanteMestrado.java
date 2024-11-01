public class EstudanteMestrado extends EstudantePosGrad {
    private String tipo; // tipo pode ser acadêmico ou profisional
    private String tituloDissertacao;

    public EstudanteMestrado(String nome, String endereco, String formacao,
                             String linhadDePesquisa, String tipo, String tituloDissertacao) {
        super(nome, endereco, formacao, linhadDePesquisa);
        this.tipo = tipo;
        this.tituloDissertacao = tituloDissertacao;
    }

    public void print() {
        super.print();
        System.out.println("Estudante de Mestrado" + "\nTipo: " + getTipo() + " - Título da dissertação: " + getTituloDissertacao());
    }

    public void print(boolean linha) {
        if(!linha)
            print();
        else {
            System.out.println(getNome()+"; "+ getEndereco() + "; " + getTipo() + "; " + getTituloDissertacao() + "; " + getFormacao() + "; " + getLinhaDePesquisa() + ".");
        }
    }

    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public String getTituloDissertacao() {
        return tituloDissertacao;
    }

    public void setTituloDissertacao(String tituloDissertacao) {
        this.tituloDissertacao = tituloDissertacao;
    }
}
