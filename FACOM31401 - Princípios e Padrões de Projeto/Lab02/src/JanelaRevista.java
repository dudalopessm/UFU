import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class JanelaRevista extends JFrame {
    public JanelaRevista() {
        JFrame janelaR = new JFrame("Cadastro de revistas");

        JPanel painelR = new JPanel();

        JLabel labelRevistas = new JLabel("Revistas");
        JLabel labelTituloR = new JLabel("Título:");
        JLabel labelOrgR = new JLabel("Org.:");
        JLabel labelVolR = new JLabel("Vol.:");
        JLabel labelNroR = new JLabel("Nro:");
        JLabel labelAnoR = new JLabel("Ano:");

        JTextField campoTituloR = new JTextField(25);
        JTextField campoOrgR = new JTextField(25);
        JTextField campoVolR = new JTextField(3);
        JTextField campoNroR = new JTextField(3);
        JTextField campoAnoR = new JTextField(4);

        JButton botaoIncluir = new JButton("Incluir");
        JButton botaoLivros = new JButton("Livros");
        JButton botaoLista = new JButton("Listagem");
        JButton botaoVideos = new JButton("Vídeos");

        painelR.add(labelRevistas);
        painelR.add(labelTituloR);
        painelR.add(campoTituloR);
        painelR.add(labelOrgR);
        painelR.add(campoOrgR);
        painelR.add(labelVolR);
        painelR.add(campoVolR);
        painelR.add(labelNroR);
        painelR.add(campoNroR);
        painelR.add(labelAnoR);
        painelR.add(campoAnoR);
        painelR.add(botaoIncluir);
        painelR.add(botaoLivros);
        painelR.add(botaoLista);
        painelR.add(botaoVideos);

        janelaR.getContentPane().add(painelR);
        janelaR.setVisible(true);
        janelaR.setSize(450, 400);

        labelRevistas.setBounds(187, 10, 250, 50);
        labelTituloR.setBounds(35, 50, 250, 50);
        labelOrgR.setBounds(35, 100, 250, 50);
        labelVolR.setBounds(37, 150, 25, 50);
        labelNroR.setBounds(177, 150, 25, 50);
        labelAnoR.setBounds(297, 150, 25, 50);

        campoTituloR.setBounds(100, 65, 275, 20);
        campoOrgR.setBounds(100, 115, 275, 20);
        campoVolR.setBounds(77, 165, 50, 20);
        campoNroR.setBounds(217, 165, 50, 20);
        campoAnoR.setBounds(337, 165, 50, 20);

        botaoIncluir.setBounds(50,225,85,50);
        botaoLivros.setBounds(175,225,85,50);
        botaoVideos.setBounds(300,225,87,50);
        botaoLista.setBounds(175,290,87,50);

        painelR.setLayout(null);

        botaoIncluir.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                try {
                    String titulo = campoTituloR.getText();
                    String org = campoOrgR.getText();
                    int vol = Integer.parseInt(campoVolR.getText());
                    int nro = Integer.parseInt(campoNroR.getText());
                    int ano = Integer.parseInt(campoAnoR.getText());

                    //Revistas r = new Revistas(ano, titulo, org, vol, nro);

                    //Biblioteca.addRevista(r);

                    try {
                        Revistas.cadastraRevista(ano, titulo, org, vol, nro);
                        JOptionPane.showMessageDialog(janelaR, "Revista incluída com sucesso.");
                        campoTituloR.setText("");
                        campoOrgR.setText("");
                        campoVolR.setText("");
                        campoNroR.setText("");
                        campoAnoR.setText("");
                    } catch(Exception e1) {
                        JOptionPane.showMessageDialog(janelaR, e1.getMessage());
                    }
                } catch(Exception e2) {
                    JOptionPane.showMessageDialog(janelaR, "Erro ao incluir revista.");
                }
            }
        });

        botaoLivros.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                new JanelaLivro();
                janelaR.setVisible(false);
            }
        });

        botaoLista.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                new JanelaLista();
                janelaR.setVisible(false);
            }
        });

        botaoVideos.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                new JanelaVideo();
                janelaR.setVisible(false);
            }
        });

        janelaR.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                new JanelaLivro();
            }
        });
    }
}