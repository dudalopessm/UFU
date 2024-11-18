import java.io.Serializable;

public class Estudante_Graduacao extends Estudante implements Serializable {
    //Atributos
    public String estagio;

    //Construtor
    public Estudante_Graduacao( String nome, String data, String CPF, double CRA, String estagio) {
        super( nome, data, CPF, CRA);
        this.estagio = estagio;
    }
    
    //Getters e setters
    public String getEstagio() {
        return estagio;
    }
    private void setEstagio(String estagio) {
        this.estagio = estagio;
    }

    @Override
    public String toString(){
        return "\n____________________________________" + "\n\tESTUDANTE DE GRADUAÇÃO " + super.toString() + "\nEstágio: " + this.estagio;
    }

    //Mudanças cadastrais
    public boolean mudaEstagio(String est) {
        if(this.estagio.equalsIgnoreCase(est)) {
            System.out.println("Novo estágio idêntico ao anterior. Tente novamente.");
            return false;
        } else {
            setEstagio(est);
            return true;
        }
    }
    
}