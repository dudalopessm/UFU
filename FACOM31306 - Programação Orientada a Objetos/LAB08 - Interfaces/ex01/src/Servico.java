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

    public boolean eMenorQue(Classificavel obj) {
        Servico compara = (Servico) obj;
        if(this.preco < compara.getPreco())
            return true;
        else
            return false;
    }

    public String toString() {
        return "Serviço de preço: " + getPreco();
    }
}