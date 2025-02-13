public class Main {
    public static void main(String args[]) {
        Biblioteca.criarLista();

        //Populando a biblioteca
        Livros l1 = new Livros(1899, "Dom Casmurro", "Machado de Assis");
        Biblioteca.addItem(l1);
        Livros l2 = new Livros(1949, "1984", "George Orwell");
        Biblioteca.addItem(l2);
        Livros l3 = new Livros(1902, "Os Sertões", "Euclides da Cunha");
        Biblioteca.addItem(l3);
        Livros l4 = new Livros(1890, "O Cortiço", "Aluísio de Azevedo");
        Biblioteca.addItem(l4);
        Livros l5 = new Livros(1881, "Memórias Póstumas de Brás Cubas", "Machado de Assis");
        Biblioteca.addItem(l5);
        Revistas r1 = new Revistas(2018, "Cor não é raça", "National Geographic", 1, 1);
        Biblioteca.addItem(r1);
        Revistas r2 = new Revistas(2024, "O voo para o futuro", "Forbes", 123, 24);
        Biblioteca.addItem(r2);
        Videos v1 = new Videos(2025, "Kendrick Lamar's Apple Music Super Bowl Halftime Show", "NFL", 13.24);
        Biblioteca.addItem(v1);
        Videos v2 = new Videos(2024, "Olivia Rodrigo | The Grudge (Live Debut) Ace Theatre 2023", "onthefest", 3.05);
        Biblioteca.addItem(v2);
        Videos v3 = new Videos(2024, "3 am vibes | escape reality with this playlist", "night gaze", 124.25);
        Biblioteca.addItem(v3);

        new JanelaLivro();
    }
}