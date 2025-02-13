import javax.swing.*;
import java.util.ArrayList;
import java.util.List;

public abstract class Biblioteca {
    private static List<Biblioteca> listaB;
    private int ano;
    private String titulo;

    public Biblioteca(int ano, String titulo) {
        setAno(ano);
        setTitulo(titulo);
    }

    public int getAno() {
        return ano;
    }

    public void setAno(int ano) throws IllegalArgumentException {
        if(ano > 0 && ano <= 2025)
            this.ano = ano;
        else
            throw new IllegalArgumentException("O ano não pode ser maior que o ano vigente.");
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


    public static void addItem(Biblioteca it) {
        if(it != null)
            listaB.add(it);
    }

    public static List<Biblioteca> criarLista() {
        listaB = new ArrayList<Biblioteca>();
        return listaB;
    }

    public static List<Biblioteca> getLista() {
        return listaB;
    }

    public static void mostrarConteudo(JTextArea textoJanela) {
        for(Biblioteca elemento : listaB) {
            String textoInterno = elemento.toString();
            textoJanela.append(textoInterno + "\n");
        }
    }

    @Override
    public String toString() {
        return "";
    }
}