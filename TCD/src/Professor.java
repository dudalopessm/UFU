public class Professor extends Dados_Pessoa {
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
    private String inicioContrato;
    public String departamento;

    //Construtor
    public Professor(String nome, String dataNasc, String CPF, String departamento, String inicioContrato) {
        super(nome, dataNasc, CPF);
        this.departamento = departamento;
        setInicioContrato(inicioContrato);
    }

    //Getters e setters
    public String getInicioContrato() {
        return inicioContrato;
    }
    public void setInicioContrato(String inicioContrato) {
        if(verificaData(inicioContrato)) {
            this.inicioContrato = inicioContrato;
        } else {
            System.out.println("Inicio do contrato no formato inválido. Tente novamente.");
        }
    }
    public String getDepartamento() {
        return departamento;
    }
    public void setDepartamento(String departamento) {
        this.departamento = departamento;
    }

    //Mudanças cadastrais
    public boolean mudaInicioContrato(String novocontrato) {
        if(this.inicioContrato.equalsIgnoreCase(novocontrato)) {
            System.out.println("Data de início do contrato idêntica a anterior. Tente novamente.");
            return false;
        } else {
            if(verificaData(novocontrato)) {
                setInicioContrato(novocontrato);
                return true;
            } else {
                System.out.println("Data de início de contrato no formato inválido. Tente novamente.");
                return false;
            }
        }
    }
    public boolean mudaDepartamento(String novodep) {
        if(this.departamento.equalsIgnoreCase(novodep)) {
            System.out.println("Novo departamento idêntico ao anterior. Tente novamente.");
            return false;
        } else {
            setDepartamento(novodep);
            return true;
        }
    }
}
