package App;
import BD.*;
import Codigo.Produto;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.SQLException;


public class ProdutoApp {
    private ProdutoDAO produtoDAO;
    private JFrame mainFrame;

    public ProdutoApp(Connection connection) {
        this.produtoDAO = new ProdutoDAO(connection);
        inicializar();
    }

    private void inicializar() {
        mainFrame = new JFrame("Sistema de Gerenciamento de Produtos");
        mainFrame.setSize(400, 300);
        mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        mainFrame.setLayout(new BorderLayout());

        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(3, 1, 10, 10));
        buttonPanel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));

        JButton btnInserir = new JButton("Inserir Produto");
        JButton btnRemover = new JButton("Remover Produto");
        JButton btnMostrarTodos = new JButton("Mostrar Todos os Produtos");

        btnInserir.addActionListener(e -> abrirJanelaInserirProduto());
        btnRemover.addActionListener(e -> abrirJanelaRemoverProduto());
        btnMostrarTodos.addActionListener(e -> abrirJanelaMostrarTodos());

        buttonPanel.add(btnInserir);
        buttonPanel.add(btnRemover);
        buttonPanel.add(btnMostrarTodos);

        mainFrame.add(buttonPanel, BorderLayout.CENTER);
        mainFrame.setLocationRelativeTo(null);  // Center on screen
        mainFrame.setVisible(true);
    }

    private void abrirJanelaInserirProduto() {
        JFrame frame = new JFrame("Inserir Produto");
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setLayout(new BorderLayout());

        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(5, 2, 10, 10));
        panel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));

        JLabel lblNome = new JLabel("Nome:");
        JTextField txtNome = new JTextField(20);

        JLabel lblDescricao = new JLabel("Descrição:");
        JTextField txtDescricao = new JTextField(20);

        JLabel lblPreco = new JLabel("Preço:");
        JTextField txtPreco = new JTextField(20);

        JLabel lblEstoque = new JLabel("Estoque:");
        JTextField txtEstoque = new JTextField(20);

        JButton btnSalvar = new JButton("Salvar");

        panel.add(lblNome);
        panel.add(txtNome);
        panel.add(lblDescricao);
        panel.add(txtDescricao);
        panel.add(lblPreco);
        panel.add(txtPreco);
        panel.add(lblEstoque);
        panel.add(txtEstoque);
        panel.add(new JLabel());
        panel.add(btnSalvar);

        btnSalvar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    String nome = txtNome.getText();
                    String descricao = txtDescricao.getText();

                    if (nome.trim().isEmpty()) {
                        JOptionPane.showMessageDialog(frame, "Nome é obrigatório!");
                        return;
                    }

                    double preco;
                    try {
                        preco = Double.parseDouble(txtPreco.getText().replace(",", "."));
                    } catch (NumberFormatException ex) {
                        JOptionPane.showMessageDialog(frame, "Preço inválido!");
                        return;
                    }

                    int estoque;
                    try {
                        estoque = Integer.parseInt(txtEstoque.getText());
                    } catch (NumberFormatException ex) {
                        JOptionPane.showMessageDialog(frame, "Estoque inválido!");
                        return;
                    }

                    Produto produto = new Produto();
                    produto.setNome(nome);
                    produto.setDescricao(descricao);
                    produto.setPreco(preco);
                    produto.setEstoque(estoque);

                    int id = produtoDAO.inserirProduto(produto);

                    if (id > 0) {
                        JOptionPane.showMessageDialog(frame, "Produto inserido com sucesso! ID: " + id);
                        frame.dispose();
                    } else {
                        JOptionPane.showMessageDialog(frame, "Erro ao inserir produto!");
                    }
                } catch (SQLException ex) {
                    JOptionPane.showMessageDialog(frame, "Erro de banco de dados: " + ex.getMessage());
                }
            }
        });

        frame.add(panel, BorderLayout.CENTER);
        frame.setLocationRelativeTo(mainFrame);
        frame.setVisible(true);
    }

    private void abrirJanelaRemoverProduto() {
        JFrame frame = new JFrame("Remover Produto");
        frame.setSize(300, 150);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setLayout(new BorderLayout());

        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(2, 2, 10, 10));
        panel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));

        JLabel lblId = new JLabel("ID do Produto:");
        JTextField txtId = new JTextField(10);

        JButton btnRemover = new JButton("Remover");

        panel.add(lblId);
        panel.add(txtId);
        panel.add(new JLabel());
        panel.add(btnRemover);

        btnRemover.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    int id;
                    try {
                        id = Integer.parseInt(txtId.getText());
                    } catch (NumberFormatException ex) {
                        JOptionPane.showMessageDialog(frame, "ID inválido!");
                        return;
                    }

                    int option = JOptionPane.showConfirmDialog(
                            frame,
                            "Tem certeza que deseja remover o produto com ID " + id + "?",
                            "Confirmar Remoção",
                            JOptionPane.YES_NO_OPTION);

                    if (option == JOptionPane.YES_OPTION) {
                        int result = produtoDAO.removerProduto(id);

                        if (result > 0) {
                            JOptionPane.showMessageDialog(frame, "Produto removido com sucesso!");
                            frame.dispose();
                        } else if (result == 0) {
                            JOptionPane.showMessageDialog(frame, "Produto não encontrado!");
                        } else {
                            JOptionPane.showMessageDialog(frame, "Erro ao remover produto!");
                        }
                    }
                } catch (SQLException ex) {
                    JOptionPane.showMessageDialog(frame, "Erro de banco de dados: " + ex.getMessage());
                }
            }
        });

        frame.add(panel, BorderLayout.CENTER);
        frame.setLocationRelativeTo(mainFrame);
        frame.setVisible(true);
    }

    private void abrirJanelaMostrarTodos() {
        JFrame frame = new JFrame("Todos os Produtos");
        frame.setSize(600, 400);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setLayout(new BorderLayout());

        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout());
        panel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));

        try {
            String produtosTexto = produtoDAO.mostrarTodos();

            if (produtosTexto.equals("Nenhum produto cadastrado no banco de dados.")) {
                JTextArea txtAreaProdutos = new JTextArea(produtosTexto);
                txtAreaProdutos.setEditable(false);
                panel.add(new JScrollPane(txtAreaProdutos), BorderLayout.CENTER);
            } else {
                String[] produtos = produtosTexto.split("\n");

                JPanel produtosPanel = new JPanel();
                produtosPanel.setLayout(new BoxLayout(produtosPanel, BoxLayout.Y_AXIS));
                produtosPanel.setBackground(Color.WHITE);

                for (String produto : produtos) {
                    if (!produto.trim().isEmpty()) {
                        JPanel produtoPanel = new JPanel(new BorderLayout());
                        produtoPanel.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));

                        JTextArea txtProduto = new JTextArea(produto);
                        txtProduto.setEditable(false);
                        txtProduto.setLineWrap(true);
                        txtProduto.setWrapStyleWord(true);
                        txtProduto.setBackground(produtosPanel.getBackground());

                        produtoPanel.add(txtProduto, BorderLayout.CENTER);

                        produtosPanel.add(produtoPanel);

                        JSeparator separator = new JSeparator(JSeparator.HORIZONTAL);
                        separator.setForeground(Color.GRAY);
                        produtosPanel.add(separator);

                        produtosPanel.add(Box.createRigidArea(new Dimension(0, 5)));
                    }
                }

                JScrollPane scrollPane = new JScrollPane(produtosPanel);
                panel.add(scrollPane, BorderLayout.CENTER);
            }

            JButton btnFechar = new JButton("Fechar");
            btnFechar.addActionListener(e -> frame.dispose());

            panel.add(btnFechar, BorderLayout.SOUTH);

        } catch (SQLException e) {
            JOptionPane.showMessageDialog(frame, "Erro ao carregar produtos: " + e.getMessage());
        }

        frame.add(panel, BorderLayout.CENTER);
        frame.setLocationRelativeTo(mainFrame);
        frame.setVisible(true);
    }
    public static void main(String[] args) {
        try {
            Connection conn = ConexaoBD.abrirConexaoBD();

            if (conn != null) {
                SwingUtilities.invokeLater(() -> new ProdutoApp(conn));

                Runtime.getRuntime().addShutdownHook(new Thread(() -> {
                    ConexaoBD.fecharConexaoBD();
                }));
            } else {
                JOptionPane.showMessageDialog(null, "Não foi possível conectar ao banco de dados.");
            }
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null, "Erro ao iniciar a aplicação: " + e.getMessage());
        }
    }

}
