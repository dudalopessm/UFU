package Codigo;

public class Produto {
    private int id;
    private String nome;
    private String descricao;
    private double preco;
    private int estoque;
    private final int max = 1000;

    public Produto(String nome, String descricao, double preco, int estoque) {
        this.nome = nome;
        this.descricao = descricao;
        setPreco(preco);
        setEstoque(estoque);
    }

    public Produto(int id, String nome, String descricao, double preco, int estoque) {
        this.id = id;
        this.nome = nome;
        this.descricao = descricao;
        setPreco(preco);
        setEstoque(estoque);
    }

    public Produto() {

    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getPreco() {
        return preco;
    }

    public void setPreco(double preco) {
        if(preco < 0)
            throw new IllegalArgumentException("Erro: preço não pode ser negativo.");
        else
            this.preco = preco;
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public int getEstoque() {
        return estoque;
    }

    public void setEstoque(int estoque) {
        if(estoque < 0 || estoque > max)
            throw new IllegalArgumentException("Erro: quantidade deve ser maior que zero e não deve exceder 1000.");
        else
            this.estoque = estoque;
    }

    @Override
    public String toString() {
        return "ID: " + getId()
                + " | Nome: " + getNome()
                + " | Descrição: " + getDescricao()
                + " | Preço: " + getPreco()
                + " | Estoque: " + getEstoque();
    }
}
