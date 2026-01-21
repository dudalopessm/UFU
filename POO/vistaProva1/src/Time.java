import java.util.Arrays;
public class Time {
    private String nomeTime;
    private Jogador[] titulares = new Jogador[2];
    private Jogador reserva;

    //construtores
    public Time(String nome, Jogador[] listatitulares, Jogador r) {
        this.nomeTime = nome;
        for(int i = 0; i < titulares.length; i++) {
            titulares[i] = new Jogador(listatitulares[i].getNomeJogador(), listatitulares[i].getIdadeJogador(), listatitulares[i].getAlturaJogador(), listatitulares[i].getPesoJogador());
        }
        this.reserva = new Jogador(r.getNomeJogador(), r.getIdadeJogador(), r.getAlturaJogador(), r.getPesoJogador());
    }
    public Time(String nome, Jogador[] listatitulares) {
        this.nomeTime = nome;
        for(int i = 0; i < titulares.length; i++) {
            titulares[i] = new Jogador(listatitulares[i].getNomeJogador(), listatitulares[i].getIdadeJogador(), listatitulares[i].getAlturaJogador(), listatitulares[i].getPesoJogador());
        }
        this.reserva = null;
    }
    public Time() {

    }

    //getters e setters
    public String getNomeTime() {
        return nomeTime;
    }
    public void setNomeTime(String nomeTime) {
        this.nomeTime = nomeTime;
    }
    public Jogador[] getTitulares() {
        return titulares;
    }
    public void setTitulares(Jogador[] titulares) {
        this.titulares = titulares;
    }
    public Jogador getReserva() {
        return reserva;
    }
    public void setReserva(Jogador reserva) {
        this.reserva = reserva;
    }

    //mostrar
    public String toString() {
        return "\n--------------------\nTime: " + getNomeTime() + "\nTitulares: " + Arrays.toString(titulares) + "\nReserva: " + getReserva().toString();
    }
    public void mostraSemReserva(){
        System.out.println("\n--------------------Time: " + getNomeTime() + "\nTitulares: " + Arrays.toString(titulares) + "\nNão há reservas.");
    }

    //cálculo idade média
    public double calculoIdadeMedia() {
        if(getReserva() != null) {
            double soma = 0;
            for(int i = 0; i < titulares.length; i++) {
                soma = titulares[i].getIdadeJogador();
            }
            soma = soma + reserva.getIdadeJogador();
            return (soma/(titulares.length+1));
        } else {
            double soma = 0;
            for(int i = 0; i < titulares.length; i++) {
                soma = titulares[i].getIdadeJogador();
            }
            return (soma/ titulares.length);
        }
    }

    //destroi time -> se time é destruído, jogadores também são destruídos
    public void destroiTime() {
        setNomeTime(null);
        if(getReserva() != null) {
            reserva = null;
        }
        for(int i = 0; i < titulares.length; i++) {
            titulares[i] = null;
        }
    }
}