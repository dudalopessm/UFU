import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;

public class Ex01 {
    public static void main(String[]args) {
        /* Uso de ArrayList para fazer uma lista de Estudantes */
        /* Uso de HashMap para pesquisa de Estudantes */
        System.out.println("\n ----------------------------- Collections  -----------------------------");
        ArrayList<Estudante> listateste = new ArrayList<Estudante>();
        listateste.add(new EstudanteGraduacao("Carlos","Rua 1o de Abril", "Assembly is hard"));
        listateste.add(new EstudanteGraduacao("Maria", "Rua Maio", "Java is funny"));
        listateste.add(new EstudanteMestrado("Carla","Rua Primavera","Medicina","Vacinas de RNA", "Anticorpos","Vacinas de RNA aplicadas com anticorpos - Um estudo"));
        listateste.add(new EstudanteDoutorado("Bruno","Rua Inverno","Tecnologia","Processamento de Imagens","Carros Inteligentes"));
        listateste.add(new EstudanteGraduacao("Joana", "Rua Estrela", "I love C++"));
        listateste.add(new EstudanteMestrado("Fernanda", "Rua Neve", "Biologia", "Clonagem", "DNA", "Clonagem laboratorial aplicada a DNA de ratos - Um experimento"));
        listateste.add(new EstudanteDoutorado("Gustavo", "Rua Lua", "Física", "Astrofísica", "Buracos Negros"));
        listateste.add(new EstudanteDoutorado("Ana", "Rua Vento", "Química", "Reações Orgânicas", "Síntese de Fármacos"));

        HashMap<Estudante, String> mapa = new HashMap<Estudante, String>();
        for(Estudante a : listateste) {
            mapa.put(a, a.getNome());
            a.print();
            System.out.println("_______________________________");
        }

        System.out.println("***************** Remoção do estudante Gustavo *****************");
        Iterator <Estudante> iter = listateste.iterator();
        while(iter.hasNext()) {
            Estudante alun = (Estudante) iter.next();
            if(alun.getNome().equalsIgnoreCase("gustavo"))
                iter.remove();
        }
        while(iter.hasNext()) {
            Estudante alun = (Estudante) iter.next();
            alun.print();
        }
    }
}
