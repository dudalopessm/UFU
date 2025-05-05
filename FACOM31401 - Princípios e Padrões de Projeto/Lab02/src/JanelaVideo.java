import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class JanelaVideo extends JFrame {
    public JanelaVideo() {
        JFrame janelaV = new JFrame("Cadastro de Vídeos");

        JPanel painelV = new JPanel();

        JLabel labelVideosV = new JLabel("Vídeos");
        JLabel labelAutorV = new JLabel("Autor: ");
        JLabel labelTituloV = new JLabel("Título: ");
        JLabel labelAnoV = new JLabel("Ano: ");
        JLabel labelDuracaoV = new JLabel("Duração (min): ");

        JTextField campoAutorV = new JTextField(25);
        JTextField campotituloV = new JTextField(25);
        JTextField campoAnoV = new JTextField(4);
        JTextField campoDuracaoV = new JTextField(6);

        JButton botaoIncluirV = new JButton("Incluir");
        JButton botaoLivrosV = new JButton("Livros");
        JButton botaoRevistasV = new JButton("Revistas");
        JButton botaoListaV = new JButton("Listagem");

        painelV.add(labelVideosV);
        painelV.add(labelAutorV);
        painelV.add(campoAutorV);
        painelV.add(labelTituloV);
        painelV.add(campotituloV);
        painelV.add(labelDuracaoV);
        painelV.add(campoDuracaoV);
        painelV.add(labelAnoV);
        painelV.add(campoAnoV);
        painelV.add(botaoIncluirV);
        painelV.add(botaoLivrosV);
        painelV.add(botaoRevistasV);
        painelV.add(botaoListaV);

        janelaV.getContentPane().add(painelV);
        janelaV.setVisible(true);
        janelaV.setSize(450, 400);

        labelVideosV.setBounds(200, 10, 250, 50);
        labelAutorV.setBounds(35, 50, 250, 50);
        labelTituloV.setBounds(35, 100, 250, 50);
        labelDuracaoV.setBounds(35, 150, 100, 50);
        labelAnoV.setBounds(240, 150, 100, 50);

        campoAutorV.setBounds(100, 65, 275, 20);
        campotituloV.setBounds(100, 115, 275, 20);
        campoDuracaoV.setBounds(122, 165, 50, 20);
        campoAnoV.setBounds(272, 165, 50, 20);

        botaoIncluirV.setBounds(50,225,85,50);
        botaoLivrosV.setBounds(175,225,85,50);
        botaoRevistasV.setBounds(300,225,87,50);
        botaoListaV.setBounds(175,290,87,50);

        painelV.setLayout(null);

        botaoIncluirV.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                try {
                    String autor = campoAutorV.getText();
                    String titulo = campotituloV.getText();
                    int ano = Integer.parseInt(campoAnoV.getText());
                    double duracao = Double.parseDouble(campoDuracaoV.getText());

                    try {
                        Videos.cadastraVideo(ano, titulo, autor, duracao);
                        JOptionPane.showMessageDialog(janelaV, "Vídeo incluído com sucesso.");
                        campotituloV.setText("");
                        campoAutorV.setText("");
                        campoDuracaoV.setText("");
                        campoAnoV.setText("");
                    } catch(Exception e1) {
                        JOptionPane.showMessageDialog(janelaV, e1.getMessage());
                    }
                } catch(Exception e2) {
                    JOptionPane.showMessageDialog(janelaV, "Erro ao incluir vídeo.");
                }
            }
        });

        botaoLivrosV.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                new JanelaLivro();
                janelaV.setVisible(false);
            }
        });

        botaoRevistasV.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                new JanelaRevista();
                janelaV.setVisible(false);
            }
        });

        botaoListaV.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                new JanelaLista();
                janelaV.setVisible(false);
            }
        });

        janelaV.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                new JanelaLivro();
            }
        });
    }
}
