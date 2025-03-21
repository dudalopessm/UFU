package BD;
import java.sql.*;

public class ConexaoBD {
    private static Connection conn = null;

    public static Connection abrirConexaoBD() {
        String url = "jdbc:derby:C:/Faculdade/Quarto_Periodo/PPP/Labs/Lab05/BDProdutos";

        try {
            if (conn == null || conn.isClosed()) {
                conn = DriverManager.getConnection(url);
                System.out.println("Conexão estabelecida com o DB.");
            }
            return conn;
        } catch(SQLException e) {
            System.err.println("Erro ao abrir conexão com o banco: " + e.getMessage());
            System.err.println("Código de erro SQL: " + e.getErrorCode());
            System.err.println("Estado SQL: " + e.getSQLState());
            e.printStackTrace();
            return null;
        }
    }

    public static void fecharConexaoBD() {
        try {
            if (conn != null && !conn.isClosed()) {
                conn.close();
                System.out.println("Conexão com o DB fechada.");
            }
        } catch(SQLException e) {
            System.err.println("Erro ao fechar conexão com o banco: " + e.getMessage());
            System.err.println("Código de erro SQL: " + e.getErrorCode());
            System.err.println("Estado SQL: " + e.getSQLState());
            e.printStackTrace();
        }
    }
}