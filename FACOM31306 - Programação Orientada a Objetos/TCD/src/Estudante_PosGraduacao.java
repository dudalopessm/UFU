public class Estudante_PosGraduacao extends Estudante {
    //Atributos
    public String temaPesquisa;

    //Construtor
    public Estudante_PosGraduacao(String login, String nome, String data, String CPF, double CRA, String temaPesquisa) {
        super(login, nome, data, CPF,CRA);
        this.temaPesquisa = temaPesquisa;
    }

    //Getters e setters
    public String getTemaPesquisa() {
        return temaPesquisa;
    }

    public void setTemaPesquisa(String temaPesquisa) {
        this.temaPesquisa = temaPesquisa;
    }

    @Override
    public String toString() {
        return "\n____________________________________" + "\n\tESTUDANTE DE PÓS-GRADUAÇÃO" + super.toString() + "\nTema da pesquisa: " + this.temaPesquisa;
    }

    //Mudanças cadastrais
    public boolean mudaPesquisa(String novapesq) {
        if(this.temaPesquisa.equalsIgnoreCase(novapesq)) {
            System.out.println("Mesmo tema de pesquisa. Tente novamente.");
            return false;
        } else {
            setTemaPesquisa(novapesq);
            return true;
        }
    }
}