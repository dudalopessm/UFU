public class Ex07 {
    public static void insertionSort(Produto[] lista) {
        int n = lista.length;
        for( int j = 1; j < n; j++) {
            Produto chave = lista[j];
            int i = j - 1;
            while(i > -1 && lista[i].getNomeProd().compareTo(chave.getNomeProd()) > 0) {
                lista[i+1] = lista[i];
                i--;
            }
            lista[i+1] = chave;
        }
    }

    public static void main(String[]args) {
        Produto[] listaProdutosTotal = new Produto[14];
        //definindo produtos
        listaProdutosTotal[0] = new Produto("Alvejante", 19.99F, 77);
        listaProdutosTotal[1] = new Produto("Sabão em pó OMO", 12.99F, 80);
        listaProdutosTotal[2] = new Produto("Detergente", 5.99F, 123);
        listaProdutosTotal[3] = new Produto("Máscara de cílios Maybelline New York", 42.99F, 13);
        listaProdutosTotal[4] = new Produto("Shampoo aussie", 37.99F, 40);
        listaProdutosTotal[5] = new Produto("Corretivo Nina Secrets", 51.99F, 36);
        listaProdutosTotal[6] = new Produto("Base Mari Maria Makeup", 54.99F, 22);
        listaProdutosTotal[7] = new Produto("Òleo capilar Wella Oil Reflections", 84.99F, 18);
        listaProdutosTotal[8] = new Produto("Bolacha Danix Sensação Gelada", 1.97F, 230);
        listaProdutosTotal[9] = new Produto("Coca-cola 2L", 8.99F, 507);
        listaProdutosTotal[10] = new Produto("Arroz Cocal 5KG", 12.99F, 367);
        listaProdutosTotal[11] = new Produto("Maionese Hellmans", 13.99F, 153);
        //definindo produtos não cadastrados -> não possuem preço definido ainda
        listaProdutosTotal[12] = new Produto("Limpa-vidros Veja", 51);
        listaProdutosTotal[13] = new Produto("Nutella 200g", 132);

        //testando ordenação por ordem alfabética
        System.out.println("~~~~~~~~~~~~~~~~~~~~ Produtos antes da ordenação ~~~~~~~~~~~~~~~~~~~~");
        for(Produto produto : listaProdutosTotal) {
            produto.imprime_produto();
        }

        //mudando quantidades de produtos para teste da função
        System.out.println("\n~~~~~~~~~~~~~~~~~~~~ Mudando quantidades ~~~~~~~~~~~~~~~~~~~~");
        listaProdutosTotal[2].alteraEstoque("Aumentar", -2);
        listaProdutosTotal[3].alteraEstoque("Aumentar", 30);
        listaProdutosTotal[0].alteraEstoque("diminuir", 78);
        listaProdutosTotal[9].alteraEstoque("diminuir", 7);

        //mudando preços de produtos para teste da função
        System.out.println("\n~~~~~~~~~~~~~~~~~~~~ Mudando preços ~~~~~~~~~~~~~~~~~~~~");
        listaProdutosTotal[0].alteraPreco(-5);
        listaProdutosTotal[1].alteraPreco(100);
        listaProdutosTotal[2].alteraPreco(-101);
        listaProdutosTotal[13].setPrecoProd(15.99F);
        listaProdutosTotal[12].setPrecoProd(9.99F);

        System.out.println("\n~~~~~~~~~~~~~~~~~~~~ Produtos depois da ordenação ~~~~~~~~~~~~~~~~~~~~");
        insertionSort(listaProdutosTotal);
        for(Produto produto : listaProdutosTotal) {
            produto.imprime_produto();
        }
    }
}