package freezemonster.sprite;

import java.awt.*;
import java.util.LinkedList;
import java.util.Random;

import javax.swing.ImageIcon;

import freezemonster.Commons;
import spriteframework.sprite.BadSprite;
import spriteframework.sprite.BadnessBoxSprite;

public class Monstro extends BadnessBoxSprite {

    private Gosma gosma;
    private int tipo;
    private Image imagemNormal;
    private Image imagemCongelado;
    private boolean congelado = false;
    private final int velocidade = 1; // controle da velocidade do movimento dos monstros

    private int dx, dy;
    private int direcao = 1; // 1 = direita, -1 = esquerda, 2 = cima, -2 = baixo

    public Monstro(int x, int y, int tipo) {
        this.tipo = tipo;
        initMonstro(x, y);
        definirDirecaoAleatoria();

    }

    // possibilita movimentos nas diagonais
    private void definirDirecaoAleatoria() {
        int[][] direcoes = {
                {1, 0}, {-1, 0},
                {0, -1}, {0, 1},
                {1, -1}, {-1, -1},
                {1, 1}, {-1, 1}
        };

        Random rand = new Random();
        int[] escolhida = direcoes[rand.nextInt(direcoes.length)];
        dx = escolhida[0];
        dy = escolhida[1];
    }

    public boolean isCongelado() {
        return congelado;
    }

    public void setCongelado(boolean congelado) {
        this.congelado = congelado;
    }

    private void initMonstro(int x, int y) {
        this.x = x;
        this.y = y;

        String caminhoNormal = "/images/monster" + tipo + ".png";
        String caminhoCongelado = "/images/monster" + tipo + "bg.png";

        ImageIcon iconNormal = new ImageIcon(getClass().getResource(caminhoNormal));
        ImageIcon iconCongelado = new ImageIcon(getClass().getResource(caminhoCongelado));

        this.imagemNormal = iconNormal.getImage().getScaledInstance(40, 40, Image.SCALE_SMOOTH);
        this.imagemCongelado = iconCongelado.getImage().getScaledInstance(40, 40, Image.SCALE_SMOOTH);

        gosma = new Gosma(x, y);

        setImage(imagemNormal);
    }

    public int getTipo() {
        return tipo;
    }

    public int getDirecao() {
        return direcao;
    }

    public Image getImagemCongelado() {
        return imagemCongelado;
    }

    public Gosma getGosma() {
        return gosma;
    }

    public void setGosma(Gosma gosma) {
        this.gosma = gosma;
    }

    public void setDy(int dy) {
        this.dy = dy;
    }

    public void setDx(int dx) {
        this.dx = dx;
    }

    public void act() {
        // previsão dos próximos passos
        int nextX = x + dx * velocidade;
        int nextY = y + dy * velocidade;

        // reflexão nas bordas horizontais
        if (nextX < 0) {
            nextX = 0;
            dx = -dx;
        }
        if (nextX > Commons.BOARD_WIDTH - Commons.MONSTRO_WIDTH) {
            nextX = Commons.BOARD_WIDTH - Commons.MONSTRO_WIDTH;
            dx = -dx;
        }

        // reflexão nas bordas verticais
        if (nextY < 0) {
            nextY = 0;
            dy = -dy;
        }

        // controle para os monstros não saírem da tela
        int margemSeguranca = 80;
        if (nextY > Commons.GROUND - Commons.MONSTRO_HEIGHT - margemSeguranca) {
            nextY = Commons.GROUND - Commons.MONSTRO_HEIGHT - margemSeguranca;
            dy = -dy;
        }

        // atualização das posições
        x = nextX;
        y = nextY;

        // atualização da direção
        if (Math.abs(dx) >= Math.abs(dy)) {
            direcao = dx > 0 ? 1 : -1;
        } else {
            direcao = dy > 0 ? -2 : 2;
        }
    }

    @Override
    public LinkedList<BadSprite> getBadnesses() {
        if(this.isCongelado() == true){
            return new LinkedList<>();
        } else {
            LinkedList<BadSprite> aGosma = new LinkedList<>();
            aGosma.add(gosma);
            return aGosma;
        }
    }
}