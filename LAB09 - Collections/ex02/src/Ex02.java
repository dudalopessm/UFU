import java.util.*;

public class Ex02 {
    public static void main(String[]args) {
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
        for(Estudante est : listateste) {
            try {
                estudanteDeque.addFirst(est);
            } catch (NullPointerException e) {
                System.out.println(e.getMessage());
            }
        }
    }
}