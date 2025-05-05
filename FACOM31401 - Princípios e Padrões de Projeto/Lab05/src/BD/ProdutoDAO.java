package BD;
import Codigo.Produto;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class ProdutoDAO {
    private Connection connection;

    public ProdutoDAO(Connection connection) {
        this.connection = connection;
    }

    public int inserirProduto(Produto produto) throws SQLException {
        String sql = "INSERT INTO produtos (nome, descricao, preco, estoque) VALUES (?, ?, ?, ?)";

        try(PreparedStatement stmt = connection.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS)) {
            stmt.setString(1, produto.getNome());
            stmt.setString(2, produto.getDescricao());
            stmt.setDouble(3, produto.getPreco());
            stmt.setInt(4, produto.getEstoque());

            int linhasAfetadas = stmt.executeUpdate();

            if(linhasAfetadas > 0) {
                try(ResultSet generatedKeys = stmt.getGeneratedKeys()) {
                    if(generatedKeys.next())
                        return generatedKeys.getInt(1); // retorna id do produto
                }
            }
        }
        return -1;
    }

    public int removerProduto(int id) throws SQLException {
        String sql = "DELETE FROM produtos WHERE id = ?";
        PreparedStatement stmt = null;

        try {
            stmt = connection.prepareStatement(sql);
            stmt.setInt(1, id);

            int linhasAfetadas = stmt.executeUpdate();

            return linhasAfetadas;

        } catch(SQLException e) {
            System.err.println("Erro ao remover produto: " + e.getMessage());
            return -1;

        } finally {
            if(stmt != null) {
                try {
                    stmt.close();
                } catch (SQLException e) {
                    System.err.println("Erro ao fechar PreparedStatement: " + e.getMessage());
                }
            }
        }
    }

    public boolean atualizarProduto(Produto produto) throws SQLException {
        String sql = "UPDATE produtos SET nome = ?, descricao = ?, preco = ?, estoque = ? WHERE id = ?";
        PreparedStatement stmt = null;

        try {
            stmt = connection.prepareStatement(sql);
            stmt.setString(1, produto.getNome());
            stmt.setString(2, produto.getDescricao());
            stmt.setDouble(3, produto.getPreco());
            stmt.setInt(4, produto.getEstoque());
            stmt.setInt(5, produto.getId());

            int linhasAfetadas = stmt.executeUpdate();

            return linhasAfetadas > 0;

        } catch (SQLException e) {
            System.err.println("Erro ao atualizar produto: " + e.getMessage());

            return false;

        } finally {
            if(stmt != null) {
                try {
                    stmt.close();
                } catch (SQLException e) {
                    System.err.println("Erro ao fechar PreparedStatement: " + e.getMessage());
                }
            }
        }
    }

    public boolean atualizarEstoque(int id, int quantidade) throws SQLException {
        String sql = "UPDATE produtos SET estoque = estoque + ? WHERE id = ?";

        PreparedStatement stmt = null;

        try {
            stmt = connection.prepareStatement(sql);
            stmt.setInt(1, quantidade);
            stmt.setInt(2, id);

            int linhasAfetadas = stmt.executeUpdate();

            return linhasAfetadas > 0;

        } catch (SQLException e) {
            System.err.println("Erro ao atualizar estoque: " + e.getMessage());
            return false;

        } finally {
            if(stmt != null) {
                try {
                    stmt.close();
                } catch (SQLException e) {
                    System.err.println("Erro ao fechar PreparedStatement: " + e.getMessage());
                }
            }
        }
    }

    public void criarTabela() throws SQLException {
        String sql = "CREATE TABLE produtos (" +
                "id INT PRIMARY KEY GENERATED ALWAYS AS IDENTITY (START WITH 1, INCREMENT BY 1), " +
                "nome VARCHAR(100), " +
                "descricao VARCHAR(255), " +
                "preco DECIMAL(10,2), " +
                "estoque INT)";

        Statement stmt = null;

        try {
            stmt = connection.createStatement();
            stmt.executeUpdate(sql);
            System.out.println("Tabela criada com sucesso!");

        } catch (SQLException e) {
            System.err.println("Erro ao criar tabela: " + e.getMessage());

        } finally {
            if (stmt != null) {
                try {
                    stmt.close();
                } catch (SQLException e) {
                    System.err.println("Erro ao fechar Statement: " + e.getMessage());
                }
            }
        }
    }

    public void dropTabela() throws SQLException { //debug
        String sql = "DROP TABLE produtos";

        try (Statement stmt = connection.createStatement()) {
            stmt.executeUpdate(sql);
            System.out.println("Tabela 'produtos' excluída com sucesso!");
        } catch (SQLException e) {
            System.err.println("Erro ao excluir a tabela: " + e.getMessage());
        }
    }

    public void mostrarTabelas() throws SQLException { //debug
        String sql = "SELECT TABLENAME FROM SYS.SYSTABLES WHERE TABLETYPE = 'T'";

        try (Statement stmt = connection.createStatement();
             ResultSet rs = stmt.executeQuery(sql)) {

            System.out.println("Tabelas no banco de dados:");
            while (rs.next()) {
                System.out.println(rs.getString("TABLENAME"));
            }

        } catch (SQLException e) {
            System.err.println("Erro ao listar tabelas: " + e.getMessage());
        }
    }



    public String mostrarTodos() throws SQLException {
        List<Produto> produtos = new ArrayList<>();
        String sql = "SELECT * FROM produtos";

        try (Statement stmt = connection.createStatement();
             ResultSet rs = stmt.executeQuery(sql)) {

            while (rs.next()) {
                Produto p = new Produto(rs.getInt("id"), rs.getString("nome"),
                        rs.getString("descricao"), rs.getDouble("preco"),
                        rs.getInt("estoque"));
                produtos.add(p);
            }
        }

        if (produtos.isEmpty()) {
            return "Nenhum produto cadastrado no banco de dados.";
        }

        StringBuilder sb = new StringBuilder();
        for (Produto p : produtos) {
            sb.append(p.toString()).append("\n");
        }

        return sb.toString();
    }


}