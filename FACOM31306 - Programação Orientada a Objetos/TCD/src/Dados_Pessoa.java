import java.time.DateTimeException;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.InputMismatchException;
import java.util.Scanner;

public abstract class Dados_Pessoa implements ConvertString {
    //Atributos
    public String nome;
    public String dataNasc;
    private String CPF;
    // TRABALHAR NISSO USANDO INTERFACES
    private String login;
    private String senha;

    //Construtor
    public Dados_Pessoa(String login, String nome, String data, String CPF) {
        setLogin(login);
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
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        return dataNasc.format(String.valueOf(formatter));
    }

    private void setDataNasc(String data) {
        Scanner sc = new Scanner(System.in);
        String input = data;
        boolean veri = false;
        while(!veri) {
            try {
                if(verificaData(input) && ValidacaoDataNasc.dataValida(input)) {
                    DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
                    this.dataNasc = String.valueOf(LocalDate.parse(input, formatter));
                } else {
                    System.out.println("Data inválida. Digite novamente no formato dd/mm/aaaa: ");
                    input = sc.nextLine();
                }
            } catch(InputMismatchException e) {
                System.out.println(e.getMessage());
                System.out.println("Digite novamente no formato dd/mm/aaaa: ");
                input = sc.nextLine();
            } catch(DateTimeParseException e) {
                System.out.println("Formato de data inválido. Digite novamente no formato dd/mm/aaaa: ");
                input = sc.nextLine();
            }
        }
    }

    public String getCPF() {
        return CPF;
    }

    private void setCPF(String CPF) {
        Scanner sc = new Scanner(System.in);
        String input = CPF;
        boolean veri = false;

        while(!veri) {
            try {
                if(verificaCPF(input) && ValidacaoCPF.CPFvalido(input)) {
                    this.CPF = input;
                    veri = true;
                } else {
                    System.out.println("CPF inválido. Digite novamente (xxx.xxx.xxx-xx):");
                    input = sc.nextLine();
                }
            } catch(IllegalArgumentException e) {
                System.out.println(e.getMessage());
                System.out.println("Digite novamente (xxx.xxx.xxx-xx):");
                input = sc.nextLine();
            } catch(InputMismatchException e) {
                System.out.println(e.getMessage());
                System.out.println("Digite novamente (xxx.xxx.xxx-xx):");
                input = sc.nextLine();
            }
        }
        sc.close();
    }

    public String getLogin() {
        return login;
    }

    private void setLogin(String login) {
        this.login = login;
    }

    public String getSenha() {
        return senha;
    }

    private void setSenha(String senha) {
        this.senha = senha;
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