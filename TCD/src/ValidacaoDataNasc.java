import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.time.format.ResolverStyle;
import java.util.InputMismatchException;

/* Fonte: https://pt.stackoverflow.com/questions/187272/como-verificar-se-a-data-é-válida-ou-inválida */

public abstract class ValidacaoDataNasc {
    public static boolean dataValida(String data) {
        String dateFormat = "dd/MM/uuuu";

        DateTimeFormatter dateTimeFormatter = DateTimeFormatter
                .ofPattern(dateFormat)
                .withResolverStyle(ResolverStyle.STRICT);
        try {
            LocalDate date = LocalDate.parse(data, dateTimeFormatter);
            return true;
        } catch (DateTimeParseException e) {
            return false;
        }
    }
}