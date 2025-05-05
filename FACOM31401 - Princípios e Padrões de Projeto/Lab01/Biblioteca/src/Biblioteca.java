import java.util.ArrayList;

public class Biblioteca {
    private static ArrayList<Biblioteca> listaB;
    private int ano;
    private String titulo;

    public Biblioteca(int ano, String titulo) {
        setAno(ano);
        setTitulo(titulo);
    }

    public int getAno() {
        return ano;
    }

    public void setAno(int ano) {
        if(ano > 0 && ano <= 2025)
            this.ano = ano;
        else
            this.ano = 0;
    }

    public String getTitulo() {
        return titulo;
    }

    public boolean soNumeros(String s) {
        return s != null && s.matches("-?\\d+(\\.\\d+)?");
    }

    public void setTitulo(String titulo) throws IllegalArgumentException {
        if(titulo == null || titulo.trim().isEmpty())
            throw new IllegalArgumentException("Título não pode estar vazio.");
        this.titulo = titulo;
    }

    public static void addLivro(Livros l) {
        if(l != null)
            listaB.add(l);
    }

    public static void addRevista(Revistas r) {
        if(r != null)
            listaB.add(r);
    }

    public static ArrayList<Biblioteca> criarLista() {
        listaB = new ArrayList<Biblioteca>();
        return listaB;
    }

    public static ArrayList<Biblioteca> getLista() {
        return listaB;
    }

    @Override
    public String toString() {
        return "";
    }
}