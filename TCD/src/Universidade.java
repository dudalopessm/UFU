import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.ArrayList;
public class Universidade {
    public String nome;
    public String dataFundacao;

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
        //continuar a partir do item 5
        ArrayList<Disciplinas> disciplinas = new ArrayList<Disciplinas>();
        ArrayList<Professor> professores = new ArrayList<Professor>();
        ArrayList<Estudante> estudantes = new ArrayList<Estudante>();
    }
}
