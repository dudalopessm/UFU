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
        float media = 0;
        for(int i = 0; i < vet.length; i++) {
            if(vet[i] > maior) {
                maior = vet[i];
            }
            if(vet[i] < menor) {
                menor = vet[i];
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
        System.out.println("<< Média de n alunos e número máximo >>");
        Scanner sc = new Scanner(System.in);
        int n;
        System.out.print("Insira o número de alunos que deseja registrar: ");
        n = sc.nextInt();
        while(n > 100) {
            System.out.println("Erro! O número máximo de alunos permitido é 100.");
            System.out.print("Insira novamente: ");
            n = sc.nextInt();
        }
        float notas[] = new float[n];
        float medianotas = 0;
        for(int i = 0; i < notas.length; i++) {
            System.out.print("Entre com a nota do aluno " + (i+ 1) + ": ");
            notas[i] = sc.nextFloat();
            medianotas = medianotas + notas[i];
        }
        medianotas = medianotas/n;
        System.out.println("__ Relatório de notas __");
        for(int i = 0; i < notas.length; i++) {
            System.out.println("A nota do aluno " + (i+1) + " é " + notas[i] + " .");
        }
        System.out.println("A média de notas da turma de " + n + " alunos é " + medianotas + " .");
        sc.close();
    }

    public static void ex10() {
        System.out.println("<< Subtração de vetores >>");
        Scanner sc = new Scanner(System.in);
        int A[] = new int[3];
        int B[] = new int[3];
        int C[] = new int[3];
        for(int i = 0; i < A.length; i++) {
            System.out.print("Digite o " + (i+1) + " número do vetor A: ");
            A[i] = sc.nextInt();
        }
        for(int i = 0; i < B.length; i++) {
            System.out.print("Digite o " + (i+1) + " número do vetor B: ");
            B[i] = sc.nextInt();
        }
        System.out.println("O resultado da subtração do vetor A e B resultou em um vetor C:");
        for(int i = 0; i < C.length; i++) {
            C[i] = A[i] - B[i];
            System.out.print(" " + C[i]);
        }
        System.out.print(".");
        sc.close();
    }

    public static void ex11() {
        Scanner sc = new Scanner(System.in);
        System.out.println("<< Vetor com pares e vetor com impares >>");
        int vet[] = new int[5];
        int npares = 0, nimpares = 0;
        for(int i = 0; i < vet.length; i++) {
            System.out.print("Digite o " + (i+1) + " número: ");
            vet[i] = sc.nextInt();
            if(vet[i]%2 == 0) {
                npares = npares + 1;
            } else {
                nimpares = nimpares + 1;
            }
        }
        int vetpar[] = new int[npares];
        int vetimpar[] = new int[nimpares];
        int j = 0, k = 0;
        for(int i = 0; i < vet.length; i++) {
            if(vet[i]%2 == 0) {
                vetpar[j] = vet[i];
                j++;
            } else {
                vetimpar[k] = vet[i];
                k++;
            }
        }
        System.out.println("Valores ímpares:");
        for(int i = 0; i < vetimpar.length; i++) {
            System.out.print(" " + vetimpar[i]);
        }
        System.out.print(".");
        System.out.println(" ");
        System.out.println("Valores pares:");
        for(int i = 0; i < vetpar.length; i++) {
            System.out.print(" " + vetpar[i]);
        }
        System.out.print(".");
        sc.close();
    }

    public static void ex12() {
        System.out.println("<< Probabilidades de cores >>");
        Scanner sc = new Scanner(System.in);
        float bolinhas[] = new float[4]; //0 é azul, 1 é verde, 2 é amarelo, 3 é vermelho
        float somatorio = 0;
        String nomescores[] = {"azul", "verde", "amarelo", "vermelho"};
        System.out.println("Digite a quantidade de bolinhas de cada cor abaixo.");
        //60, 51 70, 80
        for(int i = 0; i < bolinhas.length; i++) {
            System.out.print("Digite a quantidade de bolinhas da cor " + nomescores[i] + ": ");
            bolinhas[i] = sc.nextFloat();
            somatorio = somatorio + bolinhas[i];
        }
        float probabilidades[] = new float[4]; //0 é azul, 1 é verde, 2 é amarelo, 3 é vermelho
        for(int i = 0; i < probabilidades.length; i++) {
            probabilidades[i] = (bolinhas[i]/somatorio)*100;
        }
        float maiorvalor = probabilidades[0];
        for(int i = 0; i < probabilidades.length; i++) {
            if(probabilidades[i] > maiorvalor) maiorvalor = probabilidades[i];
        }
        System.out.println("As probabilidades aparecerão abaixo.");
        for(int i = 0; i < probabilidades.length; i++) {
            if(probabilidades[i] == maiorvalor) {
                System.out.println(nomescores[i] + ": " + probabilidades[i] + " << Maior probabilidade.");
            } else {
                System.out.println(nomescores[i] + ": " + probabilidades[i] + ".");
            }
        }
        sc.close();
    }

    public static void ex13() {
        Scanner sc = new Scanner(System.in);
        System.out.println("<< Zerando negativos >>");
        int vet[] = new int[5];
        for(int i = 0; i < vet.length; i++) {
            System.out.print("Digite o " + (i+1) + " número: ");
            vet[i] = sc.nextInt();
        }
        System.out.println("Ao zerar os negativos, obtém-se:");
        for(int i = 0; i < vet.length; i++) {
            if(vet[i] < 0) {
                vet[i] = 0;
            }
            System.out.print(" " + vet[i]);
        }
        sc.close();
    }

    public static void ex14() {
        Scanner sc = new Scanner(System.in);
        System.out.println("<< Universidade Àlamo >>");
        int n;
        System.out.print("Digite a quantidade de alunos que serão cadastrados: ");
        n = Integer.parseInt(sc.nextLine());
        while(n > 10000) {
            System.out.println("O número máximo de alunos suportado é 10.000! Tente novamente.");
            System.out.print("Digite a quantidade de alunos que serão cadastrados: ");
            n = Integer.parseInt(sc.nextLine());
        }
        int matriculas[] = new int[n];
        String[] classesocial = new String[n];
        float CRA[] = new float[n];
        int controle = 1;
        System.out.println();
        for(int i = 0; i < matriculas.length; i++) {
            boolean rep;
            do {
                rep = false;
                System.out.print("Entre com o número do aluno: ");
                matriculas[i] = Integer.parseInt(sc.nextLine());
                for(int j = 0; j < i; j++) {
                    if(matriculas[i] == matriculas[j]) {
                        System.out.println();
                        System.out.print("Número de aluno já existente! Tente novamente.");
                        System.out.println();
                        rep = true;
                        break;
                    }
                }
            } while(rep == true);
            System.out.print("Entre com a classe social do aluno " + matriculas[i] + ": ");
            classesocial[i] = sc.nextLine();
            System.out.print("Entre com o CRA do aluno " + matriculas[i] + ": ");
            CRA[i] = Float.parseFloat(sc.nextLine());
            System.out.println("");
        }
        System.out.println("==== Alunos Cadastrados ====");
        for(int i = 0; i < matriculas.length; i++) {
            System.out.print("Número: " + matriculas[i] + " | Classe social: " + classesocial[i].toUpperCase() + " | CRA: " + CRA[i]);
            System.out.println("");
        }
        sc.close();
    }

    public static void ex15() {
        Scanner sc = new Scanner(System.in);
        int vet[] = new int[8];
        System.out.println("<< Números iguais >>");
        int rep[] = new int[8]; //pior caso: todos iguais
        int aux = 0, cont = 0;
        for(int i = 0; i < vet.length; i++) {
            System.out.print("Entre com o " + (i+1) + " número: ");
            vet[i] = sc.nextInt();
        }
        for(int i = 0; i < vet.length; i++) {
            for(int j = i + 1; j < vet.length; j++) {
                if(vet[i] == vet[j]) {
                    boolean repetido = false;
                   for(int k = 0; k < aux; k++) {
                       if(rep[k] == vet[i]) {
                           repetido = true;
                           break;
                       }
                   }
                   if(repetido == false) {
                       rep[aux] = vet[i];
                       aux++;
                   }
                   break;
                }
            }
        }
        int temp[] = new int[aux];
        System.arraycopy(rep, 0, temp, 0, aux);
        rep = temp;
        temp = null;
        System.out.println("Valores repetidos: ");
        for(int i = 0; i < rep.length; i++) {
            System.out.print(" " + rep[i]);
        }
        sc.close();
    }

    public static void ex16(){
        Scanner sc = new Scanner(System.in);
        int vet[] = new int[8];
        System.out.println("<< Números iguais >>");
        int cont[] = new int[8]; //maximo de numeros repetido é 8
        boolean repetiu = false;
        for(int i = 0; i < vet.length; i++) {
            System.out.print("Entre com o " + (i+1) + " número: ");
            vet[i] = sc.nextInt();
        }
        for(int i = 0; i < vet.length; i++) {
            for(int j = 0; j < vet.length; j++) {
                if(vet[i] == vet[j]) cont[i]++;
            }
        }
        System.out.println("Valores repetidos:");
        for(int i = 0; i < vet.length; i++) {
            if(cont[i] > 1) {
                boolean exibiu = false;
                for(int j = 0; j < i; j++) {
                    if(vet[i] == vet[j]) {
                        exibiu = true;
                        break;
                    }
                }
                if(exibiu == false) {
                    System.out.println(vet[i] + " aparece " + cont[i] + " vezes");
                    repetiu = true;

                }
            }
        }
        if(repetiu == false) {
            System.out.println("Não há valores repetidos no vetor.");
        }
        sc.close();
    }

    public static void main(String[] args) {
        ex01();
        ex02();
        ex03();
        ex04();
        ex05();
        ex06();
        ex07();
        ex08();
        ex09();
        ex10();
        ex11();
        ex12();
        ex13();
        ex14();
        ex15();
        ex16();
    }
}