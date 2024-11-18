import java.io.Serializable;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.ArrayList;

public class Professor extends Dados_Pessoa implements Serializable {
    //Atributos
    private Universidade universidade;
    private String inicioContrato;
    public String departamento;
    private ArrayList<Turma> ministradas = new ArrayList<Turma>();

    //Construtor
    public Professor( String nome, String data, String CPF, String departamento, String inicioContrato, Universidade universidade) {
        super(nome, data, CPF);
        this.departamento = departamento;
        this.universidade = universidade;
        setInicioContrato(inicioContrato);
    }

    //Getters e setters
    public String getInicioContrato() {
        return inicioContrato;
    }

    private void setInicioContrato(String inicioContrato) {
        try {
            if(verificaDataContrato(inicioContrato)) {
                this.inicioContrato = inicioContrato;
            }
            } catch(DataInvalidaException e) {
                System.out.println("Erro: " + e.getMessage());
                this.inicioContrato = null;
        }
    }

    public boolean isInicioContratoValido() {
        try {
            return verificaDataContrato(this.inicioContrato);
        } catch (DataInvalidaException e) {
            return false;
        }
    }

    public String getInicioContratoErrorMessage() {
        try {
            verificaDataContrato(this.inicioContrato);
            return null;
        } catch (DataInvalidaException e) {
            return e.getMessage();
        }
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

    public void setMinstradas(Turma ministada){
        if(!ministradas.contains(ministada)){
            ministradas.add(ministada);
        }
    }
    public void removeMinistada(Turma ministada){
        ministradas.remove(ministada);
    }

    @Override
    public String toString() {
        return "\n____________________________________" + "\n\tPROFESSOR" + super.toString() + "\nInicio contrato: " + this.inicioContrato + "\nDepartamento: " + this.departamento;
    }

    //Verificação data do contrato
    private boolean verificaDataContrato(String data) {
        if(!verificaData(data)) {
            throw new DataInvalidaException("Data deve estar no formato dd/mm/aaaa");
        }
        try {
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
            LocalDate dataContrato = LocalDate.parse(data, formatter);
            LocalDate dataFund = LocalDate.parse(universidade.getDataFundacao(), formatter);
            LocalDate hoje = LocalDate.now();

            if(dataContrato.isBefore(dataFund)) {
                throw new DataInvalidaException("Data de início do contrato não pode ser anterior à da fundação da universidade.");
            }
            if(dataContrato.isAfter(hoje)) {
                throw new DataInvalidaException("Data de inínicio do contrato não pode estar no futuro.");
            }
        } catch(DateTimeParseException e) {
            throw new DataInvalidaException("Data inválida");
        }
        return true;
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
        } catch(DataInvalidaException e) {
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