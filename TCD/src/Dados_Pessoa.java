import java.util.regex.Matcher;
public class Dados_Pessoa {
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
    public String nome;
    public String dataNasc;
    private String CPF;

    //Construtor
    public Dados_Pessoa(String nome, String dataNasc, String CPF) {
        this.nome = nome;
        setDataNasc(dataNasc);
        setCPF(CPF);
    }

    //Getters e setters
    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public String getDataNasc() {
        return dataNasc;
    }
    public void setDataNasc(String dataNasc) {
        if(verificaData(dataNasc)) {
            this.dataNasc = dataNasc;
        } else {
            System.out.println("Data de nascimento no formato inválido. Tente novamente.");
            this.dataNasc = "XX/XX/XXXX";
        }
    }
    public String getCPF() {
        return CPF;
    }
    public void setCPF(String CPF) {
        if(verificaCPF(CPF)) {
            this.CPF = CPF;
        } else {
            System.out.println("CPF no formato inválido. Tente novamente.");
            this.CPF = "XXX.XXX.XXX-XX";
        }
    }

    //Verificações - CPF e data nascimento
    /* Nas funções de cpf e data de nascimento usarei o recurso "regex" - Regular Expression.
    * Usarei esse formato para evitar a ocorrência de vários ifs os quais prejudicam a rapidez do programa.
    * Referência utilizada: https://www.w3schools.com/java/java_regex.asp */
    public boolean verificaCPF(String cpf) {
        String modelo = "\\d{3}\\.\\d{3}\\.\\d{3}-\\d{2}"; //Formato xxx.xxx.xxx-xx
        return cpf.matches(modelo);
    }
    public boolean verificaData(String data) {
        String modelo = "\\d{2}/\\d{2}/\\d{4}"; //Formato xx/xx/xxxx
        return data.matches(modelo);
    }

    //Mudanças cadastrais
    public boolean mudaNome(String nomenovo) {
        if(this.nome.equalsIgnoreCase(nomenovo)) {
            System.out.println("Novo nome idêntico ao anterior. Tente novamente.");
            return false;
        } else {
            setNome(nomenovo);
            return true;
        }
    }
    public boolean mudaDataNasc(String datanova) {
        if(this.dataNasc.equalsIgnoreCase(datanova)) {
            System.out.println("Nova data idêntica a anterior. Tente novamente.");
            return false;
        } else {
            if(verificaData(datanova)) {
                setDataNasc(datanova);
                return true;
            } else {
                return false;
            }
        }
    }
    public boolean mudaCPF(String cpfnovo) {
        if(this.CPF.equalsIgnoreCase(cpfnovo)) {
            System.out.println("Novo CPF idêntico a anterior. Tente novamente.");
            return false;
        } else {
            if(verificaCPF(cpfnovo)) {
                setCPF(cpfnovo);
                return true;
            } else {
                return false;
            }
        }
    }
}
