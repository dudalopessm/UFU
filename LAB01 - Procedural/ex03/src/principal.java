import java.util.Scanner;

public class principal {

    public static void ex01(){
        Scanner sc = new Scanner(System.in);
        int val1,val2,val3,val4,val5,val6;

        System.out.println("<< Listando um vetor >>");
        System.out.println("Entre com o número 1:");
        val1 = sc.nextInt();

        System.out.println("Entre com o número 2:");
        val2 = sc.nextInt();

        System.out.println("Entre com o número 3:");
        val3 = sc.nextInt();

        System.out.println("Entre com o número 4:");
        val4 = sc.nextInt();

        System.out.println("Entre com o número 5:");
        val5 = sc.nextInt();

        System.out.println("Entre com o número 6:");
        val6 = sc.nextInt();

        System.out.println("Os valores lidos são:");
        System.out.printf("%d %d %d %d %d %d ", val1, val2, val3, val4, val5, val6);

    }

    public static void ex02(){
        Scanner sc = new Scanner(System.in);
        int[] vet = new int[6];
        System.out.println("<< Listando um vetor >>");

        for (int i = 0; i < 6; i++){
            System.out.printf("Entre com o número %d:\n",i+1);
            vet[i] = sc.nextInt();
        }

        System.out.println("Os valores lidos são:");
        for (int i = 0; i < 6; i++){
            System.out.printf("%d ",vet[i]);
        }
    }

    public static void ex03() {
        Scanner sc = new Scanner(System.in);
        int[] vet = new int[6];
        System.out.println("<< Listando um vetor na ordem inversa >>");

        for(int i = 0; i < 6; i++) {
            System.out.print("Entre com o número " + (i+1) + ": ");
            vet[i] = sc.nextInt();
        }

        System.out.println("Os valores lidos são: ");
        for(int i = vet.length-1; i >= 0; i--) {
            System.out.print(" " + vet[i]);
        }
        sc.close();
    }

    public static void ex04() {
        Scanner sc = new Scanner(System.in);
        int[] vet = new int[6];
        System.out.println("<< Listando um vetor com somente números pares >>");

        int i = 0, temp;

        do {
            System.out.print("Entre com o número " + (i+ 1) + " :");
            temp = sc.nextInt();
            if(temp%2 == 0) {
                vet[i] = temp;
                i++;
            } else {
                System.out.println("Número inválido. Digite novamente a posição " + (i+1) + " do vetor.");
            }
        } while(i < 6);

        System.out.println("O vetor lido foi:");
        for(int j = 0; j < vet.length; j++) {
            System.out.print(" " + vet[j]);
        }

        sc.close();
    }

    public static void ex05() {
        Scanner sc = new Scanner(System.in);
        System.out.println("<< Maior, menor e média >>");
        int vet[] = new int[5];
        for(int i = 0; i < vet.length; i++) {
            System.out.print("Entre com o número " + (i+ 1) + ": ");
            vet[i] = sc.nextInt();
        }

        int maior = vet[0], menor = vet[0];
        float media = vet[4];
        for(int i = 0; i < vet.length-1; i++) {
            if(vet[i+1] > vet[i]) {
                maior = vet[i+1];
            }
            if(vet[i+1] < vet[i]) {
                menor = vet[i+1];
            }
            media = media + vet[i];
        }
        media = media/2;
        System.out.println("Maior elemento: " + maior);
        System.out.println("Menor elemento: " + menor);
        System.out.println("Média dos elementos: " + media);
        sc.close();
    }

    public static void ex06() {
        Scanner sc = new Scanner(System.in);
        System.out.println("<< Maior e menor >>");
        int vet[] = new int[5];
        for(int i = 0; i < vet.length; i++) {
            System.out.print("Entre com o número " + (i+ 1) + ": ");
            vet[i] = sc.nextInt();
        }

        int maior = vet[0], menor = vet[0];
        int indexmaior = 0, indexmenor = 0;
        for(int i = 0; i < vet.length-1; i++) {
            if(vet[i+1] > vet[i]) {
                maior = vet[i+1];
                indexmaior = i+1;
            }
            if(vet[i+1] < vet[i]) {
                menor = vet[i+1];
                indexmenor = i+1;
            }

        }
        System.out.println("O maior elemento é o " + maior + " e seu índice de posição é: " + indexmaior + " .");
        System.out.println("O menor elemento é o " + menor + " e seu índice de posição é: " + indexmenor + " .");
        sc.close();
    }

    public static void ex07() {
        Scanner sc = new Scanner(System.in);
        int vet[] = new int[5];
        float maiorvalor = vet[0], indicenormal;
        System.out.println("<< Notas normalizadas >>");

        //100 dividido pelo maior valor e depois multiplica todos por esse valor
        for(int i = 0; i < vet.length; i++) {
            System.out.print("Entre com a nota " + (i+ 1) + ": ");
            vet[i] = sc.nextInt();
        }

        for(int i = 0; i < vet.length-1; i++) {
            if (vet[i + 1] > vet[i]) {
                maiorvalor = vet[i+1];
            }
        }

        indicenormal = 100/maiorvalor;

        System.out.println("Notas normalizadas: ");
        for(int i = 0; i < vet.length; i++) {
            System.out.println("Aluno" + (i+1) + ": " + (vet[i]*indicenormal));
        }
        sc.close();
    }

    public static void ex08() {
        Scanner sc = new Scanner(System.in);
        double vet[] = new double[5];
        System.out.println("<< Média e desvio padrão amostral >>");
        double soma = 0, soma1 = 0;
        double media;
        double desvioamostral;

        for(int i = 0; i < vet.length; i++) {
            System.out.print("Entre com o número " + (i+ 1) + ": ");
            vet[i] = sc.nextDouble();
            soma = soma + vet[i];
        }

        media = soma/5;

        for(int i = 0; i < vet.length; i++) {
            soma1 = soma1+((vet[i]-media)*(vet[i]-media));
        }

        soma1 = soma1/4;

        desvioamostral = Math.sqrt(soma1);

        System.out.println("A média é " + media + " e o desvio padrão amostral é " + desvioamostral + ".");
        sc.close();
    }

    public static void ex09() {
        System.out.println("<< Média de alunos e número máximo >>");
        Scanner sc = new Scanner(System.in);

        sc.close();
    }

    public static void main(String[] args) {
        //ex01();
        //ex02();
        //ex03();
        //ex04();
        //ex05();
        //ex06();
        //ex07();
        //ex08();
        ex09();
    }
}