import java.util.*;

public class Ex02 {
    public static void main(String[] args) {
        System.out.println("\n ----------------------------- Deque  -----------------------------");

        ArrayList<Estudante> listateste = new ArrayList<>();
        listateste.add(new EstudanteGraduacao("Carlos","Rua 1o de Abril", "Assembly is hard"));
        listateste.add(new EstudanteGraduacao("Maria", "Rua Maio", "Java is funny"));
        listateste.add(new EstudanteMestrado("Carla","Rua Primavera","Medicina","Vacinas de RNA", "Anticorpos","Vacinas de RNA aplicadas com anticorpos - Um estudo"));
        listateste.add(new EstudanteDoutorado("Bruno","Rua Inverno","Tecnologia","Processamento de Imagens","Carros Inteligentes"));
        listateste.add(new EstudanteGraduacao("Joana", "Rua Estrela", "I love C++"));
        listateste.add(new EstudanteMestrado("Fernanda", "Rua Neve", "Biologia", "Clonagem", "DNA", "Clonagem laboratorial aplicada a DNA de ratos - Um experimento"));
        listateste.add(new EstudanteDoutorado("Gustavo", "Rua Lua", "Física", "Astrofísica", "Buracos Negros"));
        listateste.add(new EstudanteDoutorado("Ana", "Rua Vento", "Química", "Reações Orgânicas", "Síntese de Fármacos"));

        Deque<Estudante> estudanteDeque = new ArrayDeque<>();

        System.out.println("\nAdicionando elementos ao Deque:");
        for(Estudante est : listateste) {
            try {
                estudanteDeque.addFirst(est);
                System.out.println("Adicionado: " + est.getNome());
            } catch (NullPointerException e) {
                System.out.println("Erro ao adicionar estudante: " + e.getMessage());
            }
        }

        System.out.println("\nDemonstrando diferentes métodos do Deque:");

        try {
            Estudante primeiro = estudanteDeque.getFirst();
            System.out.println("Primeiro elemento (getFirst): " + primeiro.getNome());

            Estudante primeiro2 = estudanteDeque.peekFirst();
            System.out.println("Primeiro elemento (peekFirst): " +
                    (primeiro2 != null ? primeiro2.getNome() : "null"));
        } catch (NoSuchElementException e) {
            System.out.println("Erro ao obter primeiro elemento: " + e.getMessage());
        }

        try {
            while (!estudanteDeque.isEmpty()) {
                estudanteDeque.pollFirst();
            }

            System.out.println("\nTentando remover de um deque vazio:");

            Estudante removido = estudanteDeque.pollFirst();
            System.out.println("pollFirst() em deque vazio: " +
                    (removido != null ? removido.getNome() : "null"));

            Estudante removido2 = estudanteDeque.removeFirst();
            System.out.println("removeFirst() em deque vazio: " + removido2.getNome());

        } catch (NoSuchElementException e) {
            System.out.println("Erro ao remover elemento: Deque está vazio");
        }

        System.out.println("\nDemonstrando offerFirst() vs addFirst():");
        try {
            boolean ofertaAceita = estudanteDeque.offerFirst(listateste.get(0));
            System.out.println("offerFirst() resultado: " + ofertaAceita);

            estudanteDeque.addFirst(null);

        } catch (NullPointerException e) {
            System.out.println("Erro ao adicionar elemento null: " + e.getMessage());
        }
    }
}