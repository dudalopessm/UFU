public class Classificador {
    public static void ordena(Classificavel[] a) {
        int n = a.length;
        for(int j = 1; j < n; j++) {
            Classificavel chave = a[j];
            int i = j - 1;
            while(i>=0 && chave.eMenorQue(a[i]) == -1) {
                a[i+1] = a[i];
                i = i - 1;
            }
            a[i+1] = chave;
        }
    }
}