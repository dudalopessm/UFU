import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.time.format.ResolverStyle;
import java.util.InputMismatchException;

/* Fonte: https://pt.stackoverflow.com/questions/187272/como-verificar-se-a-data-é-válida-ou-inválida */

public class ValidacaoDataNasc {
    public static boolean dataValida(String data) {
        String formato = "dd/MM/yyyy";
        DateTimeFormatter dateTimeFormatter = DateTimeFormatter.ofPattern(formato).withResolverStyle(ResolverStyle.STRICT);
        try {
            LocalDate date = LocalDate.parse(data, dateTimeFormatter);
            return true;
        } catch(DateTimeParseException e) {
            throw new InputMismatchException("Data digitada inválida. Tente novamente.");
        }
    }
}