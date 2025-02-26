import java.util.ArrayList;
public class Testes {
    public static void main(String[]args){
        ArrayList<Double> lista = new ArrayList<>();
        lista.add(56.90);
        lista.add(43.20);
        lista.add(1.39);
        Pedido teste = new Pedido("Eduarda", lista);
        teste.processarPedido();

        System.out.println("\n");

        Pessoa teste2 = new Pessoa("Eduarda", "cachorrofofo123@email", "1111111111", "Flores", "Narnia", "Cachoeirinha", "78600-345");
        teste2.exibirInformacoes();

        System.out.println("\n");

        Carro teste3 = new Carro("Carro do James Bond", "Aston Martin", 2025);
        Moto teste4 = new Moto("Ninja", "Kawasaki", 2023);
        teste3.ligar();
        teste4.ligar();

        System.out.println("\n");

        ContaBancaria teste6 = new ContaBancaria(8779.78, 0.01);
        Cliente teste5 = new Cliente("Duda", teste6);
        System.out.println("Juros: " + teste6.calcularJuros());
    }
}