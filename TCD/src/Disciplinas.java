public class Disciplinas {
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
    public String codigo;
    public String nome;
    public String cargaHoraria;

    //Construtor
    public Disciplinas(String nome, String codigo, String cargaHoraria) {
        this.nome = nome;
        this.codigo = codigo;
        this.cargaHoraria = cargaHoraria;
    }

    //Getters e setters
    public String getCodigo() {
        return codigo;
    }
    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }
    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public String getCargaHoraria() {
        return cargaHoraria;
    }
    public void setCargaHoraria(String cargaHoraria) {
        this.cargaHoraria = cargaHoraria;
    }

    //Mudanças cadastrais
    public boolean mudaNome(String novo) {
        if(this.nome.equalsIgnoreCase(novo)) {
            System.out.println("Nome anterior idêntico ao novo. Tente novamente.");
            return false;
        } else {
            setNome(novo);
            return true;
        }
    }
    public boolean mudaCodigo(String novo) {
        if(this.codigo.equalsIgnoreCase(novo)) {
            System.out.println("Código anterior idêntico ao novo. Tente novamente.");
            return false;
        } else {
            setCodigo(novo);
            return true;
        }
    }
    public boolean mudaCargaHoraria(String novo) {
        if(this.cargaHoraria.equalsIgnoreCase(novo)) {
            System.out.println("Carga horária anterior idêntico ao novo. Tente novamente.");
            return false;
        } else {
            setCargaHoraria(novo);
            return true;
        }
    }
}