public class Turma {
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
    public Disciplinas materia;
    public String semestre;
    public int ano;

    //Construtor
    public Turma(Disciplinas materia, String semestre, int ano) {
        this.materia = new Disciplinas(materia.getNome(), materia.getCodigo(), materia.getCargaHoraria());
        this.semestre = semestre;
        this.ano = ano;
    }

    //Getters e setters
    public Disciplinas getMateria() {
        return materia;
    }
    public void setMateria(Disciplinas materia) {
        this.materia = materia;
    }
    public String getSemestre() {
        return semestre;
    }
    public void setSemestre(String semestre) {
        this.semestre = semestre;
    }
    public int getAno() {
        return ano;
    }
    public void setAno(int ano) {
        this.ano = ano;
    }

    //Verificação da formatação do semestre (ano.semestre)
    public boolean verificaSemestre(String sem) {

    }
}