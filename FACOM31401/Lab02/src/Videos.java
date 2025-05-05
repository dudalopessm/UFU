public class Videos extends Biblioteca {
    private String autor;
    private double duracao;
    private String duracaoFormatada;

    public Videos(int ano, String titulo, String autor, double duracao) {
        super(ano, titulo);
        setAutor(autor);
        setDuracao(duracao);
    }

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) throws IllegalArgumentException {
        if(autor == null || super.soNumeros(autor) || autor.trim().isEmpty())
            throw new IllegalArgumentException("Nome do autor não pode ser vazio ou só números.");
        this.autor = autor;
    }

    public String converteTempo(double tempo) throws IllegalArgumentException {
        if(tempo < 0)
            throw new IllegalArgumentException("O tempo deve ser maior ou igual a zero.");
        this.duracao = tempo;
        int min = (int)tempo;
        double decimal = tempo - min;
        int seg = (int)Math.round(decimal*60);

        if(seg >= 60) {
            seg = 0;
            min++;
        }

        int h = min / 60;
        min = min % 60;

        return String.format("%02d:%02d:%02d", h, min, seg);
    }

    public void setDuracao(double duracao) {
        this.duracaoFormatada = converteTempo(duracao);
    }

    public String getDuracaoFormatada() {
        return duracaoFormatada;
    }

    public static void cadastraVideo(int ano, String titulo, String autor, double duracao) {
        Videos v = new Videos(ano, titulo, autor, duracao);
        Biblioteca.addItem(v);
    }

    public String toString() {
        return "Vídeos: " + getTitulo() + "\t" + getAutor() + "\t" + getAno() + "\t" + getDuracaoFormatada();
    }
}
