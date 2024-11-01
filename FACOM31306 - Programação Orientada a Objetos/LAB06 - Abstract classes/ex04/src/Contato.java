import java.util.ArrayList;
public abstract class Contato {
    private String nome;
    public String apelido;
    private String email;
    private String aniversario;

    public Contato(String nome, String apelido, String email, String aniversario, ArrayList<Contato> base) {
        this.nome = nome;
        this.apelido = apelido;
        setEmail(email, base); // verificar email na main
        this.aniversario = aniversario;
    }

    public String getNome() {
        return nome;
    }

    private void setNome(String nome) {
        this.nome = nome;
    }

    public String getApelido() {
        return apelido;
    }

    private void setApelido(String apelido) {
        this.apelido = apelido;
    }

    public String getEmail() {
        return email;
    }

    private void setEmail(String email, ArrayList<Contato> base) {
        if(verificaEmail(base, email))
            this.email = email;
        else
            this.email = null;
    }

    public boolean mudaEmail(String email, ArrayList<Contato> base) {
        if(this.email.compareToIgnoreCase(email) != 0) {
            setEmail(email, base);
            return true;
        } else {
            return false; // email identico ao ja cadastrado no usuario
        }
    }

    public String getAniversario() {
        return aniversario;
    }

    private void setAniversario(String aniversario) {
        this.aniversario = aniversario;
    }

    public String imprimirBasico() {
        return "\nNome: " + getNome() + "\nApelido: " + getApelido();
    }

    public abstract String imprimirContato();

    public static boolean verificaEmail(ArrayList<Contato> vet, String email) {
        for(int i = 0; i < vet.size(); i++) {
            if(email.compareToIgnoreCase(vet.get(i).getEmail()) == 0) {
                return false;
            }
        }
        return true;
    }
}