import java.util.InputMismatchException;

/* Fonte do cálculo do dígito verificador: https://www.campuscode.com.br/conteudos/o-calculo-do-digito-verificador-do-cpf-e-do-cnpj */

public class ValidacaoCPF {
    public static boolean CPFvalido(String cpf) {
        if(cpf.length() != 11) {
            throw new IllegalArgumentException("CPF deve ter 11 dígitos. Tente novamente.");
        }

        cpf = cpf.replace(".", "").replace("-", "");

        int[] digitos = new int[11];

        try {
            for(int i = 0; i < 11; i++)
                digitos[i] = Integer.parseInt(cpf.substring(i, i+1));
        } catch (NumberFormatException e) {
            throw new InputMismatchException("CPF deve conter apenas dígitos numéricos inteiros. Tente novamente.");
        }

        int soma = 0;
        for(int i = 0; i < 9; i++)
            soma += (digitos[i]*(10-i));
        int resto = (soma*10)%11;
        if((resto == 10) || (resto == 1))
            resto = 0;
        if(digitos[9] != resto)
            throw new IllegalArgumentException("CPF com primeiro dígito verificador inválido. Tente novamente.");

        soma = 0;
        for(int i = 0; i < 10; i++)
            soma += (digitos[i]*(11-i));
        resto = (soma*10)%11;
        if((resto == 10) || (resto == 1))
            resto = 0;
        if(digitos[10] != resto)
            throw new IllegalArgumentException("CPF com segundo dígito verificador inválido. Tente novamente.");

        return true;
    }
}