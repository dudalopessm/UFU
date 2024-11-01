public class Universidade {
    public String nome;
    private String dataFundacao;
    public int quantidadeAlunos;
    public Estudante[] listaAlunos;

    public Universidade(String nome, String data, int quantidade, Estudante[] lista) {
     this.nome = nome;
     this.dataFundacao = data;
     setQuantidadeAlunos(quantidade);
     this.listaAlunos = new Estudante[this.quantidadeAlunos];
     for(int i = 0; i < lista.length; i++) {
         this.listaAlunos[i] = new Estudante(lista[i].getNome(), lista[i].getEndereco());
     }
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getDataFundacao() {
        return dataFundacao;
    }

    public void setDataFundacao(String dataFundacao) {
        this.dataFundacao = dataFundacao;
    }

    public int getQuantidadeAlunos() {
        return quantidadeAlunos;
    }

    public void setQuantidadeAlunos(int quantidadeAlunos) {
        if(quantidadeAlunos > 100) {
            this.quantidadeAlunos = 100;
        } else if(quantidadeAlunos < 0) {
            this.quantidadeAlunos = 0;
        }else {
            this.quantidadeAlunos = quantidadeAlunos;
        }
    }

    public Estudante[] getListaAlunos() {
        return listaAlunos;
    }

    public void setListaAlunos(Estudante[] listaAlunos) {
        this.listaAlunos = listaAlunos;
    }

    public void contaAlunos(Estudante [] listaAlunos) {
        int grad = 0, posgrad = 0, mest = 0, dout = 0;

        for (Estudante elemento : listaAlunos) {
            if (elemento instanceof EstudanteGraduacao) {
                grad++;
            }  else if (elemento instanceof EstudanteMestrado) {
                mest++;
            } else if (elemento instanceof EstudanteDoutorado) {
                dout++;
            } else if (elemento instanceof EstudantePosGrad) {
                posgrad++;
            }
        }
        System.out.println("\n---------------------- GRADUAÇÃO ----------------------\nTotal alunos: " + grad);
        System.out.println("\n---------------------- PÓS GRADUAÇÃO ----------------------\nTotal alunos: " + posgrad);
        System.out.println("\n---------------------- MESTRADO ----------------------\nTotal alunos: " + mest);
        System.out.println("\n---------------------- DOUTORADO ----------------------\nTotal alunos: " + dout);
    }


    public void mostraAlunos() {
        System.out.println("\n---------------------- TODOS OS ALUNOS ----------------------");
        for(Estudante elemento : this.listaAlunos) {
            elemento.print();
            if(elemento instanceof EstudanteDoutorado)
                System.out.println("\nTese: " + ((EstudanteDoutorado)elemento).getTituloTese() + "\nLinha de pesquisa: " + ((EstudanteDoutorado)elemento).getLinhaDePesquisa());
        }
    }
}
