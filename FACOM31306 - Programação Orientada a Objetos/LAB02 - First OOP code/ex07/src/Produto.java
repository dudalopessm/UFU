public class Produto {
    private String nomeProduto;
    private float precoProduto;
    private int quantidadeEstoque;

    //quando já tenho o preço
    public Produto(String nome, float preco, int quant) {
        this.nomeProduto = nome;
        this.precoProduto = preco;
        this.quantidadeEstoque = quant;
    }
    //quando não tenho o preço
    public Produto(String nome, int quant) {
        this.nomeProduto = nome;
        this.precoProduto = 0;
        this.quantidadeEstoque = quant;
    }

    //getters
    public String getNomeProd() {
        return this.nomeProduto;
    }
    public float getPrecoProd() {
        return this.precoProduto;
    }
    public int getQuantProd() {
        return this.quantidadeEstoque;
    }

    //setters para auxílio nas funções de alteração
    public void setNomeProd(String nome) {
        this.nomeProduto = nome;
    }
    public void setPrecoProd(float preco) {
        this.precoProduto = preco;
    }
    public void setQuantProd(int quant) {
        this.quantidadeEstoque = quant;
    }

    //apaga produto
    public void destroiProduto() {
        setNomeProd(null);
        setPrecoProd(0);
        setQuantProd(0);
    }

    //alterações no estoque
    public void alteraEstoque(String opcao, int quantidade) {
        if(quantidade < 0) System.out.println("A quantidade deve ser um número inteiro positivo. Tente novamente.");
        if (opcao.equalsIgnoreCase("aumentar")) {
            setQuantProd((getQuantProd()) + quantidade);
            System.out.println("Quantidade de " + getNomeProd() + " aumentada para: " + getQuantProd());
        } else if (opcao.equalsIgnoreCase("diminuir")) {
            if(quantidade > getQuantProd()) {
                setQuantProd(0);
                System.out.println("Quantidade do produto decrescida para 0, pois o valor " + quantidade + " é maior do que os " + getQuantProd() + " de " + getNomeProd() + " disponíveis.");
            } else {
                setQuantProd((getQuantProd()) - quantidade);
                System.out.println("Quantidade de " + getNomeProd() + " diminuída para: " + getQuantProd());
            }
        }
    }

    //alterações no preço
    public void alteraPreco(float porcentagem) {
        float aux;
        if (porcentagem > -100) {
            aux = 1 + (porcentagem/100);
            setPrecoProd((getPrecoProd()) * aux);
            System.out.println("Preço do produto " + getNomeProd() + " alterado para: " + getPrecoProd() + " ");
        } else {
            System.out.println("Porcentagem inválida! Preço irá decrescer para menor que 0. Tente novamente.");
        }
    }

    //imprime informações do objeto
    public void imprime_produto() {
        System.out.println("------------");
        System.out.println("Nome do produto: " + getNomeProd());
        System.out.println("Preço do produto: " + getPrecoProd());
        System.out.println("Quantidade disponível em estoque: " + getQuantProd());
    }
}
