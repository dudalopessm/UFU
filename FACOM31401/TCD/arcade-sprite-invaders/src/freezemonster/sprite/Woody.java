package freezemonster.sprite;

import freezemonster.Commons;
import spriteframework.sprite.Player;
import spriteframework.sprite.Sprite;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyEvent;

// Woody é nosso jogador, extends de Player do framework.

public class Woody extends Player {

    private int width;
    private int direcao = 2; // utilizaremos 1 = direita, -1 = esquerda
    // 2 = para cima e -2 = para baixo

    public Woody() {
        loadImage();
        getImageDimensions();
        resetState();
    }

    public int getDirecao() {
        return direcao;
    }

    protected void loadImage() {
        ImageIcon ii = new ImageIcon(getClass().getResource("/images/woody.png"));

        Image woodyImage = ii.getImage().getScaledInstance(50, 80, Image.SCALE_DEFAULT);
        setImage(woodyImage);
    }


    public void act() {

        x += dx;
        y += dy;

        if (x <= Commons.BORDER_LEFT) {
            x = Commons.BORDER_LEFT;
        } else if (x + getImageWidth() > Commons.BOARD_WIDTH - Commons.BORDER_RIGHT) {
            x = Commons.BOARD_WIDTH - Commons.BORDER_RIGHT - getImageWidth();
        }

        if (y <= 0) {
            y = 0;
        } else if (y + getImageHeight() > Commons.BOARD_HEIGHT) {
            y = Commons.BOARD_HEIGHT - getImageHeight();
        }
    }

    public void keyPressed(KeyEvent e) {

        int key = e.getKeyCode();

        if (key == KeyEvent.VK_LEFT) {

            dx = -2;
            direcao = -1; // aplicando direção
        }

        if (key == KeyEvent.VK_RIGHT) {

            dx = 2;
            direcao = 1;
        }

        if(key == KeyEvent.VK_UP){
            dy = -2; // positivo, pensando no crescimento no eixo y.
            direcao = 2;
        }

        if(key == KeyEvent.VK_DOWN){
            dy = 2;// negativo, também pensando no eixo y.
            direcao = -2;
        }
    }

    public void keyReleased(KeyEvent e) {

        int key = e.getKeyCode();

        if (key == KeyEvent.VK_LEFT) {

            dx = 0;
        }

        if (key == KeyEvent.VK_RIGHT) {

            dx = 0;
        }

        if (key == KeyEvent.VK_UP){
            dy = 0;
        }

        if (key == KeyEvent.VK_DOWN){
            dy = 0;
        }
    }

    private void resetState() {
        setX(Commons.INIT_PLAYER_X);
        setY(Commons.INIT_PLAYER_Y);
    }
}