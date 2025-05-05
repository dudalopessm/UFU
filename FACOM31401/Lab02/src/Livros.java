public class Livros extends Biblioteca {
    private String autor;

    public Livros(int ano, String titulo, String autor) {
        super(ano, titulo);
        setAutor(autor);
    }

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) throws IllegalArgumentException {
        if(autor == null || super.soNumeros(autor) || autor.trim().isEmpty())
            throw new IllegalArgumentException("Nome do autor não pode ser vazio ou só números.");
        this.autor = autor;
    }

    public static void cadastraLivro(int ano, String titulo, String autor) {
        Livros l = new Livros(ano, titulo, autor);
        Biblioteca.addItem(l);
    }

    @Override
    public String toString() {
        return "Livros:  " + getTitulo() + "\t" + getAutor() + "\t" +  getAno();
    }
}