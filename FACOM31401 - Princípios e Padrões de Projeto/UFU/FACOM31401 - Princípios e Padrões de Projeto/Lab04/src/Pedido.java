import java.util.ArrayList;
import java.util.List;

public class Pedido {
    private String cliente;
    private List<Double> itens;

    public Pedido(String cliente, List<Double> itens) {
        this.cliente = cliente;
        this.itens = itens;
    }

    public void processarPedido() {
        System.out.println("Processando pedido para o cliente: " + cliente);
        double subtotal = getSubtotal();
        double desconto = getDesconto(subtotal);
        double imposto = getImposto(subtotal, desconto);
        double total = getTotal(subtotal, desconto, imposto);
        printInformacoesPedido(subtotal, desconto, imposto, total);
    }

    private void printInformacoesPedido(double subtotal, double desconto, double imposto, double total) {
        System.out.println("Subtotal: R$" + subtotal);
        System.out.println("Desconto: R$" + desconto);
        System.out.println("Imposto: R$" + imposto);
        System.out.println("Total: R$" + total);
    }

    private double getTotal(double subtotal, double desconto, double imposto) {
        double total = subtotal - desconto + imposto;
        return total;
    }

    private double getImposto(double subtotal, double desconto) {
        double imposto = (subtotal - desconto) * 0.08;
        return imposto;
    }

    private double getDesconto(double subtotal) {
        double desconto = 0;
        if (subtotal > 100) {
            desconto = subtotal * 0.1;
        }
        return desconto;
    }

    private double getSubtotal() {
        double subtotal = 0;
        for (double item : itens) {
            subtotal += item;
        }
        return subtotal;
    }
}
