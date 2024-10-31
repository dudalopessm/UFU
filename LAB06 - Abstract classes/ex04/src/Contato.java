public abstract class Contato {
    private String nome;
    public String apelido;
    private String email;
    private String aniversario;

    public Contato(String nome, String apelido, String email, String aniversario, Contato[] base) {
        this.nome = nome;
        this.apelido = apelido;
        setEmail(email, base); // verificar email na main
        this.aniversario = aniversario;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getApelido() {
        return apelido;
    }

    public void setApelido(String apelido) {
        this.apelido = apelido;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email, Contato[] base) {
        if(verificaEmail(base, email))
            this.email = email;
        else
            this.email = null;
    }

    public String getAniversario() {
        return aniversario;
    }

    public void setAniversario(String aniversario) {
        this.aniversario = aniversario;
    }

    public String imprimirBasico() {
        return "\nNome: " + getNome() + "\nApelido: " + getApelido();
    }

    public abstract String imprimirContato();

    public boolean verificaEmail(Contato vet[], String email) {
        for(int i = 0; i < vet.length; i++) {
            if(email.compareTo(vet[i].getEmail()) == 0) {
                return false;
            }
        }
        return true;
    }
}