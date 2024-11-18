import java.io.Serializable;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.ArrayList;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

public class Universidade implements Serializable {
    public String nome;
    public String dataFundacao;
    public ArrayList<Disciplinas> disciplinas = new ArrayList<Disciplinas>();
    public ArrayList<Professor> professores = new ArrayList<Professor>();
    public ArrayList<Estudante> estudantes = new ArrayList<Estudante>();

    public Universidade(String nome, String dataFundacao) {
        this.nome = nome;
        this.dataFundacao = dataFundacao;
    }

    public String getDataFundacao() {
        return this.dataFundacao;
    }

    public void setDataFundacao(String data) {
        try {
            if(ValidacaoDataNasc.dataValida(data)) {
                DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
                LocalDate.parse(data, formatter);
                this.dataFundacao = data;
            } else {
                throw new IllegalArgumentException("Data de fundação deve estar no formato dd/mm/aaaa");
            }
        } catch(DateTimeParseException e) {
            throw new IllegalArgumentException("Data de fundação inválida.");
        }
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    //try with resources: https://pt.stackoverflow.com/questions/172909/como-funciona-o-try-with-resources, https://www.baeldung.com/java-try-with-resources
    public void escreverUniversidade(String nomeArq){
        try (FileOutputStream arq = new FileOutputStream(nomeArq); ObjectOutputStream os = new ObjectOutputStream(arq)) {
            os.writeObject(this);
            System.out.println("Dados salvos com sucesso no arquivo: " + nomeArq);

        } catch (IOException e) {
            System.err.println("Erro ao escrever no arquivo: " + nomeArq);
            e.printStackTrace();
        }
    }

    /*
- Vamos registrar as atividades acadêmicas de uma universidade
- 1) É necessário fazer o cadastro de estudantes. Para eles são armazenadas as informações de CPF, Nome, Data de Nascimento, CRA
- 2) É necessário fazer o cadastro de Professores. Para eles são armazenados o CPF, Nome, Data de Nascimento, Início do contrato,
Departamento Vinculado
3) Os estudantes podem ser de graduação ou pós-graduação. Os alunos de graduação devem realizar um estágio supervisionado.
Já os de pós-graduação devem ter um tema de pesquisa
4) As disciplinas possuem um código, um nome e uma carga horária
5) Devem ser criadas turmas para as disciplinas, indicando o semestre e ano da turma.
Faça um programa principal que permita realizar o cadastro e consulta de todas essas informações.
Para facilitar o teste do sistema, crie algumas funções para popular o sistema (colocar dados) sem a necessidade de digitação,
embora a possibilidade de cadastrar os dados deva estar disponível.
*/
public static void main(String args[]) {
    // continuar a partir do item 5
    Universidade ufu = new Universidade("UFU", "01/11/2015");
    {
        Professor aux = new Professor("Carlos Sergio", "12/11/1975", "700.179.826-69", "Facom", "15/12/2018", ufu);
        ufu.professores.add(aux);

        aux = new Professor("Maria da Silva", "05/03/1982", "876.543.210-06", "Fafich", "20/01/2021", ufu);
        ufu.professores.add(aux);

        aux = new Professor("João Paulo", "28/07/1968", "123.456.789-09", "Farmácia", "10/06/2018", ufu);
        ufu.professores.add(aux);

        aux = new Professor("Ana Beatriz", "18/10/1990", "987.654.321-00", "Medicina", "01/09/2023", ufu);
        ufu.professores.add(aux);

        aux = new Professor("Pedro Henrique", "02/04/1979", "456.789.012-02", "Engenharia", "18/03/2019", ufu);
        ufu.professores.add(aux);

        aux = new Professor("Laura Santos", "25/12/1985", "789.012.345-02", "Direito", "05/07/2022", ufu);
        ufu.professores.add(aux);

        aux = new Professor("Ricardo Almeida", "11/06/1995", "321.654.987-08", "Ciências", "28/11/2020", ufu);
        ufu.professores.add(aux);

        aux = new Professor("Juliana Oliveira", "09/09/1972", "654.321.987-04", "Educação Física", "15/04/2017", ufu);
        ufu.professores.add(aux);

        aux = new Professor("Rafael Costa", "17/08/1988", "147.258.369-60", "Música", "30/05/2023", ufu);
        ufu.professores.add(aux);

        aux = new Professor("Camila Ferreira", "22/05/1992", "581.364.792-70", "Letras", "20/10/2016", ufu);
        ufu.professores.add(aux);
    }
    {
        Estudante est = new Estudante_Graduacao("Lucas Matos", "05/04/2006", "540.544.334-33", 86.3, "QTI");
        ufu.estudantes.add(est);

        est = new Estudante_Graduacao("Maria Silva", "12/11/2005", "123.456.789-09", 78.9, "fisk");
        ufu.estudantes.add(est);

        est = new Estudante_Graduacao("João Souza", "28/07/2004", "987.654.321-00", 92.5, "Drumind edificios");
        ufu.estudantes.add(est);

        est = new Estudante_Graduacao("Ana Santos", "15/03/2007", "456.789.012-02", 81.2, "UBS");
        ufu.estudantes.add(est);

        est = new Estudante_Graduacao("Pedro Oliveira", "02/09/2006", "789.012.345-02", 75.0, "VTR");
        ufu.estudantes.add(est);

        est = new Estudante_Graduacao("Laura Almeida", "21/06/2005", "321.654.987-08", 95.8, "Sankha");
        ufu.estudantes.add(est);

        est = new Estudante_Graduacao("Ricardo Costa", "18/10/2007", "654.321.987-04", 88.1, "Drogasil");
        ufu.estudantes.add(est);

        est = new Estudante_Graduacao("Juliana Ferreira", "05/05/2004", "147.258.369-60", 72.7, "Lar Doce");
        ufu.estudantes.add(est);

        est = new Estudante_Graduacao("Rafael Santos", "11/12/2006", "581.364.792-70", 90.0, "NTT Data");
        ufu.estudantes.add(est);

        est = new Estudante_Graduacao("Camila Costa", "29/08/2005", "258.369.147-81", 84.6, "Lumini");
        ufu.estudantes.add(est);
    }
    {
        Estudante_PosGraduacao grad = new Estudante_PosGraduacao("Maria Luiza", "15/06/2002", "658.658.453-53", 59.3, "Arodinamica das vacas");
        ufu.estudantes.add(grad);

        grad = new Estudante_PosGraduacao("João Pedro", "20/03/1998", "123.456.789-09", 82.1, "Desenvolvimento de algoritmos de aprendizado de máquina para diagnóstico médico");
        ufu.estudantes.add(grad);

        grad = new Estudante_PosGraduacao("Ana Clara", "01/11/2000", "987.654.321-00", 75.5, "O papel da biodiversidade na mitigação das mudanças climáticas");
        ufu.estudantes.add(grad);

        grad = new Estudante_PosGraduacao("Pedro Henrique", "10/07/1999", "456.789.012-02", 90.8, "Análise da eficiência energética em edifícios sustentáveis");
        ufu.estudantes.add(grad);

        grad = new Estudante_PosGraduacao("Laura Beatriz", "25/12/2001", "789.012.345-02", 68.2, "Estudos sobre a influência da mídia social no comportamento do consumidor");
        ufu.estudantes.add(grad);

        grad = new Estudante_PosGraduacao("Ricardo Silva", "18/05/1997", "321.654.987-08", 85.9, "Investigação sobre novas terapias para doenças neurodegenerativas");
        ufu.estudantes.add(grad);

        grad = new Estudante_PosGraduacao("Juliana Oliveira", "08/09/1996", "654.321.987-04", 78.0, "Modelagem matemática de sistemas ecológicos");
        ufu.estudantes.add(grad);

        grad = new Estudante_PosGraduacao("Rafael Santos", "15/04/2001", "147.258.369-60", 92.3, "O impacto da globalização na economia brasileira");
        ufu.estudantes.add(grad);

        grad = new Estudante_PosGraduacao("Camila Souza", "22/10/2000", "581.364.792-70", 71.6, "Desenvolvimento de novos materiais para aplicações em energia renovável");
        ufu.estudantes.add(grad);

        grad = new Estudante_PosGraduacao("Daniel Ferreira", "03/02/1999", "258.369.147-81", 88.7, "Estudos sobre a diversidade genética de espécies ameaçadas de extinção");
        ufu.estudantes.add(grad);
    }
    ufu.escreverUniversidade("baseDedados");

}
}