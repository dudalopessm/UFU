package Codigo;
import BD.ConexaoBD;
import BD.ProdutoDAO;

import java.sql.Connection;
import java.sql.SQLException;

public class TesteBD {
    public static void main(String[] args) {
        Connection connection = null;
        try {
            connection = ConexaoBD.abrirConexaoBD();

            ProdutoDAO produtoDAO = new ProdutoDAO(connection);

            System.out.println(produtoDAO.mostrarTodos());

        } catch (SQLException e) {
            System.err.println("Erro no banco de dados: " + e.getMessage());
            e.printStackTrace();
        } finally {
            if (connection != null) {
                ConexaoBD.fecharConexaoBD();
            }
        }
    }
}
