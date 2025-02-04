public class Main {
    public static void main(String args[]) {
        Biblioteca.criarLista();

        //Populando a biblioteca
        Livros l1 = new Livros(1899, "Dom Casmurro", "Machado de Assis");
        Biblioteca.addLivro(l1);
        Livros l2 = new Livros(1949, "1984", "George Orwell");
        Biblioteca.addLivro(l2);
        Livros l3 = new Livros(1902, "Os Sertões", "Euclides da Cunha");
        Biblioteca.addLivro(l3);
        Livros l4 = new Livros(1890, "O Cortiço", "Aluísio de Azevedo");
        Biblioteca.addLivro(l4);
        Livros l5 = new Livros(1881, "Memórias Póstumas de Brás Cubas", "Machado de Assis");
        Biblioteca.addLivro(l5);
        Revistas r1 = new Revistas(2018, "Cor não é raça", "National Geographic", 1, 1);
        Biblioteca.addRevista(r1);
        Revistas r2 = new Revistas(2024, "O voo para o futuro", "Forbes", 123, 24);
        Biblioteca.addRevista(r2);

        new JanelaLivro();
    }
}