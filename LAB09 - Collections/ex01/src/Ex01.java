import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;

public class Ex01 {
    public static void main(String[]args) {
        /* Uso de ArrayList para fazer uma lista de Estudantes */
        /* Uso de HashMap para pesquisa de Estudantes */
        System.out.println("\n ----------------------------- Collections  -----------------------------");
        // -------------------------------------------------- ARRAYLIST --------------------------------------------------
        ArrayList<Estudante> listateste = new ArrayList<Estudante>();
        listateste.add(new EstudanteGraduacao("Carlos","Rua 1o de Abril", "Assembly is hard"));
        listateste.add(new EstudanteGraduacao("Maria", "Rua Maio", "Java is funny"));
        listateste.add(new EstudanteMestrado("Carla","Rua Primavera","Medicina","Vacinas de RNA", "Anticorpos","Vacinas de RNA aplicadas com anticorpos - Um estudo"));
        listateste.add(new EstudanteDoutorado("Bruno","Rua Inverno","Tecnologia","Processamento de Imagens","Carros Inteligentes"));
        listateste.add(new EstudanteGraduacao("Joana", "Rua Estrela", "I love C++"));
        listateste.add(new EstudanteMestrado("Fernanda", "Rua Neve", "Biologia", "Clonagem", "DNA", "Clonagem laboratorial aplicada a DNA de ratos - Um experimento"));
        listateste.add(new EstudanteDoutorado("Gustavo", "Rua Lua", "Física", "Astrofísica", "Buracos Negros"));
        listateste.add(new EstudanteDoutorado("Ana", "Rua Vento", "Química", "Reações Orgânicas", "Síntese de Fármacos"));

        System.out.println("\n*********** Estudantes antes das alterações (ArrayList) ***********");
        System.out.println("__________________________________________________________");
        for(Estudante a : listateste) {
            a.print();
            System.out.println("__________________________________________________________");
        }

        System.out.println("\n~~ Removendo os estudantes Gustavo e Bruno... ~~");
        Iterator<Estudante> iter = listateste.iterator();
        while(iter.hasNext()) {
            Estudante est = iter.next();
            if(est.getNome().equalsIgnoreCase("gustavo") || est.getNome().equalsIgnoreCase("bruno"))
                iter.remove();
        }

        System.out.println("\n*********** Estudantes após alterações (ArrayList) ***********");
        System.out.println("__________________________________________________________");
        for(Estudante a : listateste) {
            a.print();
            System.out.println("__________________________________________________________");
        }

        // -------------------------------------------------- HASHMAP --------------------------------------------------
        HashMap<String, Estudante> mapa = new HashMap<String, Estudante>();
        for(Estudante a : listateste) {
            mapa.put(a.getNome(), a);
        }

        System.out.println("\n*********** Estudantes antes das alterações (HashMap) ***********");
        System.out.println("__________________________________________________________");
        for(String nome : mapa.keySet()) {
            Estudante est = mapa.get(nome);
            est.print();
            System.out.println("__________________________________________________________");
        }

        System.out.println("\n ~~ Removendo o estudante Carlos (HashMap)... ~~");
        mapa.remove("Carlos");
        System.out.println("\n*********** Estudantes após alterações (HashMap) ***********");
        System.out.println("__________________________________________________________");
        for(String nome : mapa.keySet()) {
            Estudante est = mapa.get(nome);
            est.print();
            System.out.println("__________________________________________________________");
        }
    }
}