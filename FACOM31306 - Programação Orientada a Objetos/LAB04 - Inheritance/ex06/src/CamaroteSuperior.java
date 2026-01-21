public class CamaroteSuperior extends VIP {
        /*
- Crie uma classe chamada {Ingresso}, que possui um valor e um método {escreveValor()}. Em seguida:
- Crie uma classe {VIP}, que herda {Ingresso} e possui um valor adicional. Crie um método que retorne o valor do ingresso VIP (com o adicional incluído).
- Crie uma classe {Normal}, que herda {Ingresso} e possui um método que imprime: "Ingresso Normal".
- Crie uma classe {CamaroteInferior} (que possui a localização do ingresso e métodos para acessar e imprimir esta localização) e uma
classe {CamaroteSuperior}, que é mais cara (possui valor adicional). Esta última possui um método para retornar o valor do ingresso.
Ambas as classes herdam a classe {VIP}.
     */
    double valorAdicionalC;

    //construtor
    public CamaroteSuperior(double valor, double valorAdicional, double valorAdicionalC) {
        super(valor, valorAdicional);
        this.valorAdicionalC = valorAdicionalC;
    }

    //gets e sets
    public double getValorAdicionalC() {
        return valorAdicionalC;
    }
    public void setValorAdicionalC(double valorAdicionalC) {
        this.valorAdicionalC = valorAdicionalC;
    }

    //retonar valor
    public double retornarValor() {
        return(getValor()+getValorAdicional()+valorAdicionalC);
    }
}
