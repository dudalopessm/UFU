import javax.swing.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.ArrayList;

public class JanelaLista {
    public JanelaLista() {
        JFrame janelaL = new JFrame("Lista de Textos disponíveis");

        JPanel painelL = new JPanel();

        JLabel labelLista = new JLabel("Listagem");

        JTextArea info = new JTextArea();

        //String textoObj;

        //ArrayList<Biblioteca> listaB = Biblioteca.getLista();

        painelL.add(info);
        painelL.setLayout(null);

        janelaL.getContentPane().add(painelL);
        janelaL.setVisible(true);
        janelaL.setSize(1000, 350);

        info.setBounds(40, 20, 900, 200);

        /* for (Biblioteca biblioteca : listaB) {
            textoObj = biblioteca.toString();
            info.append(textoObj + "\n");
        }*/
        Biblioteca.mostrarConteudo(info);

        janelaL.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                new JanelaLivro();
            }
        });
    }
}