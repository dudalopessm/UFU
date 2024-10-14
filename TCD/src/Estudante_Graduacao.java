import java.util.regex.Matcher;
public class Estudante_Graduacao extends Dados_Pessoa {
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
    //Atributos
    private double CRA;
    public String estagio;

    //Construtor
    public Estudante_Graduacao(String nome, String dataNasc, String CPF, double CRA, String estagio) {
        super(nome, dataNasc, CPF);
        setCRA(CRA);
        this.estagio = estagio;
    }

    //Getters e setters
    public double getCRA() {
        return CRA;
    }
    public void setCRA(double CRA) {
        if(verificaCRA(CRA)) {
            this.CRA = CRA;
        } else {
            System.out.println("CRA deve ser número válido. Será colocado 0.");
            this.CRA = 0;
        }
    }
    public String getEstagio() {
        return estagio;
    }
    public void setEstagio(String estagio) {
        this.estagio = estagio;
    }

    //Verifica se CRA é número entre 0 e 100
    public boolean verificaCRA(double cra) {
        if(cra < 0 || cra > 100) {
            System.out.println("CRA deve ser número real entre 0 e 100. Tente novamente.");
            return false;
        } else {
            return true;
        }
    }

    //Mudanças cadastrais
    public boolean mudaEstagio(String est) {
        if(this.estagio.equalsIgnoreCase(est)) {
            System.out.println("Novo estágio idêntico ao anterior. Tente novamente.");
            return false;
        } else {
            setEstagio(est);
            return true;
        }
    }
    public boolean mudaCRA(double cra) {
        if(this.CRA == cra) {
            System.out.println("Novo CRA idêntico ao anterior. Tente novamente.");
            return false;
        } else {
            if(verificaCRA(cra)) {
                setCRA(cra);
                return true;
            } else {
                return false;
            }
        }
    }
}