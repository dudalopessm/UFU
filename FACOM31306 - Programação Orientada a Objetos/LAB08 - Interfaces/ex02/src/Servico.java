public class Servico implements Classificavel {
    public float preco;

    public Servico(float preco) {
        this.preco = preco;
    }

    public float getPreco() {
        return preco;
    }

    public void setPreco(float preco) {
        this.preco = preco;
    }

    public int eMenorQue(Classificavel obj) {
        Servico compara = (Servico) obj;
        if(this.preco < compara.getPreco())
            return -1;
        else if (this.preco > compara.getPreco())
            return 1;
        else
            return 0;
    }

    public String toString() {
        return "Serviço de preço: " + getPreco();
    }
}