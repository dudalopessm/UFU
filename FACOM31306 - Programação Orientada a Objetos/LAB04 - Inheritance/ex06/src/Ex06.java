public class Ex06 {
    /*
- Crie uma classe chamada {Ingresso}, que possui um valor e um método {escreveValor()}. Em seguida:
- Crie uma classe {VIP}, que herda {Ingresso} e possui um valor adicional. Crie um método que retorne o valor do ingresso VIP (com o adicional incluído).
- Crie uma classe {Normal}, que herda {Ingresso} e possui um método que imprime: "Ingresso Normal".
- Crie uma classe {CamaroteInferior} (que possui a localização do ingresso e métodos para acessar e imprimir esta localização) e uma
classe {CamaroteSuperior}, que é mais cara (possui valor adicional). Esta última possui um método para retornar o valor do ingresso.
Ambas as classes herdam a classe {VIP}.
     */
    public static void main(String[]args) {
        double valorUnico = 60;
        Ingresso i1 = new Ingresso(valorUnico);
        VIP i2 = new VIP(valorUnico, 30);
        Normal i3 = new Normal(valorUnico);
        CamaroteInferior i4 = new CamaroteInferior(valorUnico, 40, "Cadeira superior 05");
        CamaroteSuperior i5 = new CamaroteSuperior(valorUnico, 40, 20);
        System.out.println("------------------- Ingressos -------------------");
        i1.escreveValor();
        System.out.println("Valor do ingresso VIP: " + i2.retornaValor());
        i3.retornaValor();
        i4.achaLocal();
        System.out.println("Valor do ingresso Camarote Superior: " + i5.retornaValor());
    }
}