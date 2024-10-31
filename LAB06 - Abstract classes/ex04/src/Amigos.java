public class Amigos extends Contato {
    private int grau; // 1 = melhor amigo, 2 = amigo, 3 = conhecido

    public Amigos(String nome, String apelido, String email, String aniversario, int grau) {
        super(nome, apelido, email, aniversario);
        setGrau(grau);
    }

    public int getGrau() {
        return grau;
    }

    public void setGrau(int grau) {
        if (grau == 1 || grau == 2 || grau == 3) {
            this.grau = grau;
        }
        else {
            this.grau = -1; // erro
        }
    }

    public String imprimirContato() {
        int retorno = getGrau();
        String ret;
        if (retorno == 1 ) {
            ret = "Melhor amigo";
        } else if(retorno == 2) {
            ret = "Amigo";
        } else if(retorno == 3){
            ret = "Conhecido";
        } else {
            ret = "Erro";
        }
        return "\nGrau de amizade: " + ret;
    }
}