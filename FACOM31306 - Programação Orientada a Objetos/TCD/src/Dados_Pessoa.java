import java.io.Serializable;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.InputMismatchException;

public abstract class Dados_Pessoa implements ConvertString, Serializable {
    //Atributos
    public String nome;
    public String dataNasc;
    private String CPF;

    //Construtor
    public Dados_Pessoa(String nome, String data, String CPF) {
        this.nome = nome;
        setDataNasc(data);
        setCPF(CPF);
    }

    //Getters e setters
    public String getNome() {
        return nome;
    }

    private void setNome(String nome) {
        this.nome = nome;
    }


    public String getDataNasc() {
        return dataNasc;
    }

    private void setDataNasc(String data) {
        try {
            if(verificaData(data) && ValidacaoDataNasc.dataValida(data)) {
                this.dataNasc = data;
            }
        } catch (DateTimeParseException e) {
            System.out.println("Erro: " + e.getMessage());
            this.dataNasc = null;
        }
    }

    public boolean isDataValida() {
        return verificaData(this.dataNasc) && ValidacaoDataNasc.dataValida(this.dataNasc);
    }

    public String getCPF() {
        return CPF;
    }

    private void setCPF(String CPF) {
        try {
            if (verificaCPF(CPF) && ValidacaoCPF.CPFvalido(CPF)) {
                this.CPF = CPF;
            }
        } catch (IllegalArgumentException e) {
            System.out.println("Erro: " + e.getMessage());
            this.CPF = null;
        }
    }

    public boolean isCPFValido() {
        try {
            return verificaCPF(this.CPF) && ValidacaoCPF.CPFvalido(this.CPF);
        } catch (IllegalArgumentException e) {
            return false;
        }
    }

    public String getCPFErrorMessage() {
        try {
            ValidacaoCPF.CPFvalido(this.CPF);
            return null;
        } catch (IllegalArgumentException e) {
            return e.getMessage();
        }
    }

    //Verificações - CPF e data nascimento
    /* Nas funções de cpf e data de nascimento usarei o recurso "regex" - Regular Expression.
    * Usarei esse formato para evitar a ocorrência de vários ifs os quais prejudicam a rapidez do programa.
    * Referência utilizada: https://www.w3schools.com/java/java_regex.asp */
    public boolean verificaCPF(String cpf) {
        return cpf.matches("\\d{3}\\.\\d{3}\\.\\d{3}-\\d{2}");
    }
    public boolean verificaData(String data) {
        return data.matches("\\d{2}/\\d{2}/\\d{4}");
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

    public boolean mudaDataNasc (String data) {
        if(verificaData(data) && ValidacaoDataNasc.dataValida(data)) {
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
            this.dataNasc = String.valueOf(LocalDate.parse(data, formatter));
            if(this.dataNasc.equals(data)) {
                System.out.println("Nova data idêntica a anterior. Tente novamente.");
                return false;
            } else {
                setDataNasc(data);
                return true;
            }
        }
        return false;
    }

    public boolean mudaCPF(String cpfnovo) {
        if(verificaCPF(cpfnovo) && ValidacaoCPF.CPFvalido(cpfnovo)) {
            if(this.CPF.equals(cpfnovo)) {
                System.out.println("Novo CPF idêntico a anterior. Tente novamente.");
                return false;
            } else {
                setCPF(cpfnovo);
                return true;
            }
        }
        return false;
    }

    //Impressão dos dados pessoais
    public String toString(){
        return "Nome: " + this.nome + "\nData de nascimento: " + this.dataNasc + "\nCPF: " + this.CPF;
    }
}