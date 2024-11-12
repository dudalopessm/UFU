import java.util.InputMismatchException;
import java.util.Scanner;

public abstract class Estudante extends Dados_Pessoa{
    private double CRA;
    
    //Construtor
    public Estudante(String nome, String data, String CPF, double CRA){
        super(nome, data, CPF);
        setCRA(CRA);
    }

    //Getters e setters
    public double getCRA() {
        return this.CRA;
    }

    private void setCRA(double cra) {
        Scanner sc = new Scanner(System.in);
        boolean veri = false;
        double input = cra;
        while(!veri) {
            try {
                verificaCRA(cra);
                this.CRA = cra;
                veri = true;
            } catch(ValidacaoCRA e) {
                System.out.println(e.getMessage());
                System.out.println("Digite o CRA novamente, de 0 a 100: ");
                try {
                    cra = sc.nextDouble();
                } catch(InputMismatchException ee) {
                    System.out.println("Digite um número válido.");
                    sc.nextLine();
                }
            }
        }
    }

    @Override
    public String toString(){
        return super.toString() + "\nCRA: " + this.CRA;
    }

     //Verifica se CRA é número entre 0 e 100
     public boolean verificaCRA(double cra) throws ValidacaoCRA {
        if(cra < 0 || cra > 100) {
            throw new ValidacaoCRA("CRA deve estar entre 0 e 100.");
        }
        return true;
    }

    //Mudanças cadastrais
    public boolean mudaCRA(double cra) {
        if(verificaCRA(cra)) {
            setCRA(cra);
            return true;
        }
        return false;
    }
}