import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.Scanner;

public class Professor extends Dados_Pessoa{
    //Atributos
    private Universidade universidade;
    private String inicioContrato;
    public String departamento;

    //Construtor
    public Professor(String nome, String data, String CPF, String departamento, String inicioContrato, Universidade universidade) {
        super(nome, data, CPF);
        this.departamento = departamento;
        this.universidade = universidade;
        setInicioContrato(inicioContrato);
    }

    //Getters e setters
    public String getInicioContrato() {
        return inicioContrato;
    }

    public void setInicioContrato(String inicioContrato) {
        Scanner sc = new Scanner(System.in);
        String input = inicioContrato;
        boolean veri = false;

        while(!veri) {
            try {
                verificaDataContrato(input);
                this.inicioContrato = input;
                veri = true;
            } catch(ValidacaoContrato e) {
                System.out.println(e.getMessage());
                System.out.println("Digite nova data de início do contrato no formato dd/mm/aaaa: ");
                input = sc.nextLine();
            }
        }
        sc.close();
    }

    public String getDepartamento() {
        return departamento;
    }

    private void setDepartamento(String departamento) {
        this.departamento = departamento;
    }

    public Universidade getUniversidade() {
        return universidade;
    }

    private void setUniversidade(Universidade universidade) {
        this.universidade = universidade;
    }

    @Override
    public String toString() {
        return "\n____________________________________" + "\n\tPROFESSOR" + super.toString() + "\nInicio contrato: " + this.inicioContrato + "\nDepartamento: " + this.departamento;
    }

    //Verificação data do contrato
    private void verificaDataContrato(String data) {
        if(!verificaData(data)) {
            throw new ValidacaoContrato("Data deve estar no formato dd/mm/aaaa");
        }
        try {
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
            LocalDate dataContrato = LocalDate.parse(data, formatter);
            LocalDate dataFund = LocalDate.parse(universidade.getDataFundacao(), formatter);
            LocalDate hoje = LocalDate.now();

            if(dataContrato.isBefore(dataFund)) {
                throw new ValidacaoContrato("Data de início do contrato não pode ser anterior à da fundação da universidade.");
            }
            if(dataContrato.isAfter(hoje)) {
                throw new ValidacaoContrato("Data de inínicio do contrato não pode estar no futuro.");
            }
        } catch(DateTimeParseException e) {
            throw new ValidacaoContrato("Data inválida");
        }
    }

    //Mudanças cadastrais
    public boolean mudaInicioContrato(String novocontrato) {
        if(this.inicioContrato.equalsIgnoreCase(novocontrato)) {
            System.out.println("Data de início do contrato idêntica a anterior. Tente novamente.");
            return false;
        }
        try {
            verificaDataContrato(novocontrato);
            setInicioContrato(novocontrato);
            return true;
        } catch(ValidacaoContrato e) {
            System.out.println(e.getMessage());
            return false;
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