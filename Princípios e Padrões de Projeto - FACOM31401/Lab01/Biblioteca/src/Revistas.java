public class Revistas extends Biblioteca {
    private String organizacao;
    private int volume;
    private int numero;

    public Revistas(int ano, String titulo, String organizacao, int volume, int numero) {
        super(ano, titulo);
        setOrganizacao(organizacao);
        setVolume(volume);
        setNumero(numero);
    }

    public String getOrganizacao() {
        return organizacao;
    }

    public void setOrganizacao(String organizacao) throws IllegalArgumentException {
        if(organizacao == null || super.soNumeros(organizacao) || organizacao.trim().isEmpty())
            throw new IllegalArgumentException("Organização não pode estar vazia ou ser só números.");
        this.organizacao = organizacao;
    }

    public int getVolume() {
        return volume;
    }

    public void setVolume(int volume) {
        if(volume > 0)
            this.volume = volume;
        else
            this.volume = 0;
    }

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        if(numero > 0)
            this.numero = numero;
        else
            this.numero = 0;
    }

    @Override
    public String toString() {
        return "Revistas:  " + getTitulo() + "\t" + getOrganizacao() + "\t" + getVolume() + "\t" + getNumero() + "\t" + getAno();
    }
}