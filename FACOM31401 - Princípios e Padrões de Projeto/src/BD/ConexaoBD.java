package BD;
import java.sql.*;

public class ConexaoBD {
    public static void abrirConexaoBD() {
        String url = "jdbc:derby:C:/Faculdade/Quarto_Periodo/PPP/Labs/Lab05/BDProdutos";

        try {
            Connection conn = DriverManager.getConnection(url);
            System.out.println("Conexão estabelecida com o DB.");
            conn.close();
        } catch(SQLException e) {
            e.printStackTrace();
        }
    }

    public static void fecharConexaoBD() {
        String url = "jdbc:derby:C:/Faculdade/Quarto_Periodo/PPP/Labs/Lab05/BDProdutos";

        try {
            Connection conn = DriverManager.
        }
    }
}
