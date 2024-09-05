public class Candidato {
        public static String nomeCompleto;
        public static String dataNascimento;
        public static String genero;
        public static double bens;
        public static boolean reeleicao;
        public static int numeroPartido;
        public static String cargoPretendido;
        public static int codigoMunicipio;
        public static String matriculaEleitoral;
        public static String municipio;

        public Candidato(String nome, String datanasc, String gen, double ben, boolean re, int nump, String carg, int codm, String mat, String mun) {
            nomeCompleto = nome;
            dataNascimento = datanasc;
            genero = gen;
            bens = ben;
            numeroPartido = nump;
            cargoPretendido = carg;
            codigoMunicipio = codm;
            matriculaEleitoral = mat;
            municipio = mun;
        }

        public static String ultimos3DigitosMatricula(String mat) {
            String aux;
            aux = mat.substring(mat.length()-3);
            return aux;
        }

        public static void mostrar() {
            System.out.println("---------------------------------------------------------");
            System.out.println("Matrícula por extenso: " + matriculaEleitoral);
            System.out.println("Código: " + ultimos3DigitosMatricula(matriculaEleitoral));
            System.out.println("Município: " + municipio);
            System.out.println("Nome: " + nomeCompleto);
            System.out.println("Data de nascimento: " + dataNascimento);
            System.out.println("Gênero: "+ genero);
            System.out.println("Bens totais declarados: " + bens);
            System.out.println("Candidato a reeleição?: " + reeleicao);
            System.out.println("Número do partido: " + numeroPartido);
            System.out.println("Cargo pretendido: " + cargoPretendido);
            System.out.println("---------------------------------------------------------");
        }
}
