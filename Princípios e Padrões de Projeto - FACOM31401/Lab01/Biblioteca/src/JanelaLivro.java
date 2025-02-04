import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class JanelaLivro extends JFrame {
public JanelaLivro() {
    JFrame janela = new JFrame("Cadastro de Livros");

    JPanel painel = new JPanel();

    JLabel labelLivros = new JLabel("Livros");
    JLabel labelTitulo = new JLabel("Título: ");
    JLabel labelAutor = new JLabel("Autor: ");
    JLabel labelAno = new JLabel("Ano: ");

    JTextField campotitulo = new JTextField(25);
    JTextField campoautor = new JTextField(25);
    JTextField campoano = new JTextField(4);

    JButton botaoincluir = new JButton("Incluir");
    JButton botaorevistas = new JButton("Revistas");
    JButton botaolista = new JButton("Listagem");

    painel.add(labelLivros);
    painel.add(labelTitulo);
    painel.add(campotitulo);
    painel.add(labelAutor);
    painel.add(campoautor);
    painel.add(labelAno);
    painel.add(campoano);
    painel.add(botaoincluir);
    painel.add(botaorevistas);
    painel.add(botaolista);

    janela.getContentPane().add(painel);
    janela.setVisible(true);
    janela.setSize(500, 400);

    labelLivros.setBounds(187, 10, 250, 50);
    labelTitulo.setBounds(35,50,250,50);
    labelAutor.setBounds(35,100,250,50);
    labelAno.setBounds(37,150,250,50);

    campotitulo.setBounds(100,65,275,20);
    campoautor.setBounds(100,115,275,20);
    campoano.setBounds(100,165,275,20);

    botaoincluir.setBounds(50,225,85,50);
    botaorevistas.setBounds(175,225,85,50);
    botaolista.setBounds(300,225,87,50);

    painel.setLayout(null);

    botaoincluir.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
            try {
                String titulo = campotitulo.getText();
                String autor = campoautor.getText();
                int ano = Integer.parseInt(campoano.getText());

                Livros l = new Livros(ano, titulo, autor);

                Biblioteca.addLivro(l);

                campotitulo.setText("");
                campoautor.setText("");
                campoano.setText("");

                JOptionPane.showMessageDialog(janela, "Livro incluído com sucesso.");
            } catch (Exception e1) {
                JOptionPane.showMessageDialog(janela, "Erro ao incluir livro.");
            }
        }
    });

    botaorevistas.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
            new JanelaRevista();
            janela.setVisible(false);
        }
    });

    botaolista.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
            new JanelaLista();
            janela.setVisible(false);
        }
    });
}
}