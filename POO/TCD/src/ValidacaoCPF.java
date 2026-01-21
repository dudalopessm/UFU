import java.util.InputMismatchException;

/* Fonte do cálculo do dígito verificador: https://www.campuscode.com.br/conteudos/o-calculo-do-digito-verificador-do-cpf-e-do-cnpj */

public abstract class ValidacaoCPF {
    public static boolean CPFvalido(String cpf) {
        if (cpf == null) return false;

        String cpfNumerico = cpf.replace(".", "").replace("-", "");

        if (cpfNumerico.length() != 11) return false;

        if (cpfNumerico.matches("(\\d)\\1{10}")) return false;

        int[] digitos = new int[11];
        try {
            for (int i = 0; i < 11; i++) {
                digitos[i] = Character.getNumericValue(cpfNumerico.charAt(i));
            }
        } catch (NumberFormatException e) {
            return false;
        }

        int soma = 0;
        for (int i = 0; i < 9; i++) {
            soma += digitos[i] * (10 - i);
        }
        int primeiroDigito = 11 - (soma % 11);
        if (primeiroDigito > 9) primeiroDigito = 0;

        if (digitos[9] != primeiroDigito) return false;

        soma = 0;
        for (int i = 0; i < 10; i++) {
            soma += digitos[i] * (11 - i);
        }
        int segundoDigito = 11 - (soma % 11);
        if (segundoDigito > 9) segundoDigito = 0;

        return digitos[10] == segundoDigito;
    }
}